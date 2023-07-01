#include <iostream>

using namespace std;

/*
    Simple pascal pyramid program

    *
    **
    ***
    ****
    *****
*/

void pascalPyramid() {
    int size;

    cout << "Enter the pyramid size: ";
    cin>>size;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < i; j++) {
            cout << "*";
        }

        cout << endl;
    }
}