#include <iostream>
using namespace std;

class JobQueue
{
    int queue[100];
    int front;
    int rear;

public:

    JobQueue()
    {
        front = -1;
        rear = -1;
    }

    // Function to add a job to the queue
    void addJob(int job)
    {
        if (rear == 99)
        {
            cout << "Queue is full. Cannot add job." << endl;
            return;
        }

        if (front == -1)
        {
            front = 0;
        }

        rear++;
        queue[rear] = job;

        cout << "Job " << job << " added to the queue." << endl;
    }

    // Function to delete/process a job from the queue
    void deleteJob()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue is empty. No job to process." << endl;
            return;
        }

        cout << "Job " << queue[front] << " processed and deleted."
             << endl;

        front++;

        // Reset queue when it becomes empty
        if (front > rear)
        {
            front = -1;
            rear = -1;
        }
    }

    // Display all jobs in the queue
    void display()
    {
        if (front == -1)
        {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Jobs in queue: ";

        for (int i = front; i <= rear; i++)
        {
            cout << queue[i] << " ";
        }

        cout << endl;
    }
};

int main()
{
    JobQueue q;

    int choice;
    int job;

    do
    {
        cout << "\n========== JOB QUEUE ==========" << endl;
        cout << "1. Add Job" << endl;
        cout << "2. Delete/Process Job" << endl;
        cout << "3. Display Jobs" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Job ID: ";
            cin >> job;

            q.addJob(job);
            break;

        case 2:
            q.deleteJob();
            break;

        case 3:
            q.display();
            break;

        case 4:
            cout << "Exiting Job Queue..." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 4);

    return 0;
}