#pragma once
#include"Function.h"

// ����� ���� ��� "������� ���"
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

