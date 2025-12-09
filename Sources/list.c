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

void append_song(Playlist *playlist, Song song) {
   Node *new_node = (Node*) malloc(sizeof(Node));
   new_node->data = song;
   new_node->next = NULL;
   new_node->prev = NULL;

   if (playlist->first == NULL) {
      playlist->first = new_node;
      playlist->last = new_node;
      playlist->current = new_node;
   } else {
      playlist->last->next = new_node;
      new_node->prev = playlist->last;
      playlist->last = playlist->last->next;
   }
   playlist->size++;
}