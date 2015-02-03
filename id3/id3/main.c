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
int main(int argc, char *argv[])
{
    int i = 0;
    FILE * f;
    int title=0;
    int artist=0;
    int album =0;
    int year=0;
    int comment=0;
    int track=0;
    struct song{
        char tag[3];
        char songTitle[30];
        char songArtist[30];
        char songAlbum[30];
        char songYear[4];
        char comment[28];
        int zero;
        int track;
        int genre;

    };
    struct song s;
    char buffer[128];
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
    fread(buffer,128,1,f);
    if(argc==2)
    {
        for(i=0; i<3; i++)
        {
            s.tag[i]=buffer[i];
        }
        printf("%s\n",s.tag );
        if(strcmp(s.tag, "TAG")!=0)
        {
            printf("No Metadata found\n");
            return 0;
        }
        for(i=0; i<30; i++)
        {
            s.songTitle[i]=buffer[i+3];
        }
        printf("Song Title: %s\n", s.songTitle);
        for(i=0; i<30; i++)
        {
            s.songArtist[i]=buffer[i+33];
        }
        printf("Song Artist: %s\n", s.songArtist);
        for(i=0; i<30; i++)
        {
            s.songAlbum[i]=buffer[i+63];
        }
        printf("Song Album: %s\n", s.songAlbum);
        for(i=0; i<4; i++)
        {
            s.songYear[i]=buffer[i+93];
        }
        printf("Song Album: %s\n", s.songYear);
        for(i=0; i<28; i++)
        {
            s.comment[i]=buffer[i+97];
        }
        printf("Comments: %s\n", s.comment);
        s.zero=atoi(&buffer[125]);
        s.track=atoi(&buffer[126]);
        s.genre= atoi(&buffer[127]);
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
                s.track=argv[++i];
                track=1;
                printf("Track Number: %d\n", s.track);
            }

        }
    }

    fclose(f);
//cp ~jrmst106/public/cs449/*.ogg .
//Command to replace corrupted files
    return 0;
}