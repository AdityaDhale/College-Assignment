#include <iostream>
#include <string>
using namespace std;

// Node of the tree
struct Node
{
    string name;
    Node* child;
    Node* sibling;

    Node(string n)
    {
        name = n;
        child = NULL;
        sibling = NULL;
    }
};

// Add a child node
void addChild(Node* parent, Node* newNode)
{
    if (parent->child == NULL)
    {
        parent->child = newNode;
    }
    else
    {
        Node* temp = parent->child;

        while (temp->sibling != NULL)
        {
            temp = temp->sibling;
        }

        temp->sibling = newNode;
    }
}

// Display the tree
void display(Node* root, int level = 0)
{
    if (root == NULL)
        return;

    // Print indentation
    for (int i = 0; i < level; i++)
    {
        cout << "    ";
    }

    cout << root->name << endl;

    // Display children
    display(root->child, level + 1);

    // Display next sibling
    display(root->sibling, level);
}

int main()
{
    string bookName;
    int chapters, sections, subsections;

    cout << "Enter Book Name: ";
    getline(cin, bookName);

    Node* book = new Node("Book: " + bookName);

    cout << "\nEnter number of chapters: ";
    cin >> chapters;
    cin.ignore();

    for (int i = 1; i <= chapters; i++)
    {
        string chapterName;

        cout << "\nEnter Chapter " << i << " name: ";
        getline(cin, chapterName);

        Node* chapter = new Node("Chapter " + to_string(i) + ": " + chapterName);
        addChild(book, chapter);

        cout << "Enter number of sections in Chapter " << i << ": ";
        cin >> sections;
        cin.ignore();

        for (int j = 1; j <= sections; j++)
        {
            string sectionName;

            cout << "Enter Section " << j << " name: ";
            getline(cin, sectionName);

            Node* section = new Node(
                "Section " + to_string(j) + ": " + sectionName
            );

            addChild(chapter, section);

            cout << "Enter number of subsections in Section "
                 << j << ": ";
            cin >> subsections;
            cin.ignore();

            for (int k = 1; k <= subsections; k++)
            {
                string subsectionName;

                cout << "Enter Subsection " << k << " name: ";
                getline(cin, subsectionName);

                Node* subsection = new Node(
                    "Subsection " + to_string(k) + ": " + subsectionName
                );

                addChild(section, subsection);
            }
        }
    }



    display(book);


    return 0;
}