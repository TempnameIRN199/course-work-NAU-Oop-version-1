#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
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

// Создание базы данных на ООП

// Структура:
// Прайс-лист WIFI-адаптеров в магазине: фирма -производитель, модель, скорость WIFI в Мбит /с, цена, дата поставки
// Параметры сортировки:
// за падением скорости
// Выбор данных по условию
// запись данных в файл и чтение из файла
// удаление записей из файла по индексу

// Классы:
// 1. База данных
// 2. Прайс-лист
// 3. Сортировка
// 4. Выбор данных по условию
// 5. Запись данных в файл и чтение из файла

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
	void print() {
		cout << "Name: " << name << endl;
		cout << "Firm: " << firm << endl;
		cout << "Model: " << model << endl;
		cout << "Speed: " << speed << endl;
		cout << "Price: " << price << endl;
		cout << "Date: " << date << endl;
	}
};

// Класс прайс-лист
class PriceList
{
private:
	vector<DataBase> list;
	public:
		PriceList() {}
		~PriceList() {}
		void add(DataBase data) {
			list.push_back(data);
		}
		void print() {
			for (int i = 0; i < list.size(); i++) {
				list[i].print();
			}
		}
		void printToFile() {
			ofstream fout;
			fout.open("PriceList.txt");
			for (int i = 0; i < list.size(); i++) {
				fout << "Name: " << list[i].getName() << endl;
				fout << "Firm: " << list[i].getFirm() << endl;
				fout << "Model: " << list[i].getModel() << endl;
				fout << "Speed: " << list[i].getSpeed() << endl;
				fout << "Price: " << list[i].getPrice() << endl;
				fout << "Date: " << list[i].getDate() << endl;
			}
			fout.close();
		}
		void readFromFile() {
			ifstream fin;
			fin.open("PriceList.txt");
			string name;
			string firm;
			string model;
			int speed;
			int price;
			string date;
			while (!fin.eof()) {
				fin >> name;
				fin >> firm;
				fin >> model;
				fin >> speed;
				fin >> price;
				fin >> date;
				DataBase data(name, firm, model, speed, price, date);
				list.push_back(data);
			}
			fin.close();
		}
		void deleteByIndex(int index) {
			list.erase(list.begin() + index);
		}
		void deleteByFirm(string firm) {
			for (int i = 0; i < list.size(); i++) {
				if (list[i].getFirm() == firm) {
					list.erase(list.begin() + i);
				}
			}
		}
		void deleteByModel(string model) {
			for (int i = 0; i < list.size(); i++) {
				if (list[i].getModel() == model) {
					list.erase(list.begin() + i);
				}
			}
		}
		void deleteBySpeed(int speed) {
			for (int i = 0; i < list.size(); i++) {
				if (list[i].getSpeed() == speed) {
					list.erase(list.begin() + i);
				}
			}
		}
		void deleteByPrice(int price) {
			for (int i = 0; i < list.size(); i++) {
				if (list[i].getPrice() == price) {
					list.erase(list.begin() + i);
				}
			}
		}
		void deleteByDate(string date) {
			for (int i = 0; i < list.size(); i++) {
				if (list[i].getDate() == date) {
					list.erase(list.begin() + i);
				}
			}
		}
};

class Sort
{

};