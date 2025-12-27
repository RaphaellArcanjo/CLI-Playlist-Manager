#include <stdio.h>

#include "interface.h"
#include "song.h"
#include "list.h"

int main(void) {

    int option = -1;
    Playlist my_playlist;

    init_playlist(&my_playlist);
    load_playlist(&my_playlist);

    do {
        if (my_playlist.current != NULL) {
            printf("\n>>> Tocando agora: %s - %s <<<\n", my_playlist.current->data.title, my_playlist.current->data.artist);
        } else {
            printf("\n>>> Player Parado <<<\n");
        }


        MENU();
        scanf("%d", &option);

        switch (option) {
            case 1:
                play_next(&my_playlist);
                break;
            case 2:
                play_prev(&my_playlist);
                break;
            case 3:
                print_playlist(&my_playlist);
                break;
            case 4:
                remove_current_song(&my_playlist);
                break;
            case 5:
                save_playlist(&my_playlist);
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }

    } while (option != 5);


    free_playlist(&my_playlist);
    return 0;
}