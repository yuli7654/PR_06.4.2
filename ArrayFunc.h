#pragma once
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <utility>

// Формує елементи масиву випадковими числами з діапазону [Low; High]
inline void Create(double* a, const int size, const double Low, const double High, int i)
{
    a[i] = std::round((Low + (High - Low) * rand() / RAND_MAX) * 100) / 100;
    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}

// Виводить елементи масиву в рядок
inline void Print(const double* a, const int size, int i)
{
    std::cout << std::setw(8) << a[i];
    if (i < size - 1)
        Print(a, size, i + 1);
    else
        std::cout << std::endl;
}

// Повертає кількість додатних елементів масиву
inline int CountPositive(const double* a, const int size, int i)
{
    if (i < size)
    {
        if (a[i] > 0)
            return 1 + CountPositive(a, size, i + 1);
        else
            return CountPositive(a, size, i + 1);
    }
    else
        return 0;
}

// Повертає добуток додатних елементів масиву
// (якщо додатних елементів немає, повертає 1 - нейтральний елемент добутку)
inline double ProductPositive(const double* a, const int size, int i)
{
    if (i < size)
    {
        if (a[i] > 0)
            return a[i] * ProductPositive(a, size, i + 1);
        else
            return ProductPositive(a, size, i + 1);
    }
    else
        return 1;
}

// Повертає індекс першого мінімального елемента масиву
// (початкові значення: i = 1, imin = 0)
inline int IndexMin(const double* a, const int size, int i, int imin)
{
    if (i < size)
    {
        if (a[i] < a[imin])
            imin = i;
        return IndexMin(a, size, i + 1, imin);
    }
    else
        return imin;
}

// Повертає суму елементів масиву, розташованих до елемента з індексом index
inline double SumBefore(const double* a, const int index, int i)
{
    if (i < index)
        return a[i] + SumBefore(a, index, i + 1);
    else
        return 0;
}

// Повертає індекс мінімального серед елементів з індексами j, j+2, j+4, ...
// (imin - індекс поточного мінімального елемента)
inline int IndexMinStep(const double* a, const int size, int j, int imin)
{
    if (j < size)
    {
        if (a[j] < a[imin])
            imin = j;
        return IndexMinStep(a, size, j + 2, imin);
    }
    else
        return imin;
}

// Впорядковує за зростанням (метод вибору) елементи з індексами
// i, i+2, i+4, ... ; решту елементів не змінює
// (початкове значення i = start)
inline void SortStep(double* a, const int size, int i)
{
    if (i < size - 2)
    {
        int imin = IndexMinStep(a, size, i + 2, i);
        std::swap(a[i], a[imin]);
        SortStep(a, size, i + 2);
    }
}