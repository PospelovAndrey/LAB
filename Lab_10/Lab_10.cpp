#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;
void input(string* a, int size) 
{
	cout << "Заполните массив строками" << endl;
	string s;
	for (int i = 0; i < size; i++)
	{
		getline(cin, s);
		a[i] = s;
	}
}
void output(string* a,int size) 
{
cout << "\nМассив :\n";
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << endl;
	}
	cout << " " << endl;
}
void move(string*& a, int& size)
{
	int delstr;
	for (int i = 0; i < size;i++)
	{
		int j = a[i].length()-1;
		if ((a[i][0]) == (a[i][j]))
		{
			delstr = i;
			for (int i = delstr; i < size-1; i++)
			{
				a[i] = a[i+1];
			}
			size--;
		}
	}
}
	void copy(string * &a, int size)
{
	string* newa = new string[size];
	for (int i = 0; i < size; i++) 
	{
		newa[i] = a[i];
	}
	delete[] a;
	a = newa; 
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int size;
	cout << "Сформировать массив строк. Удалить из него строку, начинающуюся и заканчивающуюся на одну и ту же букву.\n\n";
	cout << "Введите размер массива" << endl;
	cin >> size;
	while (size <= 0) { cout << "Ошибка ввода.Попробуйте снова.\n"; cin >> size; }
	cin.ignore();
	string* a = new string[size]; 
	if (a == NULL)
	{
		cout << "Ошибка выделения памяти. Недостаточно свободной памяти" << endl; 
		exit(1); 
	}
	input(a, size);
	output(a, size);
	move(a, size);
	copy(a, size);
	output(a, size);
	delete[] a;
	return 0;

}