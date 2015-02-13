//
//  main.c
//  id3
//
//  Created by Chris Grant on 1/30/15.
//  Copyright (c) 2015 Chris Grant. All rights reserved.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


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
    //For Loop Counter
    int i = 0; 
    //Nested for loop counter
    int x=0; 
    FILE * f;
    //Essentailly just booleans to be used for files that have no tags 
    int tagFound=0;
    int title=0;
    int artist=0;
    int album =0;
    int year=0;
    int comment=0;
    int track=0;
    struct song s;
    //opening binary file for reading and writing 
    f= fopen(argv[1], "r+b"); 
    //If the file is not found in the directory specified 
    if(f== NULL) 
    {
        printf("File Not Found, Please run again with an actual file");
        return 0;
    }
    //Setting stream in file to last 128 bytes
    fseek(f,-128, SEEK_END); 
    fread(&s,128,1,f);
    //Reading the 128 bytes into the song struct s
    //Determining if there are tags to be read
    if(strncmp(s.tag, "TAG",3)==0) 
    {
        tagFound=1;
    }

    if(argc==2) 
    {
        //If the user only wants to see the ID3 tags on the file
        //printf("%s\n", s.tag);
        if(!tagFound)
        {
            printf("No metadata found\n");
            fclose(f);
            return 0;
        }
        //Prints Tag information found on the file
        printf("Song Title: %.30s\n", s.songTitle);
        printf("Song Artist: %.30s\n", s.songArtist);
        printf("Song Album: %.30s\n", s.songAlbum);
        printf("Song Year: %.4s\n", s.songYear);
        printf("Song Comment: %.28s\n", s.comment);
        printf("Track Number: %d\n", s.track);
    }
    else{ 
        //If they want to change tags on the file
        printf("Modified ID3 Tags: \n");
        for(i=0; i<argc; i++)
        {
            //I have only commented how the title works, but the rest work exactly the same
            if(strcmp(argv[i], "title")==0)//Checks to see if user wants to modify the title
            {
                // If the user entered too many characters, this truncates it down to the max, elminating a null terminator if nesscessary
                if(strlen(argv[++i])>=30) 
                {
                    //printf("True\n");
                    for(x =0; x<30;x++)
                    {
                            s.songTitle[x]=argv[i][x];


                    }
                }
                //If they didnt enter too many characters, 
                else{
                    strcpy(s.songTitle, argv[i]);
                }
                //Prints the new title for the song(up to 30 characters because there might not be a null terminator) and sets title to 1, indicating that it has one, in case there are no ID3 tags already on the file
                title=1;
                printf("Song Title: %.30s\n", s.songTitle);
            }
            else if(strcmp(argv[i], "artist")==0)
            {
                if(strlen(argv[++i])>=30)
                {
                    //printf("True\n");
                    for(x =0; x<30;x++)
                    {
                        s.songArtist[x]=argv[i][x];
                    }
                }
                else{
                    strcpy(s.songArtist, argv[i]);
                }
                artist=1;
                printf("Song Artist: %.30s\n", s.songArtist);
            }
            else if(strcmp(argv[i], "album")==0)
            {
                if(strlen(argv[++i])>=30)
                {
                    //printf("True\n");
                    for(x =0; x<30;x++)
                    {
                        s.songAlbum[x]=argv[i][x];
                    }
                }
                else{
                    strcpy(s.songAlbum, argv[i]);
                }
                album=1;
                printf("Song Album: %.30s\n", s.songAlbum);
            }
            else if(strcmp(argv[i], "year")==0)
            {
                if(strlen(argv[++i])>=4)
                {
                    //printf("True\n");
                    for(x =0; x<4;x++)
                    {
                        s.songYear[x]=argv[i][x];
                    }
                }
                else{
                    strcpy(s.songYear, argv[i]);
                }
                //strcpy(s.songYear, argv[++i]);
                year=1;
                printf("Song Year: %.4s\n", s.songYear);

            }
            else if(strcmp(argv[i], "comment")==0)
            {
                if(strlen(argv[++i])>=28)
                {
                    //printf("True\n");
                    for(x =0; x<28;x++)
                    {
                        s.comment[x]=argv[i][x];
                    }
                }
                else{
                    strcpy(s.comment, argv[i]);
                }
                comment=1;
                printf("Song Comment: %.28s\n", s.comment);
            }
            else if(strcmp(argv[i], "track")==0)
            {
                s.track=atoi(argv[++i]);
                
                track=1;
                printf("Track Number: %.1d\n", s.track);
            }

        }
        if(tagFound)
        {
            //If there already is an ID3 tag, simply write the song struct to the last 128 bytes of the file
            fseek(f,-128, SEEK_END);
            fwrite(&s, 128, 1, f);
        }
        else
        {
            //If there are no tags, we have to append them at the end of the file
            f=fopen(argv[1], "ab");
            //Set indivdual chars to T A G so there is no null terminator 
            s.tag[0]='T';
            s.tag[1]='A';
            s.tag[2]='G';
            //Set Zero byte seperator and genre to 0/null
            s.zero=0;
            s.genre=0;
            //If the user hasn't supplied a value for a field, set it to null, again same logic for every different flag, just length changes 
            if(!title)
            {
                for(i=0; i<30;i++)
                {
                    s.songTitle[i]=0;
                }

            }
            if(!artist)
            {
                for(i=0; i<30;i++)
                {
                    s.songArtist[i]=0;
                }
            }
            if(!album)
            {
                for(i=0; i<30;i++)
                {
                    s.songAlbum[i]=0;
                }
            }
            if(!year)
            {
                for(i=0; i<30;i++)
                {
                    s.songYear[i]=0;
                }
            }
            if(!comment)
            {
                for(i=0; i<30;i++)
                {
                    s.comment[i]=0;
                }
            }
            if(!track)
            {
                s.track=0;
            }
            //Make sure that the steam is at the end of the file and write an additional 128 byte to it
            fseek(f,0, SEEK_END);
            fwrite(&s, 128, 1, f);
        }


    }

    //Close the file
    fclose(f);
//cp ~jrmst106/public/cs449/*.ogg .
//Command to replace corrupted files
    return 0;
}