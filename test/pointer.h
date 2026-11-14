#ifndef POINTER_H
#define POINTER_H

#include <stdio.h>
#include <string.h>
#include "struct.h"

void bersihkanBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void inputDataDiri(AnakKost *k) {
    printf("Nama Penghuni : ");
    fgets(k->nama, 50, stdin);
    k->nama[strcspn(k->nama, "\n")] = '\0';

    printf("NIM           : ");
    fgets(k->nim, 20, stdin);
    k->nim[strcspn(k->nim, "\n")] = '\0';

    printf("Uang Saku (Rp): ");
    scanf("%f", &k->saldo);
    bersihkanBuffer();
}

void tandaiSelesai(int *status) {
    *status = 1;
}

#endif