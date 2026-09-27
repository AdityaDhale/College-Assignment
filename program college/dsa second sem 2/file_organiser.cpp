#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Book
{
    int id;
    char title[50];
    char author[50];
    char genre[30];
    char availability[15];
};

// Add a new book
void addBook()
{
    Book b;

    cout << "\nEnter Book ID: ";
    cin >> b.id;
    cin.ignore();

    cout << "Enter Title: ";
    cin.getline(b.title, 50);

    cout << "Enter Author: ";
    cin.getline(b.author, 50);

    cout << "Enter Genre: ";
    cin.getline(b.genre, 30);

    cout << "Enter Availability (Available/Issued): ";
    cin.getline(b.availability, 15);

    ofstream file("books.dat", ios::binary | ios::app);
    file.write((char*)&b, sizeof(b));
    file.close();

    cout << "Book added successfully.\n";
}

// Display all books
void displayBooks()
{
    Book b;

    ifstream file("books.dat", ios::binary);

    cout << "\n--- Book Records ---\n";

    while (file.read((char*)&b, sizeof(b)))
    {
        cout << "\nBook ID: " << b.id;
        cout << "\nTitle: " << b.title;
        cout << "\nAuthor: " << b.author;
        cout << "\nGenre: " << b.genre;
        cout << "\nAvailability: " << b.availability << endl;
    }

    file.close();
}

// Search book by ID
void searchBook()
{
    int id;
    bool found = false;
    Book b;

    cout << "\nEnter Book ID to search: ";
    cin >> id;

    ifstream file("books.dat", ios::binary);

    while (file.read((char*)&b, sizeof(b)))
    {
        if (b.id == id)
        {
            cout << "\nBook Found!";
            cout << "\nBook ID: " << b.id;
            cout << "\nTitle: " << b.title;
            cout << "\nAuthor: " << b.author;
            cout << "\nGenre: " << b.genre;
            cout << "\nAvailability: " << b.availability << endl;

            found = true;
            break;
        }
    }

    file.close();

    if (!found)
        cout << "Book record does not exist.\n";
}

// Delete book
void deleteBook()
{
    int id;
    Book b;
    bool found = false;

    cout << "\nEnter Book ID to delete: ";
    cin >> id;

    ifstream file("books.dat", ios::binary);
    ofstream temp("temp.dat", ios::binary);

    while (file.read((char*)&b, sizeof(b)))
    {
        if (b.id == id)
        {
            found = true;
            continue;
        }

        temp.write((char*)&b, sizeof(b));
    }

    file.close();
    temp.close();

    remove("books.dat");
    rename("temp.dat", "books.dat");

    if (found)
        cout << "Book deleted successfully.\n";
    else
        cout << "Book record does not exist.\n";
}

// Update book
void updateBook()
{
    int id;
    Book b;
    bool found = false;

    cout << "\nEnter Book ID to update: ";
    cin >> id;

    fstream file("books.dat", ios::binary | ios::in | ios::out);

    while (file.read((char*)&b, sizeof(b)))
    {
        if (b.id == id)
        {
            cin.ignore();

            cout << "Enter New Title: ";
            cin.getline(b.title, 50);

            cout << "Enter New Author: ";
            cin.getline(b.author, 50);

            cout << "Enter New Genre: ";
            cin.getline(b.genre, 30);

            cout << "Enter New Availability: ";
            cin.getline(b.availability, 15);

            file.seekp(-sizeof(b), ios::cur);
            file.write((char*)&b, sizeof(b));

            found = true;
            break;
        }
    }

    file.close();

    if (found)
        cout << "Book updated successfully.\n";
    else
        cout << "Book record does not exist.\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n\n===== LIBRARY MANAGEMENT SYSTEM =====";
        cout << "\n1. Add Book";
        cout << "\n2. Display Books";
        cout << "\n3. Search Book";
        cout << "\n4. Update Book";
        cout << "\n5. Delete Book";
        cout << "\n6. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addBook();
            break;

        case 2:
            displayBooks();
            break;

        case 3:
            searchBook();
            break;

        case 4:
            updateBook();
            break;

        case 5:
            deleteBook();
            break;

        case 6:
            cout << "Exiting program...";
            break;

        default:
            cout << "Invalid choice!";
        }

    } while (choice != 6);

    return 0;
}