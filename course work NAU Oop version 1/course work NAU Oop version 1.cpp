﻿#define _CRT_SECURE_NO_WARNINGS
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include <iostream>
#include <istream>
#include <ctime>
#include <stdlib.h>
#include <iomanip>
#include <string>
#include <string.h>
#include <ctype.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <filesystem>
using namespace std;

string str = "Name           Firm          Model          Speed          Price           Date";

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
	friend bool operator==(const DataBase& lhs, const DataBase& rhs) {
		return (lhs.name == rhs.name &&
			lhs.firm == rhs.firm &&
			lhs.model == rhs.model &&
			lhs.speed == rhs.speed &&
			lhs.price == rhs.price &&
			lhs.date == rhs.date);
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
		fout.open("PriceList.txt", ios::app);
		if (fout.is_open()) {
			// Получаем текущую позицию указателя записи
			fout.seekp(0, ios::end);
			streampos fileSize = fout.tellp();
			// Если размер файла равен нулю, выводим заголовок
			if (fileSize == 0) {
				printHeader();
			}
			// Выводим данные
			for (int i = 0; i < list.size(); i++) {
				fout << list[i].getName() << setw(15) << list[i].getFirm() << setw(15) << list[i].getModel() << setw(15) << list[i].getSpeed() << setw(15) << list[i].getPrice() << setw(15) << list[i].getDate() << endl;
			}
			fout.close();
		}
	}
	void printHeader(){
		ofstream fout;
		fout.open("PriceList.txt", ios::app);
		fout << str << endl;
		fout.close();
	}
	void readFromFile() {
		ifstream fin("PriceList.txt");
		if (!fin.is_open()) {
			cout << "Failed to open file!" << endl;
			return;
		}
		string line;
		while (getline(fin, line)) {
			istringstream iss(line);
			string name, firm, model, date;
			int speed, price;
			if (!(iss >> name >> firm >> model >> speed >> price >> date)) {
				continue;
			}
			DataBase db(name, firm, model, speed, price, date);
			if (find(list.begin(), list.end(), db) == list.end()) {
				list.push_back(db);
			}
		}
		fin.close();
	}
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