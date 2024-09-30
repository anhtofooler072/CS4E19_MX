#include <iostream>

using namespace std;

int sumOfDiviser(int input) {
    int sum = 0;
    for (int i = 1; i <= input; i++) {
        if (input % i == 0) {
            sum += i;
        }
    }
    return sum;
}

int main() {
    int numOfTest;
    cout << "Enter the number of test cases: ";
    cin >> numOfTest;

    int arr[numOfTest];
    for (int i = 0; i < numOfTest; i++) {
        int input;
        cout << "Enter the number at index " << i << ": ";
        cin >> input;
        arr[i] = sumOfDiviser(input);
    }

    for (int i = 0; i < numOfTest; i++) {
        cout << arr[i] << endl;
    }
}