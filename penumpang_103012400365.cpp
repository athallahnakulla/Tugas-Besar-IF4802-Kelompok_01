
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


