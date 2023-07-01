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

string reverseWords(string s) {
	stack<string> stac;
	string tmp;
	stringstream ss;
	int i = 0;
	while (s[i] == ' ') {
		i++;
	}
	int j = i;
	while (i < s.size() - 1) {
		i = s.find(' ', i + 1);
		tmp = s.substr(j, i - j);
		cout << i << ": " << tmp << endl;
		stac.push(tmp);
		j = i + 1;
	}
	while (!stac.empty()) {
		if (!stac.top().empty()) {
			ss << stac.top() << " ";
		}

		stac.pop();
	}

	tmp = ss.str();
	return tmp.substr(0, tmp.size() - 1);
}

string reverseWords2(string s) {
	int n = s.size();
	int i = 0;
	string ans = "";

	while (i < n)
	{
		while (i < n and s[i] == ' ')
			i++;
		if (i >= n)
			break;
		int j = i + 1;
		while (j < n and s[j] != ' ')
			j++;
		string add = s.substr(i, j - i);
		if (ans == "")
			ans = add;
		else
			ans = add + " " + ans;
		i = j + 1;
	}
	return ans;
}

string reverseWords3(string s) {
	vector<string> words;
	stringstream ss(s);
	string tmp;
	while (ss >> tmp)
		words.push_back(tmp);

	string ans;
	for (int i = words.size() - 1; i >= 0; --i) {
		if (i != words.size() - 1) ans += " ";
		ans += words[i];
	}
	return ans;
}

string reverseWords4(string s) {
	reverse(s.begin(), s.end());
	int l = 0, r = 0, i = 0, n = s.size();
	while (i < n) {
		while (i < n && s[i] != ' ')
			s[r++] = s[i++];

		if (l < r) { // if we can find a non-empty word then
			reverse(s.begin() + l, s.begin() + r); // reverse current word
			if (r == n) break;
			s[r++] = ' '; // set empty space
			l = r;
		}
		++i; // now i == n or s[i] == ' ', so we skip that character!
	}
	if (r > 0 && s[r - 1] == ' ') --r; // skip last empty character if have
	s.resize(r);
	return s;
}

int maxProfit(vector<int>& prices) {
	int min = 10001;
	int result = 0;
	for (int x : prices) {
		min = (x < min) ? x : min;
		if (min != 10001 && x - min > result) {
			result = x - min;
		}
	}
	return result;
}

int maxProfitFast(vector<int>& prices) {
	int profit = 0;
	int mini = prices[0];
	for (auto it : prices) {
		mini = min(it, mini);
		profit = max(profit, it - mini);
	}
	return profit;
}

int maxProfitSlow(vector<int>& prices) {
	int left = 0;
	int right = 1;
	int max_profit = 0;
	int currentProfit = 0;
	while (right < prices.size()) {
		currentProfit = prices[right] - prices[left];
		if (prices[left] < prices[right]) {
			max_profit = max(currentProfit, max_profit);
		}
		else {
			left = right;
		}
		right++;
	}
	return max_profit;

}


int maxProfit2(vector<int>& prices) {
	int profitOld = 0;
	int max_profit = 0;
	int miniOld = prices[0];
	int miniNew = INT_MAX;
	for (int i = 1; i < prices.size(); i++) {
		if (prices[i] <= miniOld) {
			max_profit += max(profitOld, 0);
			miniOld = prices[i];
			miniNew = INT_MAX;
			profitOld = 0;
		}
		else if (miniNew != INT_MAX && prices[i] - miniNew + profitOld > prices[i] - miniOld) {
			max_profit += max(profitOld, 0);
			miniOld = min(miniNew, prices[i]);
			profitOld = prices[i] - miniNew;
			miniNew = INT_MAX;
		}
		else {
			if (prices[i] - miniOld > profitOld) {
				profitOld = prices[i] - miniOld;
			}
			else {
				miniNew = min(miniNew, prices[i]);
			}
		}
	}
	return max_profit + max(profitOld, 0);
}



int jump(vector<int>& nums) {
	int length = nums.size();
	if (nums.empty() || length == 1) {
		return 0;
	}
	else if (nums[0] >= length - 1) {
		return 1;
	}
	int count = 0;
	int i = 0;

	pair<int, int> maxx = { 0,0 };
	int z;
	while (i < length - 1) {
		count++;
		maxx = { 0,0 };
		z = -1;
		for (int j = nums[i]; j > 0; j--) {
			if (j + i >= length - 1) {
				i += j;
				break;
			}
			else if (nums[j + i] - z++ > maxx.second) {
				maxx = { j, nums[j + i] - z };
			}
		}
		if (maxx.second != 0) {
			i += maxx.first;
		}
		else {
			break;
		}

	}
	return count;
}

bool isSubsequence(string s, string t) {
	int i = 0;
	int length = t.size();
	for (char c : s) {

		while (i < length && t[i] != c) {
			i++;
		}
		if (i >= length) {
			return false;
		}
		i++;

	}
	return true;
}

bool isSubsequence2(string s, string t) {

	if (s.size() == 0) {
		return true;
	}

	int count = 0;
	for (int i = 0; i < t.size(); i++) {
		if (s[count] == t[i]) {
			count++;
		}
	}

	return count == s.size();
}


vector<int> twoSum3(vector<int>& numbers, int target) {
	int i = 0;
	int j = numbers.size() - 1;
	while (i < j) {
		int sum = numbers[i] + numbers[j];
		if (sum > target) {
			j--;
		}
		if (sum < target) {
			i++;
		}
		else if (sum == target) {
			return { i, j };
		}
	}
	return { 0,0 };
}

int maxArea(vector<int>& height) {
	int left = 0, right = height.size() - 1, maxx = 0, water;
	while (left < right) {
		water = max(height[left], height[right]) * (right - left);
		if (water > maxx) {
			maxx = water;
		}
		if (height[left] < height[right]) {
			left++;
		}
		else {
			right++;
		}
	}
	return maxx;
}


int lengthOfLastWord(string s) {
	int i = s.size() - 1;
	int spaces = 0;
	if (i == 0) {
		return !(s[0] == ' ');
	}
	while (i > 0) {
		if (s[i] != ' ') {
			break;

		}
		i--;
		spaces++;
	}
	int j = 0;
	while (j < i && s[j] == ' ') {
		j++;
	}
	while (i >= j) {

		if (s[i] == ' ') {
			return s.size() - 1 - spaces - i;
		}
		else if (i == j) {
			return s.size() - spaces - i;
		}
		i--;
	}
	return 0;
}

int minSubArrayLen(int target, vector<int>& nums) {
	if (nums.empty()) {
		return 0;
	}
	else if (nums.size() == 1) {
		return nums[0] >= target;
	}
	int i = 0, sum = 0;
	while (sum < target) {
		if (i >= nums.size()) {
			return 0;
		}
		sum += nums[i];
		i++;
	}
	int window = i;
	while (sum - nums[i - window] >= target) {

		sum -= nums[i - window];
		window--;
	}
	while (i < nums.size()) {
		sum = sum + nums[i] - nums[i - window];
		while (sum - nums[i - window + 1] >= target) {
			window--;
			sum -= nums[i - window];

		}
		i++;
	}
	return window;

}

int lengthOfLongestSubstring(string s) {
	if (s.size() == 0) {
		return 0;
	}
	else if (s.size() == 1) {
		return 1;
	}
	unordered_map<char, int> letters;
	int i = 0;
	int count = 0;
	int max_count = 0;
	while (i < s.size()) {
		if (letters.find(s[i]) == letters.end() || letters[s[i]] == 0) {
			max_count = max(++count, max_count);
		}
		else {
			while (s[i - count] != s[i]) {
				letters[s[i - count--]] = 0;
			}
		}
		letters[s[i]] = 1;
		i++;
	}
	return max_count;
}

bool isValid(string s) {
	unordered_map<char, char> brackets;
	brackets.insert({ '(',')' });
	brackets.insert({ '[',']' });
	brackets.insert({ '{','}' });
	stack<char> sta;
	for (char c : s) {
		if (brackets.find(c) != brackets.end()) {
			sta.push(c);
		}
		else if (sta.empty()) {
			return false;
		}
		else if (brackets[sta.top()] == c) {
			sta.pop();
		}
		else {
			return false;
		}
	}
	return sta.empty();
}


bool isPalindrome1(string s) {
	regex regexp("[^a-zA-Z0-9]");
	stringstream ss(regex_replace(s, regexp, ""));
	string b = ss.str();
	int l = 0, r = b.size() - 1;
	while (l < r) {
		if ((char)tolower(b[l]) != (char)tolower(b[r])) {
			return false;
		}
		l++;
		r--;
	}
	return true;

}

bool check_character(char* c) {
	if ((int)*c >= 48 && (int)*c <= 57) {
		return true;
	}
	else if ((int)*c >= 97 && (int)*c <= 122) {
		return true;
	}
	else if ((int)*c >= 65 && (int)*c <= 90) {
		*c += 32;
		return true;
	}
	return false;
}

bool isPalindrome(string s) {
	int l = 0, r = s.size() - 1;
	while (l < r) {
		while (l < r) {
			if (check_character(&s[l])) {
				break;
			}
			l++;
		}
		while (l < r) {
			if (check_character(&s[r])) {
				break;
			}
			r--;
		}
		if (s[l] != s[r]) {
			return false;
		}
		l++;
		r--;
	}
	return true;

}

bool isPalindrome2(string s) {
	int start = 0;
	int end = s.size() - 1;
	while (start <= end) {
		if (!isalnum(s[start])) { start++; continue; }
		if (!isalnum(s[end])) { end--; continue; }
		if (tolower(s[start]) != tolower(s[end]))return false;
		else {
			start++;
			end--;
		}
	}
	return true;
}

string minWindow(string s, string t) {
	if (s.empty() || t.empty() || t.size() > s.size()) {
		return "";
	}
	else if (s.compare(t) == 0) {
		return s;
	}
	int cur_count = 0;
	unordered_map<char, int> letters;
	while (cur_count < t.size()) {
		if (letters.find(t[cur_count]) == letters.end()) {
			letters.insert({ t[cur_count], 1 });
		}
		else {
			letters[t[cur_count]]++;
		}
		cur_count++;
	}

	int i = 0;
	int min = 0;
	pair<int, int> indeces = { 0,-1 };

	//finding the index of first correct letter
	while (i < s.size()) {
		if (letters.find(s[i]) != letters.end()) {
			break;
		}
		i++;
	}
	indeces.first = i;

	//finding the index of the last correct letter
	while (i < s.size()) {
		if (cur_count > 0) {
			if (letters.find(s[i]) != letters.end()) {

				if (letters[s[i]] > 0) {
					cur_count--;
				}
				letters[s[i]]--;
			}
			i++;
		}
		else {
			break;
		}
	}
	indeces.second = i;


	if (i >= s.size() && cur_count > 0) {
		return "";
	}
	//min_indeces = indeces;
	if (letters.find(s[indeces.first]) != letters.end()) {
		letters[s[indeces.first]]++;
		if (letters[s[indeces.first]] > 0) {
			cur_count++;
		}
	}
	//indeces.first++;

	int length = indeces.second - indeces.first - 1;
	while (cur_count <= 0) {

		if (letters.find(s[i - length]) != letters.end()) {
			letters[s[i - length]]++;
			if (letters[s[i - length]] > 0) {
				cur_count++;
			}
		}
		indeces = { i - length, i };
		//min_indeces = indeces;
		length--;

	}

	while (i < s.size()) {
		if (letters.find(s[i - length]) != letters.end()) {
			letters[s[i - length]]++;
			if (letters[s[i - length]] > 0) {
				cur_count++;
			}

		}
		if (letters.find(s[i]) != letters.end()) {
			letters[s[i]]--;
			if (letters[s[i]] >= 0) {
				cur_count--;
			}

		}
		while (cur_count <= 0) {
			length--;
			if (letters.find(s[i - length]) != letters.end()) {
				letters[s[i - length]]++;
				if (letters[s[i - length]] > 0) {
					cur_count++;
				}
			}
			indeces = { i - length, i + 1 };
			//min_indeces = indeces;

		}
		i++;
	}

	return s.substr(indeces.first, length + 1);
}

string minWindow2(string s, string t)
{

	int m = s.size();
	int n = t.size();
	// Edge case
	if (n > m)
		return "";

	// Char Map -- ASCII (0-128)
	vector<int> charMap(128, -1);

	int counter = 0;
	// Build the char map
	for (char c : t) {
		if (charMap[c] == -1) {
			counter++;
			charMap[c] = 0;
		}
		charMap[c]++;
	}

	int left = 0;
	int right = 0;
	int minStart = 0;
	int minSize = INT_MAX;

	while (right < m)
	{
		charMap[s[right]]--;
		if (charMap[s[right]] == 0)
			counter--;
		right++;

		while (counter == 0)
		{
			if (minSize > right - left)
			{
				minSize = right - left;
				minStart = left;
			}
			charMap[s[left]]++;
			if (charMap[s[left]] == 1)
				counter++;  // Char which are present in both 's' & 't' can only have freq > 1
			left++;
		}
	}
	return minSize == INT_MAX ? "" : s.substr(minStart, minSize);
}



//dynamic programming
int rec_rob2(vector<int>& nums, int ind, unordered_map<int, int>& memo) {
	if (ind == 0) {
		return nums[ind];
	}
	else if (ind < 0) {
		return 0;
	}
	int tmp1, tmp2;

	if (memo.find(ind - 1) == memo.end()) {
		memo.insert({ ind - 1, rec_rob2(nums, ind - 1, memo) });
	}
	tmp1 = memo[ind - 1];

	if (ind > 1) {
		if (memo.find(ind - 2) == memo.end()) {
			memo.insert({ ind - 2, rec_rob2(nums, ind - 2, memo) });
		}
		tmp2 = memo[ind - 2];
	}
	else {
		tmp2 = 0;
	}


	/*
	int tmp1 = (memo.find(ind - 1) != memo.end()) ? memo[ind - 1] : rec_rob(nums, ind - 1, memo);
	int tmp2 = (memo.find(ind - 2) != memo.end()) ? memo[ind - 2] : rec_rob(nums, ind - 2, memo);
	memo[ind - 1] = tmp1;
	memo[ind - 2] = tmp2;
	*/

	return max(nums[ind] + tmp2, tmp1);


}
int rec_rob1(vector<int>& nums, int ind, int* memo) {
	if (ind == 0) {
		return nums[ind];
	}
	else if (ind < 0) {
		return 0;
	}
	int tmp1, tmp2;

	if (memo[ind - 1] == 0) {
		memo[ind - 1] = rec_rob1(nums, ind - 1, memo);
	}
	tmp1 = memo[ind - 1];

	if (memo[ind - 2] == 0) {
		memo[ind - 2] = rec_rob1(nums, ind - 2, memo);
	}
	tmp2 = memo[ind - 2];


	return max(nums[ind] + tmp2, tmp1);


}

int rob(vector<int>& nums) {
	unordered_map<int, int> memo;
	int arr[101];
	for (int i = 0; i < 101; i++) {
		memo[i] = -1;
	}
	return rec_rob2(nums, nums.size() - 1, memo);
}

int rob2(vector<int>& nums)
{
	int n = nums.size();
	vector<int> rob(n, 0);
	vector<int> norob(n, 0);
	rob[n - 1] = nums[n - 1];
	norob[n - 1] = 0;
	for (int i = n - 2; i >= 0; i--)
	{
		rob[i] = nums[i] + norob[i + 1];
		norob[i] = max(rob[i + 1], norob[i + 1]);
	}
	return max(rob[0], norob[0]);
}


int climbStairsRec(int n, unordered_map<int, int>& steps) {
	if (n <= 1) {
		return 1;
	}
	int one, two;
	if (steps.find(n - 1) == steps.end()) {
		steps.insert({ n - 1,climbStairsRec(n - 1, steps) });
	}
	one = steps[n - 1];
	if (steps.find(n - 2) == steps.end()) {
		steps.insert({ n - 2,climbStairsRec(n - 2, steps) });
	}
	two = steps[n - 2];
	return one + two;
}


int climbStairs1(int n) {
	unordered_map<int, int> steps;
	return climbStairsRec(n, steps);
}

int climbStairs(int n) {
	int x1 = 1;
	int x2 = 1;
	while (1 < n) {
		int tmp = x1;
		x1 = x2;
		x2 = x1 + tmp;
		n--;
	}
	return x2;
}


bool wordBreakOld(string s, vector<string>& wordDict) {
	int mini = INT_MAX;
	int max = 0;
	for (string s : wordDict) {
		mini = (s.size() < mini) ? s.size() : mini;
		max = (s.size() > max) ? s.size() : max;
	}

	for (int i = 0; i < s.size(); i += mini) {
		bool fits = false;
		int increase = 0;
		for (int j = mini; j <= max; j++) {
			string ss = s.substr(i, j);
			cout << ss << " ";
			if (find(wordDict.begin(), wordDict.end(), ss) != wordDict.end()) {
				fits = true;

				break;
			}
			increase++;
		}
		i += increase;
		if (!fits) {
			return false;
		}
	}
	return true;
}

bool wordBreak(string s, vector<string>& wordDict) {
	int mini = INT_MAX;
	int max = 0;
	stack<int> stak;
	for (string s : wordDict) {
		mini = (s.size() < mini) ? s.size() : mini;
		max = (s.size() > max) ? s.size() : max;
	}

	for (int i = 0; i < s.size(); i += mini) {
		bool fits = false;
		int increase = 0;
		int true_increase = 0;
		for (int j = mini; j <= max; j++) {
			string ss = s.substr(i, j);
			if (find(wordDict.begin(), wordDict.end(), ss) != wordDict.end()) {
				fits = true;
				stak.push(i + increase + mini);
				true_increase = increase;
			}
			increase++;
		}
		if (!stak.empty() && fits) { stak.pop(); }
		i += true_increase;
		if (!fits) {
			if (!stak.empty()) {
				i = stak.top() - mini;
				stak.pop();
			}
			else {
				return false;
			}

		}
	}
	return true;
}

bool wordBreak1(string s, vector<string>& wordDict) {
	if (wordDict.size() == 0) return false;

	int mini = INT_MAX;
	int max = 0;
	for (string s : wordDict) {
		mini = (s.size() < mini) ? s.size() : mini;
		max = (s.size() > max) ? s.size() : max;
	}

	vector<bool> dp(s.size() + 1, false);
	dp[0] = true;
	int difference = 0;

	for (int i = 1; i <= s.size(); i++)
	{
		bool found = false;
		for (int j = i - 1; j >= i - max && j >= 0; j--)
		{

			if (dp[j])
			{
				string word = s.substr(j, i - j);
				if (find(wordDict.begin(), wordDict.end(), word) != wordDict.end())
				{
					dp[i] = true;
					break; //next i
					found = true;
				}
			}
			else if (!found) {
				difference = i - j;
			}
		}
		if (difference > max) {
			return false;
		}
	}

	return dp[s.size()];
}

bool wordBreak3(string s, vector<string>& wordDict)
{
	int n = s.length();
	vector<bool> dp(n + 1, false);
	dp[n] = true;

	for (int i = n - 1; i >= 0; i--)
	{
		for (const string& w : wordDict)
		{
			if (i + w.length() <= n && s.substr(i, w.length()) == w)
				dp[i] = dp[i + w.length()];
			if (dp[i])
				break;
		}
	}

	return dp[0];
}
bool myfunction(int i, int j) {
	return (i < j);
}

int coinChange1(vector<int>& coins, int amount) {
	int count = 0;
	sort(coins.begin(), coins.end(), myfunction);
	for (int i = coins.size() - 1; i >= 0; i--) {
		if (amount >= coins[i]) {
			count += (amount / coins[i]);
			amount = amount % coins[i];
		}

	}
	return count;
}

int coinChange2(vector<int>& coins, int amount) {
	int length = amount;
	vector<int> dp(amount + 1, -1);
	dp[amount] = true;
	int count = 0;
	while (amount >= 0) {
		for (int x : coins) {
			if (x + amount <= length && dp[amount + x] == true) {
				dp[amount] = true;
				count++;
			}
			if (dp[amount]) {
				break;
			}


		}
		amount--;
	}
	return count;
}

int coinChangeRec(vector<int>& coins, unordered_map<int, int>& changes, int amount) {
	if (amount == 0) {
		return 0;
	}
	else if (amount < 0) {
		return INT_MAX;
	}
	int min_count = INT_MAX;
	for (int coin : coins) {
		if (changes.find(amount - coin) == changes.end()) {
			changes.insert({ amount - coin, coinChangeRec(coins, changes, amount - coin) });
		}
		int count = changes[amount - coin];
		if (count != INT_MAX) {
			min_count = (count + 1 < min_count) ? count + 1 : min_count;
		}

	}
	return min_count;
}

int coinChange3(vector<int>& coins, int amount) {
	unordered_map<int, int> changes;
	int tmp = coinChangeRec(coins, changes, amount);
	return (tmp != INT_MAX) ? tmp : -1;
}

int coinChange(vector<int>& coins, int amount) {
	vector<int> vec(amount + 1, -1); // index is amount, value is count
	vec[0] = 0;

	for (int i = 0; i < amount; i++) {
		if (vec[i] > -1) {
			for (int coin : coins) {
				if (i + coin < amount) {
					if (vec[i] + 1 < vec[i + coin] || vec[i + coin] == -1) {
						vec[i + coin] = vec[i] + 1;
					}
				}
			}
		}

	}
	return vec[amount - 1];

}

int length_of_longest_increasing_sequence(vector<int>& nums) {
	if (nums.size() == 0) { return 0; }
	int previous = nums[0];
	int count = 1, max_count = 1;
	for (int x : nums) {
		if (x > previous) {
			max_count = (++count > max_count) ? count : max_count;
		}
		else {
			count = 1;
		}
		previous = x;
	}
	return max_count;

}


int lengthOfLISRecNaive(vector<int>& nums, int previous, int ind) {
	if (ind >= nums.size()) {
		return 0;
	}
	int tmp = lengthOfLISRecNaive(nums, previous, ind + 1);
	if (nums[ind] > previous) {
		return max(lengthOfLISRecNaive(nums, nums[ind], ind + 1) + 1, tmp);
	}
	return tmp;

}

int lengthOfLISNaive(vector<int>& nums) {

	return lengthOfLISRecNaive(nums, INT_MIN, 0);

}