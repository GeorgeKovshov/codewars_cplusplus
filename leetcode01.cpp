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


ListNode* middleNode(ListNode* head) {
	ListNode* fast = head;
	ListNode* slow = head;
	while (fast) {

		fast = fast->next;
		if (fast) {
			fast = fast->next;
		}
		else {
			break;
		}

		slow = slow->next;
	}
	return slow;
}


vector<string> fizzBuzz(int n) {
	vector<string> result;
	for (int i = 1; i <= n; i++) {


		if (i % 3 == 0 && i % 5 == 0) {
			result.push_back("FizzBuzz");
		}
		else if (i % 3 == 0) {
			result.push_back("Fizz");
		}
		else if (i % 5 == 0) {
			result.push_back("Buzz");
		}
		else {
			result.push_back(to_string(i));
		}
	}
	return result;
}

vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
	int width = mat[0].size();
	int depth = mat.size();
	int j = 0;
	vector<int> result;

	while (k > 0 && j < width) {
		for (int i = 0; i < depth && k>0; i++)
			if (mat[i][j] == 0) {
				if (std::find(result.begin(), result.end(), i) == result.end()) {
					k--;
					result.push_back(i);
				}
			}
		j++;
	}
	if (k > 0) {
		for (int i = 0; i < depth && k>0; i++) {
			if (std::find(result.begin(), result.end(), i) == result.end()) {
				k--;
				result.push_back(i);
			}
		}
	}

	return result;
}

int numberOfSteps(int num) {
	int count = 0;
	while (num > 0) {
		if (num % 2 == 0) {
			num = num / 2;
		}
		else {
			num--;
		}
		count++;
	}

	return count;
}

int maximumWealth(vector<vector<int>>& accounts) {
	int max_sum = 0;
	for (vector<int> x : accounts) {
		int sum = 0;
		for (int y : x) {
			sum += y;
		}
		max_sum = (sum > max_sum) ? sum : max_sum;
	}
	return max_sum;
}

vector<int> twoSum(vector<int>& nums, int target) {
	unordered_map<int, int> m;
	for (int i = 0; i < nums.size(); i++) {
		if (m.find(target - nums[i]) != m.end()) {
			return { m[target - nums[i]], i };
		}
		else {
			m.insert({ nums[i], i });
		}

	}
	return { 0,0 };
}

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	if (nums1.empty()) {
		nums1 = nums2;
		return;
	}
	else if (nums2.empty()) {
		return;
	}
	int i = 0;
	int j = 0;
	int val = nums2[0];
	while (i < m) {
		if (nums1[i] <= val) {
			i++;
		}
		else {
			int tmp = nums1[i];
			nums1[i] = nums2[0];
			nums2[0] = tmp;
			i++;
			while (j < n - 1) {
				if (nums2[j] > nums2[j + 1]) {
					int tmp = nums2[j];
					nums2[j] = nums2[j + 1];
					nums2[j + 1] = tmp;
					j++;
				}
				else {
					break;
				}
			}
			val = nums2[0];
			j = 0;
		}
	}
	while (j < n) {
		nums1[i] = nums2[j];
		i++;
		j++;
	}
}

int removeElement(vector<int>& nums, int val) {
	int i = 0;
	int j = 0;
	int length = nums.size();
	while (i < length) {

		if (nums[i] == val) {
			i++;
		}
		if (i < length) {
			nums[j] = nums[i];
			if (nums[j] == val) {
				j--;
			}
		}
		else {
			break;
		}

		i++;
		j++;
	}
	return j;

}

bool canConstruct1(string ransomNote, string magazine) {
	unordered_map<char, int> letters;
	for (char x : magazine) {
		if (letters.find(x) != letters.end()) {
			letters[x]++;
		}
		else {
			letters.insert({ x, 1 });
		}
	}
	for (auto x : letters) {
		cout << x.first << " " << x.second << endl;
	}
	bool result = true;
	for (char y : ransomNote) {
		if (letters.find(y) == letters.end()) {
			result = false;
			break;
		}
		else if (letters[y] <= 0) {
			result = false;
			break;
		}
		else {
			letters[y]--;
		}
	}
	return result;
}

int removeDuplicates(vector<int>& nums) {
	int previous = -101;
	int count = 0;
	vector<int> nums2;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] != previous) {
			nums2.push_back(nums[i]);
			count++;
		}
		previous = nums[i];
	}
	nums = nums2;
	return count;

}
int majorityElement(vector<int>& nums) {
	unordered_map<int, int> list;
	int length = nums.size();
	for (int x : nums) {
		if (list.find(x) != list.end()) {
			list[x]++;
			if (list[x] >= length / 2 + 1) {
				return x;
			}
		}
		else {
			list.insert({ x,1 });
		}

	}
	return 1;

}

int removeDuplicates2(vector<int>& nums) {
	int count = 1;
	int j = -1;
	int k = nums.size();
	int previous = -100001;
	int length = k;
	for (int i = 0; i < length; i++) {
		if (nums[i] == previous) {
			count++;
			if (count > 2) {
				while (i < length) {
					if (nums[i] == previous) {
						i++;
						k--;
					}
					else {
						break;
					}
				}
				if (i >= length) {
					break;
				}
				previous = nums[i];
				count = 1;
			}
		}
		else {
			count = 1;
			previous = nums[i];
		}
		j++;
		nums[j] = nums[i];


	}
	return k;
}

void rotate(vector<int>& nums, int k) {
	int length = nums.size();
	if (nums.empty()) {
		return;
	}
	else if (length == 1) {
		return;
	}
	while (k >= length) {
		k -= length;
	}
	vector<int> nums2 = nums;
	for (int i = 0; i < length; i++) {
		if (i + k < length) {
			nums2[i + k] = nums[i];
		}
		else {
			nums2[i + k - length] = nums[i];
		}
	}
	nums = nums2;

}

void rotate2(vector<int>& nums, int k) {
	k %= nums.size();
	reverse(nums.begin(), nums.end());
	reverse(nums.begin(), nums.begin() + k);
	reverse(nums.begin() + k, nums.end());
}

bool canJump(vector<int>& nums) {
	int length = nums.size();
	if (nums.empty()) {
		return false;
	}
	else if (length == 1) {
		return true;
	}
	else if (nums[0] == 0) {
		return false;
	}
	stack<int> jumps;
	jumps.push(0);
	jumps.push(0);
	int i = 0;
	while (i < length - 1) {
		if (nums[i] == 0) {
			int previous = jumps.top();
			jumps.pop();
			i -= previous;
			if (previous == 1) {
				int previous = jumps.top();
				jumps.pop();
				i -= previous;
				nums[i]--;
			}
			else {
				i += previous - 1;
				jumps.push(previous - 1);
			}

		}
		else {
			jumps.push(nums[i]);
			i = min(nums[i] + i, length - 1);
			//jumps.push(nums[i]);
		}
		if (nums[0] <= 0) {
			break;
		}
	}
	if (i >= length - 1) {
		return true;
	}
	else {
		return false;
	}

}

bool canJump2(vector<int>& nums) {
	int n = nums.size(), maxv = nums[0];
	for (int i = 0; i < nums.size(); ++i) {
		if (i > maxv) {
			return false;
		}
		maxv = max(maxv, i + nums[i]);
	}
	return true;
}


void inputRoman(int m, char c, stringstream* oss) {
	while (m > 0) {
		*oss << c;
		m--;
	}
}

void smallRoman(int* num, char c1, char c2, char c3, stringstream* oss, int multiplier) {
	/*c1 - smallest, c3 - biggest, multiplier - 10;100;1000*/
	if (*num >= 9 * multiplier) {
		*oss << c1 << c3;
		*num -= 9 * multiplier;
	}
	else if (*num >= 5 * multiplier) {
		*oss << c2;
		*num -= 5 * multiplier;
	}
	else if (*num >= 4 * multiplier) {
		*oss << c1 << c2;
		*num -= 4 * multiplier;
	}
}

string intToRoman(int num) {
	stringstream oss;
	// target X:  XX__
	int count = num / 1000;
	num = num % 1000;
	inputRoman(count, 'M', &oss);
	smallRoman(&num, 'C', 'D', 'M', &oss, 100);
	// _XX_
	count = num / 100;
	num = num % 100;
	inputRoman(count, 'C', &oss);
	smallRoman(&num, 'X', 'L', 'C', &oss, 10);
	// __XX
	count = num / 10;
	num = num % 10;
	inputRoman(count, 'X', &oss);
	smallRoman(&num, 'I', 'V', 'X', &oss, 1);
	// ___X
	inputRoman(num, 'I', &oss);

	return oss.str();
}