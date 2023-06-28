#pragma once
#include<iostream>
#include<fstream>
#include<map>
#include<vector>
#include<deque>

using std::string;
using std::map;
using std::vector;
using std::deque;
using std::ifstream;
using std::ofstream;
using std::cin;
using std::cout;

typedef map<char, deque<string>>::iterator map_iter;
typedef deque<string>::iterator deque_iter;
typedef map<char, deque<string>>::size_type map_size_type;

class Dictionary
{
	map<char, deque<string>> dict;

public:
	Dictionary() {}

	void push(string str);

	bool change(string str);

	string erase(char ch);

	string erase_first(bool);

	map_size_type size();

	map_iter begin();

	deque<string> operator[](int ind);

	friend ifstream& operator>>(ifstream&, Dictionary&);
};