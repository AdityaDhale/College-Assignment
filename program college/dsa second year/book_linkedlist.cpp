#include <iostream>
#include <string>
using namespace std;

// Node structure
struct Node
{
    int bookID;
    string title;
    string author;
    float price;
    int publicationYear;

    Node *prev;
    Node *next;
};


// Class for Book Management
class BookList
{
private:
    Node *head;
    Node *tail;

public:

    // Constructor
    BookList()
    {
        head = NULL;
        tail = NULL;
    }


    // 1. Add Book
    void addBook()
    {
        Node *newNode = new Node;

        cout << "\nEnter Book ID: ";
        cin >> newNode->bookID;

        cout << "Enter Book Title: ";
        cin.ignore();
        getline(cin, newNode->title);

        cout << "Enter Author Name: ";
        getline(cin, newNode->author);

        cout << "Enter Price: ";
        cin >> newNode->price;

        cout << "Enter Publication Year: ";
        cin >> newNode->publicationYear;

        newNode->prev = NULL;
        newNode->next = NULL;

        // If list is empty
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            // Add at the end
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        cout << "\nBook added successfully!\n";
    }


    // 2. Remove Book
    void removeBook()
    {
        if (head == NULL)
        {
            cout << "\nBook list is empty.\n";
            return;
        }

        int id;

        cout << "\nEnter Book ID to remove: ";
        cin >> id;

        Node *temp = head;

        // Search for book
        while (temp != NULL && temp->bookID != id)
        {
            temp = temp->next;
        }

        // Book not found
        if (temp == NULL)
        {
            cout << "\nBook with ID " << id << " not found.\n";
            return;
        }

        // If deleting first node
        if (temp == head)
        {
            head = temp->next;

            if (head != NULL)
            {
                head->prev = NULL;
            }
            else
            {
                tail = NULL;
            }
        }

        // If deleting last node
        else if (temp == tail)
        {
            tail = temp->prev;
            tail->next = NULL;
        }

        // If deleting middle node
        else
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }

        delete temp;

        cout << "\nBook removed successfully!\n";
    }


    // 3. Search Book
    void searchBook()
    {
        if (head == NULL)
        {
            cout << "\nBook list is empty.\n";
            return;
        }

        int id;

        cout << "\nEnter Book ID to search: ";
        cin >> id;

        Node *temp = head;

        while (temp != NULL)
        {
            if (temp->bookID == id)
            {
                cout << "\n============================================\n";
                cout << "              BOOK DETAILS\n";
                cout << "============================================\n";

                cout << "Book ID          : " << temp->bookID << endl;
                cout << "Title            : " << temp->title << endl;
                cout << "Author           : " << temp->author << endl;
                cout << "Price            : " << temp->price << endl;
                cout << "Publication Year : "
                     << temp->publicationYear << endl;

                cout << "============================================\n";

                return;
            }

            temp = temp->next;
        }

        cout << "\nBook with ID " << id << " not found.\n";
    }


    // 4. Update Book
    void updateBook()
    {
        if (head == NULL)
        {
            cout << "\nBook list is empty.\n";
            return;
        }

        int id;

        cout << "\nEnter Book ID to update: ";
        cin >> id;

        Node *temp = head;

        while (temp != NULL && temp->bookID != id)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "\nBook with ID " << id << " not found.\n";
            return;
        }

        int choice;

        cout << "\nBook found!";
        cout << "\nWhat do you want to update?\n";
        cout << "1. Title\n";
        cout << "2. Author\n";
        cout << "3. Price\n";
        cout << "4. Publication Year\n";
        cout << "5. Update All Details\n";

        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter new title: ";
            cin.ignore();
            getline(cin, temp->title);

            cout << "\nTitle updated successfully!\n";
        }

        else if (choice == 2)
        {
            cout << "Enter new author: ";
            cin.ignore();
            getline(cin, temp->author);

            cout << "\nAuthor updated successfully!\n";
        }

        else if (choice == 3)
        {
            cout << "Enter new price: ";
            cin >> temp->price;

            cout << "\nPrice updated successfully!\n";
        }

        else if (choice == 4)
        {
            cout << "Enter new publication year: ";
            cin >> temp->publicationYear;

            cout << "\nPublication year updated successfully!\n";
        }

        else if (choice == 5)
        {
            cout << "Enter new title: ";
            cin.ignore();
            getline(cin, temp->title);

            cout << "Enter new author: ";
            getline(cin, temp->author);

            cout << "Enter new price: ";
            cin >> temp->price;

            cout << "Enter new publication year: ";
            cin >> temp->publicationYear;

            cout << "\nAll details updated successfully!\n";
        }

        else
        {
            cout << "\nInvalid choice!\n";
        }
    }


    // 5. Display All Books
    void displayBooks()
    {
        if (head == NULL)
        {
            cout << "\nBook list is empty.\n";
            return;
        }

        Node *temp = head;

        cout << "\n";
        cout << "====================================================\n";
        cout << "                 ALL BOOKS\n";
        cout << "====================================================\n";

        int count = 1;

        while (temp != NULL)
        {
            cout << "\nBook " << count << endl;
            cout << "--------------------------------------------\n";
            cout << "Book ID          : " << temp->bookID << endl;
            cout << "Title            : " << temp->title << endl;
            cout << "Author           : " << temp->author << endl;
            cout << "Price            : " << temp->price << endl;
            cout << "Publication Year : "
                 << temp->publicationYear << endl;

            temp = temp->next;
            count++;
        }

        cout << "\n====================================================\n";
    }


    // 6. Find Total Books
    void totalBooks()
    {
        int count = 0;

        Node *temp = head;

        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }

        cout << "\nTotal number of books: " << count << endl;
    }


    // Destructor
    ~BookList()
    {
        Node *temp;

        while (head != NULL)
        {
            temp = head;
            head = head->next;
            delete temp;
        }

        tail = NULL;
    }
};


// Main Function
int main()
{
    BookList books;

    int choice;

    do
    {
        cout << "\n\n";
        cout << "==============================================\n";
        cout << "          BOOKSTORE MANAGEMENT SYSTEM\n";
        cout << "        DOUBLY LINKED LIST\n";
        cout << "==============================================\n";

        cout << "1. Add Book\n";
        cout << "2. Remove Book\n";
        cout << "3. Search Book\n";
        cout << "4. Update Book\n";
        cout << "5. Display All Books\n";
        cout << "6. Find Total Books\n";
        cout << "7. Exit\n";

        cout << "==============================================\n";

        cout << "Enter your choice: ";
        cin >> choice;


        switch (choice)
        {
        case 1:
            books.addBook();
            break;

        case 2:
            books.removeBook();
            break;

        case 3:
            books.searchBook();
            break;

        case 4:
            books.updateBook();
            break;

        case 5:
            books.displayBooks();
            break;

        case 6:
            books.totalBooks();
            break;

        case 7:
            cout << "\nProgram terminated successfully.\n";
            break;

        default:
            cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 7);


    return 0;
}