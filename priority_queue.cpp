#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
private:
    vector<int> heap;
    void heapify(int k)
    {
        int n = heap.size();
        bool Heap = false;

        while (!Heap && 2 * k <= n - 1)
        {
            int j = 2 * k + 1;
            if (j + 1 < n && heap[j] < heap[j + 1])
                j++;

            if (heap[k] >= heap[j])
                Heap = true;
            else
            {
                swap(heap[k], heap[j]);
                k = j;
            }
        }
    }

public:
    PriorityQueue() {}
    void insert(int value)
    {
        heap.push_back(value);
        int k = heap.size() - 1;
        while (k > 0 && heap[k] > heap[(k - 1) / 2])
        {
            swap(heap[k], heap[(k - 1) / 2]);
            k = (k - 1) / 2;
        }
    }

    int removeTop() {
        if (heap.empty())
        {
            cout << "Priority Queue is empty!" << endl;
            return -1;
        }

        int maxElement = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapify(0);
        return maxElement;
    }

    int top()
    {
        if (!heap.empty())
           return heap[0];
        return -1;
    }


    void printQueue() {
        if (heap.empty()) {
            cout << "Priority Queue is empty!" << endl;
            return;
        }
        for (int val : heap) {
            cout << val << " ";
        }
        cout << endl;
    }


    bool isEmpty() {
        return heap.empty();
    }
};

int main() {
    PriorityQueue pq;

    int choice, value;

    while (1)
    {

        cout << "\nPriority Queue Operations:\n";
        cout << "1. Insert an element\n";
        cout << "2. Remove top element\n";
        cout << "3. Peek top element\n";
        cout << "4. Print the queue\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter the element to insert: ";
                cin >> value;
                pq.insert(value);
                cout << "Element inserted successfully.\n";
                break;

            case 2:
                value = pq.removeTop();
                if (value != -1)
                    cout << "Removed top element: " << value << endl;
                break;

            case 3:
                value = pq.top();
                if (value != -1)
                    cout << "Top element (Highest Priority): " << value << endl;
                break;

            case 4:
                cout << "Priority Queue: ";
                pq.printQueue();
                break;

            case 5:
                cout << "Exiting the program.\n";
                return 0;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
}
