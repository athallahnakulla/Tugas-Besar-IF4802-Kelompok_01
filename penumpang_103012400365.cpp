#include <iostream>
#include "header.h"

using namespace std;

bool isEmptyPenumpang(address_ojol O){
    return O->first_penumpang == nullptr;
}

void deleteFirstChild(address_ojol O, address_penumpang &P){
    if (isEmptyPenumpang(O)) {
        cout << "List kosong\n";
        return;
    }

    P = O->first_penumpang;
    O->first_penumpang = P->next;

    if (O->first_penumpang != nullptr)
        O->first_penumpang->prev = nullptr;

    P->next = nullptr;
    delete P;
    P = nullptr;
}


void deleteLastChild(address_ojol O, address_penumpang &P){
    if (isEmptyPenumpang(O)) {
        cout << "List kosong\n";
        return;
    }

    address_penumpang curr = O->first_penumpang;

    if (curr->next == nullptr) {
        P = curr;
        O->first_penumpang = nullptr;
    } else {
        while (curr->next->next != nullptr) {
            curr = curr->next;
        }
        P = curr->next;
        curr->next = nullptr;
        P->prev = nullptr;
    }

    delete P;
    P = nullptr;
}


void deleteAfterChild(address_ojol O, address_penumpang prec, address_penumpang &P){
    if (prec == nullptr || prec->next == nullptr) {
        cout << "Tidak ada elemen setelahnya.\n";
        return;
    }

    P = prec->next;
    prec->next = P->next;

    if (P->next != nullptr)
        P->next->prev = prec;

    P->next = nullptr;
    P->prev = nullptr;

    delete P;
    P = nullptr;
}


void viewChild(address_ojol O) {
    if (O == nullptr) {
        cout << "Data ojol tidak ditemukan." << endl;
        return;
    }

    if (O->first_penumpang == nullptr) {
        cout << "Ojol " << O->info_ojol.nama_ojol
             << " belum memiliki penumpang." << endl;
        return;
    }

    cout << "\nDaftar Penumpang dari Ojol: " << O->info_ojol.nama_ojol << endl;
    cout << "==========================================" << endl;

    address_penumpang P = O->first_penumpang;
    int i = 1;

    while (P != nullptr) {
        cout << i << ". Nama Penumpang : " << P->info_penumpang.nama_penumpang << endl;
        cout << "   No HP         : " << P->info_penumpang.noHP << endl;
        cout << "   Daerah Asal   : " << P->info_penumpang.daerah_asal << endl;
        cout << "   Daerah Tujuan : " << P->info_penumpang.daerah_tujuan << endl;
        cout << "   Umur          : " << P->info_penumpang.umur_penumpang << " tahun" << endl;
        cout << "------------------------------------------" << endl;

        P = P->next;
        i++;
    }
}

void showAvailableDrivers() {
    if (isEmptyOjol(LO)) {
        cout << "Belum ada driver tersedia.\n";
    } else {
        viewParent(LO);
    }
}

void showMyOrder(address_ojol O) {
    if (O == nullptr || isEmptyPenumpang(O)) {
        cout << "Anda belum memiliki pesanan.\n";
    } else {
        showDriverDetail(O);
        viewChild(O);
    }
}

void showOrderStatistics() {
    int totalPesanan = 0;
    int totalUmur = 0;

    address_ojol O = LO.first;
    while (O != nullptr) {
        address_penumpang P = O->first_penumpang;
        while (P != nullptr) {
            totalPesanan++;
            totalUmur += P->info_penumpang.umur_penumpang;
            P = P->next;
        }
        O = O->next;
    }

    if (totalPesanan == 0) {
        cout << "Belum ada pesanan.\n";
    } else {
        cout << "Total Pesanan  : " << totalPesanan << endl;
        cout << "Rata-rata Umur : "
             << (float) totalUmur / totalPesanan << endl;
    }
}

void showPassengersAboveInputAge() {
    int minAge;

    cout << "Masukkan umur minimum: ";
    cin >> minAge;

    if (isEmptyOjol(LO)) {
        cout << "Tidak ada driver terdaftar.\n";
        return;
    }

    address_ojol O = LO.first;
    bool ditemukan = false;

    cout << "\n=== Penumpang dengan Umur > " << minAge << " ===\n";

    while (O != nullptr) {
        address_penumpang P = O->first_penumpang;

        while (P != nullptr) {
            if (P->info_penumpang.umur_penumpang > minAge) {
                ditemukan = true;
                cout << "- Nama   : " << P->info_penumpang.nama_penumpang << endl;
                cout << "  Umur   : " << P->info_penumpang.umur_penumpang << " tahun\n";
                cout << "  Driver : " << O->info_ojol.nama_ojol << endl;
                cout << "-----------------------------\n";
            }
            P = P->next;
        }
        O = O->next;
    }

    if (!ditemukan) {
        cout << "Tidak ada penumpang dengan umur di atas "
             << minAge << " tahun.\n";
    }
}

int countOjolByArea(list_ojol LO, string area) {
    int total = 0;
    address_ojol O = LO.first;
    while (O != nullptr) {
        if (O->info_ojol.daerah_operasi == area) {
            total++;
        }
        O = O->next;
    }
    return total;
}


void menuDeleteOjolMostPassengersByArea(list_ojol &LO) {
    string area;
    address_ojol curr = LO.first;
    address_ojol target = nullptr;
    int maxPassenger = -1;

    if (isEmptyOjol(LO)) {
        cout << "Data ojol masih kosong.\n";
        return;
    }

    cout << "Masukkan daerah operasi: ";
    cin >> area;

    if (countOjolByArea(LO, area) < 2) {
        cout << "Ojol di daerah tersebut hanya satu.\n";
        return;
    }

    while (curr != nullptr) {
        if (curr->info_ojol.daerah_operasi == area) {
            int jumlah = countPassengers(curr);
            if (jumlah > maxPassenger) {
                maxPassenger = jumlah;
                target = curr;
            }
        }
        curr = curr->next;
    }

    if (target == nullptr) {
        cout << "Tidak ada ojol di daerah tersebut.\n";
        return;
    }

    address_ojol prev = nullptr;
    curr = LO.first;

    while (curr != nullptr && curr != target) {
        prev = curr;
        curr = curr->next;
    }

    if (prev == nullptr) {
        LO.first = curr->next;
    } else {
        prev->next = curr->next;
    }

    curr->next = nullptr;
    delete curr;

    cout << "Ojol dengan penumpang terbanyak di daerah "
         << area << " berhasil dihapus.\n";
}

int countPassengers(address_ojol O) {
    int count = 0;
    address_penumpang P = O->first_penumpang;
    while (P != nullptr) {
        count++;
        P = P->next;
    }
    return count;
}
















