#include <iostream>
using namespace std;

class Deque
{
    int arr[5];
    int front;
    int rear;
    int size;

public:

    // Constructor
    Deque()
    {
        front = -1;
        rear = -1;
        size = 5;
    }

    // Check if deque is empty
    bool isEmpty()
    {
        return front == -1;
    }

    // Check if deque is full
    bool isFull()
    {
        return (front == 0 && rear == size - 1) ||
               (front == rear + 1);
    }

    // Insert element at front
    void insertFront(int value)
    {
        if (isFull())
        {
            cout << "Deque is full." << endl;
            return;
        }

        if (isEmpty())
        {
            front = 0;
            rear = 0;
        }
        else if (front == 0)
        {
            front = size - 1;
        }
        else
        {
            front--;
        }

        arr[front] = value;

        cout << value << " inserted at front." << endl;
    }

    // Insert element at rear
    void insertRear(int value)
    {
        if (isFull())
        {
            cout << "Deque is full." << endl;
            return;
        }

        if (isEmpty())
        {
            front = 0;
            rear = 0;
        }
        else if (rear == size - 1)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }

        arr[rear] = value;

        cout << value << " inserted at rear." << endl;
    }

    // Delete element from front
    void deleteFront()
    {
        if (isEmpty())
        {
            cout << "Deque is empty." << endl;
            return;
        }

        cout << arr[front] << " deleted from front." << endl;

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if (front == size - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }

    // Delete element from rear
    void deleteRear()
    {
        if (isEmpty())
        {
            cout << "Deque is empty." << endl;
            return;
        }

        cout << arr[rear] << " deleted from rear." << endl;

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if (rear == 0)
        {
            rear = size - 1;
        }
        else
        {
            rear--;
        }
    }

    // Display deque
    void display()
    {
        if (isEmpty())
        {
            cout << "Deque is empty." << endl;
            return;
        }

        cout << "Deque elements: ";

        int i = front;

        while (true)
        {
            cout << arr[i] << " ";

            if (i == rear)
            {
                break;
            }

            i = (i + 1) % size;
        }

        cout << endl;
    }
};

int main()
{
    Deque dq;

    int choice;
    int value;

    do
    {
        cout << "\n========== DOUBLE ENDED QUEUE ==========" << endl;
        cout << "1. Insert at Front" << endl;
        cout << "2. Insert at Rear" << endl;
        cout << "3. Delete from Front" << endl;
        cout << "4. Delete from Rear" << endl;
        cout << "5. Display" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            dq.insertFront(value);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;
            dq.insertRear(value);
            break;

        case 3:
            dq.deleteFront();
            break;

        case 4:
            dq.deleteRear();
            break;

        case 5:
            dq.display();
            break;

        case 6:
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 6);

    return 0;
}