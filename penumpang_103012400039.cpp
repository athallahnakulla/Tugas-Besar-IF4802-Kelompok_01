#include <iostream>
#include "header.h"

using namespace std;

address_penumpang createElemenChild(infotype_penumpang X){
    address_penumpang P = new elemen_penumpang;
    P->info_penumpang = X;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}

void insertFirstChild(address_ojol O, address_penumpang P){
    if(O->first_penumpang == nullptr){
        O->first_penumpang = P;
    } else {
        P->next = O->first_penumpang;
        O->first_penumpang->prev = P;
        O->first_penumpang = P;
    }
}

void insertLastChild(address_ojol O, address_penumpang P){
    if(O->first_penumpang == nullptr){
        O->first_penumpang = P;
    } else {
        address_penumpang C = O->first_penumpang;
        while(C->next != nullptr){
            C = C->next;
        }
        C->next = P;
        P->prev = C;
    }
}

void insertAfterChild(address_ojol O, address_penumpang prec, address_penumpang P){
    if(prec != nullptr){
        P->next = prec->next;
        if(prec->next != nullptr){
            prec->next->prev = P;
        }
        prec->next = P;
        P->prev = prec;
    }
}

address_penumpang findElemenChild(address_ojol O, string infop){
    address_penumpang C = O->first_penumpang;
    while(C != nullptr && C->info_penumpang.nama_penumpang != infop){
        C = C->next;
    }
    return C;
}

void showDriverDetail(address_ojol O){
    cout << O->info_ojol.nama_ojol << endl;
    cout << O->info_ojol.jenis_kendaraan << endl;
    cout << O->info_ojol.plat_nomor << endl;
    cout << O->info_ojol.status << endl;
}

void orderOjol(address_ojol &O) {
    infotype_penumpang data;
    infotype_ojol driver;
    address_penumpang P;

    if (O != nullptr) {
        cout << "Anda masih memiliki pesanan aktif.\n";
        return;
    }

    viewParent(LO);

    cout << "Nama penumpang : ";
    cin >> data.nama_penumpang;
    cout << "No HP          : ";
    cin >> data.noHP;
    cout << "Asal           : ";
    cin >> data.daerah_asal;
    cout << "Tujuan         : ";
    cin >> data.daerah_tujuan;
    cout << "Umur           : ";
    cin >> data.umur_penumpang;

    O = findDriverByArea(LO, data.daerah_asal);

    if (O == nullptr) {
        cout << "\nTidak ada driver di daerah tersebut.\n";
        cout << "Masukkan data driver baru\n";

        cout << "Nama driver      : ";
        cin >> driver.nama_ojol;
        cout << "Plat nomor       : ";
        cin >> driver.plat_nomor;
        cout << "Jenis kendaraan  : ";
        cin >> driver.jenis_kendaraan;
        cout << "No HP            : ";
        cin >> driver.noHP;
        cout << "Umur             : ";
        cin >> driver.umur_ojol;

        driver.daerah_operasi = data.daerah_asal;
        driver.status = "Aktif";

        O = createElemenParent(driver);
        insertLastParent(LO, O);
    }

    P = createElemenChild(data);
    insertLastChild(O, P);

    cout << "Pesanan berhasil dibuat dengan driver "
         << O->info_ojol.nama_ojol << endl;
}

address_ojol findDriverByArea(list_ojol &LO, string area) {
    address_ojol O = LO.first;
    while (O != nullptr) {
        if (O->info_ojol.daerah_operasi == area &&
            O->info_ojol.status == "Aktif") {
            return O;
        }
        O = O->next;
    }
    return nullptr;
}

void cancelMyOrder(address_ojol &O, address_penumpang &P) {
    if (O == nullptr || isEmptyPenumpang(O)) {
        cout << "Tidak ada pesanan yang bisa dibatalkan.\n";
        return;
    }

    deleteFirstChild(O, P);
    O->info_ojol.status = "Aktif";
    O = nullptr;
    P = nullptr;

    cout << "Pesanan berhasil dibatalkan.\n";
}

void finishOrderOjol(address_ojol &O) {
    if (O == nullptr) {
        cout << "Tidak ada pesanan aktif.\n";
        return;
    }

    O->info_ojol.status = "Aktif";

    O = nullptr;

    cout << "Pesanan berhasil diselesaikan. Anda dapat memesan kembali.\n";
}




