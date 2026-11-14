#include <stdio.h>
#include "kos.h"

void tampilkanKamar(Kamar daftarKamar[], int jumlahKamar) {
    printf("====== DAFTAR KAMAR KOS =====\n");

    for (int i = 0; i < jumlahKamar; i++) {
        printf("Nomor kamar: %d | Status: %d\n",
            daftarKamar[i].nomor,
            daftarKamar[i].status);
    }
}

void reservasiKamar(Kamar daftarKamar[], Tamu daftarTamu[], int jumlahKamar, int *jumlahTamu) {

    int nomorPilihan;

    printf("Masukkan nomor kamar: ");
    scanf("%d", &nomorPilihan);

    for (int i = 0; i < jumlahKamar; i++) {
        if (daftarKamar[i].nomor == nomorPilihan) {

            if (daftarKamar[i].status != 0) {
                printf("Kamar sudah terisi!\n");
                return;
            }

            if (*jumlahTamu >= jumlahKamar) {
                printf("Data tamu sudah penuh!\n");
                return;
            }

            printf("Masukkan nama tamu: ");
            scanf(" %49[^\n]", daftarTamu[*jumlahTamu].nama);

            printf("Masukkan NIK: ");
            scanf("%19s", daftarTamu[*jumlahTamu].nik);

            printf("Masukkan durasi menginap: ");
            scanf("%d", &daftarTamu[*jumlahTamu].durasi);

            daftarTamu[*jumlahTamu].nomorKamar = nomorPilihan;

            daftarKamar[i].status = 1;

            (*jumlahTamu)++;

            printf("Reservasi berhasil!\n");
            return;
        }
    }

    printf("Nomor kamar tidak ditemukan!\n");
}

void tampilkanTamu(Tamu daftarTamu[], int jumlahTamu) {
    printf("\n======= DATA TAMU KOS =======");

    if(jumlahTamu == 0) {
        printf("Belum ada tamu yang terdaftar.\n");
        return;
    }

    for (int i = 0; i < jumlahTamu; i++) {
        printf("\nTamu ke-%d\n", i + 1);
        printf("Nama        : %s\n", daftarTamu[i].nama);
        printf("NIK         : %s\n", daftarTamu[i].nik);
        printf("Nomor Kamar : %d\n", daftarTamu[i].nomorKamar);
        printf("Durasi      : %d hari\n", daftarTamu[i].durasi);
    }
}

void simpanKamar(Kamar daftarKamar[], int jumlahKamar) {
    FILE *file = fopen("data/kamar.bin", "wb");
    
    if (file == NULL) {
        printf("Gagal membuka file!\n");
        return;
    }

    fwrite(daftarKamar, sizeof(Kamar), jumlahKamar, file);
    fclose(file);

    printf("Data kamar berhasil disimpan\n");
}
