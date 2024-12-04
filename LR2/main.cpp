#include <iostream>
#include <string>

using namespace std;

class sales
{
public:
	float data_arr[3];
	void get_sales()
	{
		cout << "Введите данные о продажах за последние 3 месяца: " << endl;
		for (int i = 0; i < 3; i++)
		{
			cin >> data_arr[i];
		}
	}
	void put_sales()
	{
		for (int i = 0; i < 3; i++)
		{
			cout << "Продаж в " << i + 1 << " месяце: " << data_arr[i] << endl;
		}
	}
};


class Publication
{
public:
	void getdataP()
	{

		cout << "Введите название книги: " << endl;
		cin.ignore();
		getline(cin, Name);
		cout << "Введите цену: " << endl;
		cin >> price;
	}

	void putdataP()
	{
		cout << "Название книги: " << Name << endl;
		cout << "Стоимость книги: " << price << endl;
	}

protected:
	string Name;
	float price;
};

class Book : public Publication, sales
{
private:
	int pages;
public:

	void getdata()
	{
		getdataP();
		cout << "Ввелите количество страниц: " << endl;
		cin >> pages;
		get_sales();
	}

	void putdata()
	{
		putdataP();
		cout << "Количество страниц в книге: " << pages << endl;
		put_sales();
	}
};

class Tape : public Publication, sales
{
private:
	float b_time;
public:
	void getdata()
	{
		getdataP();
		cout << "Введиите длительность книги в минутах: " << endl;
		cin >> b_time;
		get_sales();
	}

	void putdata()
	{
		putdataP();
		cout << "Длительность книги в минутах: " << b_time;
		put_sales();
	}
};


int main()
{
	setlocale(LC_ALL, "ru_Ru");
	Book book;
	book.getdata();
	book.putdata();

	Tape tape;
	tape.getdata();
	tape.putdata();

}