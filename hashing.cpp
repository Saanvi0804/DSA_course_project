#include <iostream>

using namespace std;

const int TABLE_SIZE = 10;

struct Node {
    int key;
    string value;
    Node* next;

    Node(int k, const string& v) {
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
    HashTable() {
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

int main() {
    HashTable hashTable;
    hashTable.insert(5, "Amogh");
    hashTable.insert(10, "Bhoomika");
    hashTable.insert(15, "Ramya");
    hashTable.insert(20, "Saanvi");

    cout << hashTable.search(10) << endl;

    hashTable.remove(10);

    cout << hashTable.search(10) << endl;

    return 0;
}
