#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <sstream>
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
