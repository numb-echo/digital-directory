#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string userLogin() {
	string username;
	cin >> username;
	return username;
}

bool is_Logged_In() {
	string username, password, ur_name, ps_word;
	cout << "Введите имя пользователя: ";
	username = userLogin();
	cout << "Введите пароль: ";
	cin >> password;

	ifstream myFile;
	myFile.open("data\\" + username + ".txt");
	getline(myFile, ur_name);
	getline(myFile, ps_word);

	if (ur_name == username && ps_word == password) {
		return true;
	}
	else {
		return false;
	}
}

/* void registration() {
	
}  */

void info();

int main() {
	int option;
	string username, password;
	system("color 3f");
	setlocale(LC_ALL, "Ru");
	cout << "                                        Электронный справочник администратора" << "\n";
	cout << "1. Регистрация" << endl << "2. Вход" << endl << "3. О программе" << endl << "4. Выход" << endl << "Выберите действие: ";
	cin >> option;
	if (option == 1) {
		system("cls");
		cout << "                                       Регистрация нового пользователя" << "\n";
		cout << "Введите имя пользователя: ";
		username = userLogin();
		cout << "Введите пароль: ";
		cin >> password;
		ofstream MyFile;
		MyFile.open("data\\" + username + ".txt");
		MyFile << username << endl << password;
		MyFile.close();
		cout << "\nВы успешно зарегистрировались!" << "\n";
		system("pause");
		system("cls");
		return main();
	}
	else if (option == 2) {
		system("cls");
		cout << "                                       Вход" << "\n";
		bool status = is_Logged_In();

		if (!status) {
			cout << "Неверное имя пользователя и/или пароль!" << endl;
			system("pause");
			system("cls");
			return main();
		}
		else {
			cout << "Вход выполнен!" << endl;
			system("pause");
			system("cls");
			cout << "Добро пожаловать!" << "\n";
			info();
		}
	}
	else if (option == 3) {
		cout << "Программа была создана специально для хранения технической информации" "\n"
			"для упрощенной эксплуатации оборудования в компании." << "\n";
		cout << "Developed by @whoami"<< "\n";
		system("pause");
		system("cls");
		return main();

	}
	else if (option == 4) {
		exit(0);
	}
}

void info() {
	int option;
	string device, type, ipadress, specs;
	ofstream hardwareData("data\\hardware\\data" + device + ".txt");
	cout << "1. Информация об оборудовании" << endl << "2. Информация о выполненных  работах" << endl << "3. Добавить устройство" << endl << "4. Выход" << endl << "\nВыберите действие: ";
	cin >> option;
	if (option == 1) {
		system("cls");
		ifstream hardwareData("data\\hardware\\data" + device + ".txt");
		if (hardwareData) {
			int subOption;
			getline(hardwareData, device);
			getline(hardwareData, type);
			getline(hardwareData, ipadress);
			getline(hardwareData, specs);
			cout << "1. " << type << " " << device << endl << "2. " << type << " " << device << endl << "3. Выйти в предыдущее меню" << endl << "\nВыберите действие: ";
			/*cin >> subOption;
			if (subOption == 1) {
				system("cls");
				int subOption1 = 0;
				cout << "Название устройства: HP 1410-24G (SEOTECH J9561A)" << endl << "IP-адрес: 192.168.1.95" << endl << "\n" << "1. Выйти в меню профиля" << "\nВыберите действие: ";
				cin >> subOption1;
				if (subOption1 == 1) {
					system("cls");
					info();
				}
			} */
		} else {
			cout << "ФАЙЛ С УСТРОЙСТВАМИ НЕ НАЙДЕН!" << "\n";
			cout << "Создание файла..." << "\n";
			string device, type, ipadress, specs;
			cout << "\nВведите название устройства: ";
			cin >> device;
			cout << "\nВведите тип устройства: ";
			cin >> type;
			cout << "\nВведите IP-адрес устройства: ";
			cin >> ipadress;
			cout << "\nВведите спецификацию устройства (побочные данные при наличии): ";
			cin >> specs;
			ofstream hardwareData;
			hardwareData.open("data\\hardware\\data" + device + ".txt");
			hardwareData << device << endl << type << endl << ipadress << endl << specs;
			hardwareData.close();
			cout << "Файл создан успешно." << "\n";
			system("pause");
			system("cls");
			info();
			/*if (subOption == 2) {
				system("cls");
				int subOption1 = 0;
				cout << "Название устройства: <undefined>" << endl << "IP-адрес: 192.168.1.57" << endl << "\n" << "1. Выйти в меню профиля" << "\nВыберите действие: ";
				cin >> subOption1;
				if (subOption1 == 1) {
					system("cls");
					info();
				}
			} */
		}

	}
	else if (option == 2) {
		int subOption;
		system("cls");
		cout << "Нет активных задач." << "\n";
		cout << "1. Выйти в меню профиля" << "\nВыберите действие: ";
		cin >> subOption;
		if (subOption == 1) {
			system("cls");
			info();
		}
	}
	else if (option == 3) {
		cout << "Создание файла..." << "\n";
		string device, type, ipadress, specs;
		cout << "\nВведите название устройства: ";
		cin >> device;
		cout << "\nВведите тип устройства: ";
		cin >> type;
		cout << "\nВведите IP-адрес устройства: ";
		cin >> ipadress;
		cout << "\nВведите спецификацию устройства (побочные данные при наличии): ";
		cin >> specs;
		ofstream hardwareData;
		hardwareData.open("data\\hardware\\data" + device + ".txt");
		hardwareData << device << endl << ipadress << endl << specs;
		hardwareData.close();
		cout << "\nФайл создан успешно." << "\n";
		system("pause");
		system("cls");
		info();
	}
	else if (option == 4) {
		system("cls");
		main();
	}
}
