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

	B_node* split1(int v) {
		B_node* sibling = new B_node(val[3]);
		sibling->val[1] = v;

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
		sibling->leaves[0] = leaves[3];
		sibling->leaves[1] = leaves[4];
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
			return split1(v)->find_node(v);
		}
		else {
			int tmp = val[3];
			int j = 3;
			while (j > i) {
				val[j] = val[j - 1];
				j--;
			}
			val[i] = v;
			if (tmp == INT_MAX) { return this; }
			else { return split1(tmp)->find_node(tmp); }

		}

	}

	/*
	B_node* split(int v) {
		B_node* root = new B_node(val[2]);
		B_node* sibling = new B_node(val[3]);
		sibling->val[1] = v;
		val[2] = INT_MAX; val[3] = INT_MAX;
		root->leaves[0] = this;
		root->leaves[1] = sibling;
		return root;

	}


	B_node* add(int v) {
		int i = 0;
		///while (i < 4 && val[i] < v) {
		while (i < 4 && val[i] <= v) {
			if (val[i] == v) { return nullptr; }
			i++;
		}
		if (i < 4) {
			if (leaves[i]) { leaves[i] = leaves[i]->add(v); return this; }
		}

		if (i >= 4) {
			return split(v);
		}
		else {
			int tmp = val[3];
			int j = 3;
			while (j > i) {
				val[j] = val[j - 1];
				j--;
			}
			val[i] = v;
			if (tmp == INT_MAX) { return this; }
			else { return split(tmp); }

		}

	}*/

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

	void add(int v) {
		///B_node* d= head->add(v);
		//head = (d) ? d : head;
		B_node* tmp = head->find_node(v);
		tmp->add1(v);
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