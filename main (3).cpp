#include <iostream>
#include <cmath>
#include <limits>
using namespace std;
/*
*@brief Считывает значиния с клавиатуры с проверкой ввода
*@return возвращает значение, если оно правильное , иначе завершает программу
*/
double getValue();

/*
*@brief  Функция для вычисления значения функции y = 3ln^2x+6lnx−5 
*@return 3ln^2x+6lnx−5 
*/
double calculateFunction(double x);

/*
*@brief  Функция для проверки, что шаг положительный
*@param step шаг с которым идёт постороение графика
*@return step
*/
double getPositiveStep();


/*
*@brief  точка хода в программу
*@return 0
*/
int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "Введите начальное значение x: ";
    double startX = getValue();

    cout << "Введите конечное значение x: ";
    double endX = getValue();

    if (startX > endX)
    {
        cout << "Ошибка: xstart должно быть меньше, чем xend" << endl;
        return 1;
    }

    cout << "Введите шаг: ";
    double step = getValue();
    double getPositiveStep();



    cout << "x | y" << endl;
    cout << "--------" << endl;


    for (double x = startX; x < endX + step; x += step)
    {
        if (fabs(3 * pow(log(x), 2) + 6 * log(x) - 5) < -numeric_limits<double>::epsilon())
        {
            cout << "Деление на ноль! Решение невозможно для x = " << x << endl;
        }
        else
        {
            double y = calculateFunction(x);
            cout << x << " | " << y << endl;
        }
    }

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

double calculateFunction(double x)
{
   double S = 3 * pow(log(x), 2) + 6 * log(x) - 5;
   return  S;
}

double getPositiveStep()
{
    double step;
    do {
        cout << "Введите шаг: ";
        step = getValue();
        if (step <= 0)
        {
            cout << "Ошибка. Шаг должен быть положительным. Повторите ввод." << endl;
        }
    } while (step <= 0);
    return step;
}