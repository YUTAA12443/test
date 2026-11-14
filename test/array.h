#ifndef ARRAY_H
#define ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "pointer.h"

void gachaMenuMakan(void) {
    char menu[5][30] = {
        "Indomie Dok-Dok", "Nasi Omelet Tahu",
        "Warteg Nasi Orek", "Ayam Geprek", "Nasi Goreng Margarin"
    };
    printf("\nMenu Hari Ini: >>> %s <<<\n", menu[rand() % 5]);
}

void tambahUbahTugas(AnakKost *k) {
    int pilih, idx;
    printf("\n[1] Tambah Tugas  [2] Ubah Tugas\nPilihan >> ");
    scanf("%d", &pilih);
    bersihkanBuffer();

    if (pilih == 1) {
        if (k->jumlahTugas >= MAX_TUGAS) {
            printf("[!] Daftar tugas penuh!\n");
            return;
        }
        printf("Tugas baru: ");
        fgets(k->listTugas[k->jumlahTugas], MAX_LEN, stdin);
        k->listTugas[k->jumlahTugas][strcspn(k->listTugas[k->jumlahTugas], "\n")] = '\0';
        k->statusTugas[k->jumlahTugas] = 0;
        k->jumlahTugas++;
        printf("[+] Tugas ditambahkan!\n");
    } else if (pilih == 2 && k->jumlahTugas > 0) {
        printf("Nomor tugas (1-%d): ", k->jumlahTugas);
        scanf("%d", &idx);
        bersihkanBuffer();
        if (idx >= 1 && idx <= k->jumlahTugas) {
            printf("Teks baru: ");
            fgets(k->listTugas[idx - 1], MAX_LEN, stdin);
            k->listTugas[idx - 1][strcspn(k->listTugas[idx - 1], "\n")] = '\0';
            k->statusTugas[idx - 1] = 0;
            printf("[~] Tugas diubah!\n");
        } else {
            printf("[!] Nomor tidak valid!\n");
        }
    } else {
        printf("[!] Pilihan tidak valid atau tugas kosong!\n");
    }
}

#endif
