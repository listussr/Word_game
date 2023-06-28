#pragma once
#include"Function.h"

// выбираем куда пойти, в правила или в игровое меню
bool Call_up_main_menu() {
	std::cout << std::setw(10) << "Вам предлагается сыграть в игру в 'слова' с ботом" << '\n';
	std::cout << std::setw(10) << "-> Если вы хотите прочитать правила, то нажмите 1" << '\n'
	   	 << std::setw(10) << "-> Если вы хотите продолжить - нажмите 2" << '\n';
	short flag;
	std::cin >> flag;
	while (flag != 1 && flag != 2) {
		std::cout << "Некорректный ввод, введите ещё раз" << '\n';
		std::cin >> flag;
	}
	return (flag == 2) ? true : false; // 1, если в правила, 2, если в иговое меню
}

// игровые правила
void Show_rules() {
	system("cls");
	std::cout << "Один из игроков называет слово, а второй должен назвать слово, начинающееся на последнюю букву слова первого игрока" << '\n';
	std::cout << "1) Повторять слова нельзя" << '\n';
	std::cout << "2) Если игрок называет несуществующее слово или пишет слово грамматически неверно, то он проигрывает" << '\n';
	std::cout << "3) Если в словаре заканчиваются слова на какую-то букву, и она оказывается крайней в последнем слове, то следующий игрок проигрывает" << '\n';
	std::cout << "4) Называть только существительные в именительном падеже и единственном числе" << '\n';
	std::cout << "Чтобы продолжить нажмите любую кнопку" << '\n' << '\n';
	string str;
	std::cin >> str;
	system("cls");
}

// выбирается игрок, который первым называет слово
bool Choose_start_position() {
	std::cout << "Если вы хотите сказать слово первым, нажмите 1" << '\n';
	std::cout << "Если вы хотите, чтобы начал ИИ, нажмите 2" << '\n';
	short flag;
	std::cin >> flag;
	while (flag != 1 && flag != 2) {
		std::cout << "Некорректный ввод, введите ещё раз" << '\n';
		std::cin >> flag;
	}
	return (flag == 1) ? true : false; // 2, если в ИИ, 1, если в игрок
}

// игрок первым называет слово
bool Get_first_word_player(Dictionary& dict, std::string& str) {
	std::cout << "Назовите первое слово: " << '\t';
	std::cin >> str;
	return dict.change(str);
}

// бот первым называет слово
std::string Get_first_word_bot(Dictionary& dict, bool language) {
	return dict.erase_first(language);
}

// игрок называет слово
bool Get_word_player(Dictionary& dict, std::string str, std::string& res) {
	std::cout << "Назовите слово на букву " << '"' << str[str.size() - 1] << '"' << '\n';
	std::cin >> res;
	return ((res[0] != str[str.size() - 1]) ? false : dict.change(res));
}

// бот называет слово
std::string Get_word_bot(Dictionary& dict, std::string str) {
	return dict.erase(str[str.size() - 1]);
}