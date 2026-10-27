#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include "ArrayFunc.h"

using namespace std;

int main() {
    // Встановлення кодування UTF-8 для коректного відображення української мови в консолі
    system("chcp 65001 > nul");

    srand((unsigned)time(NULL)); // ініціалізація генератора випадкових чисел

    int n;
    cout << "n = ";
    cin >> n;
    if (n <= 0)
    {
        cerr << "Кількість елементів має бути додатною" << endl;
        return 1;
    }

    double* a = new double[n]; // Виправлено: оголошення динамічного масиву
    const double Low = -10;
    const double High = 10;

    cout << fixed << setprecision(2);

    Create(a, n, Low, High, 0);
    cout << "Початковий масив:" << endl;
    Print(a, n, 0);

    // 1.1. Добуток додатних елементів
    if (CountPositive(a, n, 0) > 0)
        cout << "Добуток додатних елементів = " << ProductPositive(a, n, 0) << endl;
    else
        cout << "Додатних елементів немає" << endl;

    // 1.2. Сума елементів, розташованих до мінімального елемента
    int imin = IndexMin(a, n, 1, 0);
    cout << "Мінімальний елемент a[" << imin << "] = " << a[imin] << endl;
    cout << "Сума елементів до мінімального = " << SumBefore(a, imin, 0) << endl;

    // 2. Впорядкування за зростанням окремо елементів на парних та непарних місцях
    SortStep(a, n, 0);
    SortStep(a, n, 1);
    cout << "Масив після впорядкування:" << endl;
    Print(a, n, 0);

    delete[] a; // звільнили пам'ять
    return 0;
}