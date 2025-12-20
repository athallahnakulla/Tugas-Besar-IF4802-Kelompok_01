#include <iostream>
#include "header.h"

using namespace std;

extern list_ojol LO;

int main_admin(){

    string pilihan = "-1";

    while(pilihan != "0"){
        cout << "\n====== MENU ADMIN ======\n";
        cout << "1. Insert First Parent\n";
        cout << "2. Insert Last Parent\n";
        cout << "3. Insert After Parent\n";
        cout << "4. Delete First Parent\n";
        cout << "5. Delete Last Parent\n";
        cout << "6. Delete After Parent\n";
        cout << "7. Find Parent\n";
        cout << "8. View Parent\n\n";
        cout << "9. Insert First Child\n";
        cout << "10. Insert Last Child\n";
        cout << "11. Insert After Child\n";
        cout << "12. Delete First Child\n";
        cout << "13. Delete Last Child\n";
        cout << "14. Delete After Child\n";
        cout << "15. Find Child by Driver\n";
        cout << "16. View Child by Driver\n\n";
        cout << "0. Kembali\n";
        cout << "========================\n";
        cout << "Pilih menu (0-16): ";
        cin >> pilihan;

        if(pilihan == "1" || pilihan == "2" || pilihan == "3"){
            infotype_ojol X;

            cout << "Nama ojol (tanpa spasi): ";
            cin >> X.nama_ojol;
            cout << "Plat nomor: ";
            cin >> X.plat_nomor;
            cout << "Jenis kendaraan: ";
            cin >> X.jenis_kendaraan;
            cout << "Nomor HP: ";
            cin >> X.noHP;
            cout << "Daerah operasi: ";
            cin >> X.daerah_operasi;
            cout << "Umur ojol: ";
            cin >> X.umur_ojol;

            address_ojol O = createElemenParent(X);

            if(pilihan == "1") insertFirstParent(LO, O);
            else if(pilihan == "2") insertLastParent(LO, O);
            else {
                string namaPrec;
                cout << "Insert setelah driver: ";
                cin >> namaPrec;

                address_ojol prec = findElemenParent(LO, namaPrec);
                if(prec != NULL){
                    insertAfterParent(LO, prec, O);
                } else {
                    cout << "Driver tidak ditemukan.\n";
                    delete O;
                }
            }
        }

        else if(pilihan == "7"){
            string nama;
            cout << "Cari parent nama: ";
            cin >> nama;

            address_ojol P = findElemenParent(LO, nama);
            if(P != NULL)
                cout << "Ditemukan: " << P->info_ojol.nama_ojol << endl;
            else
                cout << "Parent tidak ditemukan.\n";
        }

        else if(pilihan == "8"){
            viewParent(LO);
        }

        else if(
            pilihan == "9"  || pilihan == "10" || pilihan == "11" ||
            pilihan == "12" || pilihan == "13" || pilihan == "14" ||
            pilihan == "15" || pilihan == "16"
        ){
            string driver;
            cout << "Nama driver: ";
            cin >> driver;

            address_ojol O = findElemenParent(LO, driver);
            if(O == NULL){
                cout << "Driver tidak ditemukan.\n";
                continue;
            }

            if(pilihan == "9" || pilihan == "10" || pilihan == "11"){
                infotype_penumpang X;

                cout << "Nama penumpang: ";
                cin >> X.nama_penumpang;
                cout << "No HP: ";
                cin >> X.noHP;
                cout << "Asal: ";
                cin >> X.daerah_asal;
                cout << "Tujuan: ";
                cin >> X.daerah_tujuan;
                cout << "Umur: ";
                cin >> X.umur_penumpang;

                address_penumpang C = createElemenChild(X);

                if(pilihan == "9") insertFirstChild(O, C);
                else if(pilihan == "10") insertLastChild(O, C);
                else {
                    string namaPrec;
                    cout << "Insert setelah penumpang: ";
                    cin >> namaPrec;

                    address_penumpang prec = findElemenChild(O, namaPrec);
                    if(prec != NULL){
                        insertAfterChild(O, prec, C);
                    } else {
                        cout << "Penumpang tidak ditemukan.\n";
                        delete C;
                    }
                }
            }

            else if (pilihan == "12") {
                address_penumpang P;
                deleteFirstChild(O, P);
            }

            else if (pilihan == "13") {
                address_penumpang P;
                deleteLastChild(O, P);
            }

            else if (pilihan == "14") {
                string namaPrec;
                cout << "Hapus setelah penumpang: ";
                cin >> namaPrec;

                address_penumpang prec = findElemenChild(O, namaPrec);
                if (prec != NULL) {
                    address_penumpang P;
                    deleteAfterChild(O, prec, P);
                } else {
                    cout << "Penumpang tidak ditemukan.\n";
                }
            }

            else if(pilihan == "15"){
                string nama;
                cout << "Cari penumpang: ";
                cin >> nama;

                address_penumpang C = findElemenChild(O, nama);
                if(C != NULL)
                    cout << "Ditemukan: " << C->info_penumpang.nama_penumpang << endl;
                else
                    cout << "Tidak ditemukan.\n";
            }

            else if(pilihan == "16"){
                viewChild(O);
            }
        }

        else if (pilihan != "0"){
            cout << "Masukkan inputan yang benar!\n";
        }
    }
    return 0;
}
