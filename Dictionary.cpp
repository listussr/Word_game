#pragma once
#include "Dictionary.h"

// ����� ����� ����� � �������
void Dictionary::push(string str) {
	map<char, deque<string>>::iterator iter = dict.find(str[0]);
	if (iter != dict.end())
		iter->second.push_back(str);
	else {
		deque<string> d;
		d.push_back(str);
		std::pair<char, deque<string>> p(str[0], d);
		dict.insert(p);
	}
}

// ����� �������� �����
bool Dictionary::change(string str) {
	map_iter iter = dict.find(str[0]);
	if (iter != dict.end()) {
		deque_iter d_iter = find(iter->second.begin(), iter->second.end(), str);
		if (d_iter != iter->second.end()) {
			//cout << "��� �������� ����� " << '"' << *d_iter << '"' << '\n';
			iter->second.erase(d_iter);
			return true;
		}
	}
	std::cout << "������ ����� (���) ��� � �������" << '\n';
	return false;
}

// ��� �������� ����� ����� ����� ������
string Dictionary::erase(char ch) {
	map_iter iter = dict.find(ch);
	if (iter != dict.end()) {
		int rnd = (rand() % (iter->second.size() - 1));
		deque_iter d_iter = iter->second.begin() + rnd;
		string res = *d_iter;
		std::cout << "��� ������: " << res << '\n';
		iter->second.erase(d_iter);
		return res;
	}
	return "";
}

// �����, ������� ��������� ���� ������� ����� ������
string Dictionary::erase_first(bool language) {
#define english_a char{97}
#define russian_a char{-32}
	int rnd = rand() % (language? 30: 25);
	deque<string>* d_iter = &dict[(language? russian_a : english_a) + rnd];
	int d_rnd = rand() % (((*d_iter).size() > 1) ? (*d_iter).size() - 1 : 1);
	string res = (*d_iter)[d_rnd];
	(*d_iter).erase((*d_iter).begin() + d_rnd);
	cout << "��� �������� ����� " << '"' << res << '"' << '\n';
	return res;
}
//dict[(language ? russian_a : english_a) + rnd].erase(dict[(language ? russian_a : english_a) + rnd].begin() + d_rnd);

// ������ ���������
map_size_type Dictionary::size() {
	return dict.size();
}

// ��������� �� ������ �������
map_iter Dictionary::begin() {
	return dict.begin();
}

// ���������� ��������� ��������������
deque<string> Dictionary::operator[](int ind) {
	return dict[ind];
}

// ���������� ��������� ������
ifstream& operator>>(ifstream& in, Dictionary& dict) {
	string str;
	map_iter iter;
	while (in >> str)
		dict.push(str);
	return in;
}