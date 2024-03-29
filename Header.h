#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <sstream>
#include <stack>
#include <regex>
#include <set>
#include <queue>
#include <iterator>
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


class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node(int _val);
};

class NodeTree {
public:
	int val;
	NodeTree* left;
	NodeTree* right;
	NodeTree* next;

	NodeTree();

	NodeTree(int _val);

	NodeTree(int _val, NodeTree* _left, NodeTree* _right, NodeTree* _next);
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

int removeElement(vector<int>& nums, int val);
bool canConstruct1(string ransomNote, string magazine);
int removeDuplicates(vector<int>& nums);

int majorityElement(vector<int>& nums);
int removeDuplicates2(vector<int>& nums);

void rotate(vector<int>& nums, int k);
void rotate2(vector<int>& nums, int k);

bool canJump(vector<int>& nums);
bool canJump2(vector<int>& nums);

void inputRoman(int m, char c, stringstream* oss);
void smallRoman(int* num, char c1, char c2, char c3, stringstream* oss, int multiplier);
string intToRoman(int num);

string reverseWords(string s);
string reverseWords2(string s);
string reverseWords3(string s);
string reverseWords4(string s);

int maxProfit(vector<int>& prices);
int maxProfitFast(vector<int>& prices);
int maxProfitSlow(vector<int>& prices);
int maxProfit2(vector<int>& prices);

int jump(vector<int>& nums);
bool isSubsequence(string s, string t);
bool isSubsequence2(string s, string t);
vector<int> twoSum3(vector<int>& numbers, int target);
int maxArea(vector<int>& height);
int lengthOfLastWord(string s);

//sliding window
int minSubArrayLen(int target, vector<int>& nums);
int lengthOfLongestSubstring(string s);
string minWindow(string s, string t);
string minWindow2(string s, string t);


//stack
bool isValid(string s);
int calculate(string s);


bool check_character(char* c);
bool isPalindrome(string s);
bool isPalindrome1(string s);
bool isPalindrome2(string s);





bool myfunction(int i, int j);

//dinamic programming
int rec_rob2(vector<int>& nums, int ind, unordered_map<int, int>& memo);
int rec_rob1(vector<int>& nums, int ind, int memo[101]);
int rob(vector<int>& nums);
int rob2(vector<int>& nums);
int climbStairsRec(int n, unordered_map<int, int>& steps);
int climbStairs1(int n);
int climbStairs(int n);
bool wordBreakOld(string s, vector<string>& wordDict);
bool wordBreak(string s, vector<string>& wordDict);
bool wordBreak1(string s, vector<string>& wordDict);
bool wordBreak3(string s, vector<string>& wordDict);

int coinChange3(vector<int>& coins, int amount);
int coinChange1(vector<int>& coins, int amount);
int coinChange2(vector<int>& coins, int amount);
int coinChangeRec(vector<int>& coins, unordered_map<int, int>& changes, int amount);
int coinChange(vector<int>& coins, int amount);

int length_of_longest_increasing_sequence(vector<int>& nums);

int lengthOfLISRecNaive(vector<int>& nums, int previous, int ind);
int lengthOfLISNaive(vector<int>& nums);
int lengthOfLISRec(vector<int>& nums, int previous, int ind, unordered_map<int, int>& dp);
int lengthOfLIS(vector<int>& nums);
int lengthOfLIS1(vector<int>& nums);

bool check_isomorphic(unordered_map<char, char>& mp, char s, char t);
bool isIsomorphic1(string s, string t);
bool isIsomorphic2(string s, string t);
bool isIsomorphic3(string s, string t);
bool wordPattern(string pattern, string s);
int candy(vector<int>& ratings);
int candy1(vector<int>& ratings);
vector<vector<int>> threeSumOptimal(vector<int>& nums);
vector<vector<int>> threeSum(vector<int>& nums);
vector<vector<int>> threeSumClean(vector<int>& nums);
vector<vector<int>> threeSum1(vector<int>& nums);

//pointers
ListNode* reverseList(ListNode* head);
bool hasCycle1(ListNode* head);
bool hasCycleRec(ListNode* curr, ListNode* doubl);
bool hasCycle2(ListNode* head);
bool hasCycle3_fastest(ListNode* head);
bool hasCycle4_reverse(ListNode* head);
bool hasCycle5_Naive(ListNode* head);
bool hasCycle6_hash(ListNode* head);
bool hasCycle7_Floyd(ListNode* head);
ListNode* detectCycle(ListNode* head);
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2);
void adding_two_lists();
ListNode* mergeTwoLists_Naive(ListNode* list1, ListNode* list2);
ListNode* mergeTwoLists_efficient(ListNode* list1, ListNode* list2);
ListNode* reverseBetween(ListNode* head, int left, int right);
Node* copyRandomList(Node* head);
ListNode* removeNthFromEnd(ListNode* head, int n);



//trees

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode();
	TreeNode(int x);
	TreeNode(int x, TreeNode* left, TreeNode* right);
	void show(); 
	void print(int level); 

};

TreeNode* invertTree(TreeNode* root);
int maxDepth(TreeNode* root);
bool isSameTree(TreeNode* p, TreeNode* q);
bool isSymmetricRec(TreeNode* p, TreeNode* q);
bool isSymmetric(TreeNode* root);
bool hasPathSumRec(TreeNode* root, int targetSum);
bool hasPathSum(TreeNode* root, int targetSum);
TreeNode* buildTreeRec(vector<int>::iterator preorder_st, vector<int>::iterator preorder_ed,
	vector<int>::iterator inorder_st, vector<int>::iterator inorder_ed);
TreeNode* buildTree(vector<int> preorder, vector<int> inorder);

TreeNode* buildPostTreeRec(vector<int>::iterator inorder_st, vector<int>::iterator inorder_ed,
	vector<int>::iterator  postorder_st, vector<int>::iterator  postorder_ed);
TreeNode* buildPostTree(vector<int>& inorder, vector<int>& postorder);

void print(TreeNode* root, int level);
int maxPathS1(TreeNode* root, vector<int>& vec);
int maxPathSum1(TreeNode* root);
pair<int, int> maxPathS(TreeNode* root);
int maxPathSum(TreeNode* root);
int helper(TreeNode* root, int& maxi);
int maxPathSum3(TreeNode* root);
void flatten1(TreeNode* root);
void sumNumbersRec(TreeNode* root, int cur_sum, int* total_sum);
int sumNumbers(TreeNode* root);
NodeTree* connect_perfect_tree(NodeTree* root);
NodeTree* connect2(NodeTree* root); 
NodeTree* connect3(NodeTree* root); 
NodeTree* connect_hard(NodeTree* root);
NodeTree* connect_hard_2(NodeTree* root);
NodeTree* connect_hard_3(NodeTree* root);
vector<int> rightSideView(TreeNode* root);
void right(TreeNode* root, int level, vector<int>& result);
vector<int> rightSideView1(TreeNode* root);
vector<double> averageOfLevels(TreeNode* root);
vector<double> averageOfLevels1(TreeNode* root);
vector<vector<int>> levelOrder(TreeNode* root);
vector<vector<int>> levelOrder1(TreeNode* root);
vector<vector<int>> zigzagLevelOrder(TreeNode* root);
int countNodes1(TreeNode* root);


void iterate(vector<int>::iterator start, vector<int>::iterator end);
void iterators();


//graphs
int numIslands(vector<vector<char>>& grid);
class Solution {
    int height;
    int width;
    int i;
    int j;
    char c;
    int sum;
public:
	void land_explorer(vector<vector<char>>& grid);
    int numIslands(vector<vector<char>>& grid);
};
class Islands {
	int width;
	int height;

public:
	void land_explorer(vector<vector<char>>& grid, int i, int j);
	int numIslands(vector<vector<char>>& grid);
};

class Regions {
	int width;
	int height;
public:

	void marking(vector<vector<char>>& board, int i, int j);

	void solve(vector<vector<char>>& board);
};

class NodeGraph {
public:
	int val;
	std::vector<NodeGraph*> neighbors;
	NodeGraph();
	NodeGraph(int _val);
	NodeGraph(int _val, std::vector<NodeGraph*> _neighbors);
};

double deikstra(std::unordered_map<std::string, int>& hash, std::vector<std::vector<double>>& vec, std::string current, std::string destination, std::vector<std::string>& remaining_letters); 
double deikstra1(std::unordered_map<std::string, int>& hash, std::vector<std::vector<double>>& vec, std::string current, std::string destination, std::vector<std::string>& remaining_letters);
std::vector<double> calcEquation(std::vector<std::vector<std::string>>& equations, std::vector<double>& values, std::vector<std::vector<std::string>>& queries);
std::vector<double> calcEquation(std::vector<std::vector<std::string>>& equations, std::vector<double>& values, std::vector<std::vector<std::string>>& queries);

/*class UF1 {
public:
	int val;
	bool have_passed;
	std::vector<UF1*> children;
	//UF* parent;
	bool starting_node;

	UF1(int value);

};

bool canFinish1(int numCourses, std::vector<std::vector<int>>& prerequisites);
void reset(UF1* root);
bool check_cycle1(UF1* root);*/

class UF {
public:
	int val;
	std::vector<UF*> previous;
	//UF* parent;

	UF(int value);


};
bool check_cycle(std::vector<UF*>& visited, UF* vert, std::vector<UF*>& rec_stack);
bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites);
class SolutionBFS {
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites);
private:
	typedef vector<vector<int>> graph;

	graph buildGraph(int numCourses, vector<pair<int, int>>& prerequisites);

	vector<int> computeIndegrees(graph& g);
};
