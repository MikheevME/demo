#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

/**
 * @brief оператор выбоа способа заполнения массива
 * @param RANDOM = 0 автоматическое заполнение
 * @param MANUALLY =1 ручное заполнение
 */
enum SELECT
{
    RANDOM = 0,
    MANUALLY = 1
};

/**
 * @brief проверяет размер массива
 * @param n - размер массива
 */
void checkN(const int n);

/**
 * @brief считывает размер массива
 * @return размер массива в беззнаковом типе данных
 */
size_t getSize();

/**
 * @brief считывает значение типа int
 * @return считанное значение целочисленное
 */
int getNumber();

/**
 * @brief вывод массива на экран
 * @param arr - массив
 * @param n - размер массива
 */
void printArray(const int* arr, const int n);

/**
 * @brief заполнение массива автоматически случайнвми числами в заданном диапазоне
 * @param arr - массив
 * @param n - размер массива
 * @param min - минимальное значение диапазона значений элементов массива
 * @param max - максимальное значение диапазона значений элементов массива
 */
void fillArrayRandom(int* arr, const int n, const int min, const int max);

/**
 * @brief проверяет диапазон
 * @param min - минимальное значение диапазона значений элементов массива
 * @param max - максимальное значение диапазона значений элементов массива
 */
void checkRange(const int min, const int max);

/**
 * @brief находит произведение чётных элементов, значение которых меньше 5
 * @param arr  массив
 * @param n Количество элементов в массиве
 *  @return Произведение всех четных элементов массива, значения которых по модулю меньше 5
 */
int productOfEvenElementsBelow5(const int* arr, const int n);

/**
 * @brief Функция подсчитывает количество нечетных элементов целочисленного массива, значения которых по модулю больше заданного значения A.
 * @param arr  массив
 * @param n Количество элементов в массиве
 * @param a Заданное значение
 * @return Количество нечетных элементов массива, значения которых по модулю больше значения a.
 */
int countOddElementsAboveA(const int* arr, const int n, const int a);

/**
* @brief Проходит по всем элементам массива  Проверяет, является ли текущий элемент нечетным и кратным . Если условие выполняется, умножает значение элемента на его индекс
* @param arr  Указатель на массив целых чисел
* @param n  Количество элементов в массиве
*/
void multiplyOddMultiplesOf3ByIndex(const int* arr, const int n);


/**
 * @brief заполнение массива вручную
 * @param arr - массив
 * @param n - размер массива
 * @param min - минимальное значение диапазона значений элементов массива
 * @param max - максимальное значение диапазона значений элементов массива
 */
void fillArray(const int* arr, const int n, const int min, const int max);



/**
* @brief точка входа в программу
* @return 0 - если программма выполнена корректно, инече -1
*/
int main()
{

    setlocale(LC_ALL, "Russian");
    int n = getSize();
    checkN(n);
    int* arr = new int[n];

    cout << "Введите минимальное и максимальное значение диапазона: ";
    int minValue = getNumber();
    int maxValue = getNumber();
    checkRange(minValue, maxValue);

    cout << "Введите выбор для заполнения массива: " << endl
        << RANDOM << " Для случайного заполнения" << endl
        << MANUALLY << "Для ручного заполнения" << endl;

    int choice = getNumber();

    switch ((enum SELECT)choice)
    {
    case RANDOM:
        fillArrayRandom(arr, n, minValue, maxValue);
        break;
    case MANUALLY:
        fillArray(arr, n, minValue, maxValue);
        break;
    default:
        cout << "Ваш выбор неверен" << endl;
        return -1;
        break;
    }

    cout << "Элементы массива:" << endl;
    printArray(arr, n);

    // Вызов функций
    cout << "значения элементов  по модулю меньше 5:  " << productOfEvenElementsBelow5(arr,n) << endl;

    int a = getNumber();
    cout << "Введите значение  a: ";
    cout << "Количество нечётных элементов до  " << a << ": " << countOddElementsAboveA(arr,n,a) << endl;

    multiplyOddMultiplesOf3ByIndex(arr, n);

    cout << "Измененный массив: ";
      
    printArray(arr, n);
   
    delete[] arr;

    return 0;
}

void checkN(const int n)
{
    if (n <= 0)
    {
        cout << "Неправильный размер массива" << endl;
        abort();
    }
}

size_t getSize()
{
    cout << "Введите размер массива: ";
    int n;
    cin >> n;
    checkN(n);
    return (size_t)n;
}

int getNumber()
{
    int number;
    cin >> number;
    if (cin.fail())
    {
        cout << "Неправильный ввод данных";
        abort();
    }
    return number;
}

void printArray(const int* arr, const int n)
{
    for (size_t i = 0; i < n; i++)
    {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }
}

void fillArrayRandom(const int* arr, const int n, const int min, const int max)
{
    srand(time(0));
    for (size_t i = 0; i < n; i++)
    {
        arr[i] = rand() % (max - min) + min;
    }
}

void checkRange(const int min, const int max)
{
    if (min > max)
    {
        cout << "Введен неправильный диапазон" << endl;
        abort();
    }
}

int productOfEvenElementsBelow5(const int* arr, const int n) 
{
    int product = 1;
    for (size_t i = 0; i < n; i++) {
        if (abs(arr[i]) < 5 && arr[i] % 2 == 0) {
            product *= arr[i];
        }
    }
    return product;
}

int countOddElementsAboveA(const int* arr, const int n, const int a) 
{
    int count = 0;
    for (size_t i = 0; i < n; i++) {
        if (abs(arr[i]) > a && arr[i] % 2 != 0) {
            count++;
        }
    }
    return count;
}


void multiplyOddMultiplesOf3ByIndex(const int* arr, const int n) 
{
    for (size_t i = 0; i < n; i++) 
    {
        if (arr[i] % 2 != 0 && arr[i] % 3 == 0) 
        {
            arr[i] *= i;
        }
    }
}




void fillArray(int* arr, const int n, const int min, const int max)
{
    for (size_t i = 0; i < n; i++)
    {
        cout << "Введите значение для arr[" << i << "]: ";
        arr[i] = getNumber();
        if (arr[i] < min || arr[i] > max)
        {
            cout << "Значение вне диапазона" << endl;
            i--;
        }
    }
}
