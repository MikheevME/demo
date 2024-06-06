#include <iostream>

using namespace std;

/**
*@brief Считывает значиния с клавиатуры с проверкой ввода
*@return возвращает значение, если оно правильное , иначе завершает программу
*/
double getValue();

/**
* @brief проверяет что введенные данные положительные
* @param lengthCm длина в см
*/
void isPositive(const double lengthCm);

/**
* @brief Конвертирует длину из сантиметров в дюймы
* @param lengthCm Длина в сантиметрах, которую необходимо конвертировать
* @return Длина в дюймах после конвертации
*/
double convertToInches(const double lengthCm);

/**
* @brief точка входа в программу
* return 0
*/
int main() 
{
    setlocale(LC_ALL, "Russian");
    cout << "Введите длину в сантиметрах: ";
    double lengthCm = getValue();
    isPositive(lengthCm);
    double lengthInches = convertToInches(lengthCm);

  

    cout << "Длина в дюймах: " << lengthInches << endl;

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

void isPositive(const double lengthCm)
{
    if (lengthCm<= 0)
    {
        cout << "Введено отрицательное число " << endl;
        abort();
    }
}

double convertToInches(const double lengthCm)
{
    return lengthCm / 2.54; // 1 дюйм = 2.54 см
}
