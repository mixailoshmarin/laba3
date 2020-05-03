#include <iostream>
#include <string.h>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include "class.h"
using namespace std;


int main()
{
    int n;
    int k = 100;
    list *arr;
    arr = new list[k];
    menu(n, arr);
    return 0;
}

void menu(int &n, list arr[])
{
    int number;
    cout << "[1] Создать файл(по умолч. sklad.txt) " << endl;
    cout << "[2] Просмотреть весь товар на складе" << endl;
    cout << "[3] Поиск товара по наименованию" << endl;
    cout << "[4] Добавить товар" << endl;
    cout << "[5] Удалить товар" << endl;
    cout << "[6] Отправить товар" << endl;
    cout << "[7] Вернуть товар на склад" << endl;
    cout << "[8] Найти товар по категории" << endl;
    cout << "[9] Выход" << endl;
    cout << "Введите свой выбор:" << endl;
    cin >> number;
        if(number<1||number>9)
            {
                cout << "Некорректный ввод. Попробуйте еще раз: \n";
                menu(n,arr);
            }
        else 
        {
            switch (number)
                {
                case 1:
                    {
                        create(n, arr);
                        break;
                    }
                case 2:
                    {
                        show(n, arr);
                        break;
                    }
                case 3:
                    {
                        showpart(n, arr);
                        break;
                    }
                case 4:
                    {
                        add(n, arr);
                        break;
                    }
                case 5:
                    {
                        del(n, arr);
                        break;
                    }
                case 6:
                    {
                        take(n, arr);
                        break;
                    }
                case 7:
                    {
                        back(n, arr);
                        break;
                    }
                case 8:
                    {
                        find(n, arr);
                        break;
                    }
                case 9:
                    {
                    delete[] arr;
                    exit(0);
                    }
        }
    }
}