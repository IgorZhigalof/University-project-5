#include <string>
#include <iostream>
#include "IOClass.h"

using namespace std;


string IOClass::getData(void) {
    string content;
    while (true) {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout << "Enter input: ";
        getline(cin, content);
        if (!content.empty()) {
            break;
        }
        cout << content;
        cout << "Input cannot be empty. Please try again.\n";
    }
    return content;
}

void IOClass::print(string content) {
    cout << content;
}

void IOClass::println(string content) {
    cout << content << endl;
}
