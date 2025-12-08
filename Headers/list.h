//
// Created by raphaell on 08/12/2025.
//

#ifndef PROJETOC_LIST_H
#define PROJETOC_LIST_H

#include "song.h"

typedef struct node {
    Song data;
    struct node *next;
    struct node *prev;
} Node;

typedef struct list {
    Node *first;
    Node *last;
    Node *current;
    int size;
} Playlist;

void init_playlist(Playlist *playlist);



#endif //PROJETOC_LIST_H