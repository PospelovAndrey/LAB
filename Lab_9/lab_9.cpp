#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string str;
	string word;
	string sl[255];
	string laststr;
	char gl[20] = { 'А', 'а', 'Я', 'я', 'О', 'о', 'Е', 'е', 'У', 'у', 'Ю', 'ю', 'Ы', 'ы', 'И', 'и', 'Э', 'э', 'Ё', 'ё' };
	bool flag=false;
	int i;
	int n;
	int k = 0;
	ifstream F1("F1.txt");
	ofstream F2("F2.txt");
	if (F1.is_open() || F2.is_open())
	{
		cout <<"Скопировать из файла F1 в файл F2 все строки, в которых есть одинаковые слова.\nОпределить количество гласных букв в последней строке файла F2.\n\n";
		while (F1.eof() == false)
		{
			i = 0;
			n = 1;
			word = "";
			getline(F1, str);
			for (char b : str)
			{
				if (b == ' ')
				{
					sl[i] = word;
					word = "";
					i++;
				}
				else
				{
					word = word + b;
				}
			}
			sl[i] = word;
			for (int k = 0; k < i; k++)
			{
				for (int j = n; j <= i; j++)
					if (sl[k] == sl[j])
						flag = true;
				n++;
			}
			if (flag)
			{
				F2 << str;
				F2 << endl;
				flag = false;
				laststr = str;

			}
		}
		for (int i = 0; i < laststr.length(); i++)
			for (int j = 0; j < 19; j++)
			if ((int)laststr[i]==gl[j])
				k++;
		cout << "Количество гласных букв = "<<k<<endl;

	}
	else
	{
		cout << "Ошибка.Не удалось открыть файл";
	}
	F1.close();
	F2.close();
	return 0;
}
