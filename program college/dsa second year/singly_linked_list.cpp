#include <iostream>
using namespace std;

class Stack
{
    int arr[100];
    int top;

public:

    Stack()
    {
        top = -1;
    }

    // Push element into stack
    void push(int value)
    {
        if (top == 99)
        {
            cout << "Stack Overflow!" << endl;
            return;
        }

        arr[++top] = value;
    }

    // Pop element from stack
    int pop()
    {
        if (top == -1)
        {
            return -1;
        }

        return arr[top--];
    }

    // Check if stack is empty
    bool isEmpty()
    {
        return top == -1;
    }
};

class LinkedList
{
    struct Node
    {
        int data;
        Node *next;
    };

    Node *head;

public:

    LinkedList()
    {
        head = NULL;
    }

    // Add node at the end
    void insert(int value)
    {
        Node *newNode = new Node;

        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    // Display linked list
    void display()
    {
        if (head == NULL)
        {
            cout << "Linked list is empty." << endl;
            return;
        }

        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    // Reverse linked list using stack
    void reverseUsingStack()
    {
        if (head == NULL)
        {
            cout << "Linked list is empty." << endl;
            return;
        }

        Stack s;

        Node *temp = head;

        // Store all elements in stack
        while (temp != NULL)
        {
            s.push(temp->data);
            temp = temp->next;
        }

        // Put elements back into linked list
        temp = head;

        while (!s.isEmpty())
        {
            temp->data = s.pop();
            temp = temp->next;
        }
    }
};

int main()
{
    LinkedList list;

    int choice;
    int value;
    int n;

    do
    {
        cout << "\n========== LINKED LIST ==========" << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Display List" << endl;
        cout << "3. Reverse Using Stack" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;

            list.insert(value);

            cout << "Node inserted successfully." << endl;
            break;

        case 2:
            cout << "Linked List: ";
            list.display();
            break;

        case 3:
            list.reverseUsingStack();

            cout << "Linked list reversed using stack." << endl;
            break;

        case 4:
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 4);

    return 0;
}