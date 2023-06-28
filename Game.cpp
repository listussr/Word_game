#include "Game.h"

void Game::Start()
{
	// переменные
	static int iterations = 0;
	Dictionary dict;
	string player, bot;
	bool flag_player{ true }, flag_bot{ true };
	// функциональная часть
	set_settings();
	if (!Call_up_main_menu()) {
		Show_rules();
	}
		
	// основная часть программы
	do {
		bool language = set_language();

		// чтобы не перезаполнять словари лишний раз
		if (!iterations) {
			if (language == russian)
				filling_dict(dict, "Russian_dictionary.txt");
			else
				filling_dict(dict, "English_dictionary.txt");
		}
		// выбирается кто будет начинать игру
		if (Choose_start_position()) {

			// игрок
			Get_first_word_player(dict, player);
			while (flag_player) {
				bot = Get_word_bot(dict, player);
				if (bot == "") {
					// пустое слово - флаг отсутсвия слов на эту букву
					flag_bot = false;
					break;
				}
				flag_player = Get_word_player(dict, bot, player);
			}
		}
		else {

			// бот
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
		// флаги выхода
		if (!flag_player) {
			cout << "Вы проиграли" << '\n';
		}
		else {
			cout << "Вы выиграли" << '\n';
		}
		// сброс флагов и инкрементирование счётчика
		flag_player = true;
		flag_bot = true;
		++iterations;
	} while (reset());
}

// заполнение словаря из файла
void Game::filling_dict(Dictionary& dict, string file_name) {
	ifstream in(file_name);
	in >> dict;
	in.close();
}

// настройки языка и подключение рандома
void Game::set_settings() {
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}

// выбор языка
bool Game::set_language() {
	std::cout << "Какой язык вы выбираете?" << '\n';
	std::cout << "Русский - 1\nАнглийский - 2" << '\n';
	string res;
	std::cin >> res;

	// проверка на корректность
	while (res != "1" && res != "2") {
		std::cout << "Неверный ввод - повторите:\t";
		std::cin >> res;
	}
	return (res == "1" ? true : false);
}

// выбор продолжения
bool Game::reset() {
	std::cout << "Если вы хотите продолжить нажмите 1\nЕсли вы хотите выйти из игры - нажмите 2\t";
	std::string res;
	std::cin >> res;
	
	//проверка на корректность 
	while (res != "1" && res != "2") {
		std::cout << "Неверный ввод - повторите:\t";
		std::cin >> res;
	}
	// чистим консоль
	system("cls");
	return (res == "1" ? true : false);
}