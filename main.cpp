#include <iostream>
#include "header.h"
using namespace std;

list_ojol LO;

int main() {
    createListParent(LO);
    dataDump(LO);

    string pilih = "-1";

    while (pilih != "0"){
        cout << "\n===== SISTEM OJOL =====\n";
        cout << "1. Masuk sebagai Admin\n";
        cout << "2. Masuk sebagai User\n";
        cout << "0. Keluar\n";
        cout << "=======================\n";

        cout << "Pilih (0/1/2): ";
        cin >> pilih;

        if (pilih == "1") {
            main_admin();
        }

        else if (pilih == "2") {
            main_user();
        }

        else if (pilih != "0") {
            cout << "silahkan isi dengan benar!" << endl;
        }
    };

    cout << "Terima kasih!\n";
    return 0;
}
