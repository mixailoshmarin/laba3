#include <iostream>
#include <string.h>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "class.h"
#include <fstream>
using namespace std;

void create(int &n, list arr[])
{
    char ref[1];
    cout << "Введите количество добавляемых товаров: ";
    n = CorInput(20);
        for (int i = 0; i < n; i++)
            {
                cin.getline(ref, 1);
                cout << "Введите наименование товара: ";
                cin.getline(arr[i].name, 20);
                cout << "Введите общую категорию(макс. 8символов): ";
                cin.getline(arr[i].category, 20);
                cout << "Введите количество отправленного товара: ";
                cin >> arr[i].shipped;
                cout << "Введите количество оставшееся на складе: ";
                cin >> arr[i].quantity;
            }
    ofstream f("sklad.txt");
        for (int i = 0; i < n; i++)
            {
                f << arr[i].name;
                f << arr[i].category;
                f << arr[i].shipped;
                f << arr[i].quantity;
            }
    f.close();
    menu(n, arr);
}



void show(int &n, list arr[])
{
    ifstream f("sklad.txt");
        for (int i = 0; i < n; i++)
            {
                cout << "Наименование товара: " << arr[i].name << endl;
                cout << "Общая категория: " << arr[i].category << endl;
                cout << "Отправлено: " << arr[i].shipped << endl;
                cout << "Осталось на складе: " << arr[i].quantity << endl << endl;
            }
    menu(n, arr);
}



void showpart(int &n, list arr[])
{
    char ref[1];
    char last[20];
    cin.getline(ref, 1);
    cout << "Введите наименование товара: ";
    cin.getline(last, 20);
    ifstream f("sklad.txt");
        for (int i = 0; i < n; i++)
            {
                if (strcmp(arr[i].name, last) == 0)
                    {
                        cout << "Наименование товара: " << arr[i].name << endl;
                        cout << "Общая категория: " << arr[i].category << endl;
                        cout << "Отправлено: " << arr[i].shipped << endl;
                        cout << "Осталось на складе: " << arr[i].quantity << endl << endl;
                    }
            }
    menu(n, arr);
}



void add(int &n, list arr[])
{
    int j;
    char ref[1];
    cin.getline(ref, 1);
    cout << "Введите количество товара для добавления: ";
    j = CorInput(20);
    ofstream f("sklad.txt", ios::app);
        for (int i = n; i < n + j; i++)
            {
                cin.getline(ref, 1);
                cout << "Введите наименование товара: ";
                cin.getline(arr[i].name, 20);
                cout << "Введите общую категорию: ";
                cin.getline(arr[i].category, 20);
                cout << "Введите количество отправленного товара: ";
                arr[i].shipped = CorInput(1000);
                cout << "Введите количество товара оставшегося на складе: ";
                arr[i].quantity = CorInput(1000);
            }
        for (int i = n; i < n + j; i++)
            {
                f << arr[i].name;
                f << arr[i].category;
                f << arr[i].shipped;
                f << arr[i].quantity;
            }
    f.close();
    n += j;
    menu(n, arr);
}



void take(int &n, list arr[])
{
    int o;
    char last[20];
    char ref[1];
    cin.getline(ref, 1);
    cout << "Введите общую категорию товара: ";
    cin.getline(last, 20);
    cout << "Введите количество отправленного товара: ";
    o = CorInput(20);
    ofstream f("sklad.txt", ios::trunc);
        for (int i = 0; i < n; i++)
            {
                if (strcmp(arr[i].category, last) == 0)
                    {
                        if (arr[i].quantity < o)
                            {
                            cout << "Недостаточно товара на складе. Ошибка операции \n";
                            break;
                            }
                        arr[i].shipped += o;
                        arr[i].quantity -= o;
                        f << arr[i].name;
                        f << arr[i].category;
                        f << arr[i].shipped;
                        f << arr[i].quantity;
                    }
                else
                    {
                        f << arr[i].name;
                        f << arr[i].category;
                        f << arr[i].shipped;
                        f << arr[i].quantity;
                    }
            }
    f.close();
    menu(n, arr);
}
    
    
    
void back(int &n, list arr[])
{
    int o;
    char last[20];
    char ref[1];
    cin.getline(ref, 1);
    cout << "Введите общую категорию: ";
    cin.getline(last, 20);
    cout << "Введите количество товара: ";
    o = CorInput(20);
    ofstream f("sklad.txt", ios::trunc);
        for (int i = 0; i < n; i++)
            {
                if (strcmp(arr[i].category, last) == 0)
                    {
                        if (arr[i].shipped < o)
                            {
                                cout << "Ощибка в количестве выданного товара: \n";
                                break;
                            }
                        arr[i].shipped -= o;
                        arr[i].quantity += o;
                        f << arr[i].name;
                        f << arr[i].category;
                        f << arr[i].shipped;
                        f << arr[i].quantity;
                    }
                else
                    {
                        f << arr[i].name;
                        f << arr[i].category;
                        f << arr[i].shipped;
                        f << arr[i].quantity;
                    }
            }
    f.close();
    menu(n, arr);
}




void find(int &n, list arr[])
{
    char last[20];
    char ref[1];
    cin.getline(ref, 1);
    cout << "Введите общую категорию: ";
    cin.getline(last, 20);
    ifstream f("sklad.txt");
        for (int i = 0; i < n; i++)
            {
                if (strcmp(arr[i].category, last) == 0)
                    {
                        cout << "Наименование товара: " << arr[i].name << endl;
                        cout << "Общая категория: " << arr[i].category << endl;
                        cout << "Отправлено товара: " << arr[i].shipped << endl;
                        cout << "Осталось товара на складе на складе: " << arr[i].quantity << endl << endl;
                        break;
                    }
            }
    menu(n, arr);
}




void del(int &n, list arr[])
{
    char last[20];
    char ref[1];
    cin.getline(ref, 1);
    cout << "Введите общую категорию: ";
    cin.getline(last, 20);
    ofstream f("sklad.txt", ios::trunc);
        for (int z = 0; z < n; z++)
            {
                if (strcmp(arr[z].category, last) == 0)
                    {
                        for (int y = z+1; y < n+1; y++)
                            {
                                *arr[y-1].name = *arr[y].name;
                                *arr[y-1].category = *arr[y].category;
                                arr[y-1].shipped = arr[y].shipped;
                                arr[y-1].quantity = arr[y].quantity;
                            }
                        *arr[n].name =0;
                        *arr[n].category =0;
                        arr[n].shipped = 0;
                        arr[n].quantity = 0;
                        n--;
                    }
            }
        for (int y = 0; y < n+1; y++)
            {
                f << arr[y].name;
                f << arr[y].category;
                f << arr[y].shipped;
                f << arr[y].quantity;
            }
    f.close();
    menu(n, arr);
}

int StrToInt(char* str){
int i=0;
int flag=0;
if(strlen(str)>6)
return 0;
while(str[i]!=0){
if(str[i]=='1'||str[i]=='2'||str[i]=='3'||str[i]=='4'||str[i]=='5'||str[i]=='6'||str[i]=='7'||str[i]=='8'||str[i]=='9'||str[i]=='0')
i++;
else{
flag=1;
break;
}
}
if(flag==0)
return atoi(str);
else
return 0;
}


int CorInput(int max){
char str[100];
int inp;
while(1){
scanf("%s",str);
inp=StrToInt(str);
if((inp!=0)&&(inp<=max)&&(inp>0))
break;
cout <<"Введено некорректное значение. Повторите попытку: \n";
}
return inp;
}