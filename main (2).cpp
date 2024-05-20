#include <iostream>
#include <cmath>
#include <stdlib.h> 

using namespace std;

/*
*@brief Считывает значиния с клавиатуры с проверкой ввода
*@return возвращает значение, если оно правильное , иначе завершает программу
*/
double getValue();

/*
 * @brief проверяет возможность вычисления натурального логарифма для заданного числа и выводит результат на экран.
 * @param x - число, для которого нужно произвести вычисление натурального логарифма
 * @return true, если натуральный логарифм для числа x существует и был успешно вычислен, false в противном случае
 */
bool checkLnInput(double x);

/*
 *  @brief вычисляет натуральный логарифм для заданного числа x и выводит результат на экран.
 * @param x - число, для которого нужно произвести вычисление натурального логарифма
 */
void processLnInput(double x);

/*
 * @brief проверяет, существует ли значение синуса для заданного числа x.
 * Если значение синуса существует, то функция выводит его на экран в формате "sin(x) = значение"
 * Если значение синуса не существует (например, при делении на 0), то функция выводит сообщение о том, что значение не существует
 * @param x - число, для которого необходимо проверить существование синуса
 * @return true, если значение синуса существует и было выведено на экран; false, если значение синуса не существует
 */
bool checkAndPrintSin(double x);

/*
 * @brief проверяет, существует ли значение синуса для заданного числа x.
 * Если значение косинуса существует, то функция выводит его на экран в формате "cos(x) = значение"
 * Если значение косинуса не существует (например, при делении на 0), то функция выводит сообщение о том, что значение не существует
 * @param x - число, для которого необходимо проверить существование синуса
 * @return true, если значение косинуса существует и было выведено на экран; false, если значение косинуса не существует
 */
bool checkAndPrintCos(double x);

/*
* @brief проверяет, существует ли значение натурального логарифма для заданного числа x.
Если значение натурального логарифма существует, то функция обрабатывает входной аргумент и выводит результат на экран
в формате "ln(x) = значение".
Если значение натурального логарифма не существует(например, при попытке вычисления для отрицательных чисел),
то функция выводит сообщение о том, что значение не существует.
* @param x - число, для которого необходимо проверить существование натурального логарифма
* @return true, если значение натурального логарифма существует, было обработано и выведено на экран; false, если значение
натурального логарифма не существует
*/
bool checkAndPrintLn(double x);

/*
* @brief вычисляет значения sin(x), cos(x) и log(x) для заданного числа x, сравнивает их между собой
и выводит их на экран в порядке возрастания.Если два значения равны, они выводятся в порядке их следования в условии.
* @param x - число, для которого необходимо вычислить значения тригонометрических функций и натурального логарифма
*/
void printValuesInOrder(double x);

/*
 * @brief  проверяет значения sinExist, cosExist и lnExist. Если для всех трех флагов значение true,
 * она выводит сообщение на экран: "Значения sin, cos, Ln были выведены в порядке возрастания.
 * @param sinExist - флаг, указывающий, было ли выведено значение синуса
 * @param cosExist - флаг, указывающий, было ли выведено значение косинуса
 * @param lnExist - флаг, указывающий, было ли выведено значение натурального логарифма
 */
void checkAndPrintInOrder(bool& sinExist, bool& cosExist, bool& lnExist);

/**
* @brief точка входа в программу
* return 0
*/
int main() 
{
    setlocale(LC_ALL, "Russian");
    cout << "Введите x: ";
    double x = getValue();

    bool sinExist = checkAndPrintSin(x);
    bool cosExist = checkAndPrintCos(x);
    bool lnExist = checkAndPrintLn(x);

    if (sinExist && cosExist && lnExist) 
    {
        checkAndPrintInOrder(sinExist, cosExist, lnExist);
    }
    return 0;
}
void checkAndPrintInOrder(bool& sinExist, bool& cosExist, bool& lnExist) 
{
    if (sinExist && cosExist && lnExist) 
    {
        cout << "Значения sin, cos, Ln были выведены в порядке возрастания." << endl;
    }
}

bool checkAndPrintSin(double x) 
{
    if (sin(x)) 
    {
        cout << "sin(" << x << ") = " << sin(x) << endl;
        return true;
    }
    else 
    {
        cout << "sin(" << x << ") не существует" << endl;
        return false;
    }
}

bool checkAndPrintCos(double x) 
{
    if (cos(x)) 
    {
        cout << "cos(" << x << ") = " << cos(x) << endl;
        return true;
    }
    else 
    {
        cout << "cos(" << x << ") не существует" << endl;
        return false;
    }
}

double getValue() 
{
    double value;
    cin >> value;
    if (cin.fail()) 
    {
        cout << "Некорректное значение" << endl;
        exit(1);
    }
    return value;
}

bool checkLnInput(double x) 
{
    return x > 0;
}

void processLnInput(double x) 
{
    double result = log(x);
    cout << "Ln(" << x << ") = " << result << endl;
}

bool checkAndPrintLn(double x) 
{
    if (checkLnInput(x)) 
    {
        processLnInput(x);
        return true;
    }
    else 
    {
        cout << "Ln(" << x << ") не существует" << endl;
        return false;
    }
}

void printValuesInOrder(double x) 
{
    double sinValue = sin(x);
    double cosValue = cos(x);
    double lnValue = log(x);

    if (sinValue <= cosValue && sinValue <= lnValue) 
    {
        cout << "sin(" << x << ") = " << sinValue << endl;
        if (cosValue <= lnValue) 
        {
            cout << "cos(" << x << ") = " << cosValue << endl;
            cout << "Ln(" << x << ") = " << lnValue << endl;
        }
        else 
        {
            cout << "Ln(" << x << ") = " << lnValue << endl;
            cout << "cos(" << x << ") = " << cosValue << endl;
        }
    }
    else if (cosValue <= sinValue && cosValue <= lnValue) 
    {
        cout << "cos(" << x << ") = " << cosValue << endl;
        if (sinValue <= lnValue) 
        {
            cout << "sin(" << x << ") = " << sinValue << endl;
            cout << "Ln(" << x << ") = " << lnValue << endl;
        }
        else 
        {
            cout << "Ln(" << x << ") = " << lnValue << endl;
            cout << "sin(" << x << ") = " << sinValue << endl;
        }
    }
    else 
    {
        cout << "Ln(" << x << ") = " << lnValue << endl;
        if (sinValue <= cosValue) 
        {
            cout << "sin(" << x << ") = " << sinValue << endl;
            cout << "cos(" << x << ") = " << cosValue << endl;
        }
        else 
        {
            cout << "cos(" << x << ") = " << cosValue << endl;
            cout << "sin(" << x << ") = " << sinValue << endl;
        }
    }
}