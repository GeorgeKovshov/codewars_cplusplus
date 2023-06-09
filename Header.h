#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <sstream>
#include <stack>
using namespace std;

int rec_sum(int num);

class DirReduction
{
private:
	static void check(string* previous, std::vector<std::string>& new_arr, string current, string direction); 
public:
	static std::vector<std::string> dirReduc(std::vector<std::string>& arr);
	
};

void makeDirReduct();

class RGBToHex
{
public:
	static std::string rgb(int r, int g, int b);
	static char convert(int remainder);
};

int maxSequence2(const std::vector<int>& arr);
int maxSequence(const std::vector<int>& arr);

int convert_ascii(int ascii, int last_letter_index);
string rot13(string msg);
void playing_with_Ascii();
std::string rot13_2(std::string msg);


typedef unsigned long long ull;
class ProdFib
{
public:
	static std::vector<ull> productFib(ull prod);
};

unsigned long recursive_mystery(unsigned long n, unsigned long high, unsigned long low, unsigned long high_ind, unsigned long low_ind, int direction, int maximum);
unsigned long mysteryInv(unsigned long n);
unsigned long recursive_mystery2(unsigned long ind, unsigned long high, unsigned long low, unsigned long high_ind, unsigned long low_ind, int direction, int maximum);
unsigned long mystery(unsigned long n);
int print_prime_numbers(int n);
vector<int> make_vector_prime_numbers(int n);

class SumOfDivided
{

public:
	static vector<int> primes;
	static std::string sumOfDivided(std::vector<int>& lst);
	static void add_prime_numbers(int n);
};


void carrying_over(std::ostringstream* bar, const std::string& c, int* carry, int* i);
void finishing_up(std::ostringstream* bar, const std::string& c, int i);
std::string add(const std::string& a, const std::string& b);

/*
inline char
__next_char(std::string::const_reverse_iterator& it, const std::string& a);
inline char
__add_char(char a, char b, unsigned short& isdec);
std::string add2(const std::string& a, const std::string& b);*/

class mylist {
public:
	int value;
	mylist* next;
	mylist();
	void print();

	void add(int new_value);
	void sort();


};
mylist* reverse_mylist(mylist* previous, mylist* current);

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
	void add(int x);
	void show();

};

bool isPalindrome2(ListNode* head);
bool isPalindromeOld(ListNode* head);
bool isPalindrome(ListNode* node);

void list_of_letters(string s, vector<char>& letters);
bool made_of_same_letters(string ransomNote, string magazine);

void palindroming();
vector<int> kWeakestRows(vector<vector<int>>& mat, int k);
vector<string> fizzBuzz(int n);
int numberOfSteps(int num);
ListNode* middleNode(ListNode* head);
int maximumWealth(vector<vector<int>>& accounts);

vector<int> twoSum(vector<int>& nums, int target);
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);
