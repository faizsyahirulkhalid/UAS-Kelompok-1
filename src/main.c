#include <stdio.h>
#include "kos.h"

int main() {
    Kamar daftarKamar[10] = {
        {101, "Standart", 100000, 0},
        {102, "Standart", 100000, 0},
        {103, "Standart", 100000, 0},
        {104, "Standart", 100000, 0},
        {105, "Standart", 100000, 0},
        {106, "Standart", 100000, 0},
        {107, "Standart", 100000, 0},
        {108, "Standart", 100000, 0},
        {109, "Standart", 100000, 0},
        {110, "Standart", 100000, 0},
    };

    Tamu daftarTamu[10];
    int jumlahTamu = 0;

    tampilkanKamar(daftarKamar, 10);
    reservasiKamar(daftarKamar, daftarTamu, 10, &jumlahTamu);
    printf("\nSetelah reservasi: \n");
    tampilkanKamar(daftarKamar, 10);
    tampilkanTamu(daftarTamu, jumlahTamu);
    simpanKamar(daftarKamar, 10);

    return 0;
}
