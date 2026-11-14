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

void tampilkanKamar(Kamar daftarKamar[], int jumlahKamar);
void tampilkanTamu(Tamu daftarTamu[], int jumlahTamu);

void reservasiKamar(Kamar daftarKamar[], Tamu daftarTamu[], int jumlahKamar, int *jumlahTamu);
void checkout(Kamar daftarKamar[], Tamu daftarTamu[], int jumlahKamar, int *jumlahTamu);
void cetakInvoice(Kamar daftarKamar[], Tamu daftarTamu[], int jumlahKamar, int jumlahTamu);

void simpanKamar(Kamar daftarKamar[], int jumlahKamar);
int muatKamar(Kamar daftarKamar[]);
void simpanTamu(Tamu daftarTamu[], int jumlahTamu);
int muatTamu(Tamu daftarTamu[]);

#endif