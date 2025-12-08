//
// Created by raphaell on 08/12/2025.
//

#include "list.h"

#include <stdlib.h>

void init_playlist(Playlist *playlist) {
   playlist->first = NULL;
   playlist->last = NULL;
   playlist->current = NULL;
   playlist->size = 0;
}
