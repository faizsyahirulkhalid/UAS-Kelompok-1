#ifndef KOS_H
#define KOS_H

typedef struct {
    int nomor;
    char tipe[30];
    double tarif;
    int status;
} Kamar;

typedef struct {
    char nama[50];
    char nik[20];
    int nomorKamar;
    int durasi;
} Tamu;

void tampilkanKamar(Kamar daftarkamar[], int jumlahKamar);
void tampilkanTamu(Tamu daftatTamu[], int jumlahTamu);
void reservasiKamar(Kamar daftarKamar[], Tamu daftarTamu[], int jumlahKamar, int *jumlahTamu);
void checkout();
void cetakInvoice();
void simpanKamar(Kamar daftarKamar[], int jumlahKamar);

#endif
