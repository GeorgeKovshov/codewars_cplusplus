
struct B_node {
	int val[4];
	B_node* leaves[5];
	B_node* parent;


	B_node(int v) {
		for (int i = 0; i < 5; i++) {
			leaves[i] = nullptr;
		}
		val[0] = v;
		for (int i = 1; i < 4; i++) {
			val[i] = INT_MAX;
		}
		parent = nullptr;
	}

	B_node* find_node(int v) {
		int i = 0;
		while (v > val[i] && i < 4) {
			i++;
		}
		if (v == val[i]) {
			return this;
		}
		else {
			if (leaves[i]) {
				return leaves[i]->find_node(v);
			}
			else {
				return this;
			}

		}
	}


	void add_fluent(int v, B_node* child_sibling) {
		if (val[3] == INT_MAX) {
			int j = 3;
			while (val[j-1] > v && j >0) {
				val[j] = val[j - 1];
				leaves[j + 1] = leaves[j];
				j--;
			}
			val[j] = v;

			leaves[j + 1] = child_sibling;
		}
		else {
			int i = 4;
			pair<int, B_node*> max = { val[3], leaves[4] };
			while (val[i-1]>v && i>0) {
				i--;
				val[i] = (i>=1) ? val[i - 1] : val[i];
				leaves[i + 1] = leaves[i];
			}
			if (i == 4) { max = { v, child_sibling }; }
			else{
				val[i] = v;
				leaves[i+1] = child_sibling;
			}
			//initializing new sibling
			B_node* new_sibling = new B_node(val[3]);
			new_sibling->val[1] = max.first;
			new_sibling->leaves[0] = leaves[3];
			new_sibling->leaves[1] = leaves[4];
			new_sibling->leaves[2] = max.second;
			if(new_sibling->leaves[0]) new_sibling->leaves[0]->parent = new_sibling;
			if (new_sibling->leaves[1]) new_sibling->leaves[1]->parent = new_sibling;
			if (new_sibling->leaves[2]) new_sibling->leaves[2]->parent = new_sibling;

			//modifying parent
			if (parent) {
				parent->add_fluent(val[2], new_sibling);
			}
			else {
				B_node* root = new B_node(val[2]);
				parent = root;
				root->leaves[0] = this;
				root->leaves[1] = new_sibling;
			}
			new_sibling->parent = parent;
			//modifying current node/old sibling
			val[2] = INT_MAX;
			val[3] = INT_MAX;
			leaves[3] = nullptr;
			leaves[4] = nullptr;
		}
		return;

	}



	B_node* split1(pair<int, B_node*>  v) {
		B_node* sibling = new B_node(val[3]);
		sibling->val[1] = v.first;
		sibling->leaves[2] = v.second;
		if(sibling->leaves[2]) sibling->leaves[2]->parent = sibling;

		if (parent) {
			B_node* tmp = parent->add1(val[2]);
			int i = 0;
			while (i < 4 && tmp->val[i] < val[2]) {
				i++;
			}
			int j = 3;
			while (j > i) {
				tmp->leaves[j + 1] = tmp->leaves[j];
				j--;
			}
			tmp->leaves[i + 1] = sibling;

			parent = tmp;

			sibling->parent = tmp;

			//return nullptr;
		}
		else {
			B_node* root = new B_node(val[2]);
			root->leaves[0] = this;
			root->leaves[1] = sibling;
			parent = root;
			sibling->parent = root;
			//return parent;
		}
		if (!v.second) {
			sibling->leaves[0] = leaves[3];
			sibling->leaves[1] = leaves[4];
			if(sibling->leaves[0]) sibling->leaves[0]->parent = sibling;
			if (sibling->leaves[1]) sibling->leaves[1]->parent = sibling;
		}
		else {

		}

		leaves[3] = nullptr;
		leaves[4] = nullptr;
		val[2] = INT_MAX; val[3] = INT_MAX;
		//return nullptr;
		return parent;

	}


	B_node* add1(int v) {
		int i = 0;
		while (i < 4 && val[i] <= v) {
			if (val[i] == v) { return nullptr; }
			i++;
		}
		if (i >= 4) {
			return split1({ v,nullptr })->find_node(v);
		}
		else {
			pair<int, B_node*> tmp = { val[3], leaves[3] };
			int j = 3;
			while (j > i) {
				val[j] = val[j - 1];
				//leaves[j + 1] = leaves[j];
				j--;
			}
			val[i] = v;
			//leaves[i] = nullptr;
			if (tmp.first == INT_MAX) { return this; }
			else { return split1(tmp)->find_node(tmp.first); }

		}

	}



	void print(int level) {
		string white = "";
		for (int j = 0; j < level; j++) {
			white.append("  ");
		}
		cout << white << "lvl:" << level << endl << white << "| ";

		for (int x = 0; x < 4; x++) {
			if (val[x] == INT_MAX) {
				cout << " _ ";
			}
			else {
				cout << " " << val[x] << " ";
			}
		}
		cout << "|" << endl;
		for (int i = 0; i < 5; i++) {
			if (leaves[i]) {
				leaves[i]->print(level + 1);
			}
			else {
				break;
			}
		}

	}

};

class B_tree {
	B_node* head;
public:
	B_tree(int v) {
		head = new B_node(v);
	}

	void add1(int v) {
		///B_node* d= head->add(v);
		//head = (d) ? d : head;
		B_node* tmp = head->find_node(v);
		tmp->add1(v);
		while (head->parent) {
			head = head->parent;
		}
	}

	void add(int v) {
		///B_node* d= head->add(v);
		//head = (d) ? d : head;
		B_node* tmp = head->find_node(v);
		tmp->add_fluent(v, nullptr);
		while (head->parent) {
			head = head->parent;
		}
	}
	void print() {
		head->print(1);
	}
	void find(int v) {
		B_node* tmp = head->find_node(v);
		if (tmp) {
			for (int x : tmp->val) {
				if (x == INT_MAX) {
					cout << " _ ";
				}
				else {
					cout << " " << x << " ";
				}

			}
			//cout << "Found"<< endl;
		}
		else {
			cout << "Not found" << endl;
		}
	}
	void print_parent() {
		if (head->leaves[0]->parent) {
			cout << "there's a parent";
		}
		else {
			cout << "there's no parent";
		}
	}


};










int main(void) {
	B_tree* tree = new B_tree(2);
	tree->add(3);
	tree->add(1);
	tree->add(4);
	tree->add(5);
	tree->add(6);
	tree->add(7);
	tree->add(8);

	tree->add(-2);
	tree->add(-1);
	tree->add(0);
	tree->add(-3);
	tree->add(-4);
	tree->add(-5);
	tree->add(9);
	tree->add(10);
	tree->add(11);
	tree->add(-20);
	tree->add(-21);
	//tree->print_parent(); //there's a parent
	tree->add(-22);
	tree->add(-23);
	tree->add(-24);
	tree->add(-25);
	tree->add(-26);
	tree->add(-27);
	//tree->print_parent();
	tree->add(-28);
	//////
	tree->add(-30);
	tree->add(-31);
	tree->add(-32);
	tree->add(-33);
	tree->add(-34);
	tree->add(-35);
	tree->add(-36);
	tree->add(-37);
	tree->add(-38);
	tree->print();
	///tree->find(-1);
	int test[5];
	test[4] = 3;
	cout << test[0];

}
	




