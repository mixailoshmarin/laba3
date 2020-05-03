#include <iostream>
#include <string.h>
#include <cstdio>
#include <cstdlib>
#include <fstream>

using namespace std;

class list
{
public:
char name[20];
char category[20];
int shipped;
int quantity;
};


void create(int &n, list arr[]);
void menu(int &n, list arr[]);
void show(int &n, list arr[]);
void showpart(int &n, list arr[]);
void add(int &n, list arr[]);
void del(int &n, list arr[]);
void take(int &n, list arr[]);
void back(int &n, list arr[]);
void find(int &n, list arr[]);
int StrToInt(char* str);
int CorInput(int max);