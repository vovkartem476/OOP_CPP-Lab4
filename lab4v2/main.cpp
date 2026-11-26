#include "InscribedCircle.h"
#include <fstream>
#include <stdexcept>

int main()
{
	cout << "Введіть діагоналі ромба (d1 d2): ";
	double d1, d2;
	cin >> d1 >> d2;

	try
	{
		InscribedCircle ic(d1, d2);
		ic.print("Коло вписане в ромб");

		ofstream file("output.txt");
		if (!file)
			throw runtime_error("Помилка: не вдалось відкрити файл для запису!");

		file << "Коло, вписане в ромб" << endl;
		file << "[Ромб]" << endl;
		file << (Rhombus&)ic << endl;
		file << "[Коло]" << endl;
		file << (Circle&)ic << endl;
		file.close();
		cout << "\nДані записано у файл output.txt" << endl;

		ifstream fin("output.txt");
		if (!fin)
			throw runtime_error("Помилка: не вдалось відкрити файл для читання!");

		cout << "\nВміст файлу" << endl;
		string line;
		while (getline(fin, line))
			cout << line << endl;
		fin.close();
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}

	cout << "\nПеревірка винятків" << endl;
	try
	{
		InscribedCircle bad(-1, 4);
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}

	try
	{
		Rhombus empty;
		cout << empty.getD1() << endl;
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}

	return 0;
}
