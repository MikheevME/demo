#include <iostream>
#include <cmath>
#include <cstdlib> 

using namespace std;

/**
*@brief Считывает значиния с клавиатуры с проверкой ввода
*@return возвращает значение, если оно правильное , иначе завершает программу
*/
double getValue();

/**
* @brief проверяет что введенные данные положительные
* @param x вводимое число  
*/
void isPositive(const double x);

/**
* @brief рассчитывает значение функций от х
* @param sinValue значение синуса
* @param cosValue значение косинуса
* @param LnValue значечние логарифма
*/
void calculate(const double x);

/**
* @brief сравнивает значение и определяет наибольшее
* @param a первое значение
* @param b второе значение
* return возвращает наибольшее значение
*/
double max(const double a, const  double b);

/**
* @brief сравнивает значение и определяет наименьшее
* @param a первое значение
* @param b второе значение
* return возвращает наименьшее значение
*/
double min(const double a, const double b);

/**
* @brief точка входа в программу
* return 0
*/
int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Введите x: ";
    double x = getValue();
    isPositive(x);
    calculate(x);

    cout << "Наибольшее значение : " << max(sin(x), max(cos(x), log(x))) << endl;
    cout << "Наименьшее значение : " << min(sin(x), min(cos(x), log(x))) << endl;
    return 0;
}

double getValue()
{
    double value;
    cin >> value;
    if (cin.fail())
    {
        cout << "Некорректное значение" << endl;
        abort();
    }
    return value;
}

void isPositive(const double x)
{
    if (x <= 0)
    {
        cout << "число  не может быть меньше или равно 0" << endl;
        abort();
    }
}

void calculate(const double x)
{
    double sinValue = sin(x);
    double cosValue = cos(x);
    double logValue = log(x);

    cout << "Синус(" << x << ") = " << sinValue << endl;
    cout << "Косинус(" << x << ") = " << cosValue << endl;
    cout << "Натуральный логарифм(" << x << ") = " << logValue << endl;
}

double max(const double a, const double b)
{
    if (a > b)
        return a;
    return b;
}

double min(const double a, const double b)
{
    if (a < b)
        return a;
    return b;
}
