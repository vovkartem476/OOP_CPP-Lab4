#include "InscribedRect.h"
#include <fstream>
#include <stdexcept>

int main()
{
	cout << "ведіть сторони прямокутника (a b): ";
	double a, b;
	cin >> a >> b;

	try
	{
		InscribedRect rect(a, b);
		rect.print("Прямокутник вписаний у коло");
		
		ofstream file("output.txt");
		if (!file)
			throw runtime_error("Помилка: не вдалось відкрити файл для запису!");

		file << "Прямокутник, вписаний у коло" << endl;
		file << "[Коло]" << endl;
		file << (Circle&)rect << endl;
		file << "[Прямокутник]" << endl;
		file << (Rectangle&)rect << endl;
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
		InscribedRect bad(-1, 4);
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}

	try
	{
		Circle empty;
		cout << empty.getRadius() << endl;
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}

	return 0;
}
