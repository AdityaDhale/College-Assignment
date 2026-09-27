#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string text = "";
string filename = "";

// Create new file
void newFile()
{
    text = "";
    filename = "";

    cout << "\nNew file created.\n";
}

// Open existing file
void openFile()
{
    cout << "Enter file name: ";
    cin >> filename;

    ifstream file(filename);

    if (!file)
    {
        cout << "File not found!\n";
        return;
    }

    text = "";
    string line;

    while (getline(file, line))
    {
        text += line + "\n";
    }

    file.close();

    cout << "\nFile opened successfully.\n";
    cout << "\nContent:\n";
    cout << text;
}

// Write text
void writeText()
{
    cin.ignore();

    cout << "\nEnter text (type END on a new line to finish):\n";

    string line;

    while (true)
    {
        getline(cin, line);

        if (line == "END")
            break;

        text += line + "\n";
    }
}

// Display text
void displayText()
{
    cout << "\n----- Document -----\n";

    if (text == "")
        cout << "Document is empty.\n";
    else
        cout << text;

    cout << "--------------------\n";
}

// Save file
void saveFile()
{
    if (filename == "")
    {
        cout << "Enter file name: ";
        cin >> filename;
    }

    ofstream file(filename);

    file << text;

    file.close();

    cout << "\nFile saved successfully.\n";
}

// Search word
void searchText()
{
    string word;

    cin.ignore();

    cout << "Enter word to search: ";
    getline(cin, word);

    if (text.find(word) != string::npos)
        cout << "Word found in the document.\n";
    else
        cout << "Word not found.\n";
}

// Edit document
void editText()
{
    cout << "\nCurrent text:\n";
    displayText();

    writeText();

    cout << "Text updated successfully.\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n===== SMART TEXT EDITOR =====\n";
        cout << "1. New File\n";
        cout << "2. Open File\n";
        cout << "3. Write Text\n";
        cout << "4. Display Text\n";
        cout << "5. Search Text\n";
        cout << "6. Edit Text\n";
        cout << "7. Save File\n";
        cout << "8. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            newFile();
            break;

        case 2:
            openFile();
            break;

        case 3:
            writeText();
            break;

        case 4:
            displayText();
            break;

        case 5:
            searchText();
            break;

        case 6:
            editText();
            break;

        case 7:
            saveFile();
            break;

        case 8:
            cout << "\nThank you for using Smart Text Editor!\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 8);

    return 0;
}