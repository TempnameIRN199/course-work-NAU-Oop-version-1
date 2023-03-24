#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <istream>
#include <ctime>
#include <stdlib.h>
#include <iomanip>
#include <conio.h>
#include <string>
#include <string.h>
#include <ctype.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

string str = "Name           Firm          Model          Speed          Price           Date";
string str2 = "Name           Firm          Model          Speed          Price           Date";

// Класс базы данных
class DataBase
{
private:
	string name;
	string firm;
	string model;
	int speed;
	int price;
	string date;
public:
	DataBase() {
		name = " ";
		firm = " ";
		model = " ";
		speed = 0;
		price = 0;
		date = " ";
	}
	DataBase(string name, string firm, string model, int speed, int price, string date) {
		this->name = name;
		this->firm = firm;
		this->model = model;
		this->speed = speed;
		this->price = price;
		this->date = date;
	}
	~DataBase() {}
	void setName(string name) {
		this->name = name;
	}
	void setFirm(string firm) {
		this->firm = firm;
	}
	void setModel(string model) {
		this->model = model;
	}
	void setSpeed(int speed) {
		this->speed = speed;
	}
	void setPrice(int price) {
		this->price = price;
	}
	void setDate(string date) {
		this->date = date;
	}
	string getName() {
		return name;
	}
	string getFirm() {
		return firm;
	}
	string getModel() {
		return model;
	}
	int getSpeed() {
		return speed;
	}
	int getPrice() {
		return price;
	}
	string getDate() {
		return date;
	}
};

// Класс прайс-лист
class PriceList
{
private:
	vector<DataBase> list;
public:
	vector<DataBase> getList() {
		return this->list;
	}
	PriceList() {}
	~PriceList() {}
	void add(DataBase data) {
		list.push_back(data);
	}
	void print() {
		cout << "Name" << setw(15) << "Firm" << setw(15) << "Model" << setw(15) << "Speed" << setw(15) << "Price" << setw(15) << "Date" << endl;
		for (int i = 0; i < list.size(); i++)
		{
			cout << list[i].getName() << setw(15) << list[i].getFirm() << setw(15) << list[i].getModel() << setw(15) << list[i].getSpeed() << setw(15) << list[i].getPrice() << setw(15) << list[i].getDate() << endl;
		}
	}
	bool findN(string& str) {
		for (char c : str) {
			if (c == 'N') {
				return true;
			}
		}
		return false;
	}
	void printToFile() {
		ofstream fout;
		char c;
		fout.open("PriceList.txt", ios::app);
		fout.seekp(0);
		// цикл отвечает за вывод заголовка в файл по условию : если в файле нет заголовка, то он выводится
		if (fout.is_open())
		{
			fout.seekp(0);
			while (fout >> c)
			{
				if (c == 'N') {
					break;
				}
				else {
					fout.seekp(0);
					fout << str << endl;
					break;
				}
			}
		}
		for (int i = 0; i < list.size(); i++)
		{
			fout << list[i].getName() << setw(15) << list[i].getFirm() << setw(15) << list[i].getModel() << setw(15) << list[i].getSpeed() << setw(15) << list[i].getPrice() << setw(15) << list[i].getDate() << endl;
		}
		fout.close();
	}
	void printHeader() {
		ofstream fout;
		fout.open("PriceList.txt", ios::app);
		fout << str << endl;
		fout.close();
	}
	void readFromFile() {
		static bool is_file_read = false; // переменная-флаг
		if (is_file_read) {
			return; // если файл уже был прочитан, то выходим из функции
		}
		ifstream fon;
		fon.open("PriceList.txt");
		string name, firm, model, date;
		int speed, price;
		if (fon.is_open())
		{
			fon.seekg(80);
			while (fon >> name >> firm >> model >> speed >> price >> date)
			{
				list.push_back(DataBase(name, firm, model, speed, price, date));
			}
			is_file_read = true; // меняем значение переменной-флага
		}
		fon.close();
	}
	//void readFromFile() {
	//	ifstream fon;
	//	fon.open("PriceList.txt");
	//	string name, firm, model, date;
	//	int speed, price;
	//	if (fon.is_open()) // fin.eof()
	//	{
	//		// как сделать так, чтобы при повторном вызову метода информация не дублировалась? - 
	//		fon.seekg(80);
	//		while (fon >> name >> firm >> model >> speed >> price >> date)
	//		{
	//			list.push_back(DataBase(name, firm, model, speed, price, date));
	//		}
	//	}
	//	fon.close();
	//}
};

// Класс сортировка
class Sort
{
private:
	vector<DataBase> list;
public:
	vector<DataBase> getList() {
		return this->list;
	}
	Sort() {}
	~Sort() {}
	void add(DataBase data) {
		list.push_back(data);
	}
	void sortSpeed() {
		for (int i = 0; i < list.size() - 1; i++)
		{
			for (int j = 0; j < list.size() - i - 1; j++)
			{
				if (list[j].getSpeed() < list[j + 1].getSpeed())
				{
					swap(list[j], list[j + 1]);
				}
			}
		}
	}
	void print() {
		cout << "Name" << setw(15) << "Firm" << setw(15) << "Model" << setw(15) << "Speed" << setw(15) << "Price" << setw(15) << "Date" << endl;
		for (int i = 0; i < list.size(); i++)
		{
			cout << list[i].getName() << setw(15) << list[i].getFirm() << setw(15) << list[i].getModel() << setw(15) << list[i].getSpeed() << setw(15) << list[i].getPrice() << setw(15) << list[i].getDate() << endl;
		}
	}
};

// Выбор данных для сортировки
void choiceSort(PriceList& priceList, Sort& sort)
{
	int choice;
	cout << "1. Sort by speed" << endl;
	cout << "2. Sort by price" << endl;
	cout << "3. Sort by date" << endl;
	cout << "4. Sort by name" << endl;
	cout << "5. Sort by firm" << endl;
	cout << "6. Sort by model" << endl;
	cout << "7. Exit" << endl;
	cout << "Enter your choice: ";
	cin >> choice;
	if (choice == 1) {
		for (int i = 0; i < priceList.getList().size(); i++)
		{
			sort.add(priceList.getList()[i]);
		}
		sort.sortSpeed();
		sort.print();
	}
	else {
		cout << "Error! Try again!" << endl;
	}
}

// Выбор действия
void choice(PriceList& priceList)
{
	int choice;
	cout << "1. Add data" << endl;
	cout << "2. Print data" << endl;
	cout << "3. Print data to file" << endl;
	cout << "4. Read data from file" << endl;
	cout << "5. Sort data" << endl;
	cout << "6. Exit" << endl;
	cout << "Enter your choice: ";
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		system("cls");
		string name, firm, model, date;
		int speed, price;
		cout << "Enter name: ";
		cin >> name;
		cout << "Enter firm: ";
		cin >> firm;
		cout << "Enter model: ";
		cin >> model;
		cout << "Enter speed: ";
		cin >> speed;
		cout << "Enter price: ";
		cin >> price;
		cout << "Enter date: ";
		cin >> date;
		DataBase data(name, firm, model, speed, price, date);
		priceList.add(data);
		system("pause");
		system("cls");
		break;
	}
	case 2:
	{
		system("cls");
		priceList.print();
		system("pause");
		system("cls");
		break;
	}
	case 3:
	{
		system("cls");
		priceList.printToFile();
		system("pause");
		system("cls");
		break;
	}
	case 4:
	{
		system("cls");
		priceList.readFromFile();
		priceList.print();
		system("pause");
		system("cls");
		break;
	}
	case 5:
	{
		system("cls");
		Sort sort;
		choiceSort(priceList, sort);
		system("pause");
		system("cls");
		break;
	}
	case 6:
		exit(6);
	default:
		cout << "Error! Try again!" << endl;
		break;
	}
}

int main()
{
	PriceList priceList;
	while (true)
	{
		choice(priceList);
	}
	return 0;
}