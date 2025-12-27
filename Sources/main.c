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
                Song new_song;
                printf("\n--- Adicionar Nova Musica ---\n");

                if (my_playlist.last != NULL) {
                    new_song.id = my_playlist.last->data.id + 1;
                } else {
                    new_song.id = 1;
                }

                printf("Titulo: ");
                scanf(" %[^\n]", new_song.title);

                printf("Artista: ");
                scanf(" %[^\n]", new_song.artist);

                printf("Duracao (segundos): ");
                scanf("%d", &new_song.duration);

                append_song(&my_playlist, new_song);

                save_playlist(&my_playlist);

                break;
            case 6:
                save_playlist(&my_playlist);
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }

    } while (option != 6);

    free_playlist(&my_playlist);
    return 0;
}