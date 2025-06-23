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

void insertAfter(SalonNode*& head) {
    if (!head) return void(cout << "List masih kosong!\n");
    string target;
    cout << "Masukkan nama pelanggan setelah siapa ingin disisipkan: ";
    getline(cin >> ws, target);
    SalonNode* temp = head;
    while (temp && temp->nama != target) temp = temp->next;
    if (!temp) return void(cout << "Nama tidak ditemukan!\n");
    SalonNode* baru = new SalonNode;
    cout << "Nama pelanggan baru: "; getline(cin, baru->nama);
    cout << "Alamat pelanggan baru: "; getline(cin, baru->alamat);
    pilihPaket(baru->paketDipilih);
    baru->next = temp->next; temp->next = baru;
    cout << "Data berhasil disisipkan setelah " << target << ".\n";
}

void deleteData(SalonNode*& head) {
    if (!head) return void(cout << "List kosong.\n");
    string target;
    cout << "Masukkan nama pelanggan yang ingin dihapus: ";
    getline(cin >> ws, target);
    if (head->nama == target) {
        SalonNode* hapus = head;
        head = head->next;
        delete hapus;
        cout << "Data berhasil dihapus.\n";
        return;
    }
    SalonNode *prev = head, *curr = head->next;
    while (curr && curr->nama != target) prev = curr, curr = curr->next;
    if (!curr) return void(cout << "Data tidak ditemukan.\n");
    prev->next = curr->next; delete curr;
    cout << "Data berhasil dihapus.\n";
}

void showData(SalonNode* head) {
    if (!head) return void(cout << "Belum ada data pelanggan.\n");
    int no = 1;
    while (head) {
        cout << no++ << ". Nama: " << head->nama << "\n   Alamat: " << head->alamat << "\n   Paket:\n";
        double total = 0;
        for (auto& p : head->paketDipilih)
            cout << "     - " << p.namaPaket << " (Rp" << p.harga << ")\n", total += p.harga;
        cout << "   Total Harga: Rp" << total << "\n\n";
        head = head->next;
    }
}

