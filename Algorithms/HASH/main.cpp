#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stack>
using namespace std;

string names[5] = { "Андрей", "Тимур", "Петр","Дмитрий", "Евгений" };
string patronymic[5] = { "Андреевич", "Иванович", "Петрович","Иоанович", "Денисcов" };
string surnames[5] = { "Смирнов", "Маслов", "Сафонов", "Кузнецов", "Горбачёв" };
int num_pass[5] = { 123456, 246810, 135790, 523612, 423522 };
string dates[5] = { "15.09.1969", "27.01.1996", "23.10.1972", "13.04.1993", "20.07.1985" };

struct Node {
    string FIO;
    string data;
    long int num_pass;   
    Node* next;
    Node(string fio, string dat, int num) : FIO(fio), data(dat), num_pass(num), next(nullptr) {}
    Node(string data) : data(data), FIO("NULL"), num_pass(0), next(nullptr) {}
    friend ostream& operator<<(ostream& out, const Node& node)
    {
        if (node.data == "not find") { out << "not find";  }
        else if (node.data == "delete") { out << "delete"; }
        else
            out << " | " << node.FIO << "\t" << node.data << "\t" << node.num_pass << " | ";
        return out;
    }
};
class HashTable {
private:
    vector<Node*> table;
    int size;
 
    int hash(string str)
    {
        double a = ((sqrt(5) - 1) / 2) * get_sum_of_date(str);	// a = 0.618 * 2015 == 1245.27
        double c = size * (a - int(a));	// с = 10 * (1245.27 - 1245) == 2.7
        return int(c);	// с == 2
    }
    int get_sum_of_date(string str)
    {
        return stoi(str.substr(0, 2)) + stoi(str.substr(3, 2)) + stoi(str.substr(6, 4));
    }

public:
    int count_collision = 0;
    HashTable(int s) : size(s) 
    {
        table.resize(size, nullptr);
    }
    void insert(string FIO, string key, int num) {
        int index = hash(key);
        Node* newNode = new Node(FIO, key, num);
        if (table[index] == nullptr) {
            table[index] = newNode;
        }
        else {
            count_collision++;
            Node* current = table[index];
            while (current->next != nullptr) {
                /*if (current->key == key) {
                    current->value = value;
                    return;
                }*/
         
                current = current->next;
            }
            /*if (current->key == key) {
                current->value = value; 
                return;
            }*/
            current->next = newNode;

        }
    }
    void remove(string key) {
        int index = hash(key);
        if (table[index] == nullptr) {
            return;
        }
        else if (table[index]->data == key) {
            Node* temp = table[index];
            table[index] = temp->next;
            delete temp;
        }
        else {
            Node* current = table[index];
            while (current->next != nullptr && current->next->data != key) {
                current = current->next;
            }
            if (current->next != nullptr && current->next->data == key) {
                Node* temp = current->next;
                current->next = temp->next;
                delete temp;
            }
        }
    }
    Node find(string key) {
        int index = hash(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->data == key) {
                return *current;
            }
            current = current->next;
        }
        return Node("not find");
    }
    void print() {
        for (int i = 0; i < size; i++) {
            Node* current = table[i];
            if (current != nullptr) {
                cout << endl << i + 1 << ": " << *current;
                current = current->next;
            }
            while (current != nullptr) {
                cout << " ->\n   " << *current;
                current = current->next;
            }
        }
    }
    ~HashTable() {
        for (int i = 0; i < size; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
    }
};


class HashMap {
private:
    vector<Node*> table;
    int size;
    
    int hash(string str)
    {
        double a = ((sqrt(5) - 1) / 2) * get_sum_of_date(str);	// a = 0.618 * 2015 == 1245.27
        double c = size * (a - int(a));	// с = 10 * (1245.27 - 1245) == 2.7
        return int(c);	// с == 2
    }
    int get_sum_of_date(string str)
    {
        return stoi(str.substr(0, 2)) + stoi(str.substr(3, 2)) + stoi(str.substr(6, 4));
    }
public:
    int count_collision = 0;
    HashMap(int s) : size(s)
    {
        table.resize(size, nullptr);
    }

    ~HashMap() {
        for (int i = 0; i < size; i++)
        {
            if (table[i] != nullptr)
                delete table[i];
        }
    }

    void put(string FIO, string key, int num) {
        int index = hash(key);
        int end = index;
        if (table[index] == nullptr)
        {
            table[index] = new Node(FIO, key, num);
            return;
        }
        else
        {
            count_collision++;
            ++index;
            while (index < size)
            {
                if (table[index] == nullptr)
                {
                    table[index] = new Node(FIO, key, num);
                    return;
                }
                ++index;
             
            }
            if (index == size)
            {
                index = 0;
     
                while (index < end)
                {
                    if (table[index] == nullptr)
                    {
                        table[index] = new Node(FIO, key, num);
                        return;
                    }
                    ++index;
         
                }
            }
        }
    }

    Node get(string key) {
        int index = hash(key);
        while (table[index] != nullptr && table[index]->data != key) {
            index = (index + 1) % size;
        }
        if (table[index] == nullptr)
            return Node("not find");
        else
            return *table[index];
    }

    void remove(string key) {
        int index = hash(key);
        while (table[index] != nullptr) {
            if (table[index]->data == key)
                break;
            index = (index + 1) % size;
        }
        if (table[index] == nullptr)
            return;
        else {
            delete table[index];
            table[index] = nullptr;
        }
    }

    void print() {
        for (int i = 0; i < size; i++) {
            if (table[i] != nullptr)
                cout << i + 1 << ": " << * table[i] << endl;
        }
    }
};

int get_random_number()
{
    return rand() % 5;
}
string get_random_name()
{
    return (surnames[get_random_number()] + " " + names[get_random_number()] + " " + patronymic[get_random_number()]);
}
long int get_random_num_pass()
{
    return num_pass[get_random_number()];
}
string get_random_date()
{
    return dates[get_random_number()];
}
Node* create_random_human()
{
    Node* temp = new Node("not find");
    temp->FIO = get_random_name();
    temp->num_pass = get_random_num_pass();
    temp->data = get_random_date();
    return temp;
}

void fill_array_random_humans(vector<Node*>& array, const int size)
{
    for (int i = 0; i < size; ++i)
        array[i] = create_random_human();
}

int main()
{
    setlocale(0, ".1251");
    int size;
    cout << "Введите количество элементов в массиве: ";
    cin >> size;

    cout << endl;

    vector<Node*> array;
    array.resize(size);

    HashMap Table1(size);
    HashTable Table2(size);
    fill_array_random_humans(array, size);
    for (int i = 0; i < size; i++)
    {
        cout << i << ":\t" << *array[i] << endl;
        string FIO = array[i]->FIO;
        string data = array[i]->data;
        long int num = array[i]->num_pass;

        Table2.insert(FIO, data, num);
        Table1.put(FIO, data, num);
    }
    cout << endl << endl;
    Table2.print();
    cout << endl << endl;
    Table1.print();

    cout << endl << Table1.count_collision << " " << Table2.count_collision << endl;
    return 0;
}
