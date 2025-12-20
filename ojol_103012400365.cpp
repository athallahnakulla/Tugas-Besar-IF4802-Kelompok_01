#include <iostream>
#include "header.h"

using namespace std;

void createListParent(list_ojol &LO){
    LO.first = nullptr;
}

bool isEmptyOjol(list_ojol LO){
    return LO.first == nullptr;
}

address_ojol createElemenParent(infotype_ojol x){
    address_ojol P = new elemen_ojol;

    P->info_ojol.nama_ojol = x.nama_ojol;
    P->info_ojol.plat_nomor = x.plat_nomor;
    P->info_ojol.jenis_kendaraan = x.jenis_kendaraan;
    P->info_ojol.noHP = x.noHP;
    P->info_ojol.daerah_operasi = x.daerah_operasi;
    P->info_ojol.umur_ojol = x.umur_ojol;
    P->next = nullptr;
    P->first_penumpang = nullptr;

    return P;
}

void insertFirstParent(list_ojol &LO, address_ojol O){
    if(isEmptyOjol(LO)){
        LO.first = O;
    } else {
        O->next = LO.first;
        LO.first = O;
    }
}

void insertLastParent(list_ojol &LO, address_ojol O){
    address_ojol OP;

    if(isEmptyOjol(LO)){
        LO.first = O;
    } else {
        OP = LO.first;
        while(OP->next != nullptr){
            OP = OP->next;
        }
        OP->next = O;
    }
}

void insertAfterParent(list_ojol &LO, address_ojol prec, address_ojol O){
    O->next = prec->next;
    prec->next = O;
}

void viewParent(list_ojol L) {
    if (L.first == NULL) {
        cout << "List Ojol kosong." << endl;
    } else {
        address_ojol P = L.first;
        int i = 1;

        cout << "\n==============================" << endl;
        while (P != NULL) {
            cout << "Data Ojek ke-" << i << endl;
            cout << "Nama Ojek          : " << P->info_ojol.nama_ojol << endl;

            int count = 0;
            address_penumpang C = P->first_penumpang;
            while (C != NULL) {
                count++;
                C = C->next;
            }
            cout << "Daerah Operasi     : " << P->info_ojol.daerah_operasi << endl;
            cout << "Jenis Kendaraan    : " << P->info_ojol.jenis_kendaraan << endl;
            cout << "Banyak Penumpang   : " << count << endl;

            cout << "==============================" << endl;

            P = P->next;
            i++;
        }
    }
}

void dataDump(list_ojol &LO) {
    infotype_ojol o1 = {"Budi", "D1234AA", "Motor", "0811", "Aktif", "Bandung", 30};
    infotype_ojol o2 = {"Andi", "D5678BB", "Motor", "0822", "Aktif", "Bandung", 27};
    infotype_ojol o3 = {"Sandi", "D1111CC", "Mobil", "0833", "Nonaktif", "Cimahi", 35};
    infotype_ojol o4 = {"Rizal", "D2222DD", "Motor", "0844", "Aktif", "Soreang", 28};
    infotype_ojol o5 = {"Fikri", "D3333EE", "Motor", "0855", "Aktif", "Cicalengka", 29};

    address_ojol A1 = createElemenParent(o1);
    address_ojol A2 = createElemenParent(o2);
    address_ojol A3 = createElemenParent(o3);
    address_ojol A4 = createElemenParent(o4);
    address_ojol A5 = createElemenParent(o5);

    insertLastParent(LO, A1);
    insertLastParent(LO, A2);
    insertLastParent(LO, A3);
    insertLastParent(LO, A4);
    insertLastParent(LO, A5);

    insertLastChild(A1, createElemenChild({"Rina", "089111", "Bandung", "Cicendo", 20}));
    insertLastChild(A1, createElemenChild({"Doni", "089112", "Cimahi", "Bandung", 25}));

    insertLastChild(A2, createElemenChild({"Siti", "089221", "Antapani", "Cibiru", 22}));

    insertLastChild(A3, createElemenChild({"Agus", "089331", "Cimahi", "Cimindi", 30}));
    insertLastChild(A3, createElemenChild({"Mira", "089332", "Cimahi", "Alun-Alun", 19}));
    insertLastChild(A3, createElemenChild({"Yanto", "089333", "Cimahi", "Pasar", 24}));

    insertLastChild(A4, createElemenChild({"Lala", "089441", "Soreang", "Banjaran", 21}));

    insertLastChild(A5, createElemenChild({"Nanda", "089551", "Cicalengka", "Cileunyi", 23}));
    insertLastChild(A5, createElemenChild({"Yuni", "089552", "Cicalengka", "Gedebage", 22}));
}




