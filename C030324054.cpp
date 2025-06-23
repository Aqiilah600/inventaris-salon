#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Paket {
    string namaPaket;
    double harga;
};

struct SalonNode {
    string nama, alamat;
    vector<Paket> paketDipilih;
    SalonNode* next;
};

const string daftarPaket[] = {
    "Cuci Blow", "Potong Rambut", "Creambath", "Smoothing", "Facial", "Hair Coloring"
};
const double hargaPaket[] = { 25000, 30000, 40000, 100000, 50000, 120000 };
const int JUMLAH_PAKET = sizeof(daftarPaket)/sizeof(daftarPaket[0]);

void pilihPaket(vector<Paket>& paketDipilih) {
    int idx; char lagi;
    do {
        cout << "\nDaftar Paket:\n";
        for (int i = 0; i < JUMLAH_PAKET; i++)
            cout << i + 1 << ". " << daftarPaket[i] << " - Rp" << hargaPaket[i] << endl;
        cout << "Pilih nomor paket: "; cin >> idx; idx--;
        if (idx >= 0 && idx < JUMLAH_PAKET)
            paketDipilih.push_back({daftarPaket[idx], hargaPaket[idx]});
        else
            cout << "Pilihan tidak valid.\n";
        cout << "Tambah paket lagi? (y/n): "; cin >> lagi;
    } while (lagi == 'y' || lagi == 'Y');
    cin.ignore();
}

void addData(SalonNode*& head) {
    SalonNode* baru = new SalonNode;
    cout << "Nama pelanggan: "; getline(cin >> ws, baru->nama);
    cout << "Alamat pelanggan: "; getline(cin, baru->alamat);
    pilihPaket(baru->paketDipilih);
    baru->next = nullptr;
    if (!head) head = baru;
    else {
        SalonNode* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = baru;
    }
    cout << "Data berhasil ditambahkan.\n";
}

