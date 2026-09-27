#include <iostream>
#include <string>
#include <stack>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;

    Node(char ch) {
        data = ch;
        left = NULL;
        right = NULL;
    }
};

// Check whether character is operator
bool isOperator(char ch) {
    return (ch == '+' || ch == '-' ||
            ch == '*' || ch == '/' ||
            ch == '^');
}

// Construct expression tree from prefix
Node* constructTree(string prefix) {

    stack<Node*> st;

    // Read prefix from right to left
    for (int i = prefix.length() - 1; i >= 0; i--) {

        char ch = prefix[i];

        // Ignore spaces
        if (ch == ' ')
            continue;

        Node* newNode = new Node(ch);

        if (!isOperator(ch)) {
            // Operand
            st.push(newNode);
        }
        else {
            // Operator
            newNode->left = st.top();
            st.pop();

            newNode->right = st.top();
            st.pop();

            st.push(newNode);
        }
    }

    return st.top();
}

// Non-recursive postorder traversal
void postorder(Node* root) {

    if (root == NULL)
        return;

    stack<Node*> s1, s2;

    s1.push(root);

    while (!s1.empty()) {

        Node* temp = s1.top();
        s1.pop();

        s2.push(temp);

        if (temp->left != NULL)
            s1.push(temp->left);

        if (temp->right != NULL)
            s1.push(temp->right);
    }

    cout << "Postorder Traversal: ";

    while (!s2.empty()) {
        cout << s2.top()->data << " ";
        s2.pop();
    }

    cout << endl;
}

// Delete entire tree using postorder
void deleteTree(Node* root) {

    if (root == NULL)
        return;

    stack<Node*> s1, s2;

    s1.push(root);

    while (!s1.empty()) {

        Node* temp = s1.top();
        s1.pop();

        s2.push(temp);

        if (temp->left != NULL)
            s1.push(temp->left);

        if (temp->right != NULL)
            s1.push(temp->right);
    }

    while (!s2.empty()) {

        Node* temp = s2.top();
        s2.pop();

        delete temp;
    }

    cout << "Entire tree deleted successfully.\n";
}

int main() {

    Node* root = NULL;
    string prefix;
    int choice;

    do {

        cout << "\n========== EXPRESSION TREE ==========\n";
        cout << "1. Enter Prefix Expression\n";
        cout << "2. Construct Expression Tree\n";
        cout << "3. Non-Recursive Postorder Traversal\n";
        cout << "4. Delete Entire Tree\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter Prefix Expression: ";
            cin >> prefix;

            cout << "Prefix Expression: "
                 << prefix << endl;
            break;

        case 2:
            if (prefix.empty()) {
                cout << "Enter prefix expression first!\n";
            }
            else {
                root = constructTree(prefix);

                cout << "Expression tree constructed successfully.\n";
            }
            break;

        case 3:
            if (root == NULL) {
                cout << "Tree is empty!\n";
            }
            else {
                postorder(root);
            }
            break;

        case 4:
            if (root == NULL) {
                cout << "Tree is already empty!\n";
            }
            else {
                deleteTree(root);
                root = NULL;
            }
            break;

        case 5:
            cout << "Program ended.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}