#include "Header.h"

class BST {
	int value;
	BST* left;
	BST* right;
	BST* parent;


	void actual_removing() {

		/* if the node is a leaf */
		if (!left && !right) {
			if (!parent) {
				delete this;
			}
			else if (parent->value > value) {
				parent->left = nullptr;
				parent = nullptr;
				delete this;
			}
			else if (parent->value < value) {
				parent->right = nullptr;
				parent = nullptr;
				delete this;
			}
		}
		/* if the node has one child */
		else if (left && !right) { /// left child
			if (parent->value > value) {
				parent->left = left;
				left->parent = parent;
				parent = nullptr;
				left = nullptr;
				delete this;
			}
			else if (parent->value < value) {
				parent->right = left;
				left->parent = parent;
				parent = nullptr;
				left = nullptr;
				delete this;
			}
		}
		else if (right && !left) { // right child
			if (parent->value > value) {
				parent->left = right;
				right->parent = parent;
				parent = nullptr;
				right = nullptr;
				delete this;
			}
			else if (parent->value < value) {
				parent->right = right;
				right->parent = parent;
				parent = nullptr;
				right = nullptr;
				delete this;
			}
		}
		/* if the node has two children */
		else if (left && right) {
			BST* tmp = this->minimal();
			// the closest replacement (tmp) is to the right
			if (tmp->right) {
				if (tmp->parent->value > tmp->value) {
					tmp->parent->left = tmp->right;
				}
				else if (tmp->parent->value < tmp->value) {
					tmp->parent->right = tmp->right;
				}

				tmp->right->parent = tmp->parent;
			}
			///the closest replacement (tmp) is to the left
			else if (tmp->left) {
				if (tmp->parent->value > tmp->value) {
					tmp->parent->left = tmp->left;
				}
				else if (tmp->parent->value < tmp->value) {
					tmp->parent->right = tmp->left;
				}
				tmp->left->parent = tmp->parent;
			}
			// just in case there's nothing
			else {
				if (tmp->value > tmp->parent->value) {
					tmp->parent->right = nullptr;
				}
				else {
					tmp->parent->left = nullptr;
				}
			}
			value = tmp->value;
			delete tmp;
		}
	}

	void print(int level) {
		if (right) {
			right->print(level + 1);
		}
		for (int x = 1; x < level; x++) { cout << "   "; }
		cout << level << ": " << value << " " << endl;
		if (left) {
			left->print(level + 1);
		}
	}

	int depth_rec(int level) {
		if (!left && !right) {
			return level;
		}
		else if (left) {
			return left->depth_rec(level + 1);
		}
		else if (right) {
			return right->depth_rec(level + 1);
		}
		else {
			return max(left->depth_rec(level + 1), right->depth_rec(level + 1));
		}
		return -1;

	}

public:


	BST(int num) {
		value = num;
		left = nullptr;
		right = nullptr;
		parent = nullptr;
	}
	BST(int num, BST* pparent) {
		value = num;
		left = nullptr;
		right = nullptr;
		parent = pparent;
	}

	void add(int num) {
		if (num < value) {
			if (left == nullptr) {
				BST* tmp = new BST(num, this);
				left = tmp;
			}
			else {
				left->add(num);
			}
		}
		else if (num > value) {
			if (right == nullptr) {
				BST* tmp = new BST(num, this);
				right = tmp;
			}
			else {
				right->add(num);
			}
		}
	}

	void show() {
		print(1);
	}

	void inverse() {
		BST* l = left;
		left = right;
		right = l;
		if (left) {
			left->inverse();
		}
		if (right) {
			right->inverse();
		}
	}

	BST* search(int val) {
		if (value == val) {
			return this;
		}
		if (val < value && left) {
			return left->search(val);
		}
		else if (val > value && right) {
			return right->search(val);
		}
		return nullptr;
	}

	int depth() {
		return depth_rec(1);

	}

	BST* minimal() {
		/* function that returns the pointer to the tree node with closest value to the current */
		BST* lft = new BST(0);
		BST* rgt = new BST(0);
		if (left) {
			lft = left;
			while (lft->right) {
				lft = lft->right;
			}
		}
		if (right) {
			rgt = right;
			while (rgt->left) {
				rgt = rgt->left;
			}
		}


		if (left && right) {
			return (rgt->value - value > value - lft->value) ? rgt : lft;
		}
		else if (left) {
			return lft;
		}
		else if (right) {
			return rgt;
		}
		return nullptr;


	}

	void delete_val(int val) {
		if (value == val) {
			this->actual_removing();
		}
		else {
			BST* target = this->search(val);
			target->actual_removing();
		}
	}


	void turn() {
		/* the variations of the situation that provokes a turn is shown in comments */
		if ((!parent) || (!left && !right)) {
			return;
		}
		if (parent->left && !parent->right) {
			/*
					0
				   /
				  0
				 /
				0
			*/
			if (left && !right) {
				right = parent;
				parent = (parent->parent) ? parent->parent : nullptr;
				if (parent) {
					if (parent->left) {
						if (parent->left->value == right->value) {
							parent->left = this;
						}
						else {
							parent->right = this;
						}
					}
				}
				right->parent = this;
				right->left = nullptr;
			}

			/*
					3
				   /
				  1
				   \
					2
			*/
			else if (!left && right) {
				BST* three = parent;
				BST* one = this;
				BST* two = right;
				if (two->right) {
					three->left = two->right;
					two->right->parent = three;
				}
				else {
					three->left = nullptr;
				}
				two->right = three;
				two->parent = (three->parent) ? three->parent : nullptr;
				three->parent = two;

				if (two->left) {
					one->right = two->left;
					two->left->parent = one;
				}
				else {
					one->right = nullptr;
				}
				two->left = one;
				one->parent = two;

				if (two->parent) {
					if (two->parent->left) {
						if (two->parent->left->value == three->value) {
							two->parent->left = two;
						}
						else {
							two->parent->right = two;
						}
					}
				}

			}
		}
		else if (!parent->left && parent->right) {
			/*
					1
					 \
					 3
					/
				   2
			*/
			if (left && !right) {
				BST* one = parent;
				BST* three = this;
				BST* two = left;
				if (two->left) {
					one->right = two->left;
					two->left->parent = one;
				}
				else {
					one->right = nullptr;
				}
				two->left = one;
				two->parent = (one->parent) ? one->parent : nullptr;
				one->parent = two;

				if (two->right) {
					three->left = two->right;
					two->right->parent = three;
				}
				else {
					three->left = nullptr;
				}
				two->right = three;
				three->parent = two;

				if (two->parent) {
					if (two->parent->left) {
						if (two->parent->left->value == three->value) {
							two->parent->left = two;
						}
						else {
							two->parent->right = two;
						}
					}
				}
			}
			/*
					0
					 \
					  0
					   \
						0
			*/
			else if (right && !left) {
				left = parent;
				parent = (parent->parent) ? parent->parent : nullptr;
				if (parent) {
					if (parent->left) {
						if (parent->left->value == right->value) {
							parent->left = this;
						}
						else {
							parent->right = this;
						}
					}
				}
				left->parent = this;
				left->right = nullptr;

			}
		}

		///cout << value << " ";


	}


	void rebalance(int count) {
		if (count <= 0) {
			return;
		}
		this->turn();
		if (left) {
			left->rebalance(count - 1);
		}
		if (right) {
			right->rebalance(count - 1);
		}
	}



};

void binary_tree() {
	BST tree(3);
	//cout << tree.value;
	tree.add(2);
	tree.add(1);
	tree.add(6);
	tree.add(4);
	tree.add(0);
	tree.add(5);
	tree.add(7);
	tree.add(14);
	tree.add(11);
	tree.add(13);
	tree.add(12);
	tree.add(-2);
	tree.add(-3);
	tree.add(-1);
	//cout << tree.left->left->value;
	tree.show();
	//tree.rebalance();
	cout << endl << endl << endl;

	tree.rebalance(6);
	tree.show();
	tree.delete_val(1);
	tree.delete_val(-1);
	tree.rebalance(6);
	cout << endl << endl << endl;
	tree.show();

	//////tree.delete_val(3);
	//tree.show();
	//cout<<tree.search(6)->minimal()->value;
	//BST* node = tree.search(6);
	//node->print(1);

	//tree.inverse();
	//tree.print(1);

	////cout<<endl<<tree.depth();

}



struct node {
	int value;
	bool is_red;
	node* parent;
	node* left;
	node* right;

	node(int val) {
		value = val;
		is_red = true;
		parent = nullptr;
		left = nullptr;
		right = nullptr;
	}

	node(int val, node* par) {
		value = val;
		is_red = true;
		parent = par;
		left = nullptr;
		right = nullptr;
	}
	node(int val, bool red) {
		//create nil black node
		value = val;
		is_red = red;
		parent = nullptr;
		left = nullptr;
		right = nullptr;
	}

	void show() {
		if (left) { left->show(); }
		cout << value << " ";
		if (right) { right->show(); }

	}

	void print(int level) {
		if (right) {
			right->print(level + 1);
		}
		for (int x = 1; x < level; x++) { cout << "   "; }
		cout << level << ": " << value << " ";
		if (is_red) { cout << "red" << endl; }
		else { cout << "blk" << endl; }
		if (left) {
			left->print(level + 1);
		}
	}


};




class RBT {
	node* root;
	node* nil;

public:
	RBT(int val) {
		root = new node(val, false);
		nil = new node(INT_MIN, false);
	}

	void show() {

		root->show();
	}

	void print() {

		root->print(1);
	}

	void rotate_left(node* current) {
		node* tmp = current->right;
		current->right = tmp->left;
		tmp->left = current;
		tmp->parent = current->parent;
		current->parent = tmp;
		if (tmp->parent) {
			if (tmp->value > tmp->parent->value) {
				tmp->parent->right = tmp;
			}
			else {
				tmp->parent->left = tmp;
			}
		}
		else {
			root = tmp;
		}
	}

	void rotate_right(node* current) {
		node* tmp = current->left;
		current->left = tmp->right;
		tmp->right = current;
		tmp->parent = current->parent;
		current->parent = tmp;
		if (tmp->parent) {
			if (tmp->value > tmp->parent->value) {
				tmp->parent->right = tmp;
			}
			else {
				tmp->parent->left = tmp;
			}
		}
		else {
			root = tmp;
		}
	}

	void rebalance(node* current) {
		if (current == nullptr || current == root || current->parent == root || current->parent->is_red == false) { return; }
		if (current->value > current->parent->value) {
			//left triangle
			if (current->parent->value < current->parent->parent->value) {
				//uncle is black
				if (current->parent->parent->right == nullptr || current->parent->parent->right->is_red == false) {
					//current->is_red = false;
					node* tmp = current->parent;
					rotate_left(current->parent);
					rebalance(tmp);
					//current->parent->right->is_red = false;
					//recolor??
				}
				//uncle is red
				else if (current->parent->parent->right->is_red == true) {
					current->parent->parent->right->is_red = false;
					current->parent->is_red = false;
					current->parent->parent->is_red = true;
				}
			}
			//right line
			else {
				current->parent->parent->is_red = true;
				current->parent->is_red = false;
				rotate_left(current->parent->parent);
			}
		}
		else {
			//right triangle
			if (current->parent->value > current->parent->parent->value) {
				//uncle is black
				if (current->parent->parent->left == nullptr) {
					//current->is_red = false;
					node* tmp = current->parent;
					rotate_right(current->parent);
					rebalance(tmp);
					//current->parent->left->is_red = false;
					//recolor??
				}
				//uncle is red
				else if (current->parent->parent->left->is_red == true) {
					current->parent->parent->left->is_red = false;
					current->parent->is_red = false;
					current->parent->parent->is_red = true;
				}
			}
			//left line
			else {
				current->parent->parent->is_red = true;
				current->parent->is_red = false;
				rotate_right(current->parent->parent);


			}

		}
		rebalance(current->parent);
	}


	void add(int val) {
		if (!root) {
			root = new node(val, false);
		}

		node* tmp = root;
		node* tmp2 = root;
		while (tmp) {
			tmp2 = tmp;
			if (val > tmp->value) {
				tmp = tmp->right;
			}
			else if (val < tmp->value) {
				tmp = tmp->left;
			}
			else return;
		}
		node* addition = new node(val, tmp2);
		if (val > tmp2->value) {
			tmp2->right = addition;
		}
		else {
			tmp2->left = addition;
		}
		rebalance(addition);
	}

	node* find(int val) {
		node* tmp = root;
		node* tmp2 = root;
		while (tmp) {
			tmp2 = tmp;
			if (val > tmp->value) {
				tmp = tmp->right;
			}
			else if (val < tmp->value) {
				tmp = tmp->left;
			}
			else return tmp;
		}
		return (tmp2->value == val) ? tmp2 : nullptr;
	}



};

void Red_Black_trees() {
	RBT tree(15);
	tree.add(5);
	//tree.add(1);
	tree.add(8);
	//tree.add(5);
	tree.add(12);
	tree.add(19);
	tree.add(1);
	tree.add(9);

	tree.add(13);
	tree.add(23);
	tree.add(10);
	tree.print();
}