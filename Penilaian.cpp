#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

struct Mahasiswa {
    string nim, nama;
    double tugas, uts, uas, nilaiAkhir;
    char grade;
    string status;
};

char konversiGrade(double na) {
    if (na >= 85) return 'A';
    else if (na >= 75) return 'B';
    else if (na >= 65) return 'C';
    else if (na >= 50) return 'D';
    else return 'E';
}

string statusLulus(double na) {
    return (na >= 65) ? "Lulus" : "Tidak Lulus";
}

void clearInput() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    int n;
    cout << "Jumlah mahasiswa: ";
    cin >> n;
    clearInput(); // bersihkan newline setelah input angka

    Mahasiswa mhs[n];
    for (int i = 0; i < n; i++) {
        cout << "\nData mahasiswa ke-" << i+1 << ":\n";

        cout << "Masukkan NIM   : ";
        getline(cin, mhs[i].nim);

        cout << "Masukkan Nama  : ";
        getline(cin, mhs[i].nama);

        cout << "Masukkan nilai Tugas (0-100): ";
        cin >> mhs[i].tugas;

        cout << "Masukkan nilai UTS   (0-100): ";
        cin >> mhs[i].uts;

        cout << "Masukkan nilai UAS   (0-100): ";
        cin >> mhs[i].uas;
        clearInput(); // bersihkan newline sebelum input teks berikutnya

        mhs[i].nilaiAkhir = 0.3*mhs[i].tugas + 0.3*mhs[i].uts + 0.4*mhs[i].uas;
        mhs[i].grade = konversiGrade(mhs[i].nilaiAkhir);
        mhs[i].status = statusLulus(mhs[i].nilaiAkhir);
    }

    cout << "\n=== Hasil Penilaian ===\n";
    cout << left << setw(10) << "NIM" 
         << setw(15) << "Nama" 
         << setw(10) << "NA" 
         << setw(6) << "Grade"
         << setw(12) << "Status" << endl;

    for (int i = 0; i < n; i++) {
        cout << left << setw(10) << mhs[i].nim
             << setw(15) << mhs[i].nama
             << setw(10) << fixed << setprecision(2) << mhs[i].nilaiAkhir
             << setw(6) << mhs[i].grade
             << setw(12) << mhs[i].status << endl;
    }
    return 0;
}