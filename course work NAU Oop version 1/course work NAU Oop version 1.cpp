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

class DynArr
{
private:
	int* arr;
	int size;
public:
	DynArr() {
		arr = new int[0];
		size = 0;
	}
	DynArr(int* arr, int size) {
		this->arr = new int[size];
		for (int i = 0; i < size; i++)
		{
			this->arr[i] = arr[i];
		}
		this->size = size;
	}
	~DynArr() {
		delete[] arr;
	}
	void setArr(int* arr) {
		this->arr = arr;
	}
	void setSize(int size) {
		this->size = size;
	}
	int* getArr() {
		return arr;
	}
	int getSize() {
		return size;
	}
	void Create() {
		cout << "Enter size of array: ";
		cin >> size;
		arr = new int[size];
		for (int i = 0; i < size; i++)
		{
			cout << "Enter " << i + 1 << " element: ";
			cin >> arr[i];
		}
	}
	void Print() {
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	void Sort() {
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size - 1; j++)
			{
				if (arr[j] > arr[j + 1])
				{
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
	}
	void CheckSort() {
		for (int i = 0; i < size - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				cout << "Array is not sorted" << endl;
				return;
			}
		}
	}
	void Menu() {
		int choice;
		do
		{
			cout << "1. Create array" << endl;
			cout << "2. Print array" << endl;
			cout << "3. Sort array" << endl;
			cout << "4. Check sort" << endl;
			cout << "5. Exit" << endl;
			cout << "Enter your choice: ";
			cin >> choice;
			switch (choice)
			{
			case 1:
				system("cls");
				Create();
				system("pause");
				system("cls");
				break;
			case 2:
				system("cls");
				Print();
				system("pause");
				system("cls");
				break;
			case 3:
				system("cls");
				Sort();
				system("pause");
				system("cls");
				break;
			case 4:
				system("cls");
				CheckSort();
				system("pause");
				system("cls");
				break;
			case 5:
				break;
			default:
				cout << "Wrong choice" << endl;
				break;
			}
		} while (choice != 5);
	}
};

class DynArr2
{
private:
	int** arr;
	int size;
public:
	DynArr2() {
		arr = new int* [0];
		size = 0;
	}
	DynArr2(int** arr, int size) {
		this->arr = new int* [size];
		for (int i = 0; i < size; i++)
		{
			this->arr[i] = new int[size];
			for (int j = 0; j < size; j++)
			{
				this->arr[i][j] = arr[i][j];
			}
		}
		this->size = size;
	}
	~DynArr2() {
		for (int i = 0; i < size; i++)
		{
			delete[] arr[i];
		}
		delete[] arr;
	}
	void setArr(int** arr) {
		this->arr = arr;
	}
	void setSize(int size) {
		this->size = size;
	}
	int** getArr() {
		return arr;
	}
	int getSize() {
		return size;
	}
	void Create() {
		cout << "Enter size of array: ";
		cin >> size;
		arr = new int* [size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = new int[size];
			for (int j = 0; j < size; j++)
			{
				cout << "Enter " << i + 1 << " element: ";
				cin >> arr[i][j];
			}
		}
	}
	void Print() {
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
	}
	void Sort() {
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size - 1; j++)
			{
				if (arr[j][0] < arr[j + 1][0])
				{
					int* temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
	}
	void CheckSort() {
		for (int i = 0; i < size - 1; i++)
		{
			if (arr[i][0] < arr[i + 1][0])
			{
				cout << "Array is not sorted" << endl;
				return;
			}
		}
	}
	void Menu() {
		int choice;
		do
		{
			cout << "1. Create array" << endl;
			cout << "2. Print array" << endl;
			cout << "3. Sort array" << endl;
			cout << "4. Check sort" << endl;
			cout << "5. Exit" << endl;
			cout << "Enter your choice: ";
			cin >> choice;
			switch (choice)
			{
			case 1:
				system("cls");
				Create();
				system("pause");
				system("cls");
				break;
			case 2:
				system("cls");
				Print();
				system("pause");
				system("cls");
				break;
			case 3:
				system("cls");
				Sort();
				system("pause");
				system("cls");
				break;
			case 4:
				system("cls");
				CheckSort();
				system("pause");
				system("cls");
				break;
			case 5:
				return;
			default:
				cout << "Wrong choice" << endl;
				break;
			}
		} while (choice != 5);
	}
};

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
		// Считываем файл в массив строк
		ifstream fin("PriceList.txt");
		vector<string> lines;
		string line;
		while (getline(fin, line)) {
			lines.push_back(line);
		}
		fin.close();

		// Открываем файл для записи
		ofstream fout("PriceList.txt", ios::app);
		if (!fout.is_open()) {
			cout << "Failed to open file!" << endl;
			return;
		}
		// Если файл пустой, выводим заголовок
		if (lines.empty()) {
			printHeader();
		}

		// Проверяем, была ли уже запись с такими данными
		for (int i = 0; i < list.size(); i++) {
			stringstream ss;
			ss << list[i].getName() << setw(15) << list[i].getFirm() << setw(15) << list[i].getModel() << setw(15) << list[i].getSpeed() << setw(15) << list[i].getPrice() << setw(15) << list[i].getDate();
			string newLine = ss.str();
			if (find(lines.begin(), lines.end(), newLine) == lines.end()) {
				// Если такой записи еще не было, выводим ее в файл
				fout << newLine << endl;
			}
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
			if (!(iss >> name >> firm >> model >> speed >> price >> date))
			{
				continue;
			}
			DataBase db(name, firm, model, speed, price, date);
			if (find(list.begin(), list.end(), db) == list.end()) {
				list.push_back(db);
			}
		}
		fin.clear();
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
	// Сортировка по возрастанию скорост
	void sortSpeed()
	{
		for (int i = 0; i < list.size(); i++)
		{
			for (int j = 0; j < list.size() - 1; j++)
			{
				if (list[j].getSpeed() > list[j + 1].getSpeed()) {
					swap(list[j], list[j + 1]);
				}
			}
		}
	}
	// Сортировка по возрастанию цены
	void sortPrice() {
		for (int i = 0; i < list.size(); i++)
		{
			for (int j = 0; j < list.size() - 1; j++)
			{
				if (list[j].getPrice() > list[j + 1].getPrice()) {
					swap(list[j], list[j + 1]);
				}
			}
		}
	}
	// Сортировка по возрастанию даты
	void sortDate() {
		for (int i = 0; i < list.size(); i++)
		{
			for (int j = 0; j < list.size() - 1; j++)
			{
				if (list[j].getDate() > list[j + 1].getDate()) {
					swap(list[j], list[j + 1]);
				}
			}
		}
	}
	// Сортировка по имени в алфавитном порядке
	void sortName()
	{
		for (int i = 0; i < list.size(); i++)
		{
			for (int j = 0; j < list.size() - 1; j++)
			{
				if (list[j].getName() > list[j + 1].getName()) {
					swap(list[j], list[j + 1]);
				}
			}
		}
	}
	// Сортировка по фирме в алфавитном порядке
	void sortFirm()
	{
		for (int i = 0; i < list.size(); i++)
		{
			for (int j = 0; j < list.size() - 1; j++)
			{
				if (list[j].getFirm() > list[j + 1].getFirm()) {
					swap(list[j], list[j + 1]);
				}
			}
		}
	}
	// Сортировка по модели в алфавитном порядке
	void sortModel()
	{
		for (int i = 0; i < list.size(); i++)
		{
			for (int j = 0; j < list.size() - 1; j++)
			{
				if (list[j].getModel() > list[j + 1].getModel()) {
					swap(list[j], list[j + 1]);
				}
			}
		}
	}
	// Сортировка по спаду скорости
	void sortSpeedDown() {
		for (int i = 0; i < list.size(); i++)
		{
			for (int j = 0; j < list.size() - 1; j++)
			{
				if (list[j].getSpeed() < list[j + 1].getSpeed()) {
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

// класс поиска данных в базе за заданными параметрами
class Search
{
private:
	vector<DataBase> list;
	public:
		Search() {}
		~Search() {}
		void add(DataBase data) {
			list.push_back(data);
		}
		vector<DataBase> getList() {
			return this->list;
		}
		void searchName(string name) {
			for (int i = 0; i < list.size(); i++)
			{
				if (list[i].getName() == name) {
					cout << list[i].getName() << setw(15) << list[i].getFirm() << setw(15) << list[i].getModel() << setw(15) << list[i].getSpeed() << setw(15) << list[i].getPrice() << setw(15) << list[i].getDate() << endl;
				}
			}
		}
		void searchFirm(string firm) {
			for (int i = 0; i < list.size(); i++)
			{
				if (list[i].getFirm() == firm) {
					cout << list[i].getName() << setw(15) << list[i].getFirm() << setw(15) << list[i].getModel() << setw(15) << list[i].getSpeed() << setw(15) << list[i].getPrice() << setw(15) << list[i].getDate() << endl;
				}
			}
		}
		void searchModel(string model) {
			for (int i = 0; i < list.size(); i++)
			{
				if (list[i].getModel() == model) {
					cout << list[i].getName() << setw(15) << list[i].getFirm() << setw(15) << list[i].getModel() << setw(15) << list[i].getSpeed() << setw(15) << list[i].getPrice() << setw(15) << list[i].getDate() << endl;
				}
			}
		}
		void searchSpeed(int speed) {
			for (int i = 0; i < list.size(); i++)
			{
				if (list[i].getSpeed() == speed) {
					cout << list[i].getName() << setw(15) << list[i].getFirm() << setw(15) << list[i].getModel() << setw(15) << list[i].getSpeed() << setw(15) << list[i].getPrice() << setw(15) << list[i].getDate() << endl;
				}
			}
		}
		void searchPrice(int price) {
			for (int i = 0; i < list.size(); i++)
			{
				if (list[i].getPrice() == price) {
					cout << list[i].getName() << setw(15) << list[i].getFirm() << setw(15) << list[i].getModel() << setw(15) << list[i].getSpeed() << setw(15) << list[i].getPrice() << setw(15) << list[i].getDate() << endl;
				}
			}
		}
		void searchDate(string date) {
			for (int i = 0; i < list.size(); i++)
			{
				if (list[i].getDate() == date) {
					cout << list[i].getName() << setw(15) << list[i].getFirm() << setw(15) << list[i].getModel() << setw(15) << list[i].getSpeed() << setw(15) << list[i].getPrice() << setw(15) << list[i].getDate() << endl;
				}
			}
		}
		void searchSpeedDown(int speed) {
			for (int i = 0; i < list.size(); i++)
			{
				if (list[i].getSpeed() > speed) {
					cout << list[i].getName() << setw(15) << list[i].getFirm() << setw(15) << list[i].getModel() << setw(15) << list[i].getSpeed() << setw(15) << list[i].getPrice() << setw(15) << list[i].getDate() << endl;
				}
			}
		}
};

// класс для меню
class Menu
{
private:
	DynArr dynArr;
	DynArr2 dynarr2;
	PriceList priceList;
	Sort sort;
	Search search;
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
	cout << "7. Sort by speed drop" << endl;
	cout << "8. Exit" << endl;
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
	else if (choice == 2) {
		for (int i = 0; i < priceList.getList().size(); i++)
		{
			sort.add(priceList.getList()[i]);
		}
		sort.sortPrice();
		sort.print();
	}
	else if (choice == 3) {
		for (int i = 0; i < priceList.getList().size(); i++)
		{
			sort.add(priceList.getList()[i]);
		}
		sort.sortDate();
		sort.print();
	}
	else if (choice == 4) {
		for (int i = 0; i < priceList.getList().size(); i++) {
			sort.add(priceList.getList()[i]);
		}
		sort.sortName();
		sort.print();
	}
	else if (choice == 5) {
		for (int i = 0; i < priceList.getList().size(); i++) {
			sort.add(priceList.getList()[i]);
		}
		sort.sortFirm();
		sort.print();
	}
	else if (choice == 6) {
		for (int i = 0; i < priceList.getList().size(); i++) {
			sort.add(priceList.getList()[i]);
		}
		sort.sortModel();
		sort.print();
	}
	else if (choice == 7) {
		for (int i = 0; i < priceList.getList().size(); i++) {
			sort.add(priceList.getList()[i]);
		}
		sort.sortSpeedDown();
		sort.print();
	}
	else if (choice == 8) {
		return;
	}
	else {
		cout << "Error! Try again!" << endl;
	}
}

// Выбор данных для поиска
void choiceSearch(PriceList& priceList, Search& search)
{
	int choice;
	cout << "1. Search by name" << endl;
	cout << "2. Search by firm" << endl;
	cout << "3. Search by model" << endl;
	cout << "4. Search by speed" << endl;
	cout << "5. Search by price" << endl;
	cout << "6. Search by date" << endl;
	cout << "7. Search by speed drop" << endl;
	cout << "8. Exit" << endl;
	cout << "Enter your choice: ";
	cin >> choice;
	if (choice == 1) {
		string name;
		cout << "Enter name: ";
		cin >> name;
		search.searchName(name);
	}
	else if (choice == 2) {
		string firm;
		cout << "Enter firm: ";
		cin >> firm;
		search.searchFirm(firm);
	}
	else if (choice == 3) {
		string model;
		cout << "Enter model: ";
		cin >> model;
		search.searchModel(model);
	}
	else if (choice == 4) {
		int speed;
		cout << "Enter speed: ";
		cin >> speed;
		search.searchSpeed(speed);
	}
	else if (choice == 5) {
		int price;
		cout << "Enter price: ";
		cin >> price;
		search.searchPrice(price);
	}
	else if (choice == 6) {
		string date;
		cout << "Enter date: ";
		cin >> date;
		search.searchDate(date);
	}
	else if (choice == 7) {
		int speed;
		cout << "Enter speed: ";
		cin >> speed;
		search.searchSpeedDown(speed);
	}
	else if (choice == 8) {
		return;
	}
	else {
		cout << "Error! Try again!" << endl;
	}
}

// Выбор действия


/*	PriceList priceList;
while (true)
{
	choice(priceList);
}
return 0;*/

void ChoiceTask() {
	int n;
	do
	{
		cout << "Выберите задание: " << endl;
		cout << "1. Задание 1" << endl;
		cout << "2. Задание 2" << endl;
		cout << "3. Задание 3" << endl;
		cout << "0. Выход" << endl;
		cin >> n;
		switch (n)
		{
		case 1:

			break;
		case 2:
			break;
		case 3:
			break;
		case 0:
			break;
		default:
			cout << "Неверный ввод" << endl;
			break;
		}
		system("PAUSE");
		system("cls");
	} while (n != 0);
}

int main()
{
	setlocale(0, "");
}