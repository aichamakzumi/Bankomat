#include <iostream>
#include "Bankomat.h"

using namespace std;

int main()
{
	//Весь текст который выводиться в консоль написан английскими буквами но русскими словами, 
	// так как при компиляции выводились непонятные символы.
	
	Bankomat atm(101, 100, 8000, 10, 10, 5, 2);

	cout << "Bankomat #" << atm.GetId() << endl;
	cout << "Minimalnaya summa snyatiya: " << atm.GetMinWithdraw() << endl;
	cout << "Maksimalnaya summa snyatiya: " << atm.GetMaxWithdraw() << endl;
	cout << "Nachalnoe sostoyanie: " << atm.toString() << endl << endl;

	cout << "Zagruzka kupyur: 5 po 100, 2 po 500..." << endl;
	atm.LoadMoney(5, 0, 2, 0);
	cout << "Posle zagruzki: " << atm.toString() << endl << endl;

	cout << "--- Popytka snyat 50 (menshe minimuma) ---" << endl;
	atm.Withdraw(50);
	cout << endl;

	cout << "--- Popytka snyat 10000 (bolshe maksimuma) ---" << endl;
	atm.Withdraw(10000);
	cout << endl;

	cout << "--- Popytka snyat 350 (ne kratno 100) ---" << endl;
	atm.Withdraw(350);
	cout << endl;

	cout << "--- Snyatie 2800 ---" << endl;
	atm.Withdraw(2800);
	cout << "Tekuschiy ostatok: " << atm.toString() << endl << endl;

	cout << "--- Snyatie 1700 ---" << endl;
	atm.Withdraw(1700);
	cout << "Tekuschiy ostatok: " << atm.toString() << endl << endl;

	system("pause");
	return 0;
}
