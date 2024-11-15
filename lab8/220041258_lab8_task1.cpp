#include <iostream>
#include <vector>

using namespace std;

int count=0;
class HashTable
{
    int tableSize;
    double item;
    vector<int> table;

public:
    HashTable(int size) : tableSize(size), table(size, -1),item(0) {}

    int hashFunction(int key)
    {
        return key % tableSize;
    }

    int secondHash(int key)
    {
        return 5 - (key % 5);
    }
    void linear(int key)
    {
        int index = hashFunction(key);
        int originalIndex = index;
        int i = 1;
        int count=0;
        while (table[index] != -1)
        {
            count++;
            cout << "Collision : Index-" << index << endl;
            index = (index + 1) % tableSize;
            if(count==6)
            {
                cout << "Input Abandoned "  << endl;
                return;
            }
            if (index == originalIndex)
            {
                cout << "Input Abandoned "  << endl;
                return;
            }
            i++;
        }

        table[index] = key;
        item++;
        double factor=item/tableSize;
        cout << "Inserted  : Index-" << index << "(L.F="<<factor<<")" << endl;

    }

    void quadratic(int key)
    {
        int index = hashFunction(key);
        int originalIndex = index;
        int i = 1;

        while (table[index] != -1)
        {
            count++;
            cout << "Collision : Index-" << index << endl;

            index = (originalIndex + i * i) % tableSize;
            if(count==6)
            {
                cout << "Input Abandoned "  << endl;
                return;
            }
            if (index == originalIndex)
            {
                cout << "Input Abandoned "  << endl;
                return;
            }
            i++;
        }

        table[index] = key;
        item++;
        double factor=item/tableSize;
        cout << "Inserted  : Index-" << index << "(L.F="<<factor<<")" << endl;
    }

    void doublehash(int key)
    {
        int index = hashFunction(key);
        int originalIndex = index;
        int i = 1;

        while (table[index] != -1)
        {
            count++;
            cout << "Collision : Index-" << index << endl;


            index = (index + i * secondHash(key)) % tableSize;
            if(count==6)
            {
                cout << "Input Abandoned "  << endl;
                return;
            }
            if (index == originalIndex)
            {
                cout << "Input Abandoned "  << endl;
                return;
            }
            i++;
        }
        table[index] = key;
        item++;
        double factor=item/tableSize;
        cout << "Inserted  : Index-" << index << "(L.F="<<factor<<")" << endl;
    }


    void display()
    {
        for (int i = 0; i < tableSize; i++)
        {
            if (table[i] != -1)
                cout << "Index " << i << ": " << table[i] << endl;
            else
                cout << "Index " << i << ": " << "empty" << endl;
        }
    }
};

int main()
{
    int type;
    int size;
    int element;
    int i;
    int key[100];
    cin>>type>>size>>element;

    HashTable insert(size);
    for(i=0; i<element; i++)
    {
        cin>>key[i];
        if(type==1)
        {
            insert.linear(key[i]);
        }
        else if(type==2)
        {
            insert.quadratic(key[i]);
        }
        else if(type==3)
        {
            insert.doublehash(key[i]);

        }

    }

    return 0;
}
