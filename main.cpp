#include <iostream>
#include "Bankomat.h"

using namespace std;

int main()
{
	Bankomat atm(101, 100, 8000, 10, 10, 5, 2);

	cout << "Банкомат #" << atm.GetId() << endl;
	cout << "Мiнiмальна сума зняття: " << atm.GetMinWithdraw() << " грн" << endl;
	cout << "Максимальна сума зняття: " << atm.GetMaxWithdraw() << " грн" << endl;
	cout << "Початковий стан: " << atm.toString() << endl << endl;

	cout << "Завантаження купюр: 5 по 100 грн, 2 по 500 грн..." << endl;
	atm.LoadMoney(5, 0, 2, 0);
	cout << "Пiсля завантаження: " << atm.toString() << endl << endl;

	cout << "--- Спроба зняти 50 грн (менше мiнiмуму) ---" << endl;
	atm.Withdraw(50);
	cout << endl;

	cout << "--- Спроба зняти 10000 грн (бiльше максимуму) ---" << endl;
	atm.Withdraw(10000);
	cout << endl;

	cout << "--- Спроба зняти 350 грн (не кратно 100) ---" << endl;
	atm.Withdraw(350);
	cout << endl;

	cout << "--- Зняття 2800 грн ---" << endl;
	atm.Withdraw(2800);
	cout << "Поточний залишок: " << atm.toString() << endl << endl;

	cout << "--- Зняття 1700 грн ---" << endl;
	atm.Withdraw(1700);
	cout << "Поточний залишок: " << atm.toString() << endl << endl;

	system("pause");
	return 0;
}
