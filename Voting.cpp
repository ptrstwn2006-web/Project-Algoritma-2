#include <iostream>
#include <iomanip>
using namespace std;

const int JUMLAH_CALON = 3;

struct Calon {
    string nama;
    int suara;
};

int main() {
    Calon dpr[JUMLAH_CALON] = {
        {"Calon A", 0},
        {"Calon B", 0},
        {"Calon C", 0}
    };

    int jumlahPemilih;
    cout << "=== Sistem Voting Pemilihan DPR ===\n";
    cout << "Masukkan jumlah pemilih: ";
    cin >> jumlahPemilih;

    for (int i = 0; i < jumlahPemilih; i++) {
        int pilihan;
        cout << "\nPemilih ke-" << i+1 << " silakan pilih calon:\n";
        for (int j = 0; j < JUMLAH_CALON; j++) {
            cout << j+1 << ". " << dpr[j].nama << endl;
        }
        cout << "Pilihan Anda (1-" << JUMLAH_CALON << "): ";
        cin >> pilihan;

        if (pilihan >= 1 && pilihan <= JUMLAH_CALON) {
            dpr[pilihan - 1].suara++;
        } else {
            cout << "Pilihan tidak valid. Suara tidak dihitung.\n";
        }
    }

    cout << "\n=== Hasil Voting ===\n";
    cout << left << setw(10) << "Calon" << "Suara\n";
    cout << "----------------------\n";
    for (int i = 0; i < JUMLAH_CALON; i++) {
        cout << left << setw(10) << dpr[i].nama << dpr[i].suara << endl;
    }

    // Menentukan pemenang
    int maxSuara = dpr[0].suara;
    int indeksPemenang = 0;
    for (int i = 1; i < JUMLAH_CALON; i++) {
        if (dpr[i].suara > maxSuara) {
            maxSuara = dpr[i].suara;
            indeksPemenang = i;
        }
    }

    cout << "\nPemenang adalah: " << dpr[indeksPemenang].nama << " dengan " << maxSuara << " suara.\n";

    return 0;
}