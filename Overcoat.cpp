// Overcoat.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Создать класс Overcoat (Верхняя одежда) реализовать перегруженные операторы
//проверка на равенство обьектов (опрерация ==)
// операция присваивания одного обьекта в другой (операция =)
// сравнение двух чисел (операция >)

#include <iostream>
using namespace std;
class Overcoat
{
private:
	int price_of_clothes; // поле цена одежды
	string type_of_clothing; // поле тип одежды

public:

	Overcoat(int pprice_of_clothes, string ptype_of_clothing) // переприсваивание
		:price_of_clothes{ pprice_of_clothes }, type_of_clothing{ ptype_of_clothing }{}
	//Overcoat() {}
	Overcoat() :Overcoat(0, "пальто") {
		cout << "\nработает конструктор по умолчанию\n ";
	} // Конструктор по умолчанию

	//Overcoat(const Overcoat& object) // Конструктор копирования
	//{
	//	cout << "\nСработал Конструктор копирования\n";
	//}

	// Перегрузка оператора равенство == 
	// для поля вещественное число price_of_clothes
	friend bool operator ==(const Overcoat pprice_of_clothes1,
		const Overcoat pprice_of_clothes2)
	{
		cout << "Перегрузка оператора равенство ==" << "\t" << endl;
		return pprice_of_clothes1.price_of_clothes == pprice_of_clothes2.price_of_clothes;

	}
	// Перегрузка оператора больше >
	// для поля вещественное число price_of_clothes
	friend bool operator >(const Overcoat pprice_of_clothes1,
		const Overcoat pprice_of_clothes2)
	{
		cout << "Перегрузка оператора больше >" << "\t" << endl;
		return pprice_of_clothes1.price_of_clothes > pprice_of_clothes2.price_of_clothes;

	}
	//// Перегруженное копирование обьекта для двух полей
	Overcoat operator=(const Overcoat& other)
	{
		this->type_of_clothing = other.type_of_clothing;
		this->price_of_clothes = other.price_of_clothes;
		cout << "Перегрузка оператора копирования = " << "\t" << this << endl;
		return  Overcoat();
	}
	// функция вывода на экран
	void display() const
	{
		cout << endl;
		cout << "(" << type_of_clothing << " -- " << price_of_clothes << ")";
		cout << endl;
	}
	~Overcoat() {} // Деструктор
};


int main()
{
	system("chcp 1251");

	cout << "Программа сравнения цены и типов одежды\n";
	Overcoat one(11, "пальто");
	Overcoat two(22, "куртка");
	one.display();
	two.display();
	if (one == two)
	{
		cout << "Цена равна" << endl;
	}
	else cout << "Цена не равна" << endl;
	Overcoat tree;
	tree.display();
	tree = two;
	tree.display();
	Overcoat four(100, "пуховик");
	four.display();
	four = one;
	four.display();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.