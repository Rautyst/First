#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>

// ���, ����������� �������� �� ������ �������
class Label
{
protected:
	char text[256];
	short x;
	short y;
	WORD color;
public:
	Label(const char*& string, short x, short y, WORD color = NULL);
	~Label();

	void SetText(const char*& value);
	void SetColor(WORD color);
	void Render() const;
};

// ����� ������, ����������� �������� �� ������� � ������ � ��������
class Button : public Label
{
protected:
	uint8_t flash_countdown;
	bool flash_lever;
public:
	Button(const char*& string, short x, short y, WORD color = NULL);

	virtual void Flashes() = 0;
	virtual void Click(Cursore* crsr) = 0;
};

class Layout;

class SwitchLtBtn : public Button
{
	Layout* lt;
public:
	SwitchLtBtn(const char*& string, short x, short y, WORD color = NULL);

	void SetLayout(Layout* lt);

	void Flashes() override;
	void Click(Cursore* crsr) override;
};

// ������, ��������� ��� ����������� ������� ������������ �� �������
struct BtnNode
{
	Button* btn = nullptr;
	BtnNode* up = nullptr;
	BtnNode* down = nullptr;
	BtnNode* left = nullptr;
	BtnNode* right = nullptr;
};

class Layout
{
	bool is_rendered;
public:
	bool IsRendered() const;
	void ConnectWith(const SwitchLtBtn& btn) const;

	virtual void Render() = 0;
	virtual BtnNode* GetStartNode() const = 0;
};

// ��������� ������������ ������������ ��  ������� 
class Cursore
{
	Layout* crnt_lt;
	BtnNode* crnt_nd;
public:
	Cursore(Layout* start_lt, BtnNode* start_nd = nullptr);

	void Set(bool mode, const size_t& size);
	void SetLayout(Layout* new_lt);
	void SetNode(BtnNode* new_nd);

	void ExecActionHandler();
};