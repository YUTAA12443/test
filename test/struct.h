#ifndef STRUCT_H
#define STRUCT_H

#define MAX_TUGAS 5
#define MAX_LEN 100
#define HARI 7

typedef struct {
    char nama[50];
    char nim[20];
    float saldo;
    float pengeluaran[HARI];
    char listTugas[MAX_TUGAS][MAX_LEN];
    int statusTugas[MAX_TUGAS];
    int jumlahTugas;
} AnakKost;

#endif