#include <iostream>
#include <sstream>
#include <string>
#include <vector>



std::string name_to_code() {
	//Volozh,Arcady,Yurievich,11,2,1964
	std::cout << "How many interns? \n";
	std::string tmp; int n;
	std::getline(std::cin, tmp);
	try
	{
		n = stoi(tmp);
	}
	catch (std::exception& err)
	{
		std::cout << "Conversion failure: " << err.what() << std::endl; // Note: what() tells the exact error
		return "error";

	}
	std::stringstream ss;
	std::stringstream fin;
	std::string s;
	std::string token;


	while (n > 0) {
		std::getline(std::cin, s);
		ss << s;
		ss << ',';
		n--;
	}




	while (ss) {
		int number;
		std::vector<char> vec;

		std::getline(ss, token, ',');
		int var;
		std::cout << "Token = '" << token << "'\n";
		if (token.empty()) break;
		if ((int)token[0] > 64 && (int)token[0] < 90) var = (int)token[0] - 64;
		else if ((int)token[0] > 96 && (int)token[0] < 123) var = (int)token[0] - 96;
		else {
			std::cout << "wrong first letter in last name";
			return "error";
		}

		std::cout << var << "\n";

		for (int i = 0; i < 3; i++) {
			if (i != 0) {
				if (!ss) return "error";
				std::getline(ss, token, ',');
				if (!ss) return "error";
			}
			std::cout << token << "\n";
			if (token.empty()) return "error";
			for (char c : token) {
				if (((int)c <= 64 || (int)c >= 90) && ((int)c <= 96 || (int)c >= 123)) return "error";
				if (find(vec.begin(), vec.end(), c) == vec.end()) {
					vec.push_back(c);
				}
			}

		}


		int sum = 0;
		for (int i = 0; i < 2; i++) {
			if (!ss) return "error";
			std::getline(ss, token, ',');
			if (!ss) return "error";
			if (token.empty()) return "error";
			std::cout << token << "\n";
			try
			{
				number = stoi(token);
			}
			catch (std::exception& err)
			{
				std::cout << "Conversion failure: " << err.what() << std::endl; // Note: what() tells the exact error
				return "error";

			}
			if (i == 0 && (number < 1 || number >31)) return "error";
			else if (i == 1 && (number < 1 || number >12)) return "error";
			while (number >= 1) {
				sum += number % 10;
				number = number / 10;
			}
		}
		/*
		if (ss) {
			std::cout << "Too many arguments";
			return;
		}*/


		sum *= 64;
		sum += vec.size();
		sum += var * 256;
		std::cout << sum << "\n";
		std::stringstream stream;
		stream << std::hex << sum;
		std::string result(stream.str());

		result.erase(0, result.size() - 3); std::cout << result;
		fin << result; fin << " ";
		if (ss)std::getline(ss, token, ',');


	}
	return fin.str();


	/*
	while (std::getline(ss, token, ',')) {
		std::cout << token << '\n';
	}*/
}

void checking_stoi_exception() {
	std::string token = "sdfs";
	try
	{
		int number = stoi(token);
	}
	catch (std::exception& err)
	{
		std::cout << "Conversion failure: " << err.what() << std::endl; // Note: what() tells the exact error

	}
}