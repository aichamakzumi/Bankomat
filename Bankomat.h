#pragma once
#include <iostream>
#include <string>

using namespace std;

class Bankomat
{
private:
	int id;
	int minWithdraw;
	int maxWithdraw;

	int count100;
	int count200;
	int count500;
	int count1000;

public:
	Bankomat();
	Bankomat(int id, int minWithdraw, int maxWithdraw, int c100, int c200, int c500, int c1000);

	void Init(int id, int minWithdraw, int maxWithdraw, int c100, int c200, int c500, int c1000);
	void LoadMoney(int c100, int c200, int c500, int c1000);
	bool Withdraw(int amount);

	int GetTotalMoney() const;
	string toString() const;

	int GetId() const;
	int GetMinWithdraw() const;
	int GetMaxWithdraw() const;
};
