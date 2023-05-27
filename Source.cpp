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


struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}


	void add(int x) {
		ListNode* n = this;
		while (n->next) {
			n = n->next;
		}
		n->next = new ListNode(x);
	}

	void show() {
		ListNode* n = this;
		while (n) {
			cout << n->val << " ";
			n = n->next;
		}
	}
	
};


bool isPalindrome(ListNode* head) {
	ListNode* head2 = head->next;
	int count = 1;
	int reverse_count = 100;
	bool is_palindrome = false;
	map<int, int> nums = { {0, head->val} };
	while (head2) {
		nums[count] = head2->val;

		if (reverse_count < 0) {
			is_palindrome = false;
			reverse_count = 100;
		}

		if (nums[reverse_count] == nums[count] && is_palindrome == true) {
			reverse_count -= 1;
		}
		else if (nums[reverse_count] != nums[count] && is_palindrome == true) {
			is_palindrome = false;
			reverse_count = 100;
		}

		if (nums[count - 1] == nums[count] && is_palindrome == false) {
			is_palindrome = true;
			reverse_count = count - 2;
		}
		head2 = head2->next;
		count++;
	}
	
	/*
	for (int x = 0; x < count; x++) {
		cout << nums[x] << " ";
	}*/
	
	if (reverse_count == 0) {
		return true;
	}
	return false;
}



int main(void) {
	//romanToInt("MCMXCIV");
	///cout << romanToInt("MDIX");
	//cout << isPalindrome("MDIX");
	ListNode node;
	node.add(1);
	node.add(2);
	node.add(2);
	node.add(1);


;
	node.show();


	//cout << isPalindrome(&node);

	
}