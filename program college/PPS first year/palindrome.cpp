#include <iostream>
#include <string>
using namespace std;

int main() {
    string str, reverse = "";

    cout << "Enter a string: ";
    cin >> str;

    // Reverse the string
    for (int i = str.length() - 1; i >= 0; i--) {
        reverse = reverse + str[i];
    }

    // Check palindrome
    if (str == reverse) {
        cout << str << " is a Palindrome.";
    } else {
        cout << str << " is not a Palindrome.";
    }

    return 0;
}
