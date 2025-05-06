#include "TUBES.h"

using namespace std;

int main() {
    listF LF;
    listP LP;
    listR LR;
    flight f;
    passenger p;
    adrF aF;
    adrP aP;
    string y;
    int t = 0;
    int ID = 0, NIK = 0, pil = 6, nFlight = 0, nPass = 0;

    createListflight(LF);
    createListPas(LP);
    inputAwal(LF,LP);

    while (pil != 0) {
        pil = menu();
        switch (pil) {
            case 1: {
                system("cls");
                y = "yes";
                while (y == "yes") {
                    cout << "*=================================*" << endl;
                    cout << "| Anda ingin memasukkan data apa? |" << endl;
                    cout << "| 1. Flight                       |" << endl;
                    cout << "| 2. Passenger                    |" << endl;
                    cout << "| 0. Exit (Random Number)         |" << endl;
                    cout << "*=================================*" << endl;
                    cout << "Masukkan Pilihan: ";
                    cin >> t;
                    if (t == 1) {
                        system("cls");
                        cout << "Berapa banyak data yang ingin anda masukkan?: ";
                        cin >> nFlight;
                        for (int i = 0; i < nFlight; i++) {
                            cout << "ID Pesawat: ";
                            cin >> f.ID;
                            cout << "Maskapai: ";
                            cin >> f.maskapai;
                            cout << "From: ";
                            cin >> f.asal;
                            cout << "To: ";
                            cin >> f.tujuan;
                            cout << "Time: ";
                            cin >> f.waktu;
                            cout << "Date: ";
                            cin >> f.tanggal;
                            aF = createElmFlight(f);
                            insertLastFlight(LF, aF);
                        }
                    } else if (t == 2) {
                        system("cls");
                        cout << "Berapa banyak data yang ingin anda masukkan?: ";
                        cin >> nPass;
                        for (int i = 0; i < nPass; i++) {
                            cout << "NIK: ";
                            cin >> p.NIK;
                            cout << "Name: ";
                            cin >> p.nama;
                            cout << "Age: ";
                            cin >> p.usia;
                            cout << "Gender: ";
                            cin >> p.gen;
                            aP = createElmPas(p);
                            insertLastPassenger(LP, aP);
                        }
                    } else {
                        system("cls");
                        break;
                    }
                    cout << "Apakah anda ingin menambahkan data lagi? (yes/no): ";
                    cin >> y;
                }
                system("cls");
                break;
            }
            case 2: {
                y = "yes";
                while (y == "yes"){
                    system("cls");
                    cout << "*-------------------------------------*" << endl;
                    cout << "|            Tambah Relasi            |" << endl;
                    cout << "*-------------------------------------*" << endl;
                    cout << endl;
                    cout << "*-------------------------------------*" << endl;
                    cout << "|             Data Flight             |" << endl;
                    cout << "*-------------------------------------*" << endl;
                    showFlight(LF);
                    cout << endl;
                    cout << "*-------------------------------------*" << endl;
                    cout << "|            Data Passenger           |" << endl;
                    cout << "*-------------------------------------*" << endl;
                    showPass(LP);
                    cout << "Masukkan Flight ID: ";
                    cin >> ID;
                    adrF check = findID(ID,LF);
                    cout << "Masukkan Passenger NIK: ";
                    cin >> NIK;
                    adrP check1 = findNIK(NIK,LP);
                    if (check == NULL || check1 == NULL){
                        system("cls");
                        cout << "*-------------------------------------------------------*" << endl;
                        cout << "| ID / NIK yang dimasukkan tidak terdapat di dalam data |" << endl;
                        cout << "*-------------------------------------------------------   *" << endl;
                    }else{
                        addRelation(LF,LP,NIK,ID);
                    }
                    cout << "Apakah anda ingin menambahkan relasi lagi? (yes/no): ";
                    cin >> y;
                }
                system("cls");
                break;
            }
            case 3: {
                y = "yes";
                while (y == "yes") {
                    system("cls");
                    cout << "*=================================*" << endl;
                    cout << "| Anda ingin menampilkan data apa |" << endl;
                    cout << "| 1. Flight                       |" << endl;
                    cout << "| 2. Passenger                    |" << endl;
                    cout << "| 3. Relation                     |" << endl;
                    cout << "| 0. Exit (Random Number)         |" << endl;
                    cout << "*=================================*" << endl;
                    cout << "Masukkan Pilihan: ";
                    cin >> t;
                    if (t == 1) {
                        system("cls");
                        showFlight(LF);
                    } else if (t == 2) {
                        system("cls");
                        showPass(LP);
                    } else if (t == 3) {
                        system("cls");
                        showAllData(LF);
                    }else {
                        system("cls");
                        break;
                    }
                    cout << "Apakah anda ingin menampilkan data lagi? (yes/no): ";
                    cin >> y;
                }
                system("cls");
                break;
            }
            case 4: {
                y = "yes";
                while (y == "yes"){
                    system("cls");
                    cout << "*==============================*" << endl;
                    cout << "| Ingin mencari data apa?      |" << endl;
                    cout << "| 1. Flight                    |" << endl;
                    cout << "| 2. Passenger                 |" << endl;
                    cout << "| 3. Passenger di dalam Flight |" << endl;
                    cout << "| 0. Exit (Random Number)      |" << endl;
                    cout << "*==============================*" << endl;
                    cout << "Masukkan Pilihan: ";
                    cin >> t;
                    if (t == 1) {
                        system("cls");
                        cout << "Masukkan Flight ID untuk mencari data: ";
                        cin >> ID;
                        adrF p = findID(ID,LF);
                        if (p == NULL){
                            system("cls");
                            cout << "*----------------------*" << endl;
                            cout << "| Data tidak ditemukan |" << endl;
                            cout << "*----------------------*" << endl;
                        }else{
                            system("cls");
                            cout << "*===============================*" << endl;
                            cout << "ID       : " << info(p).ID << endl;
                            cout << "Maskapai : " << info(p).maskapai << endl;
                            cout << "Asal     : " << info(p).asal << endl;
                            cout << "Tujuan   : " << info(p).tujuan << endl;
                            cout << "Waktu    : " << info(p).waktu << endl;
                            cout << "Tanggal  : " << info(p).tanggal << endl;
                            cout << "*===============================*" << endl;
                            if (first(passenger(p)) != NULL){
                                cout << "Jumlah penumpang dalam penerbangan ini: " << countPassenger(LF,info(p).ID) << endl;
                                showRelation(passenger(p));
                                cout << "*==========================================*"<< endl;
                            }else{
                                cout << "Tidak ada yang menaiki penerbangan ini" << endl;
                                cout << "*==========================================*"<< endl;
                            }
                        }
                    } else if (t == 2) {
                        system("cls");
                        cout << "Masukkan NIK Passenger untuk mencari data: ";
                        cin >> NIK;
                        adrP q = findNIK(NIK,LP);
                        if (q == NULL){
                            system("cls");
                            cout << "*----------------------*" << endl;
                            cout << "| Data tidak ditemukan |" << endl;
                            cout << "*----------------------*" << endl;
                        }else{
                            system("cls");
                            cout << "*=========================*" << endl;
                            cout << "NIK           : " << info(q).NIK << endl;
                            cout << "Nama          : " << info(q).nama << endl;
                            cout << "Usia          : " << info(q).usia << endl;
                            cout << "Jenis Kelamin : " << info(q).gen << endl;
                            cout << "*=========================*" << endl;
                        }
                    }else if (t == 3){
                        system("cls");
                        cout << "Masukkan NIK Passenger: ";
                        cin >> NIK;
                        cout << "Masukkan ID Flight: ";
                        cin >> ID;
                        adrF af = findID(ID,LF);
                        adrR ar = findFlightPassenger(passenger(af), NIK);
                        if (ar == NULL){
                            cout << "Passenger tidak ditemukan" << endl;
                        }else{
                            cout << "*=========================*" << endl;
                            cout << "NIK           : " << info(nextPass(ar)).NIK << endl;
                            cout << "Nama          : " << info(nextPass(ar)).nama << endl;
                            cout << "Usia          : " << info(nextPass(ar)).usia << endl;
                            cout << "Jenis Kelamin : " << info(nextPass(ar)).gen << endl;
                            cout << "*=========================*" << endl;
                        }
                    }else{
                        system("cls");
                        break;
                    }
                    cout << "Apakah anda ingin mencari data lagi? (yes/no): ";
                    cin >> y;
                }
                system("cls");
                break;
            }
            case 5: {
                y = "yes";
                while (y == "yes"){
                    system("cls");
                    cout << "*================================*" << endl;
                    cout << "| Anda ingin menghapus data apa? |" << endl;
                    cout << "| 1. Flight                      |" << endl;
                    cout << "| 2. Passenger                   |" << endl;
                    cout << "| 3. Relation                    |" << endl;
                    cout << "| 0. Exit (Random Number)        |" << endl;
                    cout << "*================================*" << endl;
                    cout << "Masukkan pilihan: ";
                    cin >> t;
                    if (t == 1){
                        system("cls");
                        showFlight(LF);
                        cout << "Masukkan ID Flight: ";
                        cin >> ID;
                        adrF cek1 = findID(ID,LF);
                        if (cek1 == NULL){
                            system("cls");
                            cout << "*----------------------*" << endl;
                            cout << "| Data tidak ditemukan |" << endl;
                            cout << "*----------------------*" << endl;
                        }else{
                            system("cls");
                            delete_flight(LF,ID);
                        }
                    }else if (t == 2){
                        system("cls");
                        showPass(LP);
                        cout << "Masukkan NIK Passenger: ";
                        cin >> NIK;
                        adrP cek2 = findNIK(NIK,LP);
                        if (cek2 == NULL){
                            system("cls");
                            cout << "*----------------------*" << endl;
                            cout << "| Data tidak ditemukan |" << endl;
                            cout << "*----------------------*" << endl;
                        }else{
                            system("cls");
                            delete_passenger(LP,LF,NIK);
                        }
                    }else if (t == 3){
                        system("cls");
                        showAllData(LF);
                        cout << "Masukkan ID Flight: ";
                        cin >> ID;
                        cout << "Masukkan NIK Passenger: ";
                        cin >> NIK;
                        deletePassengerFromFlight(LF,NIK,ID);
                    }else{
                        system("cls");
                        break;
                    }
                    cout << "Apakah anda ingin menghapus data lagi? (yes/no): ";
                    cin >> y;
                }
                system("cls");
                break;
            }
        }
        if (pil != 1 || pil != 2 || pil != 3 || pil != 4 || pil != 5){
            pil = 0;
        }
    }
    system("cls");
    cout << "Bye, Thank You!" << endl;
    return 0;
}
