#pragma once
#include"Function.h"

// класс игры для "чистого ООП"
class Game
{
	#define russian true
	#define english false

	void filling_dict(Dictionary&, string);
	void set_settings();
	bool reset();
	bool set_language();
public:

	void Start();
};

