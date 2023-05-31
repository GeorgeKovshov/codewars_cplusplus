#include "Header.h"


map<char, int> rome = {
	   {'I', 1},
	   {'V', 5},
	   {'X', 10},
	   {'L', 50},
	   {'C', 100},
	   {'D', 500},
	   {'M', 1000}
};




int romanToInt(string s) {
	int length = s.length();
	int sum = 0;
	int previous = 0;
	for (int i = length - 1; i >= 0; i--) {
		if (rome[s[i]] >= previous) {
			sum += rome[s[i]];
		}
		else {
			sum -= rome[s[i]];
		}
		previous = rome[s[i]];

	}

	return sum;
}



void ListNode::add(int x) {
	ListNode* n = this;
	while (n->next) {
		n = n->next;
	}
	n->next = new ListNode(x);
}

void ListNode::show() {
	ListNode* n = this;
	while (n) {
		cout << n->val << " ";
		n = n->next;
	}
}

bool isPalindromeOld(ListNode* head) {
	if (head->next == nullptr) {
		return true;
	}
	ListNode* head2 = head->next;
	int count = 2;
	int reverse_count = 100001;
	int reverse_count2 = 100001;
	bool is_palindrome = false;
	unordered_map<int, int> nums = { {1, head->val}, {100001, -1} };
	while (head2) {
		nums[count] = head2->val;

		if (reverse_count < 0) {
			is_palindrome = false;
			reverse_count = 100001;
		}

		if (reverse_count2 >= 0 && reverse_count2 < 100001) {
			is_palindrome = true;
		}
		else {
			reverse_count2 = 100001;
		}

		if (nums[reverse_count] == nums[count] && is_palindrome == true) {
			reverse_count -= 1;
		}
		else if (is_palindrome == true) {
			is_palindrome = false;
			if (nums[reverse_count2] == nums[count]) {
				reverse_count2 -= 1;
				is_palindrome = true;
			}
			reverse_count = 100001;
		}

		if (nums[count - 1] == nums[count] && is_palindrome == false) {
			is_palindrome = true;
			reverse_count = count - 2;
			if (nums[count - 2] == nums[count]) {
				reverse_count2 = count - 3;
			}
		}
		else if (nums[count - 2] == nums[count] && is_palindrome == false) {
			is_palindrome = true;
			reverse_count = count - 3;
		}
		head2 = head2->next;
		count++;
	}

	for (auto const& i : nums) {
		cout << i.first << " " << i.second << std::endl;

	}

	//for (int x = 0; x < count; x++) {
	//	cout << nums[x] << " ";
	//}


	if (reverse_count == 0 || reverse_count2 == 0) {
		return true;
	}
	return false;
}



bool isPalindrome2(ListNode* head) {
	if (head->next == nullptr) {
		return true;
	}
	ListNode* head2 = head->next;
	int count = 2;
	int reverse_count = 100;
	int reverse_count2 = 100;
	bool is_palindrome = false;
	unordered_map<int, int> nums = { {1, head->val}, {0, -1}, {100, -2}, {99, -3}, {98, -4} };
	while (head2) {
		nums.insert({ count, head2->val });

		if (reverse_count < 0) {
			is_palindrome = false;
			reverse_count = 100;
		}

		if (reverse_count2 > 0 && reverse_count2 < 100) {
			is_palindrome = true;
		}
		else {
			reverse_count2 = 100;
		}

		if (nums.find(reverse_count)->second == head2->val && is_palindrome == true) {
			reverse_count -= 1;
		}
		else if (is_palindrome == true) {
			is_palindrome = false;
			if (nums.find(reverse_count2)->second == head2->val) {
				reverse_count2 -= 1;
				is_palindrome = true;
			}
			reverse_count = 100;
		}

		if (nums.find(count - 1)->second == head2->val && is_palindrome == false) {
			is_palindrome = true;
			reverse_count = count - 2;
			if (nums.find(count - 2)->second == head2->val) {
				reverse_count2 = count - 3;
			}
		}
		else if (nums.find(count - 2)->second == head2->val && is_palindrome == false) {
			is_palindrome = true;
			reverse_count = count - 3;
		}
		head2 = head2->next;
		count++;
	}

	/*
	for (int x = 0; x < count; x++) {
		cout << nums[x] << " ";
	}*/

	if (reverse_count == 0 || reverse_count2 == 0) {
		return true;
	}
	return false;
}

bool isPalindrome(ListNode* node) {
	stack<int> my_stack;
	ListNode* node_copy = node;
	int length = 0;
	while (node_copy) {
		node_copy = node_copy->next;
		length++;
	}

	if (length == 0) {
		return false;
	}
	else if (length == 1) {
		return true;
	}
	else if (length == 2) {
		if (node->val == node->next->val) {
			return true;
		}
		else {
			return false;
		}
	}

	bool result = true;
	bool length_is_even = (length % 2 == 0) ? true : false;
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
			if (length_is_even) {
				if (my_stack.top() != node->val) {
					result = false;
				}
				my_stack.pop();
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

void palindroming() {
	ListNode node(1);
	node.add(2);
	node.add(2);
	node.add(2);
	node.add(1);
	cout << endl << isPalindrome(&node);
}
