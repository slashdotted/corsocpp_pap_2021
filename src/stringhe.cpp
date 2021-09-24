#include "stringhe.h"
#include <string>
#include <iostream>

using std::string;
using std::cout;

void stringhe() {
    string msg{"Héllo world"};
    msg += "!";
    cout << msg << ":" << msg.length() << '\n';
    string msg2 = msg + msg;
    cout << "Carattere 1:" << msg[1] << "\n";
    if (msg == "Hello world!") {
        cout << "Sono uguali\n";
    }

}