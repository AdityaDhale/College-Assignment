#include <iostream>
using namespace std;

class Set
{
private:
    int elements[100];
    int count;

public:

    // Constructor
    Set()
    {
        count = 0;
    }

    // Add a new element to the set
    void add(int value)
    {
        if (count == 100)
        {
            cout << "Set is full." << endl;
            return;
        }

        // Check if element already exists
        if (contains(value))
        {
            cout << value << " already exists in the set." << endl;
            return;
        }

        elements[count] = value;
        count++;

        cout << value << " added to the set." << endl;
    }

    // Remove an element from the set
    void remove(int value)
    {
        int position = -1;

        for (int i = 0; i < count; i++)
        {
            if (elements[i] == value)
            {
                position = i;
                break;
            }
        }

        if (position == -1)
        {
            cout << value << " not found in the set." << endl;
            return;
        }

        // Shift elements to the left
        for (int i = position; i < count - 1; i++)
        {
            elements[i] = elements[i + 1];
        }

        count--;

        cout << value << " removed from the set." << endl;
    }

    // Check whether an element exists
    bool contains(int value)
    {
        for (int i = 0; i < count; i++)
        {
            if (elements[i] == value)
            {
                return true;
            }
        }

        return false;
    }

    // Return number of elements
    int size()
    {
        return count;
    }

    // Iterator - display all elements
    void iterator()
    {
        if (count == 0)
        {
            cout << "Set is empty." << endl;
            return;
        }

        cout << "Set elements: ";

        for (int i = 0; i < count; i++)
        {
            cout << elements[i] << " ";
        }

        cout << endl;
    }

    // Union of two sets
    Set unionSet(Set secondSet)
    {
        Set result;

        // Add all elements of first set
        for (int i = 0; i < count; i++)
        {
            result.add(elements[i]);
        }

        // Add elements of second set
        for (int i = 0; i < secondSet.count; i++)
        {
            result.add(secondSet.elements[i]);
        }

        return result;
    }

    // Difference: elements present in first set but not second
    Set difference(Set secondSet)
    {
        Set result;

        for (int i = 0; i < count; i++)
        {
            if (!secondSet.contains(elements[i]))
            {
                result.add(elements[i]);
            }
        }

        return result;
    }

    // Check whether current set is a subset of another set
    bool isSubset(Set secondSet)
    {
        for (int i = 0; i < count; i++)
        {
            if (!secondSet.contains(elements[i]))
            {
                return false;
            }
        }

        return true;
    }
};


int main()
{
    Set setA, setB, result;

    int choice;
    int value;

    do
    {
        cout << "\n========== SET ADT ==========" << endl;
        cout << "1. Add element to Set A" << endl;
        cout << "2. Remove element from Set A" << endl;
        cout << "3. Check element in Set A" << endl;
        cout << "4. Display Set A" << endl;
        cout << "5. Display size of Set A" << endl;
        cout << "6. Add element to Set B" << endl;
        cout << "7. Display Set B" << endl;
        cout << "8. Union of A and B" << endl;
        cout << "9. Difference A - B" << endl;
        cout << "10. Check A is subset of B" << endl;
        cout << "11. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            setA.add(value);
            break;

        case 2:
            cout << "Enter value to remove: ";
            cin >> value;
            setA.remove(value);
            break;

        case 3:
            cout << "Enter value to search: ";
            cin >> value;

            if (setA.contains(value))
            {
                cout << value << " is present in Set A." << endl;
            }
            else
            {
                cout << value << " is not present in Set A." << endl;
            }
            break;

        case 4:
            cout << "Set A: ";
            setA.iterator();
            break;

        case 5:
            cout << "Size of Set A: "
                 << setA.size() << endl;
            break;

        case 6:
            cout << "Enter value: ";
            cin >> value;
            setB.add(value);
            break;

        case 7:
            cout << "Set B: ";
            setB.iterator();
            break;

        case 8:
            result = setA.unionSet(setB);

            cout << "Union of A and B: ";
            result.iterator();
            break;

        case 9:
            result = setA.difference(setB);

            cout << "Difference (A - B): ";
            result.iterator();
            break;

        case 10:
            if (setA.isSubset(setB))
            {
                cout << "Set A is a subset of Set B." << endl;
            }
            else
            {
                cout << "Set A is not a subset of Set B." << endl;
            }
            break;

        case 11:
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 11);

    return 0;
}