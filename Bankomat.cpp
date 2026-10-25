#include "Bankomat.h"

Bankomat::Bankomat()
{
	this->Init(0, 100, 10000, 0, 0, 0, 0);
}

Bankomat::Bankomat(int id, int minWithdraw, int maxWithdraw, int c100, int c200, int c500, int c1000)
{
	this->Init(id, minWithdraw, maxWithdraw, c100, c200, c500, c1000);
}

void Bankomat::Init(int id, int minWithdraw, int maxWithdraw, int c100, int c200, int c500, int c1000)
{
	this->id = id;
	this->minWithdraw = minWithdraw;
	this->maxWithdraw = maxWithdraw;
	this->count100 = (c100 >= 0 ? c100 : 0);
	this->count200 = (c200 >= 0 ? c200 : 0);
	this->count500 = (c500 >= 0 ? c500 : 0);
	this->count1000 = (c1000 >= 0 ? c1000 : 0);
}

void Bankomat::LoadMoney(int c100, int c200, int c500, int c1000)
{
	if (c100 > 0)
	{
		this->count100 += c100;
	}
	if (c200 > 0)
	{
		this->count200 += c200;
	}
	if (c500 > 0)
	{
		this->count500 += c500;
	}
	if (c1000 > 0)
	{
		this->count1000 += c1000;
	}
}

int Bankomat::GetTotalMoney() const
{
	return this->count100 * 100 + this->count200 * 200 + this->count500 * 500 + this->count1000 * 1000;
}

bool Bankomat::Withdraw(int amount)
{
	if (amount < this->minWithdraw || amount > this->maxWithdraw)
	{
		cout << "Помилка: сума повинна бути від " << this->minWithdraw << " до " << this->maxWithdraw << " грн." << endl;
		return false;
	}

	if (amount % 100 != 0)
	{
		cout << "Помилка: сума повинна бути кратною 100 грн." << endl;
		return false;
	}

	if (amount > this->GetTotalMoney())
	{
		cout << "Помилка: недостатньо грошей у банкоматі." << endl;
		return false;
	}

	int need = amount;

	int take1000 = need / 1000;
	if (take1000 > this->count1000)
	{
		take1000 = this->count1000;
	}
	need -= take1000 * 1000;

	int take500 = need / 500;
	if (take500 > this->count500)
	{
		take500 = this->count500;
	}
	need -= take500 * 500;

	int take200 = need / 200;
	if (take200 > this->count200)
	{
		take200 = this->count200;
	}
	need -= take200 * 200;

	int take100 = need / 100;
	if (take100 > this->count100)
	{
		take100 = this->count100;
	}
	need -= take100 * 100;

	if (need != 0)
	{
		cout << "Помилка: неможливо видати потрібну суму наявними купюрами." << endl;
		return false;
	}

	this->count1000 -= take1000;
	this->count500 -= take500;
	this->count200 -= take200;
	this->count100 -= take100;

	cout << "Успішно видано " << amount << " грн:" << endl;
	if (take1000 > 0)
	{
		cout << "  1000 грн: " << take1000 << " шт." << endl;
	}
	if (take500 > 0)
	{
		cout << "  500 грн: " << take500 << " шт." << endl;
	}
	if (take200 > 0)
	{
		cout << "  200 грн: " << take200 << " шт." << endl;
	}
	if (take100 > 0)
	{
		cout << "  100 грн: " << take100 << " шт." << endl;
	}

	return true;
}

string Bankomat::toString() const
{
	return to_string(this->GetTotalMoney()) + " грн (100 грн: " + to_string(this->count100) + 
		" шт., 200 грн: " + to_string(this->count200) + 
		" шт., 500 грн: " + to_string(this->count500) + 
		" шт., 1000 грн: " + to_string(this->count1000) + " шт.)";
}

int Bankomat::GetId() const
{
	return this->id;
}

int Bankomat::GetMinWithdraw() const
{
	return this->minWithdraw;
}

int Bankomat::GetMaxWithdraw() const
{
	return this->maxWithdraw;
}
