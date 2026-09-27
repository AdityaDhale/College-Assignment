#include <iostream>
#include <string>
using namespace std;

struct Employee {
    string name;
    string role;

    Employee* child;     // First subordinate
    Employee* sibling;   // Next employee at same level

    Employee(string n, string r) {
        name = n;
        role = r;
        child = NULL;
        sibling = NULL;
    }
};

// Add employee under a manager
bool addEmployee(Employee* root, string manager,
                  string name, string role) {

    if (root == NULL)
        return false;

    // Manager found
    if (root->name == manager) {

        Employee* newEmployee =
            new Employee(name, role);

        // If manager has no employee
        if (root->child == NULL) {
            root->child = newEmployee;
        }
        else {
            // Go to last subordinate
            Employee* temp = root->child;

            while (temp->sibling != NULL)
                temp = temp->sibling;

            temp->sibling = newEmployee;
        }

        return true;
    }

    // Search in children
    if (addEmployee(root->child, manager, name, role))
        return true;

    // Search in siblings
    if (addEmployee(root->sibling, manager, name, role))
        return true;

    return false;
}

// Display hierarchy
void display(Employee* root, int level = 0) {

    if (root == NULL)
        return;

    for (int i = 0; i < level; i++)
        cout << "   ";

    cout << root->name
         << " (" << root->role << ")" << endl;

    display(root->child, level + 1);
    display(root->sibling, level);
}

// Find longest reporting chain
int longestChain(Employee* root) {

    if (root == NULL)
        return 0;

    int maxDepth = 0;

    Employee* temp = root->child;

    while (temp != NULL) {

        int depth = longestChain(temp);

        if (depth > maxDepth)
            maxDepth = depth;

        temp = temp->sibling;
    }

    return maxDepth + 1;
}

// Find least senior employee
void findLeastSenior(Employee* root,
                     Employee*& result,
                     int depth,
                     int& maxDepth) {

    if (root == NULL)
        return;

    if (depth > maxDepth) {
        maxDepth = depth;
        result = root;
    }

    findLeastSenior(root->child,
                    result,
                    depth + 1,
                    maxDepth);

    findLeastSenior(root->sibling,
                    result,
                    depth,
                    maxDepth);
}

// Search employee
bool searchEmployee(Employee* root, string name) {

    if (root == NULL)
        return false;

    if (root->name == name)
        return true;

    if (searchEmployee(root->child, name))
        return true;

    return searchEmployee(root->sibling, name);
}

int main() {

    Employee* CEO = NULL;

    int choice;

    do {

        cout << "\n========== ORGANIZATION MENU ==========\n";
        cout << "1. Create CEO\n";
        cout << "2. Add Employee\n";
        cout << "3. Display Organization\n";
        cout << "4. Find Longest Reporting Chain\n";
        cout << "5. Find Least Senior Employee\n";
        cout << "6. Search Employee\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1: {
            if (CEO != NULL) {
                cout << "CEO already exists!\n";
                break;
            }

            string name, role;

            cout << "Enter CEO name: ";
            cin >> name;

            cout << "Enter CEO role: ";
            cin >> role;

            CEO = new Employee(name, role);

            cout << "CEO created successfully.\n";
            break;
        }

        case 2: {
            if (CEO == NULL) {
                cout << "First create the CEO!\n";
                break;
            }

            string manager;
            string name;
            string role;

            cout << "Enter manager name: ";
            cin >> manager;

            cout << "Enter employee name: ";
            cin >> name;

            cout << "Enter employee role: ";
            cin >> role;

            if (addEmployee(CEO, manager,
                            name, role)) {

                cout << "Employee added successfully.\n";
            }
            else {
                cout << "Manager not found!\n";
            }

            break;
        }

        case 3: {
            if (CEO == NULL) {
                cout << "Organization is empty!\n";
            }
            else {
                cout << "\nOrganization Hierarchy:\n";
                display(CEO);
            }

            break;
        }

        case 4: {
            if (CEO == NULL) {
                cout << "Organization is empty!\n";
            }
            else {
                cout << "Longest Reporting Chain = "
                     << longestChain(CEO)
                     << " employees\n";
            }

            break;
        }

        case 5: {
            if (CEO == NULL) {
                cout << "Organization is empty!\n";
            }
            else {

                Employee* result = NULL;
                int maxDepth = -1;

                findLeastSenior(CEO,
                                result,
                                0,
                                maxDepth);

                cout << "Least Senior Employee: "
                     << result->name
                     << " (" << result->role << ")\n";
            }

            break;
        }

        case 6: {
            if (CEO == NULL) {
                cout << "Organization is empty!\n";
                break;
            }

            string name;

            cout << "Enter employee name to search: ";
            cin >> name;

            if (searchEmployee(CEO, name))
                cout << name
                     << " is part of the organization.\n";
            else
                cout << name
                     << " is NOT part of the organization.\n";

            break;
        }

        case 7:
            cout << "Program ended.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 7);

    return 0;
}