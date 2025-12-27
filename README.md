# C Project - Music Player

This is a simple command-line music player project in C. It allows the user to manage a music playlist through a command-line interface.

## How to Compile and Run

To compile the project, you can use GCC:

```bash
gcc Sources/main.c Sources/interface.c Sources/song.c Sources/list.c -o music_player
```

To run the project, simply execute the generated executable:

```bash
./music_player
```

## Features

The music player has the following features:

*   **Play next song:** Advances to the next song in the playlist.
*   **Play previous song:** Goes back to the previous song in the playlist.
*   **List all songs:** Displays a list of all songs in the playlist.
*   **Remove current song:** Removes the currently playing song from the playlist.
*   **Add a new song:** Adds a new song to the playlist.
*   **Save playlist:** Saves the playlist to a `songs.txt` file.
*   **Load playlist:** Loads the playlist from the `songs.txt` file when the program starts.

## Project Structure

The project is organized as follows:

*   **`Headers/`**: Contains header files (`.h`) with function declarations and data structures.
    *   **`interface.h`**: Declares the `MENU()` function.
    *   **`list.h`**: Defines the playlist structure (doubly linked list) and declares playlist manipulation functions.
    *   **`song.h`**: Defines the `Song` structure and declares song-related functions.
*   **`Sources/`**: Contains source code files (`.c`) with function implementations.
    *   **`main.c`**: The main entry point of the program. Manages the main loop and user interaction.
    *   **`interface.c`**: Implements the `MENU()` function to display menu options.
    *   **`list.c`**: Implements playlist manipulation functions.
    *   **`song.c`**: Implements song-related functions, such as reading a song file.
*   **`songs.txt`**: Text file where the playlist is saved. If the file does not exist, it will be created.
