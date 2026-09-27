#include <iostream>
using namespace std;

int main() {
    int num, original, remainder;
    int sum = 0;
    int digits = 0;

    cout << "Enter a number: ";
    cin >> num;

    original = num;

    // Count digits
    int temp = num;
    while (temp != 0) {
        digits++;
        temp = temp / 10;
    }

    // Calculate Armstrong sum
    temp = num;

    while (temp != 0) {
        remainder = temp % 10;

        int power = 1;
        for (int i = 1; i <= digits; i++) {
            power = power * remainder;
        }

        sum = sum + power;
        temp = temp / 10;
    }

    // Check result
    if (sum == original) {
        cout << num << " is an Armstrong number.";
    } else {
        cout << num << " is not an Armstrong number.";
    }

    return 0;
}
