#include "Header.h"
#include <queue>
#include <iostream>


struct TreeNode_New {
	int val;
	TreeNode_New* left;
	TreeNode_New* right;
	TreeNode_New* parent;

	TreeNode_New() {
		val = 0;
		left = nullptr;
		right = nullptr;
		parent = nullptr;
	}

	TreeNode_New(int v) {
		val = v;
		left = nullptr;
		right = nullptr;
		parent = nullptr;
	}

	void print(int level) {
		if (right) {
			right->print(level + 1);
		}
		for (int x = 1; x < level; x++) { std::cout << "   "; }
		std::cout << level << ": " << val << " " << std::endl;
		if (left) {
			left->print(level + 1);
		}
	}

	void left_turn() {
		if (!parent) return;
		TreeNode_New* v = this;
		TreeNode_New* vl = left;
		TreeNode_New* p = parent;
		TreeNode_New* pp = parent->parent;

		if (pp) {
			if (pp->left == parent) pp->left = v;
			else pp->right = v;
		}
		v->parent = pp;

		v->left = p;
		p->parent = v;

		p->left = vl;
		if (vl) vl->parent = p;

	}

	void right_turn() {
		if (!parent) return;
		TreeNode_New* v = this;
		TreeNode_New* vr = right;
		TreeNode_New* p = parent;
		TreeNode_New* pp = parent->parent;

		if (pp) {
			if (pp->left == parent) pp->left = v;
			else pp->right = v;
		}
		v->parent = pp;

		v->right = p;
		p->parent = v;

		p->right = vr;
		if (vr) vr->parent = p;

	}

	void printLVR() {
		if (left) left->printLVR();
		std::cout << val << " ";
		if (right) right->printLVR();
	}

	TreeNode_New* find_DFS(int i) {
		if (val == i) return this;
		if (left) {
			TreeNode_New* tmp = left->find_DFS(i);
			if (tmp) return tmp;
		}
		if (right) {
			TreeNode_New* tmp = right->find_DFS(i);
			if (tmp) return tmp;
		}
		return nullptr;
	}


};

class Tree_New {
	TreeNode_New* root;
public:
	Tree_New(int N) {
		root = new TreeNode_New(1);
		std::queue<TreeNode_New*> q;
		q.push(root);
		while (!q.empty()) {
			q.push(nullptr);
			while (q.front()) {
				if (q.front()->val * 2 <= N) {
					q.front()->left = new TreeNode_New(q.front()->val * 2);
					q.front()->left->parent = q.front();

				}
				else return;
				if (q.front()->val * 2 + 1 <= N) {
					q.front()->right = new TreeNode_New(q.front()->val * 2 + 1);
					q.front()->right->parent = q.front();
				}
				else return;
				q.push(q.front()->left);
				q.push(q.front()->right);
				q.pop();

			}
			q.pop();
		}
	}

	void print() {
		root->print(1);
	}

	void printLVR() {
		root->printLVR();
	}

	TreeNode_New* find(int v) {
		std::queue<TreeNode_New*> q;
		q.push(root);
		while (q.front()) {
			q.push(nullptr);
			while (q.front()) {
				if (q.front()->val == v) return q.front();
				else if (q.front()->val > v) break;
				else {
					if (q.front()->left) q.push(q.front()->left);
					if (q.front()->right) q.push(q.front()->right);
				}
				q.pop();

			}
			q.pop();
		}
		return nullptr;

	}



	void turn(int v) {
		TreeNode_New* tmp = find_DFS(v);
		if (!tmp || !tmp->parent) return;
		if (tmp == tmp->parent->left) tmp->left_turn();
		else if (tmp == tmp->parent->right) tmp->right_turn();
		if (root->parent) {
			while (root->parent) {
				root = root->parent;
			}
		}
	}

	TreeNode_New* find_DFS(int i) {
		return root->find_DFS(i);
	}
};



void dream_tree() {
	Tree_New* t = new Tree_New(10);
	t->print();
	std::cout << std::endl << t->find_DFS(7)->parent->val;
	///std::cout << std::endl;

	t->turn(5);
	t->turn(7);
	t->print();
	t->turn(4);
	t->print();
	t->turn(7);
	t->turn(8);
	t->turn(7);
	t->printLVR();
}