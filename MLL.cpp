#include "MLL.hpp"
#include <iostream>

using namespace std;

void create_List(List &ListChild) {
    first(ListChild) = nil;
}
void newElm_Parent(parent info, adrParent &S) {
    S = new elmParent;
    info(S) = info;
    next(S) = nil;
    nextChild(S) = nil;
}
void newElm_Child(infotypeCh info, adrChild &J) {
    J = new elmChild;
    info(J) = info;
    next(J) = nil;
}

void insertNew_Child(List &ListParent, adrParent S, adrChild J) {
    if(nextChild(S) == nil) {
        nextChild(S) = J;
    } else {
        adrChild P = nextChild(S);
        while (next(P) != nil) {
            P = next(P);
        }
        next(P) = J;
    }
}
void inserLast_Parent(List &ListParent, adrParent S) {
    if(first(ListParent) == nil) {
        first(ListParent) = S;
    } else {
        adrParent P = first(ListParent);
        while (next(P) != nil) {
            P = next(P);
        }
        next(P) = S;
    }
}

void deleteFirst_Child(List &ListParent, adrParent &S, adrChild &J) {
    adrChild P = nextChild(S);
    J = nextChild(S);
    if(next(P) == nil) {
        nextChild(S) = nil;
    } else {
        nextChild(S) = next(P);
        next(P) = nil;
    }
}
void deleteLast_Child(List &ListChild, adrParent &S, adrChild &J) {
    
}
void deleteAfter_Child(List &ListChild, adrChild Prec, adrChild &J) {
    J = next(Prec);
    next(Prec) = next(J);
    next(J) = nil;
}

adrChild searchBefore_Child(List ListParent, string number, string ID) {
    adrParent P = first(ListParent);
    while (P != nil) {
        if(info(P).nomor_KK == number) {
            adrChild Q = next(nextChild(P));
            adrChild R = nextChild(P);
            while (next(Q) != nil) {
                if(info(Q).nik == ID) {
                    return R;
                }
                R = Q;
                Q = next(Q);
            }
            return R;
        }
        P = next(P);
    }
    return 0;
}

void deleteFirst_Parent(List &ListParent) {
    adrParent P;
    if(first(ListParent) == nil) {
        cout << "List Kosong\n";
    } else {
        P = first(ListParent);
        first(ListParent) = next(P);
        next(P) = nil;
    }
    
}
void deleteAfter_Parent(adrParent Prec, adrParent P) {
    P = next(Prec);
    next(Prec) = next(P);
    next(P) = nil;
}

adrParent searchBefore_Parent(List ListParent, string number) {
    adrParent P = next(first(ListParent));
    adrParent Q = first(ListParent);
    while (next(P) == nil) {
        if(info(P).nomor_KK == number) {
            return Q;
        }
        Q = P;
        P = next(P);
    }
    return Q;
    return 0;
}

void showData_Parent(List ListParent) {
    int i;
    i = 1;
    if(first(ListParent) == nil) {
        cout << "List Kosong\n";
    } else {
        adrParent P = first(ListParent);
        while (P != nil) {
            adrChild Q;
            Q = nextChild(P);
            cout << i << ". "<< info(P).nomor_KK << endl;
            i++;
            P = next(P);
        }
    }
}
void showData_Child(List ListParent) {
    string input;
    int i = 1;
    if (first(ListParent) == NULL) {
        cout << "LIST KOSONG" << endl<<endl;
    } else {
        adrParent P = first(ListParent);
        cout << "List nomor kartu keluarga :" << endl;
        while (P != NULL){
            cout << i << ". "<< info(P).nomor_KK << endl;
            i++;
            P = next(P);
        }
        cout << "Masukkan Nomor Kartu Keluarga Yang Ingin Di Tampilkan : ";
        cin >> input;
        P = first(ListParent);
        while (P != NULL){
            adrChild Q = nextChild(P);
            if (info(P).nomor_KK == input){
                while(Q != NULL){
                cout << "Nama lengkap : " << info(Q).nama_Lengkap << endl;
                cout << "NIK  : " << info(Q).nik << endl;
                cout << "Tanggal lahir  : " << info(Q).tanggal_Lahir << endl;
                cout << "Tempat lahir  : " << info(Q).tempat_Lahir << endl;
                cout << "Status  : " << info(Q).status << endl;
                cout << endl;
                Q = next(Q);
                }
            }
            P = next(P);
        }
    }
}
adrParent search_Parent(List ListChild, string number) {
    adrParent P = first(ListChild);
    while (P != NULL) {
        if (info(P).nomor_KK == number){
            return P;
        }
        P = next(P);
    }
    return nil;
    return 0;
}


void cari_Child(List ListParent, string nik) {
    adrParent P = first(ListParent);
    adrChild C = search_Child(ListParent, nik);
    if (first(ListParent) == NULL){
      cout << "==================================" << endl;
      cout << "| Nomor Induk Keluarga Tidak Di temukan |" << endl;
      cout << "==================================" << endl;
    }else if(P != NULL){
      P = first(ListParent);
      while(P != NULL){
        adrChild Q = nextChild(P);
          while(Q != NULL){
            if (info(Q).nik == nik && C != NULL){
                if(C != NULL){
                    cout << "==================================" << endl;
                    cout << "Nama lengkap   : " << info(Q).nama_Lengkap << endl;
                    cout << "NIK    : " << info(Q).nik << endl;
                    cout << "Tanggal lahir    : " << info(Q).tanggal_Lahir << endl;
                    cout << "Tempat lahir  : " << info(Q).tempat_Lahir << endl;
                    cout << "Status : " << info(Q).status << endl;
                    cout << "==================================" << endl;
                }
            } else if(C == NULL) {
                cout << "==================================" << endl;
                cout << "| Nomor Induk Keluarga Mahasiswa Tidak Di Temukan |" << endl;
                cout << "==================================" << endl;
            }
            cout << endl;
            Q = next(Q);
          }
        P = next(P);
      }
    }
}
adrChild search_Child(List ListParent, string nik) {
    adrParent P = first(ListParent);
    while (P != NULL) {
        adrChild Q = nextChild(P);
        while(Q != NULL){
          if (info(Q).nik == nik){
            return Q;
          }
          Q = next(Q);
        }
        P = next(P);
    }
    return nil;
    return 0;
}

int selectMenu() {
    cout << "============================\n";
    cout << "   ----------------------   \n";
    cout << "   PROGRAM KARTU KELUARGA   \n";
    cout << "   ----------------------   \n";
    cout << " Ahmad Naufal Diwantara Putra 1302204085   \n";
    cout << " Jeremia Carlo Christianto Silitonga 1302204115   \n";
    cout << "============================\n";

    cout << "1. Tambah Daftar Keluarga\n";
    cout << "2. Tambah Anggota Keluarga\n";
    cout << "3. Menampilkan Daftar Keluarga\n";
    cout << "4. Menampilkan anggota keluarga\n";
    cout << "5. Delete anggota keluarga\n";
    cout << "6. Delete Anggota Keluarga\n";
    cout << "7. Cari Child\n";
    cout << "0. Keluar" << endl << endl;
    cout << "Pilihan menu : " ;
    int input;
    cin >> input;
    cout << endl;

    return input;
    return 0;
}
