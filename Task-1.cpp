#include <iostream>
#include <cmath>
using namespace std;

/**
* @brief функция для вычисления значения переменной a по заданным константам.
* @param x значение переменной x.
* @param y значение переменной y.
* @param z значение переменной z.
* @return результат вычисления переменной a.
*/

double calculatea(double x, double y, double z);

/**
* @brief функция для вычисления значения переменной b по заданным константам.
* @param x значение переменной x.
* @param y значение переменной y.
* @param z значение переменной z.
* @return результат вычисления переменной b.
*/

double calculateb(double x, double y, double z);
/**
* @brief получает значение с клавиатуры.
* @return вывод значение переменных рассчитанных по формуле.
*/

int main()
{
   const double x = 0.61;
   const double y = 0.9;
   const double z = 0.3;



cout << "x = " << x << endl;
cout << "y = " << y << endl;
cout << "z = " << z << endl;
cout << "a = " << calculatea(x, y, z) << endl;
cout << "b = " << calculateb(x, y, z) << endl;

return 0;
}

double calculatea(double x, double y, double z)
{
return (pow(z,2 * x) + pow(y,-x) * cos(z + y) * x)/ (x + 1);
}

double calculateb(double x, double y, double z)
{
return (sqrt(pow(x,2) + y) - pow(y,2) * sin(3 * ((x + z)/(x))));
}
