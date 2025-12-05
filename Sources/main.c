#include <stdio.h>

#include "interface.h"
#include "song.h"

int main(void) {

    int option = -1;
    Song library[100];

    int total_songs = 0;
    total_songs = read_songs("songs.txt", library, 100);

    do {
        MENU();
        scanf("%d", &option);

        switch (option) {
            case 1:
                print_songs(library, total_songs);
                break;
            case 2:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }

    } while (option != 2);


    return 0;
}
