#ifndef PERCABANGAN_H
#define PERCABANGAN_H

#include <stdio.h>

void cekStatusKeuangan(float saldo) {
    if (saldo < 50000.0f) {
        printf("[WARNING] Siaga 1 Tanggal Tua! Makan Indomie dulu...\n");
    } else {
        printf("[OK] Keuangan aman. Tetap bijak!\n");
    }
}

void rekomendasiTempatMakan(float saldo) {
    printf("\nSaldo: Rp %.2f\n", saldo);
    if (saldo >= 100000.0f) {
        printf("[$$] Jajan Mewah: Kafe hits, All You Can Eat, Sushi/BBQ\n");
    } else if (saldo >= 30000.0f) {
        printf("[$] Menengah: Ayam Geprek, RM Padang, Bakso Urat\n");
    } else {
        printf("[!] Mode Hemat: Warteg Orek Tempe, Indomie Warmindo\n");
    }
}

#endif