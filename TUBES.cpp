#include "TUBES.h"

void createListflight(listF &LF){
    first(LF) = NULL;
}

void createListPas(listP &LP){
    first(LP) = NULL;
}

void createListRelasi(listR &LR){
    first(LR) = NULL;
}

adrF createElmFlight(flight x){
    adrF p = new elmF;
    next(p) = NULL;
    info(p) = x;
    createListRelasi(passenger(p));
    return p;
}

adrP createElmPas(passenger x){
    adrP p = new elmP;
    next(p) = NULL;
    info(p) = x;

    return p;
}

adrR createElmRelasi(adrP x){
    adrR p = new elmR;
    next(p) = NULL;
    nextPass(p) = x;

    return p;
}

void insertLastFlight(listF &LF, adrF p){
    if (first(LF) == NULL){
        first(LF) = p;
    }else{
        adrF q = first(LF);
        while (next(q) != NULL){
            q = next(q);
        }
        next(q) = p;
    }
}

void insertLastPassenger(listP &LP, adrP p){
    if (first(LP) == NULL){
        first(LP) = p;
    }else{
        adrP q = first(LP);
        while (next(q) != NULL){
            q = next(q);
        }
        next(q) = p;
    }
}

void insertLastRelasi(listR &LR, adrR p){
    if (first(LR) == NULL){
        first(LR) = p;
    }else{
        adrR q = first(LR);
        while (next(q) != NULL){
            q = next(q);
        }
        next(q) = p;
    }
}

void showFlight(listF LF){ // parent
    adrF p = first(LF);
    if (first(LF) == NULL){
        cout << "Belum ada data" << endl;
    }else{
        while (p != NULL){
            cout << "*=====================================*"<< endl;
            cout << "ID       : " << info(p).ID << endl;
            cout << "Maskapai : " << info(p).maskapai << endl;
            cout << "Asal     : " << info(p).asal << endl;
            cout << "Tujuan   : " << info(p).tujuan << endl;
            cout << "Waktu    : " << info(p).waktu << endl;
            cout << "Tanggal  : " << info(p).tanggal << endl;
            p = next(p);
        }
        cout << "*=====================================*"<< endl;
    }
}

void showPass(listP LP){ // child
    adrP q = first(LP);
    if (first(LP) == NULL){
        cout << "Belum ada penumpang" << endl;
    }else{
        while (q != NULL){
            cout << "*==============================*"<< endl;
            cout << "NIK           : " << info(q).NIK << endl;
            cout << "Nama          : " << info(q).nama << endl;
            cout << "Usia          : " << info(q).usia << endl;
            cout << "Jenis Kelamin : " << info(q).gen << endl;
            q = next(q);
        }
        cout << "*=====================================*"<< endl;
    }
}

void showRelation(listR LR){
    adrR p = first(LR);
    if (first(LR) == NULL){
        cout << "Belum ada penumpang" << endl;
    }else{
        while (p != NULL){
            cout << "-------------------------" << endl;
            cout << "NIK           : " << info(nextPass(p)).NIK << endl;
            cout << "Nama          : " << info(nextPass(p)).nama << endl;
            cout << "Usia          : " << info(nextPass(p)).usia << endl;
            cout << "Jenis Kelamin : " << info(nextPass(p)).gen << endl;

            p = next(p);
        }
    }
}

void showAllData(listF LF){
    adrF p = first(LF);
    while (p != NULL){
        cout << endl;
        cout << "*==========================================*"<< endl;
        cout << "ID       : " << info(p).ID << endl;
        cout << "Maskapai : " << info(p).maskapai << endl;
        cout << "Asal     : " << info(p).asal << endl;
        cout << "Tujuan   : " << info(p).tujuan << endl;
        cout << "Waktu    : " << info(p).waktu << endl;
        cout << "Tanggal  : " << info(p).tanggal << endl;
        if (first(passenger(p)) != NULL){
            cout << "Jumlah penumpang dalam penerbangan ini: " << countPassenger(LF,info(p).ID) << endl;
            showRelation(passenger(p));
            cout << "*==========================================*"<< endl;

        }else{
            cout << "Tidak ada yang menaiki penerbangan ini" << endl;
            cout << "*==========================================*"<< endl;
        }
        p = next(p);
    }

}

adrF findID(int ID, listF LF){
    adrF f = first(LF);
    adrF x = NULL;

    while (f != NULL){
        if (ID == info(f).ID){
            x = f;
        }
        f = next(f);
    }
    return x;
}

adrP findNIK(int NIK, listP LP){
    adrP p = first(LP);
    adrP x = NULL;
    while (p != NULL){
        if (NIK == info(p).NIK){
            x = p;
        }
        p = next(p);
    }
    return x;
}

adrR findFlightPassenger(listR LR, int NIK){
    adrR p = first(LR);
    while (p != NULL){
        if (info(nextPass(p)).NIK == NIK){
            return p;
        }
        p = next(p);
    }
    return NULL;
}

void addRelation(listF &LF, listP LP, int NIK, int ID){
    adrF p;
    adrP q;
    adrR r;
    listR L3;

    p = findID(ID,LF);
    q = findNIK(NIK,LP);
    adrR R = findFlightPassenger(passenger(p), NIK);
    if (R != NULL){
        cout << "*===================================*" << endl;
        cout << "| Passenger sudah membeli Tiket ini |" << endl;
        cout << "*===================================*" << endl;
    }else{
        if (p != NULL && q != NULL){
        r = createElmRelasi(q);
        L3 = passenger(p);
        insertLastRelasi(L3,r);
        passenger(p) = L3;
        }
    }
}

int countPassenger(listF LF, int ID){
    int count = 0;
    adrF p = findID(ID,LF);
    adrR q = first(passenger(p));
    while (q != NULL){
        q = next(q);
        count++;
    }
    return count;
}

void delete_flight(listF &LF, int ID){
    adrF P = first(LF);
    adrF prec = NULL;
    adrF p = findID(ID,LF);

    if(P == NULL){
        cout << "List Kosong" << endl;
    }else{
        if (p == NULL){
            cout << "Data tidak ditemukan" << endl;
        }
        while (P != NULL && info(P).ID != ID){
            prec = P;
            P = next(P);
        }
        if (P != NULL){
            if (prec == NULL){
                first(LF) = next(P);
            }else{
                next(prec) = next(P);
            }
            P = NULL;
            cout << "*------------------------------*" << endl;
            cout << "| Data Flight Berhasil dihapus |" << endl;
            cout << "*------------------------------*" << endl;
        }else{
            cout << "*----------------------*" << endl;
            cout << "| Data tidak ditemukan |" << endl;
            cout << "*----------------------*" << endl;
        }
    }
}

void delete_relasi(listR &LR, int NIK){
    adrR P = first(LR);
    adrR prec = NULL;
    if (P == NULL){
        cout << "Tidak ada Passenger di Flight ini" << endl;
    }else{
        while (P != NULL && info(nextPass(P)).NIK != NIK){
            prec = P;
            P = next(P);
        }
        if (P != NULL){
            if (prec == NULL){
                first(LR) = next(P);
            }else{
                next(prec) = next(P);
            }
            P = NULL;
            cout << "*-------------------------------*" << endl;
            cout << "| Data Relasi berhasil di hapus |" << endl;
            cout << "*-------------------------------*" << endl;
        }else{
            cout << "*----------------------*" << endl;
            cout << "| Data tidak ditemukan |" << endl;
            cout << "*----------------------*" << endl;
        }
    }
}

void delete_passenger(listP &LP, listF &LF, int NIK){
    adrP P = first(LP);
    adrP prec = NULL;
    adrP q = findNIK(NIK,LP);
    if (P == NULL){
        cout << "List Kosong" << endl;
    }else{
        if (q == NULL){
            cout << "Data tidak ditemukan" << endl;
        }
        while (P != NULL && info(P).NIK != NIK){
            prec = P;
            P = next(P);
        }
        if (P != NULL){
            if (prec == NULL){
                first(LP) = next(P);
            }else{
                next(prec) = next(P);
            }
            adrF f = first(LF);
            while (f != NULL){
                if (first(passenger(f))!= NULL){
                    delete_relasi(passenger(f), info(P).NIK);
                }
                f = next(f);
            }
            P = NULL;
            cout << "*---------------------------------*" << endl;
            cout << "| Data Passenger berhasil dihapus |" << endl;
            cout << "*---------------------------------*" << endl;
        }else{
            cout << "*----------------------*" << endl;
            cout << "| Data tidak ditemukan  |" << endl;
            cout << "*----------------------*" << endl;
        }
    }
}

void deletePassengerFromFlight(listF &LF, int NIK, int ID){
    adrF q = findID(ID,LF);
    if (q != NULL){
        delete_relasi(passenger(q),NIK);
    }else{
        cout << "*----------------------*" << endl;
        cout << "| Data tidak ditemukan |" << endl;
        cout << "*----------------------*" << endl;
    }
}

void inputAwal(listF &LF, listP &LP){
    flight x;
    passenger y;
    adrP q;
    x.ID = 48;
    x.maskapai = "VirginAustralia";
    x.asal = "Denpasar";
    x.tujuan = "Brisbane";
    x.waktu = "15:10";
    x.tanggal = "01-January-2024";
    adrF p = createElmFlight(x);
    insertLastFlight(LF,p);

    x.ID = 898;
    x.maskapai = "VietJetAir";
    x.asal = "Denpasar";
    x.tujuan = "HoChiMinhCity";
    x.waktu = "15:35";
    x.tanggal = "01-January-2024";
    p = createElmFlight(x);
    insertLastFlight(LF,p);

    x.ID = 82;
    x.maskapai = "Jetstar";
    x.asal = "Denpasar";
    x.tujuan = "Darwin";
    x.waktu = "19:05";
    x.tanggal = "01-January-2024";
    p = createElmFlight(x);
    insertLastFlight(LF,p);

    x.ID = 369;
    x.maskapai = "Emirates";
    x.asal = "Dubai";
    x.tujuan = "Denpasar";
    x.waktu = "19:50";
    x.tanggal = "03-Januray-2024";
    p = createElmFlight(x);
    insertLastFlight(LF,p);

    x.ID = 6005;
    x.maskapai = "BatikAir";
    x.asal = "Sydney";
    x.tujuan = "Denpasar";
    x.waktu = "20:55";
    x.tanggal = "04-January-2024";
    p = createElmFlight(x);
    insertLastFlight(LF,p);


    x.ID = 67;
    x.maskapai = "TurkishAirlines";
    x.asal = "Istanbul";
    x.tujuan = "Sydney";
    x.waktu = "21:25";
    x.tanggal = "05-January-2024";
    p = createElmFlight(x);
    insertLastFlight(LF,p);

    y.NIK = 737;
    y.nama = "Arief";
    y.usia = "19";
    y.gen = "Pria";
    q = createElmPas(y);
    insertLastPassenger(LP,q);

    y.NIK = 517;
    y.nama = "Helmi";
    y.usia = "24";
    y.gen = "Pria";
    q = createElmPas(y);
    insertLastPassenger(LP,q);

    y.NIK = 7832;
    y.nama = "Chaewon";
    y.usia = "21";
    y.gen = "Wanita";
    q = createElmPas(y);
    insertLastPassenger(LP,q);

    y.NIK = 9517;
    y.nama = "Yunjin";
    y.usia = "36";
    y.gen = "Wanita";
    q = createElmPas(y);
    insertLastPassenger(LP,q);

    y.NIK = 6591;
    y.nama = "Kazuha";
    y.usia = "22";
    y.gen = "Wanita";
    q = createElmPas(y);
    insertLastPassenger(LP,q);

    y.NIK = 120;
    y.nama = "Wiraldy";
    y.usia = "89";
    y.gen = "Pria";
    q = createElmPas(y);
    insertLastPassenger(LP,q);

    y.NIK = 3203;
    y.nama = "Ghazy";
    y.usia = "45";
    y.gen = "Pria";
    q = createElmPas(y);
    insertLastPassenger(LP,q);

    y.NIK = 120;
    y.nama = "Wiraldy";
    y.usia = "89";
    y.gen = "Pria";
    q = createElmPas(y);
    insertLastPassenger(LP,q);

    y.NIK = 673;
    y.nama = "Winter";
    y.usia = "17";
    y.gen = "Wanita";
    q = createElmPas(y);
    insertLastPassenger(LP,q);

    y.NIK = 571;
    y.nama = "Sherlyn";
    y.usia = "23";
    y.gen = "Wanita";
    q = createElmPas(y);
    insertLastPassenger(LP,q);

    y.NIK = 5719;
    y.nama = "Eren";
    y.usia = "26";
    y.gen = "Pria";
    q = createElmPas(y);
    insertLastPassenger(LP,q);

    y.NIK = 4914;
    y.nama = "Mikasa";
    y.usia = "12";
    y.gen = "Wanita";
    q = createElmPas(y);
    insertLastPassenger(LP,q);

    y.NIK = 8129;
    y.nama = "Groot";
    y.usia = "3";
    y.gen = "Pria";
    q = createElmPas(y);
    insertLastPassenger(LP,q);

    y.NIK = 3103;
    y.nama = "Yeji";
    y.usia = "19";
    y.gen = "Wanita";
    q = createElmPas(y);
    insertLastPassenger(LP,q);

    y.NIK = 2810;
    y.nama = "Ryujin";
    y.usia = "36";
    y.gen = "Wanita";
    q = createElmPas(y);
    insertLastPassenger(LP,q);

    y.NIK = 152;
    y.nama = "Miyako";
    y.usia = "89";
    y.gen = "Wanita";
    q = createElmPas(y);
    insertLastPassenger(LP,q);

    y.NIK = 7619;
    y.nama = "Jhony";
    y.usia = "45";
    y.gen = "Pria";
    q = createElmPas(y);
    insertLastPassenger(LP,q);

    y.NIK = 9123;
    y.nama = "Knight";
    y.usia = "51";
    y.gen = "Pria";
    q = createElmPas(y);
    insertLastPassenger(LP,q);
}

int menu(){
    cout << "*===================================================*" << endl;
    cout << "|    Ngurah Rai Airport Flight & Passenger Data     |" << endl;
    cout << "*===================================================*" << endl;
    cout << "| 1. Insert data                                    |" << endl;
    cout << "| 2. Add Relation                                   |" << endl;
    cout << "| 3. Show Data                                      |" << endl;
    cout << "| 4. Find Data                                      |" << endl;
    cout << "| 5. Delete Data                                    |" << endl;
    cout << "| 0. Exit                                           |" << endl;
    cout << "*===================================================*" << endl;
    cout << "Masukkan pilihan: ";

    int input = 0;
    cin >> input;

    return input;
}
