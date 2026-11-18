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
