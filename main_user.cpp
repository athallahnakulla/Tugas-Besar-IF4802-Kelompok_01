#include <iostream>
#include "header.h"

using namespace std;

extern list_ojol LO;

int main_user() {
    int pilih;
    string namaDriver;
    infotype_penumpang data;
    address_ojol O = nullptr;
    address_penumpang P = nullptr;

    do {
        cout << "\n==== MENU PENUMPANG ====\n";
        cout << "1. Lihat Driver Tersedia\n";
        cout << "2. Pesan Ojol\n";
        cout << "3. Lihat Pesanan Saya\n";
        cout << "4. Batalkan Pesanan\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilih;

        if (pilih == 1) {
            if (isEmptyOjol(LO)) {
                cout << "Belum ada driver tersedia.\n";
            } else {
                viewParent(LO);
            }
        }

        else if (pilih == 2) {
            if (isEmptyOjol(LO)) {
                cout << "Belum ada driver tersedia.\n";
            } else {
                viewParent(LO);
                cout << "Pilih driver: ";
                cin >> namaDriver;

                O = findElemenParent(LO, namaDriver);

                if (O == nullptr) {
                    cout << "Driver tidak ditemukan.\n";
                }
                else if (!isDriverAvailable(O)) {
                    cout << "Driver sedang sibuk.\n";
                }
                else {
                    cout << "Nama penumpang: ";
                    cin >> data.nama_penumpang;
                    cout << "No HP: ";
                    cin >> data.noHP;
                    cout << "Asal: ";
                    cin >> data.daerah_asal;
                    cout << "Tujuan: ";
                    cin >> data.daerah_tujuan;
                    cout << "Umur: ";
                    cin >> data.umur_penumpang;

                    P = createElemenChild(data);
                    insertLastChild(O, P);
                    O->info_ojol.status = "sibuk";

                    cout << "Pesanan berhasil dibuat.\n";
                }
            }
        }

        else if (pilih == 3) {
            if (O == nullptr || O->first_penumpang == nullptr) {
                cout << "Anda belum memiliki pesanan.\n";
            } else {
                showDriverDetail(O);
                viewChild(O);
            }
        }

        else if (pilih == 4) {
            if (O == nullptr || O->first_penumpang == nullptr) {
                cout << "Tidak ada pesanan yang bisa dibatalkan.\n";
            } else {
                P = O->first_penumpang;

                if (P == O->first_penumpang) {
                    deleteFirstChild(O, P);
                }
                else if (P->next == nullptr) {
                    deleteLastChild(O, P);
                }
                else {
                    address_penumpang prec = O->first_penumpang;
                    while (prec->next != P) {
                        prec = prec->next;
                    }
                    deleteAfterChild(O, prec, P);
                }

                O->info_ojol.status = "tersedia";
                O = nullptr;
                P = nullptr;

                cout << "Pesanan berhasil dibatalkan.\n";
            }
        }

        else if (pilih == 0) {
            cout << "Terima kasih telah menggunakan layanan.\n";
        }

        else {
            cout << "Menu tidak valid.\n";
        }

    } while (pilih != 0);

    return 0;
}
