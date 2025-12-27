//
// Created by raphaell on 02/12/2025.
//

#ifndef PROJETOC_SONG_H
#define PROJETOC_SONG_H

typedef struct song {
    int id;
    char title[50];
    char artist[50];
    int duration;
} Song;

typedef struct time {
    int minutes;
    int seconds;
} Time;

int read_songs(char *file_name, Song* songs, int max_songs);

Time seconds_to_minutes(int total_seconds);



#endif //PROJETOC_SONG_H