
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;
/**
*@brief Считывает значиния с клавиатуры с проверкой ввода
*@return возвращает значение, если оно правильное , иначе завершает программу
*/
double getValue();

/**
 *@brief Заполняет двумерный массив случайными значениями.
 *@param array Указатель на двумерный массив.
 *@param rows Количество строк в массиве.
 *@param cols Количество столбцов в массиве.
 */
void fillArrayRandomly(int** array, const int rows, const int cols);

/**
 * brief  replaceMultipleOfThreeWithZero заменяет первый найденный элемент в каждом столбце массива,
 * который кратен трем, на ноль.
 * @param array Двумерный массив, в котором производятся замены.
 * @param rows Количество строк в массиве.
 * @param cols Количество столбцов в массиве.
 */
void replaceMultipleOfThreeWithZero(int** array, const int rows, const int cols);


/**
 * brief  deleteRowsWhereSecondIsGreaterThanPenultimate удаляет строки из двумерного массива, в которых
 * значение второго элемента больше или равно значению предпоследнего элемента.
 * @param array Двумерный массив, из которого удаляются строки.
 * @param rows Количество строк в массиве. Послле выполнения функции это значение будет изменено на новое количество строк.
 * @param cols Количество столбцов в массиве.
 */
void deleteRowsWhereSecondIsGreaterThanPenultimate(int** array, const int& rows, const int cols);

/**
*brief Выводит двумерный массив на экран.
*@param  array Указатель на двумерный массив, в котором нужно заменить нулевые элементы.
*@param rows Количество строк в массиве.
*@param cols Количество столбцов в массиве
*/
void printArray(int** array, const int rows, const int cols);

/**
 * @brief Создает новый двумерный массив с заданным количеством строк и столбцов.
 * @param rows Количество строк в новом массиве.
 * @param columns Количество столбцов в новом массиве.
 * @return Указатель на новый двумерный массив типа int.
 */
int** getNewArray(const int rows, const int columns);

/**
 * @brief Создает копию существующего двумерного массива с заданным количеством строк и столбцов.
 * @param arr Указатель на существующий двумерный массив типа int, который нужно скопировать.
 * @param rows Количество строк в существующем массиве.
 * @param columns Количество столбцов в существующем массиве.
 * @return Указатель на новую копию двумерного массива типа int.
 */
int** copyArray(int** arr, const int rows, const int columns);

/**
 * Освобождает память, выделенную под двумерный массив типа int.
 * @param arr Указатель на двумерный массив типа int, который нужно освободить.
 * @param rows Количество строк в двумерном массиве.
 */
void deleteArray(int** arr, const int rows);

/**
 * @brief проверяет, является ли переданное значение положительным.
 * @param value значение, которое требуется проверить на положительность
 * @paramdimension: const string& - строковое представление измерения, связанного с проверяемым значением
 */
void checkPositive(int value, const string& dimension);

/**
*brief Точка входа в программу
*return 0
*/
int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(0));

    cout << "Введите количество строк: ";
    int max_rows = getValue();
    cout << "Введите количество столбцов: ";
    int max_cols = getValue();
    checkPositive(max_rows, "строк");
    checkPositive(max_cols, "столбцов");

            int** array = getNewArray(max_rows, max_cols);
    fillArrayRandomly(array, max_rows, max_cols);

    cout << "Случайно заполненный массив:" << endl;
    printArray(array, max_rows, max_cols);

    int** secondArr = copyArray(array, max_rows, max_cols);
    replaceMultipleOfThreeWithZero(secondArr, max_rows, max_cols);

    cout << "\nМассив после замены элементов, кратных трем, на ноль:" << endl;
    printArray(secondArr, max_rows, max_cols);

    deleteArray(secondArr, max_rows);

    int newcols = max_cols;
    int** arr3 = copyArray(array, max_rows, newcols);
    deleteRowsWhereSecondIsGreaterThanPenultimate(arr3, max_rows, newcols);

    cout << "\nМассив после удаления строк, в которых второй элемент больше предпоследнего:" << endl;
    printArray(arr3, max_rows, newcols);

    deleteArray(arr3, max_rows);
    deleteArray(array, max_rows);

    return 0;
}
void fillArrayRandomly(int** array, int rows, int cols) {
    for (size_t i = 0; i < rows; ++i)
    {
        for (size_t j = 0; j < cols; ++j)
        {
            array[i][j] = rand() - RAND_MAX / 2;
        }
    }
}

void replaceMultipleOfThreeWithZero(int** array, int rows, int cols)
{
    for (size_t j = 0; j < cols; ++j)
    {
        for (size_t i = 0; i < rows; ++i)
        {
            if (array[i][j] % 3 == 0)
            {
                array[i][j] = 0;
                break; // Заменяем только первый элемент кратный трем
            }
        }
    }
}

void deleteRowsWhereSecondIsGreaterThanPenultimate(int** array, int& rows, int cols) {
    int writeIndex = 0;

    for (size_t i = 0; i < rows; ++i)
    {
        if (array[i][1] <= array[i][cols - 2])
        {
            if (i != writeIndex)
            {
                for (size_t j = 0; j < cols; ++j)
                {
                    array[writeIndex][j] = array[i][j];
                }
            }
            writeIndex++;
        }
    }

    rows = writeIndex;
}

void printArray(int** array, int rows, int cols)
{
    for (size_t i = 0; i < rows; ++i)
    {
        for (size_t j = 0; j < cols; ++j)
        {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
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

int** getNewArray(const int max_rows, const int max_cols)
{
    int** array = new int* [max_rows];
    for (size_t i = 0; i < max_rows; ++i)
    {
        array[i] = new int[max_cols];
    }
    return array;
}

int** copyArray(int** arr, const int rows, const int columns)
{
    int** resultArray = getNewArray(rows, columns);
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            resultArray[i][j] = arr[i][j];
        }
    }
    return resultArray;
}

void deleteArray(int** arr, const int rows)
{
    for (size_t i = 0; i < rows; ++i)
    {
        delete[] arr[i];
    }
    delete[] arr;
}

void checkPositive(int value, const string& dimension) 
{
    if (value <= 0) 
    {
        cout << "Введите положительное количество " << dimension << endl;
    }
}