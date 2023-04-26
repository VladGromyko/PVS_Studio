// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com


#include <iostream>
#include <cmath>

using namespace std;

int main() {

	setlocale(LC_ALL, "Russian");
	int oct[4], mask[4], host[4], AdresShir[4];
	long nhosts;
	int menu, numbermask, noctet;
	

	cout << "1) Выполнить действия калькулятора" << endl;
	cout << "2) Выход из программы" << endl;
	cin >> menu;
	if (menu != 1 and menu != 2) {
		cout << "Вы ввели некорректное значение!" << endl;

		while (menu != 1 and menu != 2) {

			cout << "1) Выполнить действия калькулятора" << endl;
			cout << "2) Выход из программы" << endl;
			cin >> menu;
		}
	}
	switch (menu) { //Действия

	case 1: {

		for (int i = 0; i < 4; i++) {
			cout << "Введите " << i + 1 << " октет: ";
			cin >> oct[i];
			if (oct[i] > 255 || oct[i] < 0) { //Условие подсчёта октета
				cout << "Вы ввели некорректный октет!\n";
				while (oct[i] > 255 || oct[i] < 0) {
					cout << "Введите " << i + 1 << " октет: ";
					cin >> oct[i];
				}
			}
		}
		numbermask == 0;
		
	    
		cout << "Введите маску: ";
		cin >> numbermask;
		if (numbermask > 32 || numbermask < 0) {
			cout << "Вы ввели неправильную маску!\n";
			while (numbermask > 32 || numbermask < 0) {
				cout << "Введите маску: ";
				cin >> numbermask;
			}
		}
		
		noctet = 0;
		if (noctet==true )
		noctet = numbermask / 8;
		for (int i = 0; i < noctet; i++)
			mask[i] = 255;
		if (noctet != 4)
			mask[noctet] = 256 - pow(2, 8 - numbermask % 8);
		if (noctet < 3)
			for (int i = noctet + 1; i < 4; i++)
				mask[i] = 0;

		//Считаем хосты
		if (noctet == 4)
			nhosts = 0;
		else
			nhosts = 256 - mask[noctet];

		//Широковещательный адрес
		for (int i = 0; i < noctet; i++) {
			AdresShir[i] = oct[i];
			host[i] = oct[i];
		}

		if (noctet != 4)
			for (int i = 0; i < 256; i += nhosts) {
				if (oct[noctet] >= i && oct[noctet] < i + nhosts)
				{
					AdresShir[noctet] = i;
					host[noctet] = i + nhosts - 1;
					break;
				}
			}
		if (noctet < 3)
			for (int i = noctet + 1; i < 4; i++) {
				AdresShir[i] = 0;
				host[i] = 255;
				nhosts *= 256;
			}
		

		cout << endl << "Кол-во хостов: " << nhosts << endl;
		cout << "Маска сети: " << mask[0] << "." << mask[1] << "." << mask[2] << "." << mask[3] << endl;
		cout << "Локальный адрес: " << AdresShir[0] << "." << AdresShir[1] << "." << AdresShir[2] << "." << AdresShir[3] << endl;
		cout << "Широковещательный адрес: " << host[0] << "." << host[1] << "." << host[2] << "." << host[3] << endl;
		break;
	}
		  

	case 2: { //Выходим

		exit(0);
	}
	}
	return 0;
}

