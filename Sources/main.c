#include <stdio.h>

#include "interface.h"
#include "song.h"
#include "list.h"

int main(void) {

    int option = -1;
    Playlist my_playlist;
    Song library[100];

    int total_songs = 0;
    total_songs = read_songs("songs.txt", library, 100);

    init_playlist(&my_playlist);

    for (int i = 0; i < total_songs; i++) {
        append_song(&my_playlist, library[i]);
    }

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
                print_songs(library, total_songs);
                break;
            case 4:
                remove_current_song(&my_playlist);
                break;
            case 5:
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