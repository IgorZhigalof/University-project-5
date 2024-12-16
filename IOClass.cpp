#include <string>
#include <iostream>
#include "IOClass.h"

using namespace std;


string IOClass::getData(void) {
    string content;
    while (true) {
        cout << "Enter input: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, content);
        if (!content.empty()) {
            break;
        }
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
