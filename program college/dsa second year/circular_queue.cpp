#include <iostream>
using namespace std;

class CircularQueue
{
    int queue[5];
    int frontIndex;
    int rear;
    int count;

public:

    // Constructor
    CircularQueue()
    {
        frontIndex = 0;
        rear = -1;
        count = 0;
    }

    // Check if queue is empty
    bool isEmpty()
    {
        return count == 0;
    }

    // Check if queue is full
    bool isFull()
    {
        return count == 5;
    }

    // Add a new print job
    void enqueue(int job)
    {
        if (isFull())
        {
            cout << "Printer queue is full." << endl;
            return;
        }

        rear = (rear + 1) % 5;
        queue[rear] = job;
        count++;

        cout << "Print job " << job << " added to the queue." << endl;
    }

    // Process and remove the front print job
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Printer queue is empty." << endl;
            return;
        }

        cout << "Print job " << queue[frontIndex]
             << " is being processed." << endl;

        frontIndex = (frontIndex + 1) % 5;
        count--;
    }

    // Display the front print job
    void front()
    {
        if (isEmpty())
        {
            cout << "Printer queue is empty." << endl;
            return;
        }

        cout << "Front print job: "
             << queue[frontIndex] << endl;
    }

    // Display number of print jobs
    void printJobCount()
    {
        cout << "Current number of print jobs: "
             << count << endl;
    }

    // Display all print jobs
    void display()
    {
        if (isEmpty())
        {
            cout << "Printer queue is empty." << endl;
            return;
        }

        cout << "Print jobs in queue: ";

        for (int i = 0; i < count; i++)
        {
            int index = (frontIndex + i) % 5;
            cout << queue[index] << " ";
        }

        cout << endl;
    }
};

int main()
{
    CircularQueue printer;
    int choice;
    int job;

    do
    {
        cout << "\n========== PRINTER JOB QUEUE ==========" << endl;
        cout << "1. Enqueue Print Job" << endl;
        cout << "2. Dequeue / Process Print Job" << endl;
        cout << "3. Check Front Job" << endl;
        cout << "4. Check if Queue is Empty" << endl;
        cout << "5. Check if Queue is Full" << endl;
        cout << "6. Print Job Count" << endl;
        cout << "7. Display All Jobs" << endl;
        cout << "8. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Print Job ID: ";
            cin >> job;
            printer.enqueue(job);
            break;

        case 2:
            printer.dequeue();
            break;

        case 3:
            printer.front();
            break;

        case 4:
            if (printer.isEmpty())
                cout << "Queue is empty." << endl;
            else
                cout << "Queue is not empty." << endl;
            break;

        case 5:
            if (printer.isFull())
                cout << "Queue is full." << endl;
            else
                cout << "Queue is not full." << endl;
            break;

        case 6:
            printer.printJobCount();
            break;

        case 7:
            printer.display();
            break;

        case 8:
            cout << "Exiting printer system..." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 8);

    return 0;
}