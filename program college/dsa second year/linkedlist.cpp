#include <iostream>
#include <string>
using namespace std;

// Node structure
struct Node
{
    int prn;
    string name;
    Node *next;
};

// Class for Pinnacle Club
class PinnacleClub
{
private:
    Node *head;

public:

    // Constructor
    PinnacleClub()
    {
        head = NULL;
    }

    // Function to add President
    void addPresident(int prn, string name)
    {
        Node *newNode = new Node;

        newNode->prn = prn;
        newNode->name = name;
        newNode->next = head;

        head = newNode;

        cout << "\nPresident added successfully.\n";
    }

    // Function to add Secretary
    void addSecretary(int prn, string name)
    {
        Node *newNode = new Node;

        newNode->prn = prn;
        newNode->name = name;
        newNode->next = NULL;

        // If list is empty
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

        cout << "\nSecretary added successfully.\n";
    }

    // Function to add normal member
    void addMember(int prn, string name)
    {
        Node *newNode = new Node;

        newNode->prn = prn;
        newNode->name = name;
        newNode->next = NULL;

        // If list is empty
        if (head == NULL)
        {
            head = newNode;
            cout << "\nMember added successfully.\n";
            return;
        }

        // If only one member exists,
        // add after president
        if (head->next == NULL)
        {
            head->next = newNode;
            cout << "\nMember added successfully.\n";
            return;
        }

        // Find the last node
        // and insert before secretary
        Node *temp = head;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;

        cout << "\nMember added successfully.\n";
    }

    // Function to delete a member by PRN
    void deleteMember(int prn)
    {
        if (head == NULL)
        {
            cout << "\nClub is empty.\n";
            return;
        }

        // Delete first node
        if (head->prn == prn)
        {
            Node *temp = head;
            head = head->next;

            delete temp;

            cout << "\nMember deleted successfully.\n";
            return;
        }

        Node *temp = head;

        while (temp->next != NULL &&
               temp->next->prn != prn)
        {
            temp = temp->next;
        }

        // Member not found
        if (temp->next == NULL)
        {
            cout << "\nMember with PRN " << prn
                 << " not found.\n";
            return;
        }

        Node *deleteNode = temp->next;

        temp->next = deleteNode->next;

        delete deleteNode;

        cout << "\nMember deleted successfully.\n";
    }

    // Function to count total members
    int countMembers()
    {
        int count = 0;

        Node *temp = head;

        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }

        return count;
    }

    // Function to display members
    void displayMembers()
    {
        if (head == NULL)
        {
            cout << "\nClub is empty.\n";
            return;
        }

        Node *temp = head;
        int count = 1;

        cout << "\n";
        cout << "============================================\n";
        cout << "          PINNACLE CLUB MEMBERS\n";
        cout << "============================================\n";

        while (temp != NULL)
        {
            if (temp == head)
            {
                cout << "President";
            }
            else if (temp->next == NULL)
            {
                cout << "Secretary";
            }
            else
            {
                cout << "Member";
            }

            cout << "  ->  PRN: " << temp->prn
                 << ", Name: " << temp->name << endl;

            temp = temp->next;
            count++;
        }

        cout << "============================================\n";
    }

    // Function to concatenate another list
    void concatenate(PinnacleClub &club2)
    {
        if (club2.head == NULL)
        {
            cout << "\nSecond division is empty.\n";
            return;
        }

        if (head == NULL)
        {
            head = club2.head;
            club2.head = NULL;

            cout << "\nLists concatenated successfully.\n";
            return;
        }

        Node *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = club2.head;

        club2.head = NULL;

        cout << "\nLists concatenated successfully.\n";
    }
};


// Main function
int main()
{
    PinnacleClub divisionA;
    PinnacleClub divisionB;

    int choice;
    int prn;
    string name;

    do
    {
        cout << "\n\n";
        cout << "============================================\n";
        cout << "       PINNACLE CLUB MANAGEMENT SYSTEM\n";
        cout << "============================================\n";
        cout << "1. Add President\n";
        cout << "2. Add Member\n";
        cout << "3. Add Secretary\n";
        cout << "4. Delete Member\n";
        cout << "5. Display Members\n";
        cout << "6. Count Total Members\n";
        cout << "7. Add Member to Division B\n";
        cout << "8. Display Division B\n";
        cout << "9. Concatenate Division A and Division B\n";
        cout << "10. Exit\n";
        cout << "============================================\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\nEnter President PRN: ";
            cin >> prn;

            cout << "Enter President Name: ";
            cin >> name;

            divisionA.addPresident(prn, name);
            break;


        case 2:
            cout << "\nEnter Member PRN: ";
            cin >> prn;

            cout << "Enter Member Name: ";
            cin >> name;

            divisionA.addMember(prn, name);
            break;


        case 3:
            cout << "\nEnter Secretary PRN: ";
            cin >> prn;

            cout << "Enter Secretary Name: ";
            cin >> name;

            divisionA.addSecretary(prn, name);
            break;


        case 4:
            cout << "\nEnter PRN to delete: ";
            cin >> prn;

            divisionA.deleteMember(prn);
            break;


        case 5:
            divisionA.displayMembers();
            break;


        case 6:
            cout << "\nTotal number of members = "
                 << divisionA.countMembers() << endl;
            break;


        case 7:
            cout << "\nEnter Member PRN for Division B: ";
            cin >> prn;

            cout << "Enter Member Name: ";
            cin >> name;

            divisionB.addMember(prn, name);
            break;


        case 8:
            divisionB.displayMembers();
            break;


        case 9:
            divisionA.concatenate(divisionB);

            cout << "\nAfter concatenation:";
            divisionA.displayMembers();
            break;


        case 10:
            cout << "\nProgram terminated successfully.\n";
            break;


        default:
            cout << "\nInvalid choice!";
        }

    } while (choice != 10);

    return 0;
}