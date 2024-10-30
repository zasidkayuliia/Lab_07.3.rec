#include <iostream>
#include <iomanip>
#include <cmath>
#include <Windows.h>
using namespace std;

// Функція для вводу елементів матриці рекурсивно
void InputRow(int** a, const int rowNo, const int colCount, int colNo) {
    cout << "a[" << rowNo << "][" << colNo << "] = ";
    cin >> a[rowNo][colNo];
    if (colNo < colCount - 1)
        InputRow(a, rowNo, colCount, colNo + 1);
}

void InputRows(int** a, const int rowCount, const int colCount, int rowNo) {
    InputRow(a, rowNo, colCount, 0);
    if (rowNo < rowCount - 1)
        InputRows(a, rowCount, colCount, rowNo + 1);
}

// Функція для виведення матриці рекурсивно
void PrintRow(int** a, const int rowNo, const int colCount, int colNo) {
    cout << setw(4) << a[rowNo][colNo];
    if (colNo < colCount - 1)
        PrintRow(a, rowNo, colCount, colNo + 1);
    else
        cout << endl;
}

void PrintRows(int** a, const int rowCount, const int colCount, int rowNo) {
    PrintRow(a, rowNo, colCount, 0);
    if (rowNo < rowCount - 1)
        PrintRows(a, rowCount, colCount, rowNo + 1);
}

// Рекурсивна функція для перевірки, чи є елемент локальним мінімумом
bool IsLocalMin(int** a, const int rowCount, const int colCount, int i, int j) {
    int value = a[i][j];

    // Перевіряємо всіх 8 сусідів (включаючи діагональні)
    for (int di = -1; di <= 1; ++di) {
        for (int dj = -1; dj <= 1; ++dj) {
            int ni = i + di;
            int nj = j + dj;

            // Перевіряємо, чи індекси сусіда знаходяться в межах матриці
            if (ni >= 0 && ni < rowCount && nj >= 0 && nj < colCount) {
                // Якщо знайшли сусіда, меншого за поточний елемент, то не є локальним мінімумом
                if (a[ni][nj] < value) {
                    return false;
                }
            }
        }
    }

    // Якщо жоден з сусідів не менший, то елемент є локальним мінімумом
    return true;
}
// Рекурсивна функція для підрахунку локальних мінімумів у матриці
void CountLocalMin(int** a, const int rowCount, const int colCount, int& count, int i = 0, int j = 0) {
    if (IsLocalMin(a, rowCount, colCount, i, j))
        count++;
    if (j < colCount - 1)
        CountLocalMin(a, rowCount, colCount, count, i, j + 1);
    else if (i < rowCount - 1)
        CountLocalMin(a, rowCount, colCount, count, i + 1, 0);
}

// Рекурсивна функція для підрахунку суми модулів елементів над головною діагоналлю
int SumAboveMainDiag(int** a, const int rowCount, int i = 0, int j = 1) {
    if (i >= rowCount - 1) return 0;
    int sum = abs(a[i][j]);
    if (j < rowCount - 1)
        return sum + SumAboveMainDiag(a, rowCount, i, j + 1);
    else
        return sum + SumAboveMainDiag(a, rowCount, i + 1, i + 2);
}

int main() {
    SetConsoleOutputCP(1251);
    int n;
    cout << "Розмір матриці (n x n):";
    cin >> n;

    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];

    // Введення та виведення матриці
    InputRows(a, n, n, 0);
    PrintRows(a, n, n, 0);

    // Підрахунок локальних мінімумів
    int localMinCount = 0;
    CountLocalMin(a, n, n, localMinCount);
    cout << "Кількість локальних мінімумів:  " << localMinCount << endl;

    // Підрахунок суми модулів над головною діагоналлю
    int sumAboveDiag = SumAboveMainDiag(a, n);
    cout << "Сума модулів елементів вище головної діагоналі:" << sumAboveDiag << endl;

    // Звільнення пам'яті
    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}
