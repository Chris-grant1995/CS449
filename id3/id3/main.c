//
//  main.c
//  id3
//
//  Created by Chris Grant on 1/30/15.
//  Copyright (c) 2015 Chris Grant. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//fopen('fileName', 'mode')
    //return a FILE *
        //Don't worry about it
//fclose(FILE*)

//if(fopen("file", "r")==NULL)
    //Checks to make sure that the file is able to be read
    //If it is null, print an error
//Mode String
    //"r" open for reading, if file does not exist, return null
    //"w" open for writing, if it doesn't exist, create it, if it does, overright it
        //Always creates a new empty file
    //"a" append to the end of the file
    //"r+"open for reading and writing, if it does not exist, returns null
    //"w+"open for reading and writing, if it does not exist, creates it, if it does over writes it
    //"a+" reads and appends
    //b and t suffix
        //In unix it is exactly the same, in windows no
        //Deals with how the new line (\n) is dealt with, t replaces 10 and 13 and replaces it with \n
        //B just deals with it how it is
//Text Opperations
        //fprintf(FILE *) Writes out to the file insead of the screen
        //fscanf() Gives user prompt to write to file
//fread(void*, size,count,FILE*)
//fwrite(void*, size,count,FILE*)
    //Cannot dereference a void pointer
    //fread(&tag,sizeof(tag), 1,f)
//fseek(FILE*,offset, origin)
    //origins
        //SEEK_SET set file pointer to offset
        //SEEK_CUR add offset to filepointer
        //SEEK_END Goes back offset number of byte from the end
        //fseek(f,-128,SEEK_END) WE WILL USE THIS
struct song{
    char tag[3];
    char songTitle[30];
    char songArtist[30];
    char songAlbum[30];
    char songYear[4];
    char comment[28];
    char zero;
    char track;
    char genre;

};
int main(int argc, char *argv[])
{
    int i = 0;
    FILE * f;
    int tagFound=0;
    int title=0;
    int artist=0;
    int album =0;
    int year=0;
    int comment=0;
    int track=0;

    struct song s;
    //char buffer[128];
    /*for (i = 0; i < argc; i++) {
        printf("argv[%d] = %s\n", i, argv[i]);
    }
*/
    f= fopen(argv[1], "r+b");
    if(f== NULL)
    {
        printf("File Not Found, Please run again with an actual file");
        return 0;
    }
    fseek(f,-128, SEEK_END);
    fread(&s,128,1,f);

    if(strncmp(s.tag, "TAG",3)==0)
    {
        tagFound=1;
    }

    if(argc==2)
    {
        //printf("%s\n", s.tag);
        if(!tagFound)
        {
            printf("No metadata found\n");
            return 0;
        }

        printf("Song Title: %s\n", s.songTitle);
        printf("Song Artist: %s\n", s.songArtist);
        printf("Song Album: %s\n", s.songAlbum);
        //strcat(s.songYear, '\0');
        printf("Song Year: %.4s\n", s.songYear);
        printf("Song Comment: %s\n", s.comment);
        printf("Track Number: %d\n", s.track);
    }
    else{
        for(i=0; i<argc; i++)
        {
            if(strcmp(argv[i], "title")==0)
            {
                strcpy(s.songTitle, argv[++i]);
                title=1;
                printf("Song Title: %s\n", s.songTitle);
            }
            else if(strcmp(argv[i], "artist")==0)
            {
                strcpy(s.songArtist, argv[++i]);
                artist=1;
                printf("Song Artist: %s\n", s.songArtist);
            }
            else if(strcmp(argv[i], "album")==0)
            {
                strcpy(s.songAlbum, argv[++i]);
                album=1;
                printf("Song Album: %s\n", s.songAlbum);
            }
            else if(strcmp(argv[i], "year")==0)
            {
                strcpy(s.songYear, argv[++i]);
                year=1;
                printf("Song Year: %s\n", s.songYear);
            }
            else if(strcmp(argv[i], "comment")==0)
            {
                strcpy(s.comment, argv[++i]);
                comment=1;
                printf("Song Comment: %s\n", s.comment);
            }
            else if(strcmp(argv[i], "track")==0)
            {
                s.track=atoi(argv[++i]);
                track=1;
                printf("Track Number: %d\n", s.track);
            }

        }
        if(tagFound)
        {
            fseek(f,-128, SEEK_END);
            fwrite(&s, 128, 1, f);
        }
        else
        {
            f=fopen(argv[1], "ab");
            strcpy(s.tag, "TAG");
            s.zero=0;
            s.genre=0;
            fseek(f,0, SEEK_END);
            fwrite(&s, 128, 1, f);
        }


    }


    fclose(f);
//cp ~jrmst106/public/cs449/*.ogg .
//Command to replace corrupted files
    return 0;
}