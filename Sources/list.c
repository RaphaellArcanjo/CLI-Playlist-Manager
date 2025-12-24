//
// Created by raphaell on 08/12/2025.
//

#include "list.h"

#include <stdlib.h>
#include <stdio.h>

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

void play_next(Playlist *playlist) {
   if (playlist->size > 0) {
      if (playlist->current->next != NULL) {
         playlist->current = playlist->current->next;
      } else {
         playlist->current = playlist->first;
      }
   }
}

void play_prev(Playlist *playlist) {
   if (playlist->size > 0) {
      if (playlist->current != playlist->first) {
         playlist->current = playlist->current->prev;
      }
   }
}

void free_playlist(Playlist *playlist) {
   Node *aux = playlist->first;

   while (aux != NULL) {
      Node *temp = aux->next;
      free(aux);
      aux = temp;
   }

   playlist->first = NULL;
   playlist->last = NULL;
   playlist->current = NULL;

   playlist->size = 0;
}

void remove_current_song(Playlist *playlist) {
   if (playlist->size == 0) {
      return ;
   } else if (playlist->size == 1){
      free(playlist->current);
      playlist->first = NULL;
      playlist->last = NULL;
      playlist->current = NULL;
      playlist->size = 0;
   } else {
      Node *to_remove = playlist->current;
      if (playlist->current == playlist->first) {
         playlist->first = playlist->first->next;
         playlist->first->prev = NULL;
         free(to_remove);
         playlist->current = playlist->first;
         playlist->size--;
      } else if (playlist->current == playlist->last) {
         playlist->last = playlist->last->prev;
         playlist->last->next = NULL;
         free(to_remove);
         playlist->current = playlist->last;
         playlist->size--;
      } else {
         to_remove->prev->next = to_remove->next;
         to_remove->next->prev = to_remove->prev;
         playlist->current = to_remove->next;
         free(to_remove);
         playlist->size--;
      }
   }
}

void save_playlist(Playlist *playlist) {
   FILE *arq_playlist = NULL;
   arq_playlist = fopen("songs.txt","w");

   if (arq_playlist == NULL) {
      printf("Erro ao abrir arquivo para salvar!\n");
      return;
   }

   Node *aux = playlist->first;
   while (aux != NULL) {
      fprintf(arq_playlist, "%s;%s\n", aux->data.artist , aux->data.title);
      aux = aux->next;
   }
   fclose(arq_playlist);
}