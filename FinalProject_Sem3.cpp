#include<iostream>
#include<cstdlib>
#include <string>
#define MAX 100

using namespace std;

struct lagu{
	int idLagu;
	string judul;
	string penyanyi;
};

struct queue{
	lagu data[MAX];
	int awal, akhir;
}antrean;

void init(){
	antrean.awal = -1;
	antrean.akhir= -1;
}

bool full(){
	if(antrean.akhir == MAX-1){
		return true;
	}else{
		return false;
	}
}

bool empty(){
	if(antrean.akhir==-1){
		return true;
	}else{
		return false;
	}
}

void tampilPlaylist(){
	int i;
	if(!empty()){
		for(i=antrean.awal; i<=antrean.akhir; i++){
			cout<<antrean.data[i].idLagu<<" | ";
			cout<<antrean.data[i].judul<<" | ";
			cout<<antrean.data[i].penyanyi<<endl;
		}
	}
	cout<<"\n";
}


void inQueue(){
	tampilPlaylist();
	string jdl;
	int id;
	string singer;
	
	if(!full()){
		if(antrean.awal==-1){
			antrean.awal = 0;
		}
		cout<<"Masukkan ID Lagu : ";
		cin>>id;
		cout<<"Masukkan Judul Lagu : ";
		cin>>jdl;
		cout<<"Masukkan Penyanyi : ";
		cin>>singer;
		antrean.akhir++;
		antrean.data[antrean.akhir].idLagu=id;
		antrean.data[antrean.akhir].judul=jdl;
		antrean.data[antrean.akhir].penyanyi=singer;
		cout<<endl;
		cout<<"Playlist Saat Ini : "<<endl;
		tampilPlaylist();
		
	}else{
		cout<<"Playlist penuh\n";
	}
	getchar();
}

void tampilLagu(){
	int i;
	if(!empty()){
		cout<<"Playlist Saat Ini : "<<endl;
		for(i=antrean.awal; i<=antrean.akhir; i++){
			cout<<antrean.data[i].idLagu<<" | ";
			cout<<antrean.data[i].judul<<" | ";
			cout<<antrean.data[i].penyanyi<<endl;
		}
	}else{
		cout<<"Harap Isi Playlist Terlebih Dahulu";
		inQueue();
	}
	cout<<"\n";
}


void play() {
    if (!empty()) {
        lagu* ptr = &antrean.data[antrean.awal]; 

        cout << "\nMemutar lagu \"" << ptr->judul << "\"...\n";
        cout << "ID: " << ptr->idLagu << " | Judul: " << ptr->judul
             << " | Penyanyi: " << ptr->penyanyi << endl;
    	cout<<"==============================="<<endl;
    	
        for (int i = antrean.awal; i < antrean.akhir; i++) {
            antrean.data[i] = antrean.data[i + 1];
        }
        antrean.akhir--;
        cout<<"Playlist Lagu Berikutnya : "<<endl;
		tampilPlaylist();
        if (antrean.akhir < antrean.awal) {
            init();
        }
    } else {
        cout << "Playlist kosong, harap isi playlist terlebih dahulu.\n";
    }
}


void sortingById() {
    if (!empty()) {
        for (int i = antrean.awal; i <= antrean.akhir; i++) {
            for (int j = antrean.awal; j < antrean.akhir - (i - antrean.awal); j++) {
                if (antrean.data[j].idLagu > antrean.data[j + 1].idLagu) {
                    lagu temp = antrean.data[j];
                    antrean.data[j] = antrean.data[j + 1];
                    antrean.data[j + 1] = temp;
                }
            }
        }
        cout << "Playlist telah diurutkan berdasarkan ID Lagu.\n";
        tampilLagu();
    } else {
        cout << "Playlist kosong, tidak ada yang bisa diurutkan.\n";
    }
}

void sortById(){
	if (!empty()) {
        for (int i = antrean.awal; i <= antrean.akhir; i++) {
            for (int j = antrean.awal; j < antrean.akhir - (i - antrean.awal); j++) {
                if (antrean.data[j].idLagu > antrean.data[j + 1].idLagu) {
                    lagu temp = antrean.data[j];
                    antrean.data[j] = antrean.data[j + 1];
                    antrean.data[j + 1] = temp;
                }
            }
        }
    } else {
        cout << "Playlist kosong, tidak ada yang bisa diurutkan.\n";
    }
}

void sortingByJudul() {
    if (!empty()) {
        for (int i = antrean.awal; i <= antrean.akhir; i++) {
            for (int j = antrean.awal; j < antrean.akhir - (i - antrean.awal); j++) {
                if (antrean.data[j].judul > antrean.data[j + 1].judul) {
                    lagu temp = antrean.data[j];
                    antrean.data[j] = antrean.data[j + 1];
                    antrean.data[j + 1] = temp;
                }
            }
        }
        cout << "Playlist telah diurutkan berdasarkan Judul Lagu.\n";
        tampilLagu();
    } else {
        cout << "Playlist kosong, tidak ada yang bisa diurutkan.\n";
    }
}

void sortByJudul(){
	if (!empty()) {
        for (int i = antrean.awal; i <= antrean.akhir; i++) {
            for (int j = antrean.awal; j < antrean.akhir - (i - antrean.awal); j++) {
                if (antrean.data[j].judul > antrean.data[j + 1].judul) {
                    lagu temp = antrean.data[j];
                    antrean.data[j] = antrean.data[j + 1];
                    antrean.data[j + 1] = temp;
                }
            }
        }
    } else {
        cout << "Playlist kosong, tidak ada yang bisa diurutkan.\n";
    }
}

void searchById() {
    if (!empty()) {
    	sortById();
        int id;
        cout << "Masukkan ID Lagu yang ingin dicari: ";
        cin >> id;

        int left = antrean.awal;
        int right = antrean.akhir;
        int mid;
        bool found = false;

        while (left <= right) {
            mid = left + (right - left) / 2;

            if (antrean.data[mid].idLagu == id) { 
                found = true;
                break;
            } else if (antrean.data[mid].idLagu < id) {
                left = mid + 1; 
            } else {
                right = mid - 1; 
            }
        }

        if (found) {
            cout << "Lagu dengan ID " << id << " ditemukan:\n";

            int i = mid;
            while (i >= antrean.awal && antrean.data[i].idLagu == id) {
                cout << "ID: " << antrean.data[i].idLagu << " | Judul: " << antrean.data[i].judul
                     << " | Penyanyi: " << antrean.data[i].penyanyi << endl;
                i--;
            }

            i = mid + 1;
            while (i <= antrean.akhir && antrean.data[i].idLagu == id) {
                cout << "ID: " << antrean.data[i].idLagu << " | Judul: " << antrean.data[i].judul
                     << " | Penyanyi: " << antrean.data[i].penyanyi << endl;
                i++;
            }
            cout<<"==============================="<<endl;
        } else {
            cout << "Lagu dengan ID " << id << " tidak ditemukan.\n";
        }
    } else {
        cout << "Playlist kosong, tidak ada lagu untuk dicari.\n";
    }
}

void searchByJudul() {
    if (!empty()) {
    	sortByJudul();
        string judul;
        cout << "Masukkan Judul Lagu yang ingin dicari: ";
        cin>>judul;

        int left = antrean.awal;
        int right = antrean.akhir;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (antrean.data[mid].judul == judul) { 
                cout << "Lagu ditemukan:\n";
                cout << "ID: " << antrean.data[mid].idLagu << " | Judul: " << antrean.data[mid].judul
                     << " | Penyanyi: " << antrean.data[mid].penyanyi << endl;
                return;
            } else if (antrean.data[mid].judul < judul) {
                left = mid + 1; 
            } else {
                right = mid - 1; 
            }
        }
        cout << "Lagu dengan Judul \"" << judul << "\" tidak ditemukan.\n";
    } else {
        cout << "Playlist kosong, tidak ada lagu untuk dicari.\n";
    }
}

void sortingByPenyanyi() {
    if (!empty()) {
        for (int i = antrean.awal; i <= antrean.akhir; i++) {
            for (int j = antrean.awal; j < antrean.akhir - (i - antrean.awal); j++) {
                if (antrean.data[j].penyanyi > antrean.data[j + 1].penyanyi) {
                    lagu temp = antrean.data[j];
                    antrean.data[j] = antrean.data[j + 1];
                    antrean.data[j + 1] = temp;
                }
            }
        }
        cout << "Playlist telah diurutkan berdasarkan Penyanyi.\n";
        tampilLagu();
    } else {
        cout << "Playlist kosong, tidak ada yang bisa diurutkan.\n";
    }
}

void sortByPenyanyi(){
	if (!empty()) {
        for (int i = antrean.awal; i <= antrean.akhir; i++) {
            for (int j = antrean.awal; j < antrean.akhir - (i - antrean.awal); j++) {
                if (antrean.data[j].penyanyi > antrean.data[j + 1].penyanyi) {
                    lagu temp = antrean.data[j];
                    antrean.data[j] = antrean.data[j + 1];
                    antrean.data[j + 1] = temp;
                }
            }
        }
    } else {
        cout << "Playlist kosong, tidak ada yang bisa diurutkan.\n";
    }
}

void searchByPenyanyi() {
    if (!empty()) {
    	sortByPenyanyi();
        string singer;
        cout << "Masukkan Penyanyi yang ingin dicari: ";
        cin >> singer;

        int left = antrean.awal;
        int right = antrean.akhir;
        int mid;
        bool found = false;

        while (left <= right) {
            mid = left + (right - left) / 2;

            if (antrean.data[mid].penyanyi == singer) { 
                found = true;
                break;
            } else if (antrean.data[mid].penyanyi < singer) {
                left = mid + 1; 
            } else {
                right = mid - 1; 
            }
        }

        if (found) {
            cout << "Lagu dengan Penyanyi " << singer << " ditemukan:\n";

            int i = mid;
            while (i >= antrean.awal && antrean.data[i].penyanyi == singer) {
                cout << "ID: " << antrean.data[i].idLagu << " | Judul: " << antrean.data[i].judul
                     << " | Penyanyi: " << antrean.data[i].penyanyi << endl;
                i--;
            }

            i = mid + 1;
            while (i <= antrean.akhir && antrean.data[i].penyanyi == singer) {
                cout << "ID: " << antrean.data[i].idLagu << " | Judul: " << antrean.data[i].judul
                     << " | Penyanyi: " << antrean.data[i].penyanyi << endl;
                i++;
            }
            cout<<"==============================="<<endl;
        } else {
            cout << "Lagu dengan penyanyi " << singer << " tidak ditemukan.\n";
        }
    } else {
        cout << "Playlist kosong, tidak ada lagu untuk dicari.\n";
    }
}


void clear(){
    if (!empty()) {
        cout << "Menghapus semua isi playlist...\n";
        antrean.awal = -1; 
        antrean.akhir = -1; 
        cout << "Playlist telah dikosongkan.\n";
    } else {
        cout << "Playlist sudah kosong.\n";
    }
}

int main(){
	int pilihan, elemen;
	init();
	cout<<"Pemutar Music"<<endl;
	do{
		cout<<"\nMenu Utama\n";
		cout<<"==============\n";
		cout<<"[1] Play Music \n[2] Tampilkan Playlist \n[3] Tambahkan Playlist \n[4] Urutkan Playlist berdasarkan ID"<<endl;
		cout<<"[5] Urutkan Playlist Berdasarkan Judul \n[6] Urutkan Playlist Berdasarkan Penyanyi \n[7] Cari Lagu Berdasarkan ID"<<endl; 
		cout<<"[8] Cari Lagu Berdasarkan Judul \n[9] Cari Lagu Berdasarkan Penyanyi \n[0] Clear"<<endl;
		cout<<"==============\n";
		cout<<"\nMasukkan pilihan : ";
		cin>>pilihan;
		cout<<"==============\n";
		switch(pilihan){
			case 1: play(); break;
			case 2: tampilLagu(); break;
			case 3: inQueue(); break;
			case 4: sortingById(); break;
			case 5: sortingByJudul(); break;
			case 6: sortingByPenyanyi(); break;
			case 7: searchById(); break;
			case 8: searchByJudul(); break;
			case 9: searchByPenyanyi(); break;
			case 0: clear(); break;
		}
	}
	while(pilihan!=10);
}
