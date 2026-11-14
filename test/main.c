#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "struct.h"
#include "pointer.h"
#include "loop.h"

int main(void) {
    AnakKost user = {0};
    int pilihan;

    srand((unsigned int)time(NULL));

    printf("=== PROGRAM SURVIVAL ANAK KOST ===\n");
    inputDataDiri(&user);

    do {
        printf("\n=== MENU UTAMA (%s) ===\n", user.nama);
        printf("[1] Kelola Keuangan\n[2] To-Do List\n[3] Rekomendasi Survival\n[4] Keluar\n");
        printf("Pilihan >> ");
        scanf("%d", &pilihan);
        bersihkanBuffer();

        switch (pilihan) {
            case 1: kelolaKeuangan(&user); break;
            case 2: menuToDoList(&user); break;
            case 3: menuSurvival(user.saldo); break;
            case 4: printf("\nSemangat survive, %s!\n", user.nama); break;
            default: printf("[!] Pilihan tidak valid!\n");
        }
    } while (pilihan != 4);

    return 0;
}