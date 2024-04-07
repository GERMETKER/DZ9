#include <iostream>
#include <random>
#include <Windows.h>
void Ex1();
void Ex2();
void RecFunk(int arr[], int size);
template <typename ads>
ads Funk(ads arr1[5], ads arr2[5][5], ads arr3[5][5][5], ads numb1, ads numb2, ads numb3);
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));
    int choose;
    std::cout << "Выберите номер задания, которое хотите проверить\n";
    std::cin >> choose;
    if (choose == 1)
    {
        Ex1();
    }
    else if (choose == 2)
    {
        Ex2();
    }
    return 0;
}
void Ex1()
{
    const int size = 100;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = 1 + rand() % 100;
    }
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
    RecFunk(arr, size);
}
void RecFunk(int arr[], int size)
{
    int minsum = 0;
    int startmin = 0;
    for (int i = 0; i + 9 < size; i++)
    {
        if (i == 0)
        {
            minsum = arr[i] + arr[i + 1] + arr[i + 2] + arr[i + 3] + arr[i + 4] + arr[i + 5] + arr[i + 6] + arr[i + 7] + arr[i + 8] + arr[i + 9];
            startmin = i + 1;
        }
        else
        {
            if (arr[i] + arr[i + 1] + arr[i + 2] + arr[i + 3] + arr[i + 4] + arr[i + 5] + arr[i + 6] + arr[i + 7] + arr[i + 8] + arr[i + 9] < minsum)
            {
                minsum = arr[i] + arr[i + 1] + arr[i + 2] + arr[i + 3] + arr[i + 4] + arr[i + 5] + arr[i + 6] + arr[i + 7] + arr[i + 8] + arr[i + 9];
                startmin = i + 1;
            }
        }
    }
    std::cout << "Начало минимальной суммы: " << startmin << "\n";
}
void Ex2()
{
    int arr1[5];
    int arr2[5][5];
    int arr3[5][5][5];
    for (int i = 0; i < 5; i++)
    {
        arr1[i] = rand() % 100;
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            arr2[i][j] = rand() % 100;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int z = 0; z < 5; z++)
            {
                arr3[i][j][z] = rand() % 100;
            }
        }
    }
    
    // вывод массивов для удобства
    for (int i = 0; i < 5; i++)
    {
        std::cout << arr1[i] << " ";
    }
    std::cout << "\n\n=========================================\n";
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            std::cout << arr2[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n\n=========================================\n";
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int z = 0; z < 5; z++)
            {
                std::cout << arr3[i][j][z] << " ";
            }
            std::cout << "\n";
        }
        std::cout << "-------------------\n";
    }
    int numb1 = rand() % 100, numb2 = rand() % 100, numb3 = rand() % 100;
    std::cout << numb1 << "\n" << numb2 << "\n" << numb3 << "\n\n";
    Funk(arr1, arr2, arr3, numb1, numb2, numb3);
}
template <typename ads>
ads Funk(ads arr1[5], ads arr2[5][5], ads arr3[5][5][5], ads numb1, ads numb2, ads numb3)
{
    int maxarr1 = 0;
    int maxarr2 = 0;
    int maxarr3 = 0;
    int maxin2 = 0;
    int maxin3 = 0;
    maxarr1 = arr1[0];
    for (int i = 0; i < 5; i++)
    {
        if (arr1[i] > maxarr1)
        {
            maxarr1 = arr1[i];
        }
    }
    maxarr2 = arr2[0][0];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (arr2[i][j] > maxarr2)
            {
                maxarr2 = arr2[i][j];
            }
        }
    }
    maxarr3 = arr3[0][0][0];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int z = 0; z < 5; z++)
            {
                if (arr3[i][j][z] > maxarr3)
                {
                    maxarr3 = arr3[i][j][z];
                }
            }
        }
    }
    if (numb1 > numb2)
    {
        maxin2 = numb1;
    }
    else
    {
        maxin2 = numb2;
    }
    if (numb1 > numb2 && numb1 > numb3)
    {
        maxin3 = numb1;
    }
    else if (numb2 > numb1 && numb2 > numb3)
    {
        maxin3 = numb2;
    }
    else
    {
        maxin3 = numb3;
    }
    std::cout << "Максимальное число в первом массиве: " << maxarr1 << "\n";
    std::cout << "Максимальное число во втором массиве: " << maxarr2 << "\n";
    std::cout << "Максимальное число в третьем массиве: " << maxarr3 << "\n";
    std::cout << "Максимальное число из двух целых: " << maxin2 << "\n";
    std::cout << "Максимальное число из трёх целых: " << maxin3 << "\n";


    return 0;
}
