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


char RGBToHex::convert(int remainder) {
	char result = '0';
	if (remainder > 9) {
		switch (remainder) {
		case 10:
			result = 'A';
			break;
		case 11:
			result = 'B';
			break;
		case 12:
			result = 'C';
			break;
		case 13:
			result = 'D';
			break;
		case 14:
			result = 'E';
			break;
		case 15:
			result = 'F';
			break;
		}
	}
	else {
		result = '0' + remainder;
	}
	return result;
}



string RGBToHex::rgb(int r, int g, int b) {
	char x[7] = "000000";
	int current = b;
	for (int i = 5; i >= 0; i--) {
		if (i % 2 != 0) {
			switch (i) {
			case 1:
				current = r;
				break;
			case 3:
				current = g;
				break;

			}
			if (current < 0) {
				current = 0;
			}
			else if (current > 255) {
				current = 255;
			}

		}
		cout << "i: " << i << " string: " << x << " current: " << current << endl;
		x[i] = RGBToHex::convert(current % 16);
		current = current / 16;

	}

	return string(x);
}

void rgb_conversion() {
	//cout << RGBToHex::rgb(255, 255, 255);
	//cout << RGBToHex::rgb(162, 23, 3);
	cout << RGBToHex::rgb(-162, -23, -3);
	//cout << RGBToHex::rgb(1, 2, 3);
	//cout << RGBToHex::convert(23%16);
	char a;
	int b = 9;
	a = '0' + b;
	///cout << a;
}

/*
#include <sstream>
#include <iomanip>
class RGBToHex2
{
public:
	static std::string rgb(int r, int g, int b);
};

std::string RGBToHex2::rgb(int r, int g, int b)
{
	std::ostringstream oss;
	//oss << "sus" << " makaroni " << g;
	oss << std::uppercase << std::setfill('0') << std::hex
		<< std::setw(2) << (r < 0 ? 0 : r > 255 ? 255 : r)// std::clamp(r, 0, 255)
		<< std::setw(2) << (g < 0 ? 0 : g > 255 ? 255 : g)//std::clamp(g, 0, 255)
		<< std::setw(2) << (b < 0 ? 0 : b > 255 ? 255 : b);//std::clamp(b, 0, 255);
	return oss.str();
}*/


/*
#include <algorithm>
#include <cstdio>

namespace RGBToHex
{
	std::string rgb(int r, int g, int b)
	{
		char result[7];
		std::sprintf(result, "%02X%02X%02X",
			std::clamp(r, 0, 255),
			std::clamp(g, 0, 255),
			std::clamp(b, 0, 255));
		return result;
	}
}

*/
