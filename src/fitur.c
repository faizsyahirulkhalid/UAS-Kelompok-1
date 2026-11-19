#include <stdio.h>
#include <string.h>
#include "fitur.h"

void isiKamar(Kamar kamar[]) {
    int i;
    for (i = 0; i < JUMLAH_KAMAR; i++) {
        kamar[i].nomor = i + 101;
        kamar[i].terisi = 0;
        if (i < 2) {
            strcpy(kamar[i].tipe, "Standard");
            kamar[i].tarif = 250000;
        } else if (i < 4) {
            strcpy(kamar[i].tipe, "Deluxe");
            kamar[i].tarif = 400000;
        } else {
            strcpy(kamar[i].tipe, "Suite");
            kamar[i].tarif = 650000;
        }
    }
}

void tampilkamar(kamar kamar[]) {
    int i;
    printf("\nDAFTAR KAMAR HOTEL\n");
    printf("No.\tTipe\t\tTarif\t\tStatus\n");
    for(i=0; i<JUMLAH_KAMAR; i++) {
        printf("%d\t%-10s\tRp%d\t%s\n", kamar[i].nomor,
            kamar[i].tipe, kamar[i].tarif,
            kamar[i].terisi ? "Terisi" : "Kosong");
    }
}

void simpanKamar(Kamar kamar[], const char *namaFile) {
    FILE *fp = fopen(namaFile, "wb");
    if (fp == NULL) {
        printf("Gagal menyimpan database.\n");
        return;
    }
    fwrite(kamar, sizeof(Kamar), JUMLAH_KAMAR, fp);
    fclose(fp);
}
#include <stdio.h>
#include <string.h>
#include "fitur.h"

void isiKamar(Kamar kamar[]) {
    int i;
    for (i = 0; i < JUMLAH_KAMAR; i++) {
        kamar[i].nomor = i + 101;
        kamar[i].terisi = 0;
        if (i < 2) {
            strcpy(kamar[i].tipe, "Standard");
            kamar[i].tarif = 250000;
        } else if (i < 4) {
            strcpy(kamar[i].tipe, "Deluxe");
            kamar[i].tarif = 400000;
        } else {
            strcpy(kamar[i].tipe, "Suite");
            kamar[i].tarif = 650000;
        }
    }
}

void tampilKamar(Kamar kamar[]) {
    int i;
    printf("\nDAFTAR KAMAR HOTEL\n");
    printf("No.\tTipe\t\tTarif\t\tStatus\n");
    for (i = 0; i < JUMLAH_KAMAR; i++) {
        printf("%d\t%-10s\tRp%d\t%s\n", kamar[i].nomor,
               kamar[i].tipe, kamar[i].tarif,
               kamar[i].terisi ? "Terisi" : "Kosong");
    }
}

void simpanKamar(Kamar kamar[], const char *namaFile) {
    FILE *fp = fopen(namaFile, "wb");
    if (fp == NULL) {
        printf("Gagal menyimpan database.\n");
        return;
    }
    fwrite(kamar, sizeof(Kamar), JUMLAH_KAMAR, fp);
    fclose(fp);
}

void bacaKamar(Kamar kamar[], const char *namaFile) {
    FILE *fp = fopen(namaFile, "rb");
    if (fp == NULL) {
        isiKamar(kamar);
        simpanKamar(kamar, namaFile);
        return;
    }
    if (fread(kamar, sizeof(Kamar), JUMLAH_KAMAR, fp) != JUMLAH_KAMAR)
        isiKamar(kamar);
    fclose(fp);
}

