#include<bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class user{
public:
    string name;
    char gender;
    int rating[50];

    void setData() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter Gender: ";
        cin >> gender;

        for (int i = 0; i < 50; i++) {
            rating[i] = -1;
        }

        int nop = rand() % 50 + 30;
        for (int i = 0; i < nop; i++) {
            int j = rand() % 50;
            rating[j] = rand() % 4 + 1;
        }
    }

    void showData() {
        cout << "Name: " << name << endl;
        cout << "Gender: " << gender << endl;
        cout << "Ratings: ";
        for (int i = 0; i < 50; i++) {
            cout << rating[i] << ",";
        }
        cout << endl;
    }

    string getName() {
        return name;
    }
};

int main() {
    fstream fp;
    fp.open("user.csv", ios::out);

    fp << "name,gender";
    for (int i = 1; i <= 50; i++) {
        fp << ",item" << i;
    }
    fp << endl;

    srand(time(NULL));
    while (1) {
        user obj;
        obj.setData();
        obj.showData();

        fp << obj.name << "," << obj.gender;
        for (int i = 0; i < 50; i++) {
            fp << "," << obj.rating[i];
        }
        fp << endl;

        char ch;
        cout << endl << "Do you wish to exit(y/n)?" << endl;
        cin >> ch;
        if (ch == 'y') {
            break;
        }
    }

    fp.close();
    return 0;
}
