#include <iostream>
#include <random>
#include <Windows.h>
void Ex1();
void Ex2();
void RecFunk(int arr[], int size);
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
            startmin = i+1;
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
    const int size1 = 5, size2 = 4, size3 = 3;
    int arr1[size1];
    int arr2[size1][size2];
    int arr3[size1][size2][size3];
}