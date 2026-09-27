#include <iostream>
#include <string>
using namespace std;

class Stack
{
    string arr[100];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(string operation)
    {
        if (top < 99)
        {
            arr[++top] = operation;
        }
    }

    string pop()
    {
        if (top == -1)
        {
            return "";
        }

        return arr[top--];
    }

    bool isEmpty()
    {
        return top == -1;
    }
};

class TextEditor
{
    Stack undoStack;
    Stack redoStack;
    string text;

public:

    // Add a new operation
    void addOperation(string operation)
    {
        undoStack.push(operation);

        // New operation clears redo history
        while (!redoStack.isEmpty())
        {
            redoStack.pop();
        }

        cout << "Operation added: " << operation << endl;
    }

    // Undo the last operation
    void undo()
    {
        if (undoStack.isEmpty())
        {
            cout << "Nothing to undo." << endl;
            return;
        }

        string operation = undoStack.pop();
        redoStack.push(operation);

        cout << "Undo operation: " << operation << endl;
    }

    // Redo the last undone operation
    void redo()
    {
        if (redoStack.isEmpty())
        {
            cout << "Nothing to redo." << endl;
            return;
        }

        string operation = redoStack.pop();
        undoStack.push(operation);

        cout << "Redo operation: " << operation << endl;
    }

    void display()
    {
        cout << "Current operations:" << endl;

        if (undoStack.isEmpty())
        {
            cout << "No operations available." << endl;
        }
        else
        {
            cout << "Last operation: "
                 << undoStack.pop() << endl;
        }
    }
};

int main()
{
    TextEditor editor;

    int choice;
    string operation;

    do
    {
        cout << "\n========== UNDO REDO SYSTEM ==========" << endl;
        cout << "1. Add Operation" << endl;
        cout << "2. Undo" << endl;
        cout << "3. Redo" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore();

        switch (choice)
        {
        case 1:
            cout << "Enter operation: ";
            getline(cin, operation);
            editor.addOperation(operation);
            break;

        case 2:
            editor.undo();
            break;

        case 3:
            editor.redo();
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