#include <iostream>
#include "GTUSetBase.h"
#include "GTUMap.h"
#include "GTUSet.h"
#include "GTUSet.cpp"
#include "GTUMap.cpp"
#include "Exception.h"
#include <stdexcept>
#include <utility>
using namespace bengiSpace;
using namespace std;

int main(int argc, char** argv) {

    GTUSet<int> a;
    GTUMap<int, string> myGTUmap;

    try {
        a.insert(9);
        a.insert(5);
        cout << a.size() << endl;
        cout << a.max_size() << endl;
        a.clear();
        cout << a.size() << endl;
        a.insert(15);
        a.insert(27);
        a.insert(25);
        a.insert(17);
        if (a.count(25)) {
            cout << "25 bulundu!" << endl;
        } else {
            cout << "25 bulunamadı" << endl;
        }

        if (a.count(2)) {
            cout << "2 bulundu" << endl;
        } else {
            cout << "2 bulunamadı!" << endl;
        }
        if (a.empty()) {
            cout << "Set boş" << endl;
        } else {
            cout << "set boş değil" << endl;
        }

        GTUSet<int>::GTUIterator it_1 = a.begin();
        cout << *it_1 << endl;

        ++it_1;
        cout << *it_1 << endl;

        --it_1;
        cout << *it_1 << endl;

        GTUSet<int>::GTUIterator it_2 = a.end();
        cout << *it_2 << endl;

        GTUSet<int>::GTUIterator it_3 = a.find(25);
        cout << *it_3 << endl;

        a.erase(17);
        if (a.count(17)) {
            cout << "17 bulundu" << endl;
        } else {
            cout << "17 bulunamadı!" << endl;
        }
        a.erase(25);
        if (a.count(17)) {
            cout << "25 bulundu" << endl;
        } else {
            cout << "25 bulunamadı!" << endl;
        }

        myGTUmap.insert(pair<int, string>(1, "Bengi"));
        cout << myGTUmap[1] << endl;

        myGTUmap.insert(pair<int, string>(2, "Pelin"));
        cout << myGTUmap[2] << endl;

        myGTUmap.insert(pair<int, string>(3, "Zehra"));
        cout << myGTUmap[3] << endl;

        myGTUmap.insert(pair<int, string>(4, "Cengiz"));
        cout << myGTUmap[4] << endl;

        myGTUmap.insert(pair<int, string>(5, "Sefa"));
        cout << myGTUmap[5] << endl;

        cout << myGTUmap.size() << endl;
        cout << myGTUmap.max_size() << endl;

        if (myGTUmap.count(pair<int, string>(4, "Cengiz"))) {
            cout << "(4,Cengiz) bulundu" << endl;
        } else {
            cout << "(4,Cengiz) bulunamadı" << endl;
        }

        if (myGTUmap.count(pair<int, string>(4, "Sefa"))) {
            cout << "(4,Sefa) bulundu" << endl;
        } else {
            cout << "(4,Sefa) bulunamadı" << endl;
        }

        myGTUmap.erase(pair<int, string>(4, "Cengiz"));
        cout << myGTUmap.size() << endl;

        for (GTUMap<int, string>::GTUIterator it_7 = myGTUmap.begin(); it_7 != myGTUmap.end(); ++it_7) {
            cout << it_7->second << " ";
        }
        cout << endl;

    } catch (exception& e) {
        cout << "Exception: " << e.what() << endl;
    }
    return 0;
}

