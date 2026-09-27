#include <iostream>
#include <string>
using namespace std;

struct Node {
    int id;
    string name;
    float price;
    int quantity;
    float totalValue;

    int height;

    Node* left;
    Node* right;

    Node(int i, string n, float p, int q) {
        id = i;
        name = n;
        price = p;
        quantity = q;
        totalValue = price * quantity;

        height = 1;
        left = NULL;
        right = NULL;
    }
};

// Get height
int getHeight(Node* root) {
    if (root == NULL)
        return 0;

    return root->height;
}

// Maximum of two numbers
int maxValue(int a, int b) {
    return (a > b) ? a : b;
}

// Get balance factor
int getBalance(Node* root) {
    if (root == NULL)
        return 0;

    return getHeight(root->left) -
           getHeight(root->right);
}

// Right Rotation
Node* rightRotate(Node* y) {

    Node* x = y->left;
    Node* T = x->right;

    x->right = y;
    y->left = T;

    y->height = 1 + maxValue(
        getHeight(y->left),
        getHeight(y->right));

    x->height = 1 + maxValue(
        getHeight(x->left),
        getHeight(x->right));

    return x;
}

// Left Rotation
Node* leftRotate(Node* x) {

    Node* y = x->right;
    Node* T = y->left;

    y->left = x;
    x->right = T;

    x->height = 1 + maxValue(
        getHeight(x->left),
        getHeight(x->right));

    y->height = 1 + maxValue(
        getHeight(y->left),
        getHeight(y->right));

    return y;
}

// Insert item into AVL tree
Node* insert(Node* root, int id, string name,
             float price, int quantity) {

    // Normal BST insertion
    if (root == NULL)
        return new Node(id, name, price, quantity);

    if (id < root->id) {
        root->left =
            insert(root->left, id, name,
                   price, quantity);
    }
    else if (id > root->id) {
        root->right =
            insert(root->right, id, name,
                   price, quantity);
    }
    else {
        cout << "Item ID already exists!\n";
        return root;
    }

    // Update height
    root->height = 1 + maxValue(
        getHeight(root->left),
        getHeight(root->right));

    // Calculate balance
    int balance = getBalance(root);

    // LL Case
    if (balance > 1 && id < root->left->id)
        return rightRotate(root);

    // RR Case
    if (balance < -1 && id > root->right->id)
        return leftRotate(root);

    // LR Case
    if (balance > 1 && id > root->left->id) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RL Case
    if (balance < -1 && id < root->right->id) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Find most valuable item
void findMostValuable(Node* root, Node*& maxNode) {

    if (root == NULL)
        return;

    if (maxNode == NULL ||
        root->totalValue > maxNode->totalValue) {
        maxNode = root;
    }

    findMostValuable(root->left, maxNode);
    findMostValuable(root->right, maxNode);
}

// Calculate total value of all products
float calculateTotalValue(Node* root) {

    if (root == NULL)
        return 0;

    return root->totalValue +
           calculateTotalValue(root->left) +
           calculateTotalValue(root->right);
}

// Display inventory
void display(Node* root) {

    if (root == NULL)
        return;

    display(root->left);

    cout << "ID: " << root->id
         << " | Name: " << root->name
         << " | Price: " << root->price
         << " | Quantity: " << root->quantity
         << " | Total Value: "
         << root->totalValue << endl;

    display(root->right);
}

int main() {

    Node* root = NULL;
    int choice;

    do {

        cout << "\n========== INVENTORY AVL MENU ==========\n";
        cout << "1. Add Inventory Item\n";
        cout << "2. Display Inventory\n";
        cout << "3. Find Most Valuable Item\n";
        cout << "4. Calculate Total Value\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1: {
            int id;
            string name;
            float price;
            int quantity;

            cout << "\nEnter Item ID: ";
            cin >> id;

            cout << "Enter Item Name: ";
            cin >> name;

            cout << "Enter Price: ";
            cin >> price;

            cout << "Enter Quantity: ";
            cin >> quantity;

            root = insert(root, id, name,
                          price, quantity);

            cout << "Item added successfully!\n";

            break;
        }

        case 2: {
            if (root == NULL)
                cout << "Inventory is empty!\n";
            else {
                cout << "\n========== INVENTORY ==========\n";
                display(root);
            }

            break;
        }

        case 3: {
            if (root == NULL) {
                cout << "Inventory is empty!\n";
            }
            else {
                Node* maxNode = NULL;

                findMostValuable(root, maxNode);

                cout << "\nMost Valuable Item\n";
                cout << "Item ID: "
                     << maxNode->id << endl;
                cout << "Item Name: "
                     << maxNode->name << endl;
                cout << "Price: "
                     << maxNode->price << endl;
                cout << "Quantity: "
                     << maxNode->quantity << endl;
                cout << "Total Value: "
                     << maxNode->totalValue << endl;
            }

            break;
        }

        case 4: {
            float total = calculateTotalValue(root);

            cout << "\nTotal Value of All Products = "
                 << total << endl;

            break;
        }

        case 5:
            cout << "Program ended.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}