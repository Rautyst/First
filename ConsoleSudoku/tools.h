#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>

// ���, ����������� �������� �� ������ �������
class Label
{
protected:
	char* text;
	short x;
	short y;
public:
	Label(char* itext, short ix, short iy, WORD btn_color = NULL);
	//Label(char* itext, short ix, short iy) : Label(itext, ix, iy, NULL) {			}
	~Label();
	void SwitchColor(WORD btn_color);
};

// ����� ������, ����������� �������� �� ������� � ������ � ��������
class Button : public Label
{
public:
	Button(char* itext, short ix, short iy, WORD btn_color = NULL) : Label(itext, ix, iy, btn_color) {}

	virtual void Flashes() = 0;
	virtual void Click(Cursore* crsr) = 0;
};


// ������, ��������� ��� ����������� ������� ������������ �� �������
struct BtnNode
{
	Button* btn = nullptr;
	BtnNode* up = nullptr;
	BtnNode* down = nullptr;
	BtnNode* left = nullptr;
	BtnNode* right = nullptr;

	~BtnNode() 
	{ 
		delete btn;
	}
};

class Layout
{
	bool is_rendered;
public:
	bool IsRendered() 
	{ 
		return is_rendered; 
	}
	virtual void Render() = 0;
	virtual BtnNode* GetStartNode() = 0;
};

// ��������� ������������ ������������ ��  ������� 
class Cursore
{
	Layout* crnt_lt;
	BtnNode* crnt_nd;
public:
	void SetLayout(Layout* new_lt)
	{
		crnt_lt = new_lt;
	}

	void SetNode(BtnNode* new_nd)
	{
		crnt_nd = new_nd;
	}

	Cursore(Layout* start_lt, BtnNode* start_nd = nullptr)
	{ 
		crnt_lt = start_lt; 
		if (start_nd) crnt_nd = start_nd;
		else crnt_nd = start_lt->GetStartNode();
	}
	void Set(bool mode, const size_t& size);
	void ActionHandler();
};