#pragma once
#include"Function.h"

// �������� ���� �����, � ������� ��� � ������� ����
bool Call_up_main_menu() {
	std::cout << std::setw(10) << "��� ������������ ������� � ���� � '�����' � �����" << '\n';
	std::cout << std::setw(10) << "-> ���� �� ������ ��������� �������, �� ������� 1" << '\n'
	   	 << std::setw(10) << "-> ���� �� ������ ���������� - ������� 2" << '\n';
	short flag;
	std::cin >> flag;
	while (flag != 1 && flag != 2) {
		std::cout << "������������ ����, ������� ��� ���" << '\n';
		std::cin >> flag;
	}
	return (flag == 2) ? true : false; // 1, ���� � �������, 2, ���� � ������ ����
}

// ������� �������
void Show_rules() {
	system("cls");
	std::cout << "���� �� ������� �������� �����, � ������ ������ ������� �����, ������������ �� ��������� ����� ����� ������� ������" << '\n';
	std::cout << "1) ��������� ����� ������" << '\n';
	std::cout << "2) ���� ����� �������� �������������� ����� ��� ����� ����� ������������� �������, �� �� �����������" << '\n';
	std::cout << "3) ���� � ������� ������������� ����� �� �����-�� �����, � ��� ����������� ������� � ��������� �����, �� ��������� ����� �����������" << '\n';
	std::cout << "4) �������� ������ ��������������� � ������������ ������ � ������������ �����" << '\n';
	std::cout << "����� ���������� ������� ����� ������" << '\n' << '\n';
	string str;
	std::cin >> str;
	system("cls");
}

// ���������� �����, ������� ������ �������� �����
bool Choose_start_position() {
	std::cout << "���� �� ������ ������� ����� ������, ������� 1" << '\n';
	std::cout << "���� �� ������, ����� ����� ��, ������� 2" << '\n';
	short flag;
	std::cin >> flag;
	while (flag != 1 && flag != 2) {
		std::cout << "������������ ����, ������� ��� ���" << '\n';
		std::cin >> flag;
	}
	return (flag == 1) ? true : false; // 2, ���� � ��, 1, ���� � �����
}

// ����� ������ �������� �����
bool Get_first_word_player(Dictionary& dict, std::string& str) {
	std::cout << "�������� ������ �����: " << '\t';
	std::cin >> str;
	return dict.change(str);
}

// ��� ������ �������� �����
std::string Get_first_word_bot(Dictionary& dict, bool language) {
	return dict.erase_first(language);
}

// ����� �������� �����
bool Get_word_player(Dictionary& dict, std::string str, std::string& res) {
	std::cout << "�������� ����� �� ����� " << '"' << str[str.size() - 1] << '"' << '\n';
	std::cin >> res;
	return ((res[0] != str[str.size() - 1]) ? false : dict.change(res));
}

// ��� �������� �����
std::string Get_word_bot(Dictionary& dict, std::string str) {
	return dict.erase(str[str.size() - 1]);
}