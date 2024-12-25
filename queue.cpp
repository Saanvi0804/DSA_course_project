#include <iostream>
using namespace std;
#define MAX 1000

class Queue {
    int front, rear, size;
    int queue[MAX];

public:
    Queue()
    {
        front = size = 0;
        rear = MAX - 1;
    }
    bool isFull()
    {
        return (size == MAX);
    }

    bool isEmpty()
    {
        return (size == 0);
    }
    void enqueue(int item)
    {
        if (isFull())
        {
            cout << "Queue is full!" << endl;
            return;
        }
        rear = (rear + 1) % MAX;
        queue[rear] = item;
        size++;
        cout << item << " enqueued to the queue" << endl;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        int item = queue[front];
        front = (front + 1) % MAX;
        size--;
        return item;
    }

    void printQueue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Current queue: ";
        for (int i = front, count = 0; count < size; count++)
        {
            cout << queue[i] << " ";
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};

int main()
{
    Queue q;
    int c, value;

    while(1)
    {
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Print queue\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> c;

        switch (c)
        {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                value = q.dequeue();
                if (value != -1)
                {
                    cout << "Dequeued value: " << value << endl;
                }
                break;
            case 3:
                q.printQueue();
                break;
            case 4:
                cout << "Exiting...\n";
                exit(0);
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
