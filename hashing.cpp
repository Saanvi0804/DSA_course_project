#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const int TABLE_SIZE = 10;

struct Visitor {
    int id;
    char name[50];
    char address[50];
    char city[30];
    char email[50];
    char phone[20];
    Visitor* next;

    Visitor(int i, const char* n, const char* a, const char* c, const char* e, const char* p) {
        id = i;
        strcpy(name, n);
        strcpy(address, a);
        strcpy(city, c);
        strcpy(email, e);
        strcpy(phone, p);
        next = nullptr;
    }
};

class HashTable {
private:
    Visitor* table[TABLE_SIZE];

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; ++i)
            table[i] = nullptr;
    }

    void insert(int id, const char* name, const char* address, const char* city, const char* email, const char* phone) {
        int hashKey = hashFunction(id);
        Visitor* newVisitor = new Visitor(id, name, address, city, email, phone);
        if (table[hashKey] == nullptr)
            table[hashKey] = newVisitor;
        else {
            Visitor* temp = table[hashKey];
            while (temp->next != nullptr) {
                if (temp->id == id) {
                    strcpy(temp->name, name);
                    strcpy(temp->address, address);
                    strcpy(temp->city, city);
                    strcpy(temp->email, email);
                    strcpy(temp->phone, phone);
                    delete newVisitor;
                    return;
                }
                temp = temp->next;
            }
            if (temp->id == id) {
                strcpy(temp->name, name);
                strcpy(temp->address, address);
                strcpy(temp->city, city);
                strcpy(temp->email, email);
                strcpy(temp->phone, phone);
                delete newVisitor;
                return;
            }
            temp->next = newVisitor;
        }
    }

    Visitor* search(int id) {
        int hashKey = hashFunction(id);
        Visitor* temp = table[hashKey];
        while (temp != nullptr) {
            if (temp->id == id)
                return temp;
            temp = temp->next;
        }
        return nullptr;
    }

    void remove(int id) {
        int hashKey = hashFunction(id);
        Visitor* temp = table[hashKey];
        Visitor* prev = nullptr;
        while (temp != nullptr && temp->id != id) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Key " << id << " not found in hash table" << endl;
            return;
        }
        if (prev == nullptr)
            table[hashKey] = temp->next;
        else
            prev->next = temp->next;
        delete temp;
    }

    void display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << "Bucket " << i << ": ";
            Visitor* temp = table[i];
            while (temp != nullptr) {
                cout << "[ID: " << temp->id << ", Name: " << temp->name
                     << ", Address: " << temp->address << ", City: " << temp->city
                     << ", Email: " << temp->email << ", Phone: " << temp->phone << "] -> ";
                temp = temp->next;
            }
            cout << "nullptr" << endl;
        }
    }
};

void loadVisitors(HashTable &hash_table, const string &filename) {
    ifstream file(filename);

    if (!file) {
        cout << "File Not Found\n";
        return;
    }

    int id;
    char name[50];
    char address[50];
    char city[30];
    char email[50];
    char phone[20];

    while (file >> id) {
        file.ignore(); // Ignore the comma
        file.getline(name, 50, ',');
        file.getline(address, 50, ',');
        file.getline(city, 30, ',');
        file.getline(email, 50, ',');
        file.getline(phone, 20, '\n');

        hash_table.insert(id, name, address, city, email, phone);
    }

    file.close();
}

int main() {
    HashTable hash_table;

    loadVisitors(hash_table, "visitor_details.txt");

    cout << "Hash Table Contents:" << endl;
    hash_table.display();

    int choice, id;
    char name[50], address[50], city[30], email[50], phone[20];

    while (true) {
        cout << "\n1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Delete\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter name: ";
            cin.ignore();
            cin.getline(name, 50);
            cout << "Enter address: ";
            cin.getline(address, 50);
            cout << "Enter city: ";
            cin.getline(city, 30);
            cout << "Enter email: ";
            cin.getline(email, 50);
            cout << "Enter phone: ";
            cin.getline(phone, 20);
            hash_table.insert(id, name, address, city, email, phone);
            break;

        case 2:
            cout << "Enter ID to search: ";
            cin >> id;
            {
                Visitor* visitor = hash_table.search(id);
                if (visitor != nullptr)
                    cout << "Visitor found: [ID: " << visitor->id << ", Name: " << visitor->name
                         << ", Address: " << visitor->address << ", City: " << visitor->city
                         << ", Email: " << visitor->email << ", Phone: " << visitor->phone << "]" << endl;
                else
                    cout << "Visitor with ID " << id << " not found in hash table" << endl;
            }
            break;

        case 3:
            cout << "Enter ID to delete: ";
            cin >> id;
            hash_table.remove(id);
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
