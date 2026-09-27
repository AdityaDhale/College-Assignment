#include <iostream>
#include <string>
using namespace std;

const int SIZE = 10;

// Structure for product
struct Product
{
    int productID;
    string stockDetails;
};

// Node for separate chaining
struct Node
{
    Product product;
    Node *next;
};

// Hash function
int hashFunction(int productID)
{
    return productID % SIZE;
}


// ================= CHAINING =================

class ChainingHashTable
{
    Node *table[SIZE];

public:

    ChainingHashTable()
    {
        for (int i = 0; i < SIZE; i++)
        {
            table[i] = NULL;
        }
    }

    // Insert product using chaining
    void insert(int id, string details)
    {
        int index = hashFunction(id);

        Node *newNode = new Node;

        newNode->product.productID = id;
        newNode->product.stockDetails = details;
        newNode->next = table[index];

        table[index] = newNode;

        cout << "Product " << id
             << " inserted using chaining." << endl;
    }

    // Search product
    void search(int id)
    {
        int index = hashFunction(id);

        Node *temp = table[index];

        while (temp != NULL)
        {
            if (temp->product.productID == id)
            {
                cout << "Product ID: " << id << endl;
                cout << "Stock Details: "
                     << temp->product.stockDetails << endl;
                return;
            }

            temp = temp->next;
        }

        cout << "Product not found." << endl;
    }

    // Display hash table
    void display()
    {
        cout << "\n--- Separate Chaining ---" << endl;

        for (int i = 0; i < SIZE; i++)
        {
            cout << i << " : ";

            Node *temp = table[i];

            while (temp != NULL)
            {
                cout << "[" << temp->product.productID
                     << ", " << temp->product.stockDetails << "] -> ";

                temp = temp->next;
            }

            cout << "NULL" << endl;
        }
    }
};


// ================= LINEAR PROBING =================

class LinearProbingHashTable
{
    Product table[SIZE];
    bool occupied[SIZE];

public:

    LinearProbingHashTable()
    {
        for (int i = 0; i < SIZE; i++)
        {
            occupied[i] = false;
        }
    }

    // Insert product using linear probing
    void insert(int id, string details)
    {
        int index = hashFunction(id);
        int start = index;

        while (occupied[index])
        {
            index = (index + 1) % SIZE;

            if (index == start)
            {
                cout << "Hash table is full." << endl;
                return;
            }
        }

        table[index].productID = id;
        table[index].stockDetails = details;
        occupied[index] = true;

        cout << "Product " << id
             << " inserted using linear probing." << endl;
    }

    // Search product
    void search(int id)
    {
        int index = hashFunction(id);
        int start = index;

        while (occupied[index])
        {
            if (table[index].productID == id)
            {
                cout << "Product ID: " << id << endl;
                cout << "Stock Details: "
                     << table[index].stockDetails << endl;
                return;
            }

            index = (index + 1) % SIZE;

            if (index == start)
                break;
        }

        cout << "Product not found." << endl;
    }

    // Display hash table
    void display()
    {
        cout << "\n--- Linear Probing ---" << endl;

        for (int i = 0; i < SIZE; i++)
        {
            cout << i << " : ";

            if (occupied[i])
            {
                cout << "[" << table[i].productID
                     << ", " << table[i].stockDetails << "]";
            }
            else
            {
                cout << "Empty";
            }

            cout << endl;
        }
    }
};


// ================= MAIN =================

int main()
{
    ChainingHashTable chaining;
    LinearProbingHashTable probing;

    int choice;
    int id;
    string details;

    do
    {
        cout << "\n========== PRODUCT INVENTORY ==========" << endl;
        cout << "1. Insert Product" << endl;
        cout << "2. Search Product using Chaining" << endl;
        cout << "3. Search Product using Linear Probing" << endl;
        cout << "4. Display Chaining Table" << endl;
        cout << "5. Display Linear Probing Table" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Product ID: ";
            cin >> id;

            cin.ignore();

            cout << "Enter Stock Details: ";
            getline(cin, details);

            chaining.insert(id, details);
            probing.insert(id, details);
            break;

        case 2:
            cout << "Enter Product ID to search: ";
            cin >> id;

            chaining.search(id);
            break;

        case 3:
            cout << "Enter Product ID to search: ";
            cin >> id;

            probing.search(id);
            break;

        case 4:
            chaining.display();
            break;

        case 5:
            probing.display();
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