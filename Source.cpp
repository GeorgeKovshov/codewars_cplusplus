#include "Header.h"
#include <stack>

bool isPalindrome(ListNode* node) {
	stack<int> my_stack;
	ListNode* node_copy = node;
	int length = 0;
	while (node_copy) {
		node_copy = node_copy->next;
		length++;
	}
	bool result = true;
	bool middle = (length % 2 != 0) ? true : false;
	cout << "length is: " << length;
	length = length / 2;
	cout << ", half length is: " << length << endl;
	while (node) {
		cout << "cur. length: " << length << ", node: " << node->val << endl;
		if (length > 0) {
			my_stack.push(node->val);
		}
		else if (length < 0 and !my_stack.empty()) {
			if (my_stack.top() != node->val) {
				result = false;
			}
			my_stack.pop();	
		}
		else if (length == 0) {
			if (!middle) {
				my_stack.push(node->val);
			}
			
			
		}
		else {
			result = false;
		}
		length--;
		node = node->next;
	}

	return result;
}



int main(void) {

	ListNode node(1);
	node.add(2);
	node.add(2);
	node.add(2);
	node.add(1);


	cout << endl << isPalindrome(&node);

	
}