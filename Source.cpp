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




int rob(vector<int>& nums) {

	int length = nums.size() - 1;

	return rec_rob(nums, length, 6);

}



int main(void) {
	vector<int> nums = { 2,7,9,3,1,4 };

	cout << rob(nums) << endl;
	

	
}