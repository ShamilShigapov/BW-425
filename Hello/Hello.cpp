#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <io.h>
using namespace std;

int GetMin(int numOfArgs, ...)
{
	//va_start - Для старта итераций по списку пемеренных параметров
	//va_end - Вызываем после всего, что бы корректно завершить работу
	//va_arg - вызов для получения параметра из списка (параметров)
	int minVal;
	va_list va;

	va_start(va, numOfArgs);
	minVal = va_arg(va, int);
	int tempVal = 0;
	for (int i = 0; i < numOfArgs - 1; i++)
	{
		tempVal = va_arg(va, int);
		std::cout << tempVal << ' ';
		if (minVal > tempVal)
			minVal = tempVal;
	}
	std::cout << std::endl;
	va_end(va);
	return minVal;
}

//int recMin(int arr[100], int size)
//{
//	int sum = 0;
//	static int pos = 0;
//	int i = size - 1;
//	for (int i = size - 1; i > (size - 10); i--)
//	{
//		sum += arr[i];
//	}
//	int temp = size - 10;
//
//
//	if (min_sum > sum)
//	{
//		min_i = i;
//		min_sum = sum;
//	}
//
//	return min_i;
//
//}

template<class T>
void printMass(T arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (i % 10 == 0) cout << endl;
		std::cout << arr[i] << ' ';
	}
	std::cout << "\n";
}

void swaps(int& x, int& y)
{
	int tmp;
	tmp = x;
	x = y;
	y = tmp;
}

template<class T>
void addMass(T mass[], int size)
{
	for (int i = 0; i < size; i++)
	{
		mass[i] = rand() % 101;
	}
}

int& rmax(int n, int mass[])
{
	int im = 0;
	for (int i = 1; i < n; i++)
	{
		im = mass[im] > mass[i] ? im : i;
	}
	return mass[im];
}

int fib(int n1, int n2, int n)
{
	int result;
	if (n < 1) return 0;
	else if (n >= 1)
	{
		result = n1 + n2;
		if (result > n) return 0;
		cout << result << '\n';
		n1 = n2;
		n2 = result;
		return fib(n1, n2, n);
	}
}

template<class T>
void quickSort(T arr[], int size)
{
	int i{ 0 }, j{ size };
	T temp, p;
	p = arr[size / 2];
	do
	{
		while (arr[i] < p) i++;
		while (arr[j] > p) j--;
		if (i <= j)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	} while (i <= j);
	if (j > 0) quickSort(arr, j);
	if (size > i) quickSort(arr + i, size - i);
}

int binarySearch(int arr[], int Lb, int Rb, int key)
{
	int M;
	while (1)
	{
		M = (Lb + Rb) / 2;
		if (key < arr[M])
			Rb = M - 1;
		else if (key > arr[M])
			Lb = M + 1;
		else
			return M;
		if (Lb > Rb)
			return -1;
	}
}

template<class T>
void addDinMass(T* mass, int size)
{

	for (T* i = mass; i < mass + size; i++)
	{
		*i = rand() % 101;
	}
}

template<class T>
void newDinMass(T* mass, int size)
{
	mass = new T[size];
}

template<class T>
void delDinMass(T* mass)
{
	mass = nullptr;
	delete[] mass;
}

template<class T>
void changeSize(T*& mass, int size, int newSize)
{
	T* tmp = new T[newSize];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = mass[i];
	}
	delDinMass(mass);
	mass = new T[newSize];
	for (int i = 0; i < size; i++)
	{
		mass[i] = tmp[i];
	}
	delDinMass(tmp);
	addDinMass(mass + size, newSize);
}

/*
int myStrlen(char* mass)
{
	int count = 0;
	while (*mass != '\0')
	{
		*mass++;
		count++;
	}
	return count;
}

void myStrcpy(char* mass1, char* mass2)
{
	mass2 = nullptr;
	delete[] mass2;
	mass2 = new char[strlen(mass1)];
	for (int i = 0; i < strlen(mass1); i++)
	{
		mass2[i] = mass1[i];
	}
}

char* myStrcat(char* mass1, const char* mass2)
{
	int len = strlen(mass1) + strlen(mass2);
	char* tmp = new char[len + 1];
	for (int i = 0; i < strlen(mass1); i++)
	{
		tmp[i] = mass1[i];
	}
	for (int i = 0; i < strlen(mass2); i++)
	{
		tmp[strlen(mass1) + i] = mass2[i];
	}
	for (int i = 0; i < strlen(mass2); i++)
	{
		mass1[strlen(tmp) + i] = tmp[i];
	}
	tmp[len] = '\0';
	return tmp;
	/*char* ptr = mass1;
	while (*ptr != '\0')
	{
		ptr++;
	}
	while (*mass2 != '\0')
	{
		*ptr = *mass2;
		ptr++;
		mass2++;
	}
	*ptr = '\0';
	return mass1;
}

int poof(int num)
{
	return 25;
}

int poof2(int num)
{
	return 235;
}

auto poof3()
{
	auto num = 150;
	auto num2 = 20.4;
	return num > num2 ? num : num2;
}

struct phoneBook
{
	char number[15]; //номер телефона с 7
	char name[50]; //ФИО
	char adress[255]; //адрес
};

struct myBirthDay
{
	int day;
	int month;
	int year;
	char monthName[10];
	char chineseYearName[20];
};

struct Test
{
	int c;
	int x;
	int y;
};

struct videoShop
{
	char filmName[100];
	char director[50];
	char genre[30];
	double rating;
	double diskCost;
};

void print(const videoShop& disk)
{
	cout << "Название фильма: " << disk.filmName << endl;
	cout << "Режиссер: " << disk.director << endl;
	cout << "Жанр: " << disk.genre << endl;
	cout << "Рейтинг: " << disk.rating << endl;
	cout << "Стоимость диска: " << disk.diskCost << endl;
}

void findByName(const videoShop* mass, int size)
{
	char key[30];
	cin.getline(key, 30);
	bool flag = false;
	for (int i = 0; i < size; i++)
	{
		if (strstr((mass + i)->filmName, key))
		{
			flag = true;
			print(mass[i]);
		}
	}
	if (!flag)
		cout << "Такого фильма нет!" << endl;
}

void findByGenre(const videoShop* mass, int size)
{
	char key[30];
	cin.getline(key, 30);
	bool flag = false;
	for (int i = 0; i < size; i++)
	{
		if (strstr((mass + i)->genre, key))
		{
			flag = true;
			print(mass[i]);
		}
	}
	if (!flag)
		cout << "Такого фильма нет!" << endl;
}

void findByDirector(const videoShop* mass, int size)
{
	char key[30];
	cin.getline(key, 30);
	bool flag = false;
	for (int i = 0; i < size; i++)
	{
		if (strstr((mass + i)->director, key))
		{
			flag = true;
			print(mass[i]);
		}
	}
	if (!flag)
		cout << "Такого фильма нет!" << endl;
}

void findByTOP(const videoShop* mass, int size)
{
	double top = 0.0;
	int idx;
	for (int i = 0; i < size; i++)
	{
		if ((mass + i)->rating > top)
		{
			top = (mass + i)->rating;
			idx = i;
		}
	}
	print(mass[idx]);
}

void allDisk(const videoShop* mass, int size)
{
	for (int i = 0; i < size; i++)
	{
		print(mass[i]);
		cout << endl;
	}
}

void addDisk(videoShop*& mass, int& size)
{
	videoShop tmp;
	cout << "Добавление фильма: " << endl << endl;
	cout << "Введите название фильма: " << endl;
	cin.getline(tmp.filmName, 100);
	cout << "Введите режиссера: " << endl;
	cin.getline(tmp.director, 100);
	cout << "Введите жанр: " << endl;
	cin.getline(tmp.genre, 50);
	cout << "Введите рейтинг: " << endl;
	cin >> tmp.rating;
	cout << "Введите стоимость диска: " << endl;
	cin >> tmp.diskCost;

	videoShop* tmpArr = new videoShop[size];
	for (int i = 0; i < size; i++)
	{
		tmpArr[i] = mass[i];
	}
	delete[] mass;
	size += 1;
	mass = new videoShop[size];
	for (int i = 0; i < size; i++)
	{
		mass[i] = tmpArr[i];
	}
	mass[size - 1] = tmp;
	delete[] tmpArr;
}

*/

/*
void add_text(string& txt)
{
	cout << "Введите текст стихотворения.\nДля окончания ввода нажмите '~'\n\n";
		getline(cin, txt, '~');
}

string cezar(string& txt)
{
	for (int i = 0; i < txt.length(); i++)
	{
		txt[i] = txt[i] + 3;
	}
	return txt;
}

string _cezarZ(string txt)
{
	string tmp = txt;
	for (int i = 0; i < txt.length(); i++)
	{
		txt[i] = txt[i] - 3;
	}
	return txt;
}

void print(fstream& file)
{
	string txt;
	if (file.is_open())
	{
		while (getline(file, txt))
			cout << txt << endl;
	}
	cout << endl;
}

void print_cezar(fstream& file)
{
	string txt;
	if (file.is_open())
	{
		while (getline(file, txt))
			cout << _cezarZ(txt) << endl;
	}
	cout << endl;
}

*/


int main()
{
	system("chcp 1251 > nul");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	/*int mass[10];
	for (int i = 0; i < 10; i++)
	{
		mass[i] = rand() % 101;
	}
	int* pM = &mass[0]; //можно и так -> pM = mass -> указатель на массив указавыает на первый его элемент (нулевой)
	printMass(mass, 10);
	//std::cout << *pM << ',' << *(pM + 2) << '\n';
	//std::cout << *mass << '\n';

	int tmp = *pM;
	for (int i = 0; i < 10; i++)
	{
		//(i % 2 == 0) ? cout << *(pM + i + 1) << ' ' : cout << *(pM + i - 1) << ' ';
		if (i % 2 == 0)
		{
			tmp = *(pM + i);
			*(pM + i) = *(pM + i + 1);
		}
		else
			*(pM + i) = tmp;
	}
	std::cout << '\n';


	//for (int* i = mass; i < mass + 10; i += 2)
	//{
	//	std::swap(*i, *(i + 1));
	//}
	printMass(mass, 10);
	*/

	/*
	int arr[] = {10,20,30,3};
	int size = 4;
	cout << "nrmax(n,x) = " << rmax(size, arr) << endl;

	rmax(size, arr) = 0;
	for (int i = 1; i < size; i++)
	{
		cout << "arr[" << i << "] = " << arr[i] << ' ';
	} */
	
	/*
	//09.10.24

	//int* ip = new int(5000);
	//cout << *ip;
	//delete ip;
	//
	//int size;
	//cout << "Введите размерность массива ";
	//cin >> size;
	//int* mass = new int[size];
	//addDinMass(mass, size);
	//printMass(mass, size);
	//delete[] mass;

	int size;
	cout << "Введите размерность массива: ";
	cin >> size;

	int* mass = new int[size];
	addDinMass(mass, size);
	printMass(mass, size);
	int newSize;
	cout << "Введите новую размерность массива: ";
	cin >> newSize;
	changeSize(mass, size, newSize);

	printMass(mass, newSize);
	delDinMass(mass);
	*/

	/*
	//11.10.24
	const char* name = "Ибрагим";
	puts(name);
	
	*/

	/*
		//18.10

	const int SIZE = 255;
	char name [SIZE];
	cin.getline(name, SIZE);
	cout << strlen(name);
	int size = 255;
	char* name = new char[size];
	cin.getline(name, size);
	char* str = new char[size];
	//*str = *name; //так нельзя
	cin.getline(str, size);
	cout << myStrlen(name) << ' ' << myStrlen(str) << endl;
	myStrcpy(name, str);
	cout << name << ' ' << str << endl;

	cout << myStrcat(name, str) << endl;
	*/
	
	/*
		//23.10
	int size = 3;
	int** arr = new int* [size];
	int count = 1;

	for (int i = 0; i < size; i++)
	{
		arr[i] = new int[size];
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			arr[i][j] = count;
			count++;
		}
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}

	for (int i = 0; i < size; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;

	cout << &poof << endl;

	int (*Myptr)(int) = &poof;
	cout << (*Myptr)(5) << endl;

	Myptr = poof2;
	cout << (*Myptr)(5) << endl;
	*/

	/*
	//25.10
	//auto noVar = 4.2 - 1.5;
	//auto ptr = &noVar;

	//auto myFunc = poof3();
	//cout << sizeof(myFunc) << " - " << myFunc << endl;

	//decltype(myFunc) x;//создаётся переменная того же типа, что и возвращает myFunc
	//cout << sizeof(myFunc) << " - " << myFunc << endl;

	//int y = 1.2;
	//auto p = y;

	//auto a1 = 0;
	//decltype(a1) a2 = a1;

	//int y = 5;
	//int& point = y;
	//auto x = point;
	//decltype(point) po;
	
	phoneBook me = { "790444112087", "Nuptullin Arman Suleimenovich", "Magadan" };
	cout << "Phone number: " << me.number << endl;
	cout << "Full name client: " << me.name << endl;
	cout << "City client: " << me.adress << endl;

	myBirthDay my = { 25, 8, 1990, "August", "White horse" };
	*/
	
	/*
	//28.10
	//Test test{ 34, 5, 56 };
	//cout << sizeof(test) << ' ' << sizeof(Test) << endl;
	
	int size = 5;
	videoShop* shopArray = new videoShop[size]
	{
		{"В поисках Немо", "Мистер", "Приключение", 4.2, 400},
		{"Оно", "Стивен Кинг", "Ужасы", 4.0, 500},
		{"Гарри Поттер", "Джоан Роулинг", "Фэнтези", 4.8, 600},
		{"Властелин колец", "Питер Джексон", "Фэнтези", 5.0, 900},
		{"Голый пистолет", "Лесли Нильсен", "Комедия", 5.0, 3000}
	};

	//findByName(shopArray, size);
	//findByGenre(shopArray, size);
	allDisk(shopArray, size);
	addDisk(shopArray, size);
	allDisk(shopArray, size);
	*/
	
	/*
		//01.11

		string txt[4];
		fstream file;
		file.open("Poof.txt", ios::in);
		if (file.is_open())
		{
			for (int i = 0; i < 4; i++)
			{
				getline(file, txt[i]);
			}
		}
		else
			cout << "File is not open!" << endl;
		file.close();

		for (int i = 0; i < 4; i++)
		{
			cout << txt[i] << endl;
		}
	*/
	
	/*
	//06.11
	
	_finddata64i32_t my_file_info;
	const char* path = "C:\\Users\\Shalim\\source\\repos\\Hello C++\\Lessons 1\\Hello\\*.txt";

	intptr_t done = _findfirst64i32(path, &my_file_info);

	if (done == -1)
	{
		cout << "File not found!\n";
	}
	else
	{
		int lop = 0;
		while (lop != -1)
		{
			cout << my_file_info.name << endl;
			lop = _findnext64i32(done, &my_file_info);
		}
	}
	_findclose(done);
	
	*/
	
	/*
	fstream file("Stih.txt", ios::out);
	string txt;
	add_text(txt);
	if (file.is_open())
	{
		file << txt;
	}
	file.close();

	file.open("Stih.txt", ios::in);
	if (file.is_open())
	{
		print(file);
	}
	file.close();

	fstream file2("Stih_Cezar.txt", ios::out);
	if (file2.is_open())
	{
		file2 << cezar(txt);
	}
	file2.close();
	
	file2.open("Stih_Cezar.txt", ios::in);
	if (file2.is_open())
	{
		print_cezar(file2);
	}
	file.close();
	
	*/
	
	//20.11
	
	
	
	
	return 0;
}

/*
string Cezar(string txt)
{
    string tmp = txt;
    for (int i = 0; i < txt.length(); i++)
    {
        txt[i] = txt[i] + 3;
    }
    return txt;
}
string _CezarZ(string txt)
{
    string tmp = txt;
    for (int i = 0; i < txt.length(); i++)
    {
        txt[i] = txt[i] - 3;
    }
    return txt;
}
void Print(fstream& file)
{
    string txt;
    if (file.is_open())
    {
        while (getline(file, txt))
            cout << _CezarZ(txt);
    }
}
void OutFile(fstream& file, string txt)
{
    file.open(txt);
    string text;
    if (file.is_open())
    {
        cout << "Введите текст который надо зашифровать.\n"
<<"Конец ввода наступит если ввести \"~\"" 
<< endl << endl;
        getline(cin, text, '~');
        file << text;
    }
}
*/