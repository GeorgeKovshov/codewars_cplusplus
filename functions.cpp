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


int maxSequence2(const std::vector<int>& arr) {
	int length = arr.size();
	int max_sum = 0;
	int sum = 0;
	int minus = 0;
	bool just_passed = true;
	for (int i = 0; i < length; i++) {

		if (arr[i] >= 0) {
			sum += arr[i];
		}
		else {
			int old_max_sum = max_sum;
			int tmp = max(sum, max_sum);
			if (just_passed) {
				max_sum = max(tmp, sum + max_sum + minus);
			}
			else {
				max_sum = tmp;
			}
			if (max_sum != old_max_sum) {
				just_passed = true;
			}
			else {
				just_passed = false;
			}

			sum = 0;
			minus = 0;
			while (i < length && arr[i] < 0) {
				minus += arr[i];
				i++;
				//just_passed = true;
			}
			i--;

		}
		cout << "arr[" << i << "]: " << arr[i] << " minus: " << minus << " max_sum: " << max_sum << " summ: " << sum << " just passed: " << just_passed << endl;

	}
	int old_max_sum = max_sum;
	int tmp = max(sum, max_sum);
	if (just_passed) {
		max_sum = max(tmp, sum + max_sum + minus);
	}
	else {
		max_sum = tmp;
	}
	if (max_sum != old_max_sum) {
		just_passed = true;
	}
	else {
		just_passed = false;
	}
	return max_sum;
}


int maxSequence(const std::vector<int>& arr) {
	if (arr.empty()) {
		return 0;
	}
	int cur_sum = arr[0];
	int max_sum = arr[0];
	int length = arr.size();
	for (int i = 1; i < length; i++) {
		cur_sum = max(arr[i], cur_sum + arr[i]);
		max_sum = max(cur_sum, max_sum);
	}
	return (max_sum > 0) ? max_sum : 0;
}

int convert_ascii(int ascii, int last_letter_index) {
	ascii += 13;
	if (ascii > last_letter_index) {
		ascii -= 26;
	}
	return ascii;
}

string rot13(string msg)
{
	ostringstream bar;

	for (char x : msg) {
		int ascii = int(x);
		if (65 <= ascii && ascii <= 90) {
			ascii = convert_ascii(ascii, 90);
		}
		else if (97 <= ascii && ascii <= 122) {
			ascii = convert_ascii(ascii, 122);
		}
		bar << char(ascii);

		//cout << ascii << endl;
	}
	return bar.str();
}



void playing_with_Ascii() {
	char c = 'c';
	char a = 'a';
	cout << int(a) << endl;
	cout << int('A') << endl;
	cout << int('z') << endl;
	cout << int('Z') << endl;
	cout << char(98) << endl;
}


std::string rot13_2(std::string msg)
{
	for (auto& x : msg)
		if (islower(x)) x = 'a' + (x - 'a' + 13) % 26;
		else if (isupper(x)) x = 'A' + (x - 'A' + 13) % 26;
	return msg;
}

std::vector<ull> ProdFib::productFib(ull prod) {
	ull f1 = 0;
	ull f2 = 1;
	while (f1 * f2 < prod) {
		int tmp = f2;
		f2 = f1 + f2;
		f1 = tmp;
	}
	if (f1 * f2 == prod) {
		return { f1, f2, true };
	}
	return { f1, f2, false };
}


unsigned long recursive_mystery(unsigned long n, unsigned long high, unsigned long low, unsigned long high_ind, unsigned long low_ind, int direction, int maximum) {
	if (maximum >= 6) {
		return -1;
	}
	if (high - low == 1) {
		if (direction == 1) {
			return (n == high) ? high_ind : low_ind;
		}
		else {
			return (n == high) ? low_ind : high_ind;
		}
	}
	unsigned long middle = (high - low) / 2 + low;
	unsigned long middle_ind = (high_ind - low_ind) / 2 + low_ind;

	if (middle <= 0) {
		return high_ind;
	}

	if (direction == 1) {
		if (n > middle) {
			return recursive_mystery(n, high, middle + 1, high_ind, middle_ind + 1, -direction, maximum + 1);
		}
		else if (n <= middle) {
			return recursive_mystery(n, middle, low, middle_ind, low_ind, direction, maximum + 1);
		}
	}
	else {
		if (n <= middle) {
			return recursive_mystery(n, middle, low, high_ind, middle_ind + 1, direction, maximum + 1);
		}
		else if (n > middle) {
			return recursive_mystery(n, high, middle + 1, middle_ind, low_ind, -direction, maximum + 1);
		}
	}

}

unsigned long mysteryInv(unsigned long n) {
	unsigned long highest = 2;
	while (highest <= n) {
		highest *= 2;
	}
	return recursive_mystery(n, highest - 1, 0, highest - 1, 0, 1, 0);
}


unsigned long recursive_mystery2(unsigned long ind, unsigned long high, unsigned long low, unsigned long high_ind, unsigned long low_ind, int direction, int maximum) {
	if (maximum >= 6) {
		return -1;
	}
	if (high_ind - low_ind == 1) {
		if (direction == 1) {
			return (ind == high_ind) ? high : low;
		}
		else {
			return (ind == high_ind) ? low : high;
		}
	}
	unsigned long middle = (high - low) / 2 + low;
	unsigned long middle_ind = (high_ind - low_ind) / 2 + low_ind;

	if (middle <= 0) {
		return high_ind;
	}

	if (direction == 1) {
		if (ind > middle_ind) {
			return recursive_mystery2(ind, high, middle + 1, high_ind, middle_ind + 1, -direction, maximum + 1);
		}
		else if (ind <= middle_ind) {
			return recursive_mystery2(ind, middle, low, middle_ind, low_ind, direction, maximum + 1);
		}
	}
	else {
		if (ind <= middle_ind) {
			return recursive_mystery2(ind, high, middle + 1, middle_ind, low_ind, -direction, maximum + 1);
		}
		else if (ind > middle_ind) {
			return recursive_mystery2(ind, middle, low, high_ind, middle_ind + 1, direction, maximum + 1);
		}
	}

}

unsigned long mystery(unsigned long n) {
	unsigned long highest = 2;
	while (highest <= n) {
		highest *= 2;
	}
	return recursive_mystery2(n, highest - 1, 0, highest - 1, 0, 1, 0);
}


int print_prime_numbers(int n) {
	int count = 0;
	bool check;
	for (int i = 2; i < n; i++) {
		check = true;
		for (int j = 2; j < i; j++) {
			if (i % j == 0) {
				check = false;
			}
		}
		if (check == true) {
			cout << i << ", ";
			count++;
		}

	}
	return count;
}

vector<int> make_vector_prime_numbers(int n) {
	vector<int> vec;
	bool check;
	for (int i = 2; i < n; i++) {
		check = true;
		for (int j = 2; j < i; j++) {
			if (i % j == 0) {
				check = false;
			}
		}
		if (check == true) {

			vec.push_back(i);
		}

	}
	return vec;
}




void SumOfDivided::add_prime_numbers(int n) {
	int old_last_elem = primes.back() + 1;
	bool check;
	for (int i = old_last_elem; i <= n+1; i++) {
		check = true;
		for (int j = 2; j < i; j++) {
			if (i % j == 0) {
				check = false;
				break;
			}
		}
		if (check == true) {

			primes.push_back(i);
		}

	}
}


vector<int> SumOfDivided::primes = { 2, 3 };


#include <stdlib.h> 

std::string SumOfDivided::sumOfDivided(std::vector<int>& lst) {
	if (lst.empty()) {
		return "()";
	}
	ostringstream result;
	int biggest_elem =max(*max_element(std::begin(lst), std::end(lst)), lst.back());
	int smallest_elem = min(*min_element(std::begin(lst), std::end(lst)), lst.back());
	biggest_elem = max(biggest_elem, abs(smallest_elem));
	if (biggest_elem > primes.back()) {
		add_prime_numbers(biggest_elem);
	}
	bool check;
	int length = primes.size();
	for (int i = 0; (primes[i] <= biggest_elem && i < length-1); i++) {
		check = false;
		int sum = 0;
		for (int y : lst) {
			if (y % primes[i] == 0) {
				check = true;
				sum += y;
			}
		}
		if (check == true) {
			result << "(" << primes[i] << " " << sum << ")";
		}
	}
	return result.str();
}


void carrying_over(std::ostringstream* bar, const std::string& c, int* carry, int* i) {
	/* looping through array with a carried 1 */
	while (*carry != 0) {
		if (*i >= 0) {
			int num = int(c[*i]) - int('0') + *carry;
			*bar << num % 10;
			*carry = num / 10;
			*i = *i - 1;
		}
		else {
			*bar << *carry;
			*carry = 0;
		}
	}
}


void finishing_up(std::ostringstream* bar, const std::string& c, int i) {
	/* looping through array when nothing to carry over */
	while (i >= 0) {
		*bar << int(c[i]) - int('0');
		i--;
	}
}


std::string add(const std::string& a, const std::string& b) {
	int i = a.length() - 1;
	int j = b.length() - 1;
	if (i < 0) {
		return b;
	}
	else if (j < 0) {
		return a;
	}
	int carry = 0;
	std::ostringstream bar;
	/* cycling through both arrays */
	while (i >= 0 && j >= 0) {
		int num = int(a[i]) - int('0') + int(b[j]) - int('0') + carry;
		bar << num % 10;
		carry = num / 10;
		i--;
		j--;
	}
	/* cycling through the remaining array (if not of equal length) */
	if (j >= 0) {
		carrying_over(&bar, b, &carry, &j);
		finishing_up(&bar, b, j);
	}
	else if (i >= 0) {
		carrying_over(&bar, a, &carry, &i);
		finishing_up(&bar, a, i);
	}
	if (carry != 0) {
		bar << carry;
	}

	std::string ss = bar.str();
	std::reverse(ss.begin(), ss.end());
	return ss;

}




inline char
__next_char(std::string::const_reverse_iterator& it, const std::string& a)
{
	char result = '\0';
	if (it != a.rend())
	{
		result = *it;
		++it;
	}
	return result;
}
/*
inline char
__add_char(char a, char b, unsigned short& isdec)
{
	static const unsigned short asciioffset = 48;
	unsigned short              num = ((unsigned short)(a - asciioffset)) +
		((unsigned short)(b - asciioffset));
	num += isdec;
	isdec = num / 10;

	return (char)((num % 10) + asciioffset);
}
//
std::string add(const std::string& a, const std::string& b)
{
	std::string                         result;
	std::string::const_reverse_iterator ait = a.rbegin();
	std::string::const_reverse_iterator bit = b.rbegin();

	char           ac = __next_char(ait, a);
	char           bc = __next_char(bit, b);
	char           cc = '\0';
	unsigned short isdec = 0;

	while ((ac != '\0') || (bc != '\0'))
	{
		cc = __add_char((ac == '\0') ? '0' : ac, (bc == '\0') ? '0' : bc, isdec);
		result.insert(0, 1, cc);

		ac = __next_char(ait, a);
		bc = __next_char(bit, b);
	}

	if (isdec != 0)
		result.insert(0, 1, '1');

	return result;
}


inline char
__next_char(std::string::const_reverse_iterator& it, const std::string& a)
{
	char result = '\0';
	if (it != a.rend())
	{
		result = *it;
		++it;
	}
	return result;
}
//
inline char
__add_char(char a, char b, unsigned short& isdec)
{
	static const unsigned short asciioffset = 48;
	unsigned short              num = ((unsigned short)(a - asciioffset)) +
		((unsigned short)(b - asciioffset));
	num += isdec;
	isdec = num / 10;

	return (char)((num % 10) + asciioffset);
}
//
std::string add2(const std::string& a, const std::string& b)
{
	std::string                         result;
	std::string::const_reverse_iterator ait = a.rbegin();
	std::string::const_reverse_iterator bit = b.rbegin();

	char           ac = __next_char(ait, a);
	char           bc = __next_char(bit, b);
	char           cc = '\0';
	unsigned short isdec = 0;

	while ((ac != '\0') || (bc != '\0'))
	{
		cc = __add_char((ac == '\0') ? '0' : ac, (bc == '\0') ? '0' : bc, isdec);
		result.insert(0, 1, cc);

		ac = __next_char(ait, a);
		bc = __next_char(bit, b);
	}

	if (isdec != 0)
		result.insert(0, 1, '1');

	return result;
}*/


	mylist::mylist() {
		value = 0;
		next = nullptr;
	}
	void mylist::print() {
		cout << value << " ";
		mylist* tmp = next;
		while (tmp) {
			cout << tmp->value << " ";
			tmp = tmp->next;
		}
	}

	void mylist::add(int new_value) {
		mylist* tmp = next;
		while (tmp->next) {
			tmp = tmp->next;
		}
		mylist* new_m = new mylist;
		new_m->value = new_value;
		tmp->next = new_m;
	}
	/*
	~mylist() {
		mylist* tmp = next;
		while (tmp) {
			mylist* tmp2 = new mylist;
			tmp2 = tmp->next;
			delete tmp;
			tmp = tmp2;
		}
	}*/

	void mylist::sort() {
		mylist* x = this;
		while (x) {
			mylist* y = x->next;
			while (y) {
				if (x->value > y->value) {
					int z = x->value;
					x->value = y->value;
					y->value = z;
				}
				y = y->next;
			}
			x = x->next;

		}
	}


	mylist* reverse_mylist(mylist* previous, mylist* current) {
		if (current != nullptr) {
			mylist* tmp = current->next;
			current->next = previous;
			reverse_mylist(current, tmp);
		}
		else {
			return previous;
		}
	}



void working_with_mylists() {
	mylist m1;
	mylist m2, m3, m4, m5;
	m1.value = 1;

	m2.value = 2;
	m1.next = &m2;

	m3.value = 3;
	m2.next = &m3;

	m4.value = 4;
	m3.next = &m4;

	m5.value = 5;
	m4.next = &m5;

	m1.add(6);
	m1.add(60);

	for (int x = 0; x < 20; x++) {
		m1.add(x * x);
	}

	//m1.~mylist();
	//m1.print();
	//cout << endl;
	mylist* pm2 = reverse_mylist(nullptr, &m1);
	pm2->print();
	cout << endl;
	pm2->sort();
	pm2->print();
	//m1.sort();
	//m1.print();
}


void list_of_letters(string s, vector<char>& letters) {
	for (char x : s) {
		bool insertion = true;
		int counts = 0;
		for (char y : letters) {
			if (int(x) == int(y)) {
				insertion = false;

				break;
			}
			else if (int(x) < int(y)) {
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

bool made_of_same_letters(string ransomNote, string magazine) {
	vector<char> letters_magazine;
	vector<char> letters_note;
	list_of_letters(magazine, letters_magazine);
	list_of_letters(ransomNote, letters_note);
	return letters_magazine == letters_note;
}