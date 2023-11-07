#include <iostream>
#include <iomanip>
#include <time.h>
#include<windows.h>
using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Input(int** a, const int rowCount, const int colCount);
void Print(int** a, const int rowCount, const int colCount);
int Zero(int** a, const int rowCount, const int colCount);
void SortSum(int** a, const int rowCount, const int colCount);
int SumPositiveElements(int* row, const int colCount);
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand((unsigned)time(NULL));
    int Low = -17;
    int High = 15;
    int rowCount, colCount;
    cout << "k = "; cin >> rowCount;
    cout << "n = "; cin >> colCount;
    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    Input(a, rowCount, colCount);
    Print(a, rowCount, colCount);

    int CountWithoutZero = Zero(a, rowCount, colCount);
    cout << "Stovpci bez 0: " << CountWithoutZero << endl;

    cout << endl;
    SortSum(a, rowCount, colCount);
    Print(a, rowCount, colCount);

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;
    return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High)
{
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Input(int** a, const int rowCount, const int colCount)
{
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
        {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
        cout << endl;
    }
}

void Print(int** a, const int rowCount, const int colCount)
{
    cout << endl;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << a[i][j];
        cout << " Suma dodatnih parnih elementiv: " << SumPositiveElements(a[i], colCount) << endl;
    }
    cout << endl;
}

int Zero(int** a, const int rowCount, const int colCount)
{
    int result = 0;
    for (int j = 0; j < colCount; j++)
    {
        bool hasZero = false;
        for (int i = 0; i < rowCount; i++)
        {
            if (a[i][j] == 0)
            {
                hasZero = true;
                break;
            }
        }
        if (!hasZero)
        {
            result++;
        }
    }
    return result;
}

int SumPositiveElements(int* row, const int colCount)
{
    int sum = 0;
    for (int j = 0; j < colCount; j++)
    {
        if (row[j] > 0 && row[j] % 2 == 0)
        {
            sum += row[j];
        }
    }
    return sum;
}

void SortSum(int** a, const int rowCount, const int colCount)
{
    int* rowSums = new int[rowCount];

    for (int i = 0; i < rowCount; i++)
    {
        int sum = 0;
        for (int j = 0; j < colCount; j++)
        {
            if (a[i][j] > 0 && a[i][j] % 2 == 0)
            {
                sum += a[i][j];
            }
        }
        rowSums[i] = sum;
    }

    for (int i = 0; i < rowCount - 1; i++)
    {
        for (int j = 0; j < rowCount - i - 1; j++)
        {
            if (rowSums[j] < rowSums[j + 1]) 
            {
                int* tempRow = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tempRow;

                int tempSum = rowSums[j];
                rowSums[j] = rowSums[j + 1];
                rowSums[j + 1] = tempSum;
            }
        }
    }

    delete[] rowSums;
}

