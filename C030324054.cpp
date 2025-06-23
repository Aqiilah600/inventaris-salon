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

