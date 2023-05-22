#include "Header.h"

class BST {
public:
	int value;
	BST* left;
	BST* right;
	BST* parent;

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

	void print(int level) {
		if (right) {
			right->print(level + 1);
		}
		for (int x = 1; x < level; x++) { cout << "   "; }
		cout <<level<< ": "<< value << " " << endl;
		if (left) {
			left->print(level + 1);
		}	
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



};


int main(void) {
	BST tree(3);
	//cout << tree.value;
	tree.add(2);
	tree.add(1);
	tree.add(6);
	tree.add(4);
	tree.add(0);
	tree.add(5);
	//cout << tree.left->left->value;
	tree.print(1);
	cout << endl << endl << endl;
	tree.inverse();
	tree.print(1);
	

}