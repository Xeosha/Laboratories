#include <iostream>
#include <set>
#include "Pair.h"
using namespace std;
bool operator<(const Pair& pr1, const Pair& pr2)
{
    return ((pr1.a < pr2.a) && (pr1.b < pr2.b));
}
void ex_1()
{
    setlocale(0, "rus");
    multiset <double> mst;
    multiset <double> tmp;
    mst.insert(1.5);
    mst.insert(-1.5);
    mst.insert(2.3);
    mst.insert(2.3);
    double sr = 0;
    cout << "Изначальное множество" << endl;
    for (auto it = mst.begin(); it != mst.end(); it++)
    {
        sr += *it;
        cout << *it << endl;
    }

    //1
    cout << "Среднее, добавленное в конец: " << sr / mst.size() << endl;
    mst.insert(sr / mst.size());

    //2
    double max = *mst.begin();
    double min = *mst.begin();
    tmp = mst;
    mst.clear();
    int c = 0;
    int i, j;
    double res;
    cout << "Задайте диапозон: "; cin >> i >> j; cout << "Задайте ключ: "; cin >> res;
    for (auto it = tmp.begin(); it != tmp.end(); it++, c++)
    {
        if (!(*it == res && (c > i && c < j)))
        {
            if (max < *it) max = *it;
            if (min > *it) min = *it;
            mst.insert(*it);
            cout << *it << endl;
        }
    }
    cout << "Добавление суммы мин и макс: " << endl;
    tmp = mst;
    mst.clear();
    for (auto it = tmp.begin(); it != tmp.end(); it++)
    {
        mst.insert(max + min + *it);
        cout << *it + max + min << endl;
    }
}

void ex_2()
{
    setlocale(0, "rus");
    multiset <Pair> mst;
    multiset <Pair> tmp;
    mst.insert(Pair(1, 1.5));
    mst.insert(Pair(1, -1.5));
    mst.insert(Pair(2.3, 2.3));
    mst.insert(Pair(2.3, 2.3));
    Pair sr(0,0);
    cout << "Изначальное множество" << endl;
    for (auto it = mst.begin(); it != mst.end(); it++)
    {
        sr = sr + *it;
        cout << *it << endl;
    }

    //1
    sr.a /= mst.size();
    sr.b /= mst.size();
    cout << "Среднее, добавленное в конец: " << sr << endl;
    mst.insert(sr);

    //2
    Pair max = *mst.begin();
    Pair min = *mst.begin();
    tmp = mst;
    mst.clear();
    int c = 0;
    int i, j;
    Pair res;
    cout << "Задайте диапозон: "; cin >> i >> j; cout << "Задайте ключ: "; cin >> res;
    for (auto it = tmp.begin(); it != tmp.end(); it++, c++)
    {
        if ((c < i) || (c > j) || (res.a != (*it).a || res.b != (*it).b))
        {
            if (max < *it) max = *it;
            if (min > *it) min = *it;
            mst.insert(*it);
            cout << *it << endl;
        }
    }
    cout << "Добавление суммы мин и макс: " << endl;
    tmp = mst;
    mst.clear();
    for (auto it = tmp.begin(); it != tmp.end(); it++)
    {
        mst.insert(max + min + *it);
        cout << max + min + *it << endl;
    }
}

void ex_3()
{
    setlocale(0, "rus");
    multiset <Pair> mst;
    multiset <Pair> tmp;
    mst.insert(Pair(1, 1.5));
    mst.insert(Pair(1, -1.5));
    mst.insert(Pair(2.3, 2.3));
    mst.insert(Pair(2.3, 2.3));
    Pair sr(0, 0);
    cout << "Изначальное множество" << endl;
    for (auto it = mst.begin(); it != mst.end(); it++)
    {
        sr = sr + *it;
        cout << *it << endl;
    }

    //1
    sr.a /= mst.size();
    sr.b /= mst.size();
    cout << "Среднее, добавленное в конец: " << sr << endl;
    mst.insert(sr);

    //2
    Pair max = *mst.begin();
    Pair min = *mst.begin();
    tmp = mst;
    mst.clear();
    int c = 0;
    int i, j;
    Pair res;
    cout << "Задайте диапозон: "; cin >> i >> j; cout << "Задайте ключ: "; cin >> res;
    for (auto it = tmp.begin(); it != tmp.end(); it++, c++)
    {
        if ((c < i) || (c > j) || (res.a != (*it).a || res.b != (*it).b))
        {
            if (max < *it) max = *it;
            if (min > *it) min = *it;
            mst.insert(*it);
            cout << *it << endl;
        }
    }
    cout << "Добавление суммы мин и макс: " << endl;
    tmp = mst;
    mst.clear();
    for (auto it = tmp.begin(); it != tmp.end(); it++)
    {
        mst.insert(max + min + *it);
        cout << max + min + *it << endl;
    }
}


int main()
{
    ex_1();
    ex_2();
    ex_3();
}
