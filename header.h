#ifndef OJOL_H_INCLUDED
#define OJOL_H_INCLUDED
#include <iostream>

using namespace std;

struct data_penumpang {
    string nama_penumpang;
    string noHP;
    string daerah_asal;
    string daerah_tujuan;
    int umur_penumpang;

};

typedef data_penumpang infotype_penumpang;

typedef struct elemen_penumpang *address_penumpang;

struct elemen_penumpang {
    infotype_penumpang info_penumpang;
    address_penumpang next;
    address_penumpang prev;
};

struct data_ojol {
    string nama_ojol;
    string plat_nomor;
    string jenis_kendaraan;
    string noHP;
    string status;
    string daerah_operasi;
    int umur_ojol;
};

typedef data_ojol infotype_ojol;

typedef struct elemen_ojol *address_ojol;

struct elemen_ojol {
    infotype_ojol info_ojol;
    address_ojol next;
    address_penumpang first_penumpang;
};
struct list_ojol {
    address_ojol first;
};

void createListParent(list_ojol &LO);
address_ojol createElemenParent(infotype_ojol x);
void insertFirstParent(list_ojol &LO, address_ojol O);
void insertLastParent(list_ojol &LO, address_ojol O);
void insertAfterParent(list_ojol &LO, address_ojol prec, address_ojol O);
void deleteFirstParent(list_ojol &LO, address_ojol &O);
void deleteLastParent(list_ojol &LO, address_ojol &O);
void deleteAfterParent(list_ojol &LO, address_ojol prec, address_ojol &O);
address_ojol findElemenParent(list_ojol &LO, string info);
void viewParent(list_ojol LO);
bool isEmptyOjol(list_ojol LO);

address_penumpang createElemenChild(infotype_penumpang P);
void insertFirstChild(address_ojol O, address_penumpang P);
void insertLastChild(address_ojol O, address_penumpang P);
void insertAfterChild(address_ojol O, address_penumpang prec, address_penumpang P);
void deleteFirstChild(address_ojol O, address_penumpang &P);
void deleteLastChild(address_ojol O, address_penumpang &P);
void deleteAfterChild(address_ojol O, address_penumpang prec, address_penumpang &P);
address_penumpang findElemenChild(address_ojol O, string infop);
void viewChild(address_ojol O);
bool isEmptyPenumpang(address_ojol O);
void showDriverDetail(address_ojol O);
void showAvailableDrivers();
void orderOjol(address_ojol &O);
void showMyOrder(address_ojol O);
void cancelMyOrder(address_ojol &O, address_penumpang &P);
void showOrderStatistics();
void showPassengersAboveInputAge();
address_ojol findDriverByArea(list_ojol &LO, string area);
int countPassengers(address_ojol O);
void menuDeleteOjolMostPassengersByArea(list_ojol &LO);
void finishOrderOjol(address_ojol &O);
int countOjolByArea(list_ojol LO, string area);

int main_admin();
int main_user();

extern list_ojol LO;
void dataDump(list_ojol &LO);

#endif // OJOL_H_INCLUDED
