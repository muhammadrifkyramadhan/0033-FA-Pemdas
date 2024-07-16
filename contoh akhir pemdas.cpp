#include <iostream>
using namespace std;

class MasukUniversitas {
protected:
    float uangPendaftaran;
    float uangSemesterPertama;
    float uangBangunan;
    float totalBiaya;
public:
    MasukUniversitas() {
        uangPendaftaran = 0;
        uangSemesterPertama = 0;
        uangBangunan = 0;
        totalBiaya = 0;
    }

    virtual void namaJalurMasuk() {
        cout << "Jalur Masuk Universitas" << endl;
    }

    virtual void input() = 0;
    virtual void hitungTotalBiaya() = 0;
    virtual void tampilkanTotalBiaya() = 0;

    void setUangPendaftaran(float nilai) {
        uangPendaftaran = nilai;
    }

    float getUangPendaftaran() {
        return uangPendaftaran;
    }

    void setUangSemesterPertama(float nilai) {
        uangSemesterPertama = nilai;
    }

    float getUangSemesterPertama() {
        return uangSemesterPertama;
    }

    void setUangBangunan(float nilai) {
        uangBangunan = nilai;
    }

    float getUangBangunan() {
        return uangBangunan;
    }

    float getTotalBiaya() {
        return totalBiaya;
    }
};

class SNBT : public MasukUniversitas {
public:
    void namaJalurMasuk() override {
        cout << "Jalur Masuk SNBT (Seleksi Nasional Berdasarkan Tes)" << endl;
    }

    void input() override {
        cout << "Masukkan Biaya Pendaftaran: ";
        cin >> uangPendaftaran;
        cout << "Masukkan Biaya Semester Pertama: ";
        cin >> uangSemesterPertama;
        cout << "Masukkan Biaya Bangunan: ";
        cin >> uangBangunan;
    }

    void hitungTotalBiaya() override {
        totalBiaya = uangPendaftaran + uangSemesterPertama + uangBangunan;
    }

    void tampilkanTotalBiaya() override {
        cout << "Total Biaya: Rp. " << fixed << totalBiaya << endl;
        if (totalBiaya < 20000000) {
            cout << "Kategori Biaya: Murah" << endl;
        }
        else if (totalBiaya >= 20000000 && totalBiaya < 30000000) {
            cout << "Kategori Biaya: Sedang" << endl;
        }
        else {
            cout << "Kategori Biaya: Mahal" << endl;
        }
    }
};

class SNBP : public MasukUniversitas {
public:
    void namaJalurMasuk() override {
        cout << "Jalur Masuk SNBP (Seleksi Nasional Berdasarkan Prestasi)" << endl;
    }

    void input() override {
        cout << "Masukkan Biaya Pendaftaran: ";
        cin >> uangPendaftaran;
        cout << "Masukkan Biaya Semester Pertama: ";
        cin >> uangSemesterPertama;
    }

    void hitungTotalBiaya() override {
        totalBiaya = uangPendaftaran + uangSemesterPertama;
    }

    void tampilkanTotalBiaya() override {
        cout << "Total Biaya: Rp. " << fixed << totalBiaya << endl;
        if (totalBiaya < 15000000) {
            cout << "Kategori Biaya: Murah" << endl;
        }
        else if (totalBiaya >= 15000000 && totalBiaya < 25000000) {
            cout << "Kategori Biaya: Sedang" << endl;
        }
        else {
            cout << "Kategori Biaya: Mahal" << endl;
        }
    }
};

int main() {
    int pilihan;
    MasukUniversitas* jalur;

    do {
        cout << "Menu Pilihan Jalur Masuk Universitas:" << endl;
        cout << "1. SNBT (Seleksi Nasional Berdasarkan Tes)" << endl;
        cout << "2. SNBP (Seleksi Nasional Berdasarkan Prestasi)" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih [1-3]: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            jalur = new SNBT();
            jalur->input();
            jalur->hitungTotalBiaya();
            jalur->tampilkanTotalBiaya();
            delete jalur;
            break;
        case 2:
            jalur = new SNBP();
            jalur->input();
            jalur->hitungTotalBiaya();
            jalur->tampilkanTotalBiaya();
            delete jalur;
            break;
        case 3:
            cout << "Terima kasih telah menggunakan program ini." << endl;
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
            break;
        }

        cout << endl;
    } while (pilihan != 3);

    return 0;
}