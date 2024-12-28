#include <iostream>
#include <string>
using namespace std;

struct Node 
{
    string a; 
    int b;    
    float c;  
    Node* next; 
};

void displaySLL(Node* head);
Node* insertAtFront(Node* head);
Node* deleteNode(Node* head, int b);

int main() {
    Node* head = nullptr; 
    int choice;

    while (true) {
        cout << "1--Display SLL\n";
        cout << "2--Insert at front\n";
        cout << "3--Delete a node\n";
        cout << "4--Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displaySLL(head);
                break;
            case 2:
                head = insertAtFront(head);
                break;
            case 3: {
                int b;
                cout << "Enter the value of B to delete: ";
                cin >> b;
                head = deleteNode(head, b);
                break;
            }
            case 4:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}


void displaySLL(Node* head) 
{
    if (head == nullptr) 
        cout << "SLL is empty\n";
    else 
    {
        Node* temp = head;
        while (temp != nullptr) 
        {
            cout << "A: " << temp->a
                 << "    B: " << temp->b
                 << "    C: " << temp->c << "\n";
            temp = temp->next;
        }
    }
}

Node* insertAtFront(Node* head) 
{
    Node* newNode = new Node;
    cout << "Enter A, B, and C:\n";
    cin >> newNode->a >> newNode->b >> newNode->c;

    newNode->next = head;
    head = newNode;     
    return head;
}


Node* deleteNode(Node* head, int b) 
{
    if (head == nullptr) 
    {
        cout << "SLL is empty. Nothing to delete.\n";
        return head;
    }

    // If the node to be deleted is the head
    if (head->b == b) 
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Node with B = " << b << " deleted.\n";
        return head;
    }

    // Traverse to find the node to delete
    Node* current = head;
    while (current->next != nullptr && current->next->b != b) 
        current = current->next;

    if (current->next == nullptr) 
        cout << "Node with B = " << b << " not found.\n";
    else 
    {
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
        cout << "Node with B = " << b << " deleted.\n";
    }

    return head;
}
