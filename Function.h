#pragma once
#include<iostream>
#include<iomanip>
#include<Windows.h>
#include"Dictionary.h"

bool Call_up_main_menu();

void Show_rules();

bool Choose_start_position();

bool Get_first_word_player(Dictionary&, std::string&);

std::string Get_first_word_bot(Dictionary&, bool);

bool Get_word_player(Dictionary&, std::string, std::string&);

std::string Get_word_bot(Dictionary&, std::string);