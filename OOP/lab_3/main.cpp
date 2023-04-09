#include "Pair.h"
// Добавление числа к паре должно быть коммутативно
// Хотелось бы, чтобы работало и 5 + pair;
Pair& operator+(int n, Pair& pair)
{ 
    return pair + n;
}		
Pair& operator+(double n, Pair& pair) 
{
    return pair + n; 
}	
int main()
{
    setlocale(LC_ALL, ".1251");
    Pair pair1;
    Pair pair2(12, 12.5);
    cout << "Вывод: " << endl;
    cout << pair1 << endl;
    cout << pair2 << endl;
    cout << "Считывание: " << endl;
    cin >> pair1;
    cin >> pair2;
    cout << "Вывод: " << endl;
    cout << pair1 << endl;
    cout << pair2 << endl;
    cout << "Вычитание: " << endl;
    cout << pair2 - pair1 << endl;
    cout << "Присваивние: pair1 = pair2" << endl;
    pair1 = pair2;
    cout << pair1 << endl;
    cout << "3 + pair1 + 3: " << endl;
    cout << 3 + pair1 + 3 << endl;
    cout << "4.5 + pair1 + 4.5: " << endl;
    cout << 4.5 + pair1 + 4.5 << endl;
    cout << "Инкремент префиксный / постфиксный: " << endl;
    cout << ++pair1 << endl;
    cout << pair1++ << endl;
    cout << pair1 << endl;



}

