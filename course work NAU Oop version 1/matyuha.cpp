//#pragma warning(disable : 4244)
//#pragma warning(disable : 6031)
//#pragma warning(disable : 4996)
//#define _CRT_SECURE_NO_WARNINGS
//#include <cmath>
//#include <iostream>
//#include <fstream>
//#include <stdlib.h>
//#include <string.h>
//#include <windows.h>
//#include <ctime>
//#include <iomanip>
//#include <conio.h>
//#include <algorithm>
//
//#define SCREEN_WIDTH 90
//#define SCREEN_HEIGHT 26
//#define WIN_WIDTH 70
//int main();
//using namespace std;
//const int n = 3, m = 3;
//
//HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
//COORD CursorPosition;
//void gotoxy(int x, int y)
//{
//	CursorPosition.X = x;
//	CursorPosition.Y = y;
//	SetConsoleCursorPosition(console, CursorPosition);
//}
//создание массива
//class Array {
//public:
//	Array() {}
//	Array(int* arrOne, int size) {//одномерный массив
//		srand(time(0));
//		for (int i = 0; i < size; i++) {
//			arrOne[i] = rand() % 20;
//		}
//		for (int i = 0; i < size; i++) {
//			cout << setw(4) << arrOne[i];
//		}
//	}
//	Array(int** arrTwo, int size, int height) {//двомерный массив
//		srand(time(0));
//		for (int i = 0; i < size; i++) {
//			arrTwo[i] = new int[height];
//		}
//		for (int i = 0; i < size; i++) {
//			for (int j = 0; j < height; j++) {
//				arrTwo[i][j] = rand() % 100;
//			}
//		}
//		for (int i = 0; i < size; i++) {
//			for (int j = 0; j < height; j++) {
//				cout << setw(4) << arrTwo[i][j];
//			}
//			cout << endl;
//		}
//	}
//	void MinArrOne(int* arrOne, int size) {//минимальное из положительных одомерного массива(задание 1)
//		system("cls");
//		int min = arrOne[0];
//		for (int i = 0; i < size; i++) {
//			if (arrOne[i] > 0) {
//				min = arrOne[i];
//			}
//		}
//		gotoxy(10, 5); cout << min;
//		getch();
//	}
//	void SortArrOneAscending(int* arrOne, int size) {//сортировка одномерного массива по возрастанию(задание 1)
//		system("cls");
//		int temp;
//		for (int i = 0; i < size - 1; i++) {
//			for (int j = i + 1; j < size; j++) {
//				if (arrOne[i] > arrOne[j]) {
//					temp = arrOne[i];
//					arrOne[i] = arrOne[j];
//					arrOne[j] = temp;
//				}
//			}
//		}
//		for (int i = 0; i < size; i++) {
//			cout << setw(4) << arrOne[i];
//		}
//		getch();
//	}
//	void SortArrOneВescending(int* arrOne, int size) {//сортировка одномерного массива по убыванию(задание 1)
//		system("cls");
//		int temp;
//		for (int i = 0; i < size - 1; i++) {
//			for (int j = i + 1; j < size; j++) {
//				if (arrOne[i] < arrOne[j]) {
//					temp = arrOne[i];
//					arrOne[i] = arrOne[j];
//					arrOne[j] = temp;
//				}
//			}
//		}
//		for (int i = 0; i < size; i++) {
//			cout << setw(4) << arrOne[i];
//		}
//		getch();
//	}
//	void MatrixArrTwo(int** arrTwo, int* columns, int* indexcol, int** rethult, int size, int height) {//условие задание 2.1
//		system("cls");
//		for (int i = 0; i < size; i++) {
//			for (int j = 0; j < height; j++) {
//				columns[i] = +arrTwo[i][j];
//			}
//			pow(columns[i], 2);
//		}
//		getch();
//	}
//	void SortMatrixArrTwo(int** arrTwo, int* columns, int* indexcol, int** rethult, int size, int height) {//условие задания 2.2
//		system("cls");
//		int min = -1000, index = 0;
//		for (int i = 0; i < size; i++) {
//			for (int j = 0; j < height; j++) {
//				if (min > columns[j] && columns[j] != -1) {
//					min = columns[j];
//					index = i;
//				}
//			}
//			indexcol[i] = index;// сохраняем индекс столбца в массив индексов
//			columns[index] = -1;// исключаем из поиска данный элемент массива
//			min = -1000;
//		}
//		for (int i = 0; i < size; i++) {
//			rethult[i] = new int[height];
//		}
//		for (int i = 0; i < size; i++) {
//			for (int j = 0; j < height; j++) {
//				rethult[j][i] = arrTwo[j][indexcol[i]];
//			}
//		}
//		for (int i = 0; i < size; i++) {
//			for (int j = 0; j < height; j++) {
//				cout << setw(4) << rethult[i][j];
//			}
//			cout << endl;
//		}
//		getch();
//	}
//};
//class library {
//public:
//	int InventoryNumber;
//	string NameBook;
//	string Author;
//	string Genre;
//	string YearOfIssue;
//	float Price;
//	string DateOfDelivery;
//
//}veb[n];
//void Libreary(library* veb) {
//	system("cls");
//	for (int i = 0; i < n; i++) {
//		cout << "==========================================================" << endl;
//		cout << "Inventory number: ";
//		cin >> veb[i].InventoryNumber;
//		cout << "Name book: ";
//		cin >> veb[i].NameBook;
//		cout << "Author: ";
//		cin >> veb[i].Author;
//		cout << "Genre: ";
//		cin >> veb[i].Genre;
//		cout << "Year of issue: ";
//		cin >> veb[i].YearOfIssue;
//		cout << "Price: ";
//		cin >> veb[i].Price;
//		cout << "Date of delivery: ";
//		cin >> veb[i].DateOfDelivery;
//		cout << "==========================================================" << endl;
//	}
//	getch();
//}
//поиск книги
//void SearchEngine(library* veb) {
//	system("cls");
//	string name_book;
//	cout << "Enter name book  - ";
//	cin >> name_book;
//	for (int i = 0; i < n; i++)
//	{
//		if (veb[i].NameBook == name_book) {
//			cout << "==========================================================" << endl;
//			cout << "Name book: " << veb[i].NameBook << endl;
//			cout << "Inventory number: " << veb[i].InventoryNumber << endl;
//			cout << "Author: " << veb[i].Author << endl;
//			cout << "Genre: " << veb[i].Genre << endl;
//			cout << "Price: " << veb[i].Price << endl;
//			cout << "Year of issue: " << veb[i].YearOfIssue << endl;
//			cout << "Date of delivery: " << veb[i].DateOfDelivery << endl;
//			cout << "==========================================================" << endl;
//		}
//	}
//	getch();
//}
//сортировка по дате
//void sortYearOfIssue(library* veb) {
//	system("cls");
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n - 1; j++)
//		{
//			if (veb[j].YearOfIssue < veb[j + 1].YearOfIssue) {
//				library Year = veb[j];
//				veb[j] = veb[j + 1];
//				veb[j + 1] = Year;
//			}
//		}
//	}
//	for (int i = 0; i < n; i++) {
//		cout << "Year of issue: " << veb[i].YearOfIssue << endl;
//		cout << "Name book: " << veb[i].NameBook << endl;
//		cout << "Inventory number: " << veb[i].InventoryNumber << endl;
//		cout << "Author: " << veb[i].Author << endl;
//		cout << "Genre: " << veb[i].Genre << endl;
//		cout << "Price: " << veb[i].Price << endl;
//		cout << "Date of delivery: " << veb[i].DateOfDelivery << endl;
//		cout << "==========================================================" << endl;
//	}
//	getch();
//}
//БД
//void CreatingADatabase() {
//	system("cls");
//	ofstream Database("Library.txt");
//	for (int i = 0; i < m; i++) {
//		Database << "Year of issue: " << veb[i].YearOfIssue << endl;
//		Database << "Name book: " << veb[i].NameBook << endl;
//		Database << "Inventory number: " << veb[i].InventoryNumber << endl;
//		Database << "Author: " << veb[i].Author << endl;
//		Database << "Genre: " << veb[i].Genre << endl;
//		Database << "Price: " << veb[i].Price << endl;
//		Database << "Date of delivery: " << veb[i].DateOfDelivery << endl;
//	}
//	cout << "U are database creat!" << endl;
//	cout << "Press any button to return to the previous window";
//	getch();
//	Database.close();
//}
//вызов БД
//void ShowDatabase() {
//	system("cls");
//	fstream Database("Library.txt");
//	string coutStr;
//	while (!Database.eof()) {
//		Database >> coutStr;
//	}
//	cout << "Press any button to return to the previous window";
//	getch();
//	Database.close();
//}
//class Menu {
//	Array array;
//public:
//	Menu() {}
//	~Menu() {}
//	void exercisуOne(int* arrOne, int size) {
//		system("cls");
//		do {
//			gotoxy(10, 4); cout << "====================================\n";
//			gotoxy(10, 5); cout << "Minimum of positive odomeric array - 1\n";
//			gotoxy(10, 6); cout << "sorting a one-dimensional array in ascending order - 2\n";
//			gotoxy(10, 7); cout << "sorting a one-dimensional array in descending order - 3\n";
//			gotoxy(10, 9); cout << "exet - 4\n";
//			gotoxy(10, 10); cout << "====================================\n";
//			char op = getch();
//			if (op == '1')array.MinArrOne(arrOne, size);
//			else if (op == '2')array.SortArrOneAscending(arrOne, size);
//			else if (op == '3')array.SortArrOneВescending(arrOne, size);
//			else if (op == '4')main();
//		} while (1);
//
//	}
//	меню задания 2
//	void exercisуTwo(int** arrTwo, int size, int height, int* columns, int* indexcol, int** rethult) {
//		system("cls");
//		do {
//			gotoxy(10, 4); cout << "====================================\n";
//			gotoxy(10, 5); cout << "Minimum of positive odomeric array - 1\n";
//			gotoxy(10, 6); cout << "sorting a one-dimensional array in ascending order - 2\n";
//			gotoxy(10, 8); cout << "exet - 3\n";
//			gotoxy(10, 9); cout << "====================================\n";
//			char op = getch();
//			if (op == '1')array.MatrixArrTwo(arrTwo, columns, indexcol, rethult, size, height);
//			else if (op == '2')array.SortMatrixArrTwo(arrTwo, columns, indexcol, rethult, size, height);
//			else if (op == '3')main();
//		} while (1);
//		main();
//	}
//	меню задания 3
//	void ExercisуThree() {
//		system("cls");
//		do {
//			gotoxy(10, 4); cout << "====================================\n";
//			gotoxy(10, 5); cout << "Book search - 1\n";
//			gotoxy(10, 6); cout << "sort by date - 2\n";
//			gotoxy(10, 8); cout << "exet - 3\n";
//			gotoxy(10, 9); cout << "====================================\n";
//			char op = getch();
//			if (op == '1')SearchEngine(veb);
//			else if (op == '2')sortYearOfIssue(veb);
//			else if (op == '3')main();
//		} while (1);
//		main();
//	}
//};
//class Admin {
//public:
//	Admin() {
//		system("cls");
//		do {
//			gotoxy(10, 4); cout << "====================================\n";
//			gotoxy(10, 5); cout << "populating the database - 1\n";
//			gotoxy(10, 6); cout << "saving the database - 2\n";
//			gotoxy(10, 7); cout << "open database - 3\n";
//			gotoxy(10, 8); cout << "exet - 4\n";
//			gotoxy(10, 9); cout << "====================================\n";
//			char op = getch();
//			if (op == '1')Libreary(veb);
//			else if (op == '2')CreatingADatabase();
//			else if (op == '3')ShowDatabase();
//			else if (op == '4')exit(0);
//		} while (1);
//		main();
//	}
//};
//
//
//
//int main() {
//	setlocale(0, "");
//	const int size = 10, height = 10; //размер массивов
//	int* arrOne = new int[size];
//	int** arrTwo = new int* [size];
//	int* columns = new int[size];//Массив квадрата суммы всех этоментов колоны матрици
//	int* indexcol = new int[size];//массив индексов для формирования порядка
//	int** rethult = new int* [size];
//	Array arrayOne(arrOne, size);
//	Array arrayTwo(arrTwo, size, height);
//	Menu menu;
//	do {
//		system("cls");
//		gotoxy(10, 5); cout << "Exercisу one - 1\n";
//		gotoxy(10, 6); cout << "Exercisу two - 2\n";
//		gotoxy(10, 7); cout << "Exercisу three - 3\n";
//		gotoxy(10, 8); cout << "admin\n";
//		gotoxy(10, 11); cout << "Exit - 4\n";
//		char op = getch();
//		if (op == '1')menu.exercisуOne(arrOne, size);
//		else if (op == '2')menu.exercisуTwo(arrTwo, size, height, columns, indexcol, rethult);
//		else if (op == '3')menu.ExercisуThree();
//		else if (op == '0')Admin admin;
//		else if (op == '4')exit(0);
//	} while (1);
//	return 0;
//
//
//	delete[] arrOne;
//	delete[] arrTwo;
//	delete[] columns;
//	delete[] rethult;
//	delete[] indexcol;
//}