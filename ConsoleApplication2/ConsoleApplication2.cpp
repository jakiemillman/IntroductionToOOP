// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

class Fraction
{
    int numerator;
    int denominator;
    int integer_from_fruction;

public:
    int get_numerator()
    {
        return numerator;
    }
    int get_denominator()
    {
        return denominator;
            
    }
    int integer_from_fruction()
    {
        return integer_from_fruction;
    }
    void set_numerator(int numerator)
    {
        this->numerator = numerator;
    }
    void set_denominator
    (int denominator)
    {
        this->denominator
            = denominator;
    }
    void integer_from_fruction(int integer_from_fruction)
    {
        this->integer_from_fruction = integer_from_fruction;
    }
    //constructor
   
};

int main()
{
    setlocale(LC_ALL, "rus");
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
