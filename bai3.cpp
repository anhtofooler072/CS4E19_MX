#include <iostream>

using namespace std;

string encodeString(string input) {
    string result = "";
    int count = 1;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == input[i + 1]) {
            count++;
        } else {
            result += input[i] + to_string(count);
            count = 1;
        }
    }
    return result;
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);
    cout << encodeString(input) << endl;
    return 0;
}