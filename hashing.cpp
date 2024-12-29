#include <iostream>

using namespace std;

const int TABLE_SIZE = 10;

struct Node 
{
    int key;
    string value;
    Node* next;

    Node(int k, const string& v) 
    {
        key = k;
        value = v;
        next = nullptr;
    }
};

class HashTable {
private:
    Node* table[TABLE_SIZE];

    int hashFunction(int key)
    {
        return key % TABLE_SIZE;
    }

public:
    HashTable()
    {
        for (int i = 0; i < TABLE_SIZE; ++i)
            table[i] = nullptr;
    }

    void insert(int key, const string& value)
    {
        int hashKey = hashFunction(key);
        Node* newNode = new Node(key, value);
        if (table[hashKey] == nullptr)
            table[hashKey] = newNode;
        else
        {
            Node* temp = table[hashKey];
            while (temp->next != nullptr)
            {
                if (temp->key == key)
                {
                    temp->value = value;
                    delete newNode;
                    return;
                }
                temp = temp->next;
            }
            if (temp->key == key)
            {
                temp->value = value;
                delete newNode;
                return;
            }
            temp->next = newNode;
        }
    }

    string search(int key)
    {
        int hashKey = hashFunction(key);
        Node* temp = table[hashKey];
        while (temp != nullptr)
        {
            if (temp->key == key)
                return temp->value;
            temp = temp->next;
        }
        return "Key " + to_string(key) + " not found in hash table";
    }

    void remove(int key)
    {
        int hashKey = hashFunction(key);
        Node* temp = table[hashKey];
        Node* prev = nullptr;
        while (temp != nullptr && temp->key != key)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp == nullptr)
        {
            cout << "Key " + to_string(key) + " not found in hash table" << endl;
            return;
        }
        if (prev == nullptr)
            table[hashKey] = temp->next;
        else
            prev->next = temp->next;
        delete temp;
    }
};

int main()
{
    HashTable hashTable;
    int choice, key;
    string value;

    while (1) 
    {
        cout << "\n1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Delete\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
         {
        case 1:
            cout << "Enter key: ";
            cin >> key;
            cout << "Enter value: ";
            cin >> value;
            hashTable.insert(key, value);
            break;

        case 2:
            cout << "Enter key to search: ";
            cin >> key;
            cout << hashTable.search(key) << endl;
            break;

        case 3:
            cout << "Enter key to delete: ";
            cin >> key;
            hashTable.remove(key);
            break;

        case 4:
            cout << "Exiting program." << endl;
            return 0;

        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
