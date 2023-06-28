#include "Game.h"

void Game::Start()
{
	// ����������
	static int iterations = 0;
	Dictionary dict;
	string player, bot;
	bool flag_player{ true }, flag_bot{ true };
	// �������������� �����
	set_settings();
	if (!Call_up_main_menu()) {
		Show_rules();
	}
		
	// �������� ����� ���������
	do {
		bool language = set_language();

		// ����� �� ������������� ������� ������ ���
		if (!iterations) {
			if (language == russian)
				filling_dict(dict, "Russian_dictionary.txt");
			else
				filling_dict(dict, "English_dictionary.txt");
		}
		// ���������� ��� ����� �������� ����
		if (Choose_start_position()) {

			// �����
			Get_first_word_player(dict, player);
			while (flag_player) {
				bot = Get_word_bot(dict, player);
				if (bot == "") {
					// ������ ����� - ���� ��������� ���� �� ��� �����
					flag_bot = false;
					break;
				}
				flag_player = Get_word_player(dict, bot, player);
			}
		}
		else {

			// ���
			bot = Get_first_word_bot(dict, language);
			while (flag_player) {
				flag_player = Get_word_player(dict, bot, player);
				if (!flag_player)
					break;
				bot = Get_word_bot(dict, player);
				if (bot == "") {
					flag_bot = false;
					break;
				}
			}
		}
		// ����� ������
		if (!flag_player) {
			cout << "�� ���������" << '\n';
		}
		else {
			cout << "�� ��������" << '\n';
		}
		// ����� ������ � ����������������� ��������
		flag_player = true;
		flag_bot = true;
		++iterations;
	} while (reset());
}

// ���������� ������� �� �����
void Game::filling_dict(Dictionary& dict, string file_name) {
	ifstream in(file_name);
	in >> dict;
	in.close();
}

// ��������� ����� � ����������� �������
void Game::set_settings() {
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}

// ����� �����
bool Game::set_language() {
	std::cout << "����� ���� �� ���������?" << '\n';
	std::cout << "������� - 1\n���������� - 2" << '\n';
	string res;
	std::cin >> res;

	// �������� �� ������������
	while (res != "1" && res != "2") {
		std::cout << "�������� ���� - ���������:\t";
		std::cin >> res;
	}
	return (res == "1" ? true : false);
}

// ����� �����������
bool Game::reset() {
	std::cout << "���� �� ������ ���������� ������� 1\n���� �� ������ ����� �� ���� - ������� 2\t";
	std::string res;
	std::cin >> res;
	
	//�������� �� ������������ 
	while (res != "1" && res != "2") {
		std::cout << "�������� ���� - ���������:\t";
		std::cin >> res;
	}
	// ������ �������
	system("cls");
	return (res == "1" ? true : false);
}