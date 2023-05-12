#include "Header.h"

int rec_sum(int num) {
	int sum = 0;
	while (num > 0) {
		sum = sum + num % 10;
		cout << num << endl;
		num = num / 10;
	}
	if (sum > 9) {
		return rec_sum(sum);
	}
	return sum;
}




void DirReduction::check(string* previous, std::vector<std::string>& new_arr, string current, string direction) {
		if (strcmp(current.c_str(), direction.c_str()) != 0) {
			new_arr.push_back(current);
			*previous = current;
		}
		else {
			new_arr.pop_back();
			*previous = (new_arr.empty()) ? " " : new_arr.back();
		}
}

std::vector<std::string> DirReduction::dirReduc(std::vector<std::string>& arr) {
		int i = 1;
		std::vector<std::string> new_arr = {};
		new_arr.push_back(arr[0]);
		string previous = arr[0];

		map<string, string> my_map = {
		{ "NORTH", "SOUTH"},
		{ "SOUTH", "NORTH"},
		{ "EAST", "WEST"},
		{ "WEST", "EAST"},
		{ " ", " "}
		};

		while (i < arr.size()) {
			check(&previous, new_arr, arr[i], my_map[previous]);
			i++;
		}

		return new_arr;
}

void makeDirReduct() {
	std::vector<std::string> d1 = { "NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST" };
	std::vector<std::string> ans1 = DirReduction::dirReduc(d1);
	int i = 0;
	while (i < ans1.size()) {
		cout << "new: " << ans1[i] << endl;
		i++;
	}
	/*
	map<string, string> my_map = {
		{ "NORTH", "SOUTH"},
		{ "SOUTH", "NORTH"},
		{ "EAST", "WEST"},
		{ "WEST", "EAST"},
		{ " ", " "}

	};
	string n = "NORTH";
	cout << my_map[n] << endl;*/
}
