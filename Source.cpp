#include "Header.h"



int robOld(vector<int>& nums) {
	if (nums.empty()) {
		return 0;
	}
	int sum1 = 0;
	int sum2 = 0;
	int odd = 1;
	for (int x : nums) {
		if (odd == 1) {
			sum1 += x;
		}

		else {
			sum2 += x;
		}
		odd *= -1;
	}
	return (sum1 > sum2) ? sum1 : sum2;

}

int rec_rob(vector<int>& nums, int ind, int count) {
	if (count < 0) {
		return 1;
	}
	else if (ind == 0) {
		return nums[ind];
	}
	else if (ind < 0) {
		return 0;
	}

	return max(nums[ind] + rec_rob(nums, ind - 2, count-1), rec_rob(nums, ind - 1, count-1));
	

}

//{ 4,1,2,7,5,3,1,0 }

void backtrack(vector<int>& nums, stack<bool>& rights, int* sum, int i) {
	int sum_right = nums[i] + nums[i - 2];
	*sum += nums[i];
	int sum_left = nums[i - 3] + nums[i - 1];
	int j = i - 4;
	int make_switch = true;
	while (rights.top() && j >= 1) {
		sum_left += nums[j - 1];
		sum_right += nums[j];
		if (nums[j] >= nums[j+1] && nums[j] >= nums[j+2] && nums[j] >= nums[j-1] + nums[j+1]) {
			if (sum_left - nums[j - 1] - nums[j + 1] > sum_right - nums[j]) {
				*sum = *sum + nums[j] - nums[j - 1] - nums[j + 1];
			}
			else {
				//*sum += nums[i];
				rights.push(true);
				make_switch = false;
			}
			
			break;
		}
		else if (sum_right >= sum_left) {
			make_switch = false;
			break;
		}
		rights.pop();
		j -= 2;
	}
	if (make_switch) {
		*sum = *sum - sum_right + sum_left;
		rights.push(false);
	}
	else {
		rights.push(true);
	}
}


int rob(vector<int>& nums) {
	int length = nums.size();
	if (length == 0) {
		return 0;
	}
	else if (length % 2 != 0) {
		nums.push_back(0);
		length++;
	}
	stack<bool> rights;
	rights.push(false);
	int sum = 0;
	for (int i = 1; i < length; i+=2) {
		if (nums[i] > nums[i-1]) {
			sum += nums[i];
			rights.push(true);
		}
		else if ((rights.top()) && 
				(nums[i - 3] + nums[i - 1] > nums[i] + nums[i - 2]))
		{
			rights.pop();
			backtrack(nums, rights, &sum, i);
		}
		else if (!rights.top()){

			sum += nums[i-1];
			rights.push(false);
		}
		else {
			sum += nums[i];
			rights.push(true);
		}
	}
	return sum;
}


void list_of_letters(string s, vector<char>& letters) {
	for (char x : s) {
		bool insertion = true;
		int counts = 0;
		for (char y : letters) {
			 if (int(x) <= int(y)) {
				letters.insert(letters.begin() + counts, x);
				insertion = false;

				break;
			}
			counts++;
		}
		if (insertion) {
			letters.push_back(x);
		}
	}
}


bool canConstruct(string ransomNote, string magazine) {
	vector<char> letters_magazine;
	vector<char> letters_note;
	list_of_letters(magazine, letters_magazine);
	list_of_letters(ransomNote, letters_note);
	return letters_magazine==letters_note;
}


int main(void) {
	/*vector<int> nums = {1,1,3,6,7,10,7,1,8,5,9,1,4,4,3}; //6,3,10,8,2,10,3,5,10,5,3 };// 4,1,2,7,5,3,1 }; // 1,3,1, 3, 100};

	cout << rob(nums) << endl;*/
	cout<<endl<<canConstruct("allbyback", "lybackk");
	

	
}