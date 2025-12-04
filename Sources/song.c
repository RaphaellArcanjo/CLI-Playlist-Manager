//
// Created by raphaell on 03/12/2025.
//

#include "song.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int read_songs(char *file_name, Song* songs, int max_songs) {
     FILE* fp = fopen(file_name, "r");



     if (fp == NULL) {
          return 0;
     }

     char line[100];
     int i = 0; //Contador de musicas lidas


     while (fgets(line, sizeof(line), fp) != NULL && i < max_songs) {


          char *token = strtok(line, ";");
          songs[i].id = (int)strtol(token, NULL, 10);

          token = strtok(NULL, ";");
          strcpy(songs[i].title, token);

          token = strtok(NULL, ";");
          strcpy(songs[i].artist, token);

          token = strtok(NULL, ";");
          songs[i].duration = (int)strtol(token, NULL, 10);

          i++;
     }
     fclose(fp);

     return i;
}

Time seconds_to_minutes(int total_seconds) {
     Time time;

     time.minutes = total_seconds / 60;
     time.seconds = total_seconds % 60;
     return  time;
}


void print_songs(Song* songs, int songs_count) {
     for (int i = 0; i < songs_count; i++) {
          Time time = seconds_to_minutes(songs[i].duration);
          printf("%-20.20s (%d:%02d) - %s\n", songs[i].title, time.minutes, time.seconds, songs[i].artist);
     }
}