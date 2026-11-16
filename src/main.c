#include <stdio.h>
#include <string.h>
#include "fitur.h"

int main(int argc, char *argv[]) {
  Kamar kamar[JUMLAH_KAMAR];
  const char *namaFile = FILE_DB;
  int pilihan;

  if (argc > 1 && strcmp(argv[1], "--help") ==0) {
    printf("Penggunaan: ./hotel [nama_file_database]\n");
    printf("            ./hotel --status\n");
    return 0;
  }

  if (argc > 1 && strcmp(argv[1], "--status") != 0) {
    namFile = argv[1];
  }

bacaKamar(kamar, namaFile);

if (argc > 1 && strcmp(argv[1], "--status") == 0) {
  tampilanStatus(kamar);
  return 0;
}

