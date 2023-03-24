//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <ctime>
//#include <stdlib.h>
//#include <iomanip>
//#include <conio.h>
//#include <string>
//#include <string.h>
//#include <ctype.h>
//#include <fstream>
//#include <sstream>
//#include <vector>
//#include <algorithm>
//#include <cstdlib>
//using namespace std;
//
//// �������� ���� ������ �� ���
//
//// ���������:
//// �����-���� WIFI-��������� � ��������: ����� -�������������, ������, �������� WIFI � ���� /�, ����, ���� ��������
//// ��������� ����������:
//// �� �������� ��������
//// ����� ������ �� �������
//// ������ ������ � ���� � ������ �� �����
//
//// ������:
//// 1. ���� ������
//// 2. �����-����
//// 3. ����������
//// 4. ����� ������ �� �������
//// 5. ������ ������ � ���� � ������ �� �����
//
//// ����� ���� ������
//class DataBase
//{
//private:
//	string name;
//	string firm;
//	string model;
//	int speed;
//	int price;
//	string date;
//	int num;
//public:
//	DataBase() {
//		name = " ";
//		firm = " ";
//		model = " ";
//		speed = 0;
//		price = 0;
//		date = " ";
//		num = 0;
//	}
//	DataBase(string name, string firm, string model, int speed, int price, string date, int num) {
//		this->name = name;
//		this->firm = firm;
//		this->model = model;
//		this->speed = speed;
//		this->price = price;
//		this->date = date;
//		this->num = num;
//	}
//	~DataBase() {}
//	void setName(string name) {
//		this->name = name;
//	}
//	void setFirm(string firm) {
//		this->firm = firm;
//	}
//	void setModel(string model) {
//		this->model = model;
//	}
//	void setSpeed(int speed) {
//		this->speed = speed;
//	}
//	void setPrice(int price) {
//		this->price = price;
//	}
//	void setDate(string date) {
//		this->date = date;
//	}
//	void setNum(int num) {
//		this->num = num;
//	}
//	string getName() {
//		return name;
//	}
//	string getFirm() {
//		return firm;
//	}
//	string getModel() {
//		return model;
//	}
//	int getSpeed() {
//		return speed;
//	}
//	int getPrice() {
//		return price;
//	}
//	string getDate() {
//		return date;
//	}
//	int getNum() {
//		return num;
//	}
//};
//
//// ����� �����-����
//class PriceList
//{
//private:
//	vector<DataBase> list;
//public:
//	vector<DataBase> getList() {
//		return this->list;
//	}
//	PriceList() {}
//	~PriceList() {}
//	void add(DataBase data) {
//		list.push_back(data);
//	}
//	void print() {
//		cout << "Name" << setw(15) << "Firm" << setw(15) << "Model" << setw(15) << "Speed" << setw(15) << "Price" << setw(15) << "Date" << setw(15) << "Num" << endl;
//		for (int i = 0; i < list.size(); i++)
//		{
//			cout << list[i].getName() << setw(15) << list[i].getFirm() << setw(15) << list[i].getModel() << setw(15) << list[i].getSpeed() << setw(15) << list[i].getPrice() << setw(15) << list[i].getDate() << setw(15) << list[i].getNum() << endl;
//		}
//	}
//	void printToFile() {
//		ofstream fout;
//		fout.open("PriceList.txt", ios::app);
//
//		fout << "Name" << setw(15) << "Firm" << setw(15) << "Model" << setw(15) << "Speed" << setw(15) << "Price" << setw(15) << "Date" << setw(15) << "Num" << endl;
//		for (int i = 0; i < list.size(); i++)
//		{
//			fout << list[i].getName() << setw(15) << list[i].getFirm() << setw(15) << list[i].getModel() << setw(15) << list[i].getSpeed() << setw(15) << list[i].getPrice() << setw(15) << list[i].getDate() << setw(15) << list[i].getNum() << endl;
//		}
//		fout.close();
//	}
//	void readFromFile() {
//		ifstream fin;
//		fin.open("PriceList.txt");
//		string name, firm, model, date;
//		int speed, price, num;
//		if (fin.is_open()) // fin.eof()
//		{
//			fin.seekg(80);
//			while (fin >> name >> firm >> model >> speed >> price >> date >> num)
//			{
//				list.push_back(DataBase(name, firm, model, speed, price, date, num));
//			}
//		}
//		fin.close();
//	}
//	void deleteByIndex(int num) {
//		list.erase(list.begin() + num);
//	}
//	
//};
//
//// ����� ����������
//class Sort
//{
//private:
//	vector<DataBase> list;
//public:
//	vector<DataBase> getList() {
//		return this->list;
//	}
//	Sort() {}
//	~Sort() {}
//	void add(DataBase data) {
//		list.push_back(data);
//	}
//	void sortSpeed() {
//		for (int i = 0; i < list.size() - 1; i++)
//		{
//			for (int j = 0; j < list.size() - i - 1; j++)
//			{
//				if (list[j].getSpeed() < list[j + 1].getSpeed())
//				{
//					swap(list[j], list[j + 1]);
//				}
//			}
//		}
//	}
//	void print() {
//		cout << "Name" << setw(15) << "Firm" << setw(15) << "Model" << setw(15) << "Speed" << setw(15) << "Price" << setw(15) << "Date" << setw(15) << "Num" << endl;
//		for (int i = 0; i < list.size(); i++)
//		{
//			cout << list[i].getName() << setw(15) << list[i].getFirm() << setw(15) << list[i].getModel() << setw(15) << list[i].getSpeed() << setw(15) << list[i].getPrice() << setw(15) << list[i].getDate() << setw(15) << list[i].getNum() << endl;
//		}
//	}
//};
//
//// ����� ������ ��� ����������
//void choiceSort(PriceList& priceList, Sort& sort)
//{
//	int choice;
//	cout << "1. Sort by speed" << endl;
//	cout << "2. Sort by price" << endl;
//	cout << "3. Sort by date" << endl;
//	cout << "4. Sort by name" << endl;
//	cout << "5. Sort by firm" << endl;
//	cout << "6. Sort by model" << endl;
//	cout << "7. Exit" << endl;
//	cout << "Enter your choice: ";
//	cin >> choice;
//	if (choice == 1) {
//		for (int i = 0; i < priceList.getList().size(); i++)
//		{
//			sort.add(priceList.getList()[i]);
//		}
//		sort.sortSpeed();
//		sort.print();
//	}
//	else {
//		cout << "Error! Try again!" << endl;
//	}
//}
//
//// ����� ��������
//void choice(PriceList& priceList)
//{
//	int choice;
//	cout << "1. Add data" << endl;
//	cout << "2. Print data" << endl;
//	cout << "3. Print data to file" << endl;
//	cout << "4. Read data from file" << endl;
//	cout << "5. Sort data" << endl;
//	cout << "6. Delete data" << endl;
//	cout << "7. Exit" << endl;
//	cout << "Enter your choice: ";
//	cin >> choice;
//	switch (choice)
//	{
//	case 1:
//	{
//		system("cls");
//		string name, firm, model, date;
//		int speed, price, num;
//		cout << "Enter name: ";
//		cin >> name;
//		cout << "Enter firm: ";
//		cin >> firm;
//		cout << "Enter model: ";
//		cin >> model;
//		cout << "Enter speed: ";
//		cin >> speed;
//		cout << "Enter price: ";
//		cin >> price;
//		cout << "Enter date: ";
//		cin >> date;
//		cout << "Enter num: ";
//		cin >> num;
//		DataBase data(name, firm, model, speed, price, date, num);
//		priceList.add(data);
//		system("pause");
//		system("cls");
//		break;
//	}
//	case 2:
//	{
//		system("cls");
//		priceList.print();
//		system("pause");
//		system("cls");
//		break;
//	}
//	case 3:
//	{
//		system("cls");
//		priceList.printToFile();
//		system("pause");
//		system("cls");
//		break;
//	}
//	case 4:
//	{
//		system("cls");
//		priceList.readFromFile();
//		priceList.print();
//		system("pause");
//		system("cls");
//		break;
//	}
//	case 5:
//	{
//		system("cls");
//		Sort sort;
//		choiceSort(priceList, sort);
//		system("pause");
//		system("cls");
//		break;
//	}
//	/*case 6:
//	{
//		system("cls");
//		int index;
//		cout << "Enter index: ";
//		cin >> index;
//		priceList.remove(index);
//		system("pause");
//		system("cls");
//		break;
//	}*/
//	case 7:
//		exit(6);
//	default:
//		cout << "Error! Try again!" << endl;
//		break;
//	}
//}
//
//int main()
//{
//	PriceList priceList;
//	while (true)
//	{
//		choice(priceList);
//	}
//	return 0;
//}

//void readFromFile() {
//	static bool is_file_read = false; // ����������-����
//	if (is_file_read) {
//		return; // ���� ���� ��� ��� ��������, �� ������� �� �������
//	}
//	ifstream fon;
//	fon.open("PriceList.txt");
//	string name, firm, model, date;
//	int speed, price;
//	fon.seekg(80);
//	if (fon.is_open())
//	{
//		fon.seekg(80);
//		while (fon >> name >> firm >> model >> speed >> price >> date)
//		{
//			list.push_back(DataBase(name, firm, model, speed, price, date));
//		}
//		is_file_read = true; // ������ �������� ����������-�����
//	}
//	fon.close();
//	fon.clear();
//}