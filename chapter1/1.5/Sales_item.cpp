#include "Sales_item.h"

#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    Sales_item book;
    cout << "Enter transactions:" << endl;
    while (cin >> book) {
        cout << "ISBN          sold   price   revenue" << endl;
        cout << book << endl;
    }
    return 0;
}
