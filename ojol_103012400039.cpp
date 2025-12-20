#include <iostream>
#include "header.h"

using namespace std;

void deleteFirstParent(list_ojol &LO, address_ojol &O){
    if(LO.first == nullptr){
        O = nullptr;
    } else if(LO.first->next == nullptr){
        O = LO.first;
        LO.first = nullptr;
    } else {
        O = LO.first;
        LO.first = O->next;
        O->next = nullptr;
    }
}

void deleteLastParent(list_ojol &LO, address_ojol &O){
    if(LO.first == nullptr){
        O = nullptr;
    } else if(LO.first->next == nullptr){
        O = LO.first;
        LO.first = nullptr;
    } else {
        address_ojol P = LO.first;
        while(P->next->next != nullptr){
            P = P->next;
        }
        O = P->next;
        P->next = nullptr;
    }
}

void deleteAfterParent(list_ojol &LO, address_ojol prec, address_ojol &O){
    if(prec != nullptr && prec->next != nullptr){
        O = prec->next;
        prec->next = O->next;
        O->next = nullptr;
    } else {
        O = nullptr;
    }
}

address_ojol findElemenParent(list_ojol &LO, string info){
    address_ojol P = LO.first;
    while(P != nullptr){
        if(P->info_ojol.nama_ojol == info){
            return P;
        }
        P = P->next;
    }
    return nullptr;
}



