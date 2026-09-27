#include <iostream>
using namespace std;

#define MAX 50

struct Request
{
    int id;
    int priority;
};

Request heap[MAX];
int size = 0;

// Insert request into max heap
void insertRequest(int id, int priority)
{
    size++;

    int i = size;
    heap[i].id = id;
    heap[i].priority = priority;

    while (i > 1 && heap[i].priority > heap[i / 2].priority)
    {
        swap(heap[i], heap[i / 2]);
        i = i / 2;
    }
}

// Remove highest priority request
void processRequest()
{
    if (size == 0)
    {
        cout << "No service requests available.\n";
        return;
    }

    cout << "Processing Request " << heap[1].id
         << " (Priority: " << heap[1].priority << ")\n";

    heap[1] = heap[size];
    size--;

    int i = 1;

    while (2 * i <= size)
    {
        int child = 2 * i;

        if (child + 1 <= size &&
            heap[child + 1].priority > heap[child].priority)
        {
            child++;
        }

        if (heap[i].priority >= heap[child].priority)
            break;

        swap(heap[i], heap[child]);
        i = child;
    }
}

// Display requests
void display()
{
    if (size == 0)
    {
        cout << "No requests available.\n";
        return;
    }

    cout << "\nService Requests:\n";

    for (int i = 1; i <= size; i++)
    {
        cout << "Request ID: " << heap[i].id
             << "  Priority: " << heap[i].priority << endl;
    }
}

int main()
{
    int choice, id, priority;

    do
    {
        cout << "\n--- Customer Support Center ---\n";
        cout << "1. Add Service Request\n";
        cout << "2. Process Request\n";
        cout << "3. Display Requests\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Request ID: ";
            cin >> id;

            cout << "Enter Priority (3=Urgent, 2=Moderate, 1=Routine): ";
            cin >> priority;

            insertRequest(id, priority);
            cout << "Request added successfully.\n";
            break;

        case 2:
            processRequest();
            break;

        case 3:
            display();
            break;

        case 4:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 4);

    return 0;
}