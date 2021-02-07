#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Gosvo
{
	string name;
	string language;
	string cur_unit;
	float rate;
};
void input(bool flag ,int i,Gosvo gos[])
{
	cout << "Введите название государства " << endl;
	getline(cin, gos[i].name);
	while (flag == false)
	{
		flag = true;
		for (int j = 0; j < i; j++)
		{
			if (gos[i].name == gos[j].name)
				flag = false;
		}
		if (flag == false)
		{
			cout << "Элемент с таким названием уже существует.Попробуйте снова. " << endl;
			getline(cin, gos[i].name);
		}
	}
	flag = false;
	cout << "Введите государственный язык " << endl;
	getline(cin, gos[i].language);
	cout << "Введите денежную единицу" << endl;
	getline(cin, gos[i].cur_unit);
	cout << "Введите курс валюты относительно $" << endl;
	cin >> gos[i].rate;
	while (gos[i].rate < 1 || gos[i].rate > 1000000)
	{
		cout << "Ошибка ввода.Попробуйте снова ";
		cin >> gos[i].rate;
	}
}
void outputfile(int i, Gosvo gos[])
{
	ofstream file("lab.txt");
	for (int j = 0; j < i; j++)
	{
		file << "Название государства : " << gos[j].name << endl;
		file << "Государственный язык :  " << gos[j].language << endl;
		file << "Денежная единица : " << gos[j].cur_unit << endl;
		file << "Курс валюты относительно $ : " << gos[j].rate << endl;
		file << endl;
	}
}
void output(int i,Gosvo gos[])
{
	for (int j = 0; j < i; j++)
	{
		cout << "Название государства : " << gos[j].name << endl;
		cout << "Государственный язык :  " << gos[j].language << endl;
		cout << "Денежная единица : " << gos[j].cur_unit << endl;
		cout << "Курс валюты относительно $ : " << gos[j].rate << endl;
		cout << endl;
	}
}
void del(bool flag, int i, Gosvo gos[])
{
	string del;
	int k;
	cout << "Введите название элемента, который необходимо удалить " << endl;
	getline(cin, del);
	while (flag == false)
	{
		flag = true;
		for (int j = 0; j <= i; j++)
		{
			if (del == gos[j].name)
			{
				flag = false;
				k = j;
			}
		}
		if (flag == false)
		{
			for (k; k < i - 1; k++)
				gos[k] = gos[k + 1];
			flag = true;
		}
		else
		{
			cout << "Элемента с таким название не существует.Попробуйте снова." << endl;
			getline(cin, del);
			flag == false;
		}
	}
	system("cls");
}
void main()
{
	system("chcp 1251>null");
	Gosvo gos[100];
	int otvet = 1;
	int i = 0;
	bool flag = false;
	ofstream file("lab.txt");
	if (file.is_open())
	{
		while (otvet != 0)
		{
			input(flag, i, gos);
			cout << "Хотите ли вы продолжить ввод (1 - ДА , 0 - НЕТ)? " << endl;
			cin >> otvet;
			i++;
			cin.get();
			system("cls");
		}
		outputfile(i,gos);
		output(i, gos);
		del(flag, i, gos);
		i--;
		outputfile(i, gos);
		output(i, gos);
		system("pause");
		system("cls");
		for (int j = i; j < i + 2; j++)
		{
			input(flag, j, gos);
			cin.get();
			system("cls");
		}
		output(i + 2, gos);
		outputfile(i+2, gos);
	}
	else
	{
		cout << "Ошибка.Не удалось открыть файл";
	}
	file.close();
	}

