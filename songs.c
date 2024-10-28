#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct songs{
    char artist[30];
    char song[30];
    char album[30];
    int year;
    char genre[30];
    int minutes;
    int seconds;
}songs;                             //this structure is what holds the whole program, what can be searched, created, deleted and edited

songs *s;                           //pointer to struct songs
int i, size=0;                      //size is initialized to 0 to keep track of number of songs

// Function to load data from file incase application is closed
void load() {
    FILE *fptr = fopen("songs.txt", "r");               //saves to external file called songs.txt
    if (fptr == NULL) {
        printf("Error opening file.\n");                        //if no file is found
        return;
    }

    s = (songs *)malloc(sizeof(songs)); // Allocate memory for first song

    while (fscanf(fptr, "%[^|]|%[^|]|%[^|]|%d|%[^|]|%d|%d\n", s[i].artist, s[i].song, s[i].album, &(s[i].year), s[i].genre, &(s[i].seconds),&(s[i].minutes)) != EOF) {
        // /n indicates the end of the line to seperate the databases, basically reads input from the file
        i++;
        size++;
        s = (songs *)realloc(s, sizeof(songs) * (size + 1));                //for the memory of the next song
    }

    fclose(fptr);
}

// this function is to search for a artist, song, album, genre in the saved file
void search() {

    int choice;
    int year_s;


    printf("\nWhat are you looking for?\n1.Artist\n2.Song\n3.Album\n4.Year\n5.Genre\n6.Exit");
    scanf("%d", &choice);

    switch(choice) {                                    //switch function enables selection
        case 1: {
            char searchArtist[30];
            printf("Enter Artist: ");
            scanf("%s", searchArtist);

            int found =0;                              //indicate if any match is found

            for (i = 0; i < size; i++) {
                if (strcmp(s[i].artist, searchArtist) == 0) {               //this compares if the saved is equal to the searched
                    printf("Artist:%s\n Song:%s\n Album:%s\n Year:%d\n Genre:%s\nLength:%d %d\n",
                           s[i].artist, s[i].song, s[i].album, s[i].year, s[i].genre, s[i].minutes, s[i].seconds);
                    found = 1; // Set flag as a match is found
                }
            }

            if (!found) {
                printf("Artist not found.\n");
            }
            break;
        }

        case 2: {
            char song_s[30];
            printf("Enter Song: ");
            scanf("%s", song_s);

            int found = 0;

            for (i = 0; i < size; i++) {
                if (strcmp(s[i].song, song_s) == 0) {
                    printf("Artist:%s\n Song:%s\n Album:%s\n Year:%d\n Genre:%s\nLength:%d %d\n",
                           s[i].artist, s[i].song, s[i].album, s[i].year, s[i].genre, s[i].minutes, s[i].seconds);
                    found = 1;
                }
            }

            if (!found) {
                printf("Song not found.\n");
            }
            break;
        }

        case 3: {
            char album_s[30];
            printf("Enter Album: ");
            scanf("%s", album_s);

            int found = 0;

            for (i = 0; i < size; i++) {
                if (strcmp(s[i].album, album_s) == 0) {
                    printf("Artist:%s\n Song:%s\n Album:%s\n Year:%d\n Genre:%s\nLength:%d %d\n",
                           s[i].artist, s[i].song, s[i].album, s[i].year, s[i].genre, s[i].minutes, s[i].seconds);
                    found = 1;
                }
            }

            if (!found) {
                printf("Album not found.\n");
            }
            break;
        }

        case 4:

            scanf("%d", &year_s);

            for (i = 0; i < size; i++) {
                if (s[i].year == year_s) {                  //comparison is easier with integers
                    printf("Artist:%s\n Song:%s\n Album:%s\n Year:%d\n Genre:%s\nLength:%d %d\n",
                           s[i].artist, s[i].song, s[i].album, s[i].year, s[i].genre, s[i].minutes, s[i].seconds);
                }
            }
            break;

        case 5: {
            char genre_s[30];
            printf("Enter Genre: ");
            scanf("%s", genre_s);

            int found = 0;

            for (i = 0; i < size; i++) {
                if (strcmp(s[i].genre, genre_s) == 0) {
                    printf("Artist:%s\n Song:%s\n Album:%s\n Year:%d\n Genre:%s\nLength:%d %d\n",
                           s[i].artist, s[i].song, s[i].album, s[i].year, s[i].genre, s[i].minutes, s[i].seconds);
                    found = 1;
                }
            }

            if (!found) {
                printf("Genre not found.\n");
            }
            break;
        }
    }
    if( choice == 6){                       //this selection returns back to the main menu
        return;
    }
}

// this function is for the creation of new databases
void create() {

    if (size == 0) {
        s = (songs *)malloc(sizeof(songs));                             //for the allocation of memory, if size is 0(no elements in the array) it allocates if it is not 0 it reallocates
    } else {
        s = (songs *)realloc(s, sizeof(songs) * (size + 1));
    }

    printf("Enter Artist:\n");
    fflush(stdin);                               //clears the buffer to enable smooth entry
    scanf(" %s", s[i].artist);

    printf("Enter Song:\n");
    fflush(stdin);
    scanf(" %s", s[i].song);

    printf("Enter Album:\n");
    fflush(stdin);
    scanf(" %s", s[i].album);

    printf("Enter Year:\n");
    fflush(stdin);
    scanf(" %d", &(s[i].year));
    getchar();                          //consumes new line

    printf("Enter Genre:\n");
    fflush(stdin);
    scanf(" %s", s[i].genre);

    printf("Enter Minutes:\n");
    fflush(stdin);
    scanf(" %d", &(s[i].minutes));
    getchar();                          //consumes new line

    printf("Enter Seconds:\n");
    fflush(stdin);
    scanf(" %d", &(s[i].seconds));
    getchar();

    i++;                    //increments counters
    size++;
}

void save() {

    FILE *fptr = fopen("songs.txt", "w");

    if ( fptr == NULL){
        printf("Error");
        return;
    }
    for (i=0; i<size; i++) {
        fprintf(fptr, "%s|%s|%s|%d|%s|%d|%d\n", s[i].artist, s[i].song, s[i].album, (s[i].year), s[i].genre, (s[i].minutes),s[i].seconds);
    }

    fclose(fptr);
    printf("Saved successfully");
}
//this function is for editing as it replaces the old content with the new content
void updateFile() {
    FILE *fptr = fopen("songs.txt", "w");
    if (fptr == NULL) {
        printf("Error opening file.\n");
        return;
    }

    for (i = 0; i < size; i++) {
        fprintf(fptr, "%s|%s|%s|%d|%s|%d|%d\n", s[i].artist, s[i].song, s[i].album, s[i].year, s[i].genre, s[i].minutes, s[i].seconds);
    }

    fclose(fptr);
    printf("File updated successfully.\n");
}
//this function is for updating already existing data
void edit() {

    int choice;
    int year_s;


    printf("\nWhat do you want to edit?\n1.Artist\n2.Song\n3.Album\n4.Year\n5.Genre\n6.Exit");
    scanf("%d", &choice);

    switch(choice) {
        case 1: {
            char searchArtist[30];
            printf("Enter Artist: ");
            scanf("%s", searchArtist);

            int found = 0;                              //indicate if any match is found

            for (i = 0; i < size; i++) {
                if (strcmp(s[i].artist, searchArtist) == 0) {
                    printf("Enter New Artist:\n");
                    fflush(stdin);
                    scanf(" %s", s[i].artist);
                    updateFile();                           //connects to updateFile function to save to file
                    found = 1; // Set flag as a match is found
                }
            }

            if (!found) {
                printf("Artist not found.\n");
            }
            break;
        }

        case 2: {
            char song_s[30];
            printf("Enter Song: ");
            scanf("%s", song_s);

            int found = 0;

            for (i = 0; i < size; i++) {
                if (strcmp(s[i].song, song_s) == 0) {
                    printf("Enter New Song:\n");
                    fflush(stdin);                               //clears the buffer to enable smooth entry
                    scanf(" %s", s[i].song);
                    updateFile();
                    found = 1;
                }
            }

            if (!found) {
                printf("Song not found.\n");
            }
            break;
        }

        case 3: {
            char album_s[30];
            printf("Enter Album: ");
            scanf("%s", album_s);

            int found = 0;

            for (i = 0; i < size; i++) {
                if (strcmp(s[i].album, album_s) == 0) {
                    printf("Enter New Album:\n");
                    fflush(stdin);                               //clears the buffer to enable smooth entry
                    scanf(" %s", s[i].album);
                    updateFile();
                    found = 1;
                }
            }

            if (!found) {
                printf("Album not found.\n");
            }
            break;
        }

        case 4: {
            int editYear;
            printf("Enter Year: ");
            scanf("%d", &editYear);

            int found = 0;

            for (i = 0; i < size; i++) {
                if (s[i].year == editYear) {
                    printf("Enter New Year:\n");
                    fflush(stdin);
                    scanf("%d", &(s[i].year));
                    updateFile();
                    found = 1;
                }
            }

            if (!found) {
                printf("Year not found.\n");
            }
            break;
        }


        case 5: {
            char genre_s[30];
            printf("Enter Genre: ");
            scanf("%s", genre_s);

            int found = 0;

            for (i = 0; i < size; i++) {
                if (strcmp(s[i].genre, genre_s) == 0) {
                    printf("Enter New Genre:\n");
                    fflush(stdin);                               //clears the buffer to enable smooth entry
                    scanf(" %s", s[i].genre);
                    updateFile();
                    found = 1;
                }
            }

            if (!found) {
                printf("Genre not found.\n");
            }
            break;
        }
    }
    if( choice == 6){
        return;
    }
}
//this function is to delete already existing data in the file
void delete() {int choice;
    int year_s;


    printf("\nWhat do you want to delete?\n1.Artist\n2.Song\n3.Album\n4.Year\n5.Genre\n6.Exit");
    scanf("%d", &choice);

    switch(choice) {
        case 1: {
            char searchArtist[30];
            printf("Enter Artist: ");               //search for the artist which is to be deleted
            scanf("%s", searchArtist);

            int found = 0;                              //indicate if any match is found

            for (i = 0; i < size; i++) {
                if (strcmp(s[i].artist, searchArtist) == 0) {
                    found = 1; // Set flag as a match is found
                    for (int j = i; j < size - 1; j++) {
                        s[j] = s[j + 1];
                    }
                    size--;                                 //reduces size for effective deletion
                    printf("Successful deletion");
                }
            }

            if (!found) {
                printf("Artist not found.\n");
            }
            break;
        }

        case 2: {
            char song_s[30];
            printf("Enter Song: ");
            scanf("%s", song_s);

            int found = 0;

            for (i = 0; i < size; i++) {
                if (strcmp(s[i].song, song_s) == 0) {
                    found = 1;
                    for (int j = i; j < size - 1; j++) {
                        s[j] = s[j + 1];
                    }
                    size--;
                    printf("Successful deletion");
                }
            }

            if (!found) {
                printf("Song not found.\n");
            }
            break;
        }

        case 3: {
            char album_s[30];
            printf("Enter Album: ");
            scanf("%s", album_s);

            int found = 0;

            for (i = 0; i < size; i++) {
                if (strcmp(s[i].album, album_s) == 0) {
                    found = 1;
                    for (int j = i; j < size - 1; j++) {
                        s[j] = s[j + 1];
                    }
                    size--;
                    printf("Successful deletion");
                }
            }

            if (!found) {
                printf("Album not found.\n");
            }
            break;
        }

        case 4: {
            int editYear;
            printf("Enter Year: ");
            scanf("%d", &editYear);

            int found = 0;

            for (i = 0; i < size; i++) {
                if (s[i].year == editYear) {
                    found = 1;
                    for (int j = i; j < size - 1; j++) {
                        s[j] = s[j + 1];
                    }
                    size--;
                    printf("Successful deletion");
                }
            }

            if (!found) {
                printf("Year not found.\n");
            }
            break;
        }


        case 5: {
            char genre_s[30];
            printf("Enter Genre: ");
            scanf("%s", genre_s);

            int found = 0;

            for (i = 0; i < size; i++) {
                if (strcmp(s[i].genre, genre_s) == 0) {
                    found = 1;
                    for (int j = i; j < size - 1; j++) {
                        s[j] = s[j + 1];
                    }
                    size--;
                    printf("Successful deletion");
                }
            }

            if (!found) {
                printf("Genre not found.\n");
            }
            break;
        }
    }
    if( choice == 6){
        return;
    }}

int main() {
    int n = 0;
    load();

    //do while loop for continuous selection
    do {
        printf("\n----Welcome to songs application.----\n\n1.Search\n2.Create new\n3.Save to file\n4.Edit\n5.Delete\n6.Exit\n");
        fflush(stdin);
        scanf("%d", &n);     //look for a way to remove scanf value from user's view

        switch (n) {
            case 1:
                search();
                break;

            case 2:
                create();
                break;

            case 3:
                save();
                break;

            case 4:
                edit();
                break;

            case 5:
                delete();
                break;

            case 6:
                break;

            default:
                printf("Error. Pick a number between 0 and 6.");
        }

    } while (n != 6);        //if number imputed is greater than 5 an error message appears

    free(s);         //to free memory
    return 0;
}