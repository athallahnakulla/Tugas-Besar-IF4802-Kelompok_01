#include <iostream>
#include "header.h"

using namespace std;

extern list_ojol LO;

int main_user() {
    string pilih = "-1";
    address_ojol O = nullptr;
    address_penumpang P = nullptr;

    while (pilih != "0"){
        cout << "\n==== MENU PENUMPANG ====\n";
        cout << "1. Lihat Driver Tersedia\n";
        cout << "2. Pesan Ojol\n";
        cout << "3. Lihat Pesanan Saya\n";
        cout << "4. Batalkan Pesanan\n";
        cout << "5. Selesaikan Pesanan\n";
        cout << "6. Lihat Semua Penumpang (Bedasarkan Umur)\n";
        cout << "7. Statistik Pesanan\n";
        cout << "8. Hapus Ojol Terbanyak di Daerah Operasi\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilih;

        if (pilih == "1") {
            showAvailableDrivers();
        }
        else if (pilih == "2") {
            orderOjol(O);
        }
        else if (pilih == "3") {
            showMyOrder(O);
        }
        else if (pilih == "4") {
            cancelMyOrder(O, P);
        }
        else if (pilih == "5") {
            finishOrderOjol(O);
        }
        else if (pilih == "6") {
            showPassengersAboveInputAge();
        }
        else if (pilih == "7") {
            showOrderStatistics();
        }
        else if (pilih == "8") {
            menuDeleteOjolMostPassengersByArea(LO);
        }
        else if (pilih == "0") {
            cout << "Terima kasih telah menggunakan layanan.\n";
        }
        else if (pilih != "0") {
            cout << "Menu tidak valid.\n";
        }
    }
    return 0;
}
