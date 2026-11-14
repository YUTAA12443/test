#ifndef LOOP_H
#define LOOP_H

#include <stdio.h>
#include "struct.h"
#include "pointer.h"
#include "array.h"
#include "percabangan.h"

void kelolaKeuangan(AnakKost *k) {
    const char *hari[] = {"Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu", "Minggu"};
    float total = 0.0f;

    printf("\nSaldo saat ini: Rp %.2f\n", k->saldo);
    for (int i = 0; i < HARI; i++) {
        printf("Pengeluaran %s: Rp ", hari[i]);
        scanf("%f", &k->pengeluaran[i]);
        bersihkanBuffer();
        total += k->pengeluaran[i];
    }

    k->saldo -= total;
    printf("\nTotal Pengeluaran: Rp %.2f | Sisa Saldo: Rp %.2f\n", total, k->saldo);
    cekStatusKeuangan(k->saldo);
}

void lihatDaftarTugas(AnakKost k) {
    printf("\n--- DAFTAR TUGAS ---\n");
    if (k.jumlahTugas == 0) {
        printf("(Kosong)\n");
        return;
    }
    for (int i = 0; i < k.jumlahTugas; i++) {
        printf("%d. [%c] %s\n", i + 1, k.statusTugas[i] ? 'X' : ' ', k.listTugas[i]);
    }
}

void menuToDoList(AnakKost *k) {
    int pilih, idx;
    do {
        printf("\n[1] Lihat Tugas  [2] Tambah/Ubah  [3] Tandai Selesai  [0] Kembali\nPilihan >> ");
        scanf("%d", &pilih);
        bersihkanBuffer();

        switch (pilih) {
            case 1: lihatDaftarTugas(*k); break;
            case 2: tambahUbahTugas(k); break;
            case 3:
                lihatDaftarTugas(*k);
                if (k->jumlahTugas > 0) {
                    printf("Nomor selesai (1-%d): ", k->jumlahTugas);
                    scanf("%d", &idx);
                    bersihkanBuffer();
                    if (idx >= 1 && idx <= k->jumlahTugas) {
                        tandaiSelesai(&k->statusTugas[idx - 1]);
                        printf("[V] Selesai!\n");
                    }
                }
                break;
        }
    } while (pilih != 0);
}

void menuSurvival(float saldo) {
    int pilih;
    do {
        printf("\n[1] Rekomendasi Makan  [2] Gacha Menu  [0] Kembali\nPilihan >> ");
        scanf("%d", &pilih);
        bersihkanBuffer();

        switch (pilih) {
            case 1: rekomendasiTempatMakan(saldo); break;
            case 2: gachaMenuMakan(); break;
        }
    } while (pilih != 0);
}

#endif