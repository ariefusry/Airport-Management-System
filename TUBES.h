#ifndef MLL_H_INCLUDED
#define MLL_H_INCLUDED

#include <iostream>
#include <stdlib.h>

using namespace std;

#define first(L) L.first
#define next(p) p->next
#define info(p) p->info
#define passenger(p) p->passenger
#define nextPass(p) p->nextpass

struct flight {
    string asal, tujuan, maskapai, tanggal, waktu;
    int ID;
};
struct passenger {
    string nama, usia, gen;
    int NIK;
};

typedef struct elmF *adrF;
typedef struct elmP *adrP;
typedef struct elmR *adrR;

struct listF{
    adrF first;
};
struct listP{
    adrP first;
};
struct listR{
    adrR first;
};

struct elmR {
    adrP nextpass;
    adrR next;
};
struct elmF {
    flight info;
    adrF next;
    listR passenger;
};
struct elmP {
    passenger info;
    adrP next;
};

int menu();
void inputAwal(listF &LF, listP &LP);
void createListflight(listF &LF);
void createListPas(listP &LP);
void createListRelasi(listR &LR);
adrF createElmFlight(flight x);
adrP createElmPas(passenger x);
adrR createElmRelasi();
void insertLastFlight(listF &LF, adrF p);
void insertLastPassenger(listP &LP, adrP p);
void insertLastRelasi(listR &LP, adrR p);
void showFlight(listF LF);
void showPass(listP LP);
void showRelation(listR LR);
adrF findID(int ID, listF LF);
adrP findNIK(int NIK, listP LP);
adrR findFlightPassenger(listR LR, int NIK);
void addRelation(listF &LF, listP LP, int NIK, int ID);
void showAllData(listF LF);
int countPassenger(listF LF, int ID);
void delete_flight(listF &LF, int ID);
void delete_relasi(listR &LR, int ID);
void delete_passenger(listP &LP, listF &LF, int NIK);
void deletePassengerFromFlight(listF &LF, int NIK, int ID);

#endif // MLL_H_INCLUDED
