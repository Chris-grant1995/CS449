//
//  main.c
//  id3
//
//  Created by Chris Grant on 1/30/15.
//  Copyright (c) 2015 Chris Grant. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

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
    for (i = 0; i < argc; i++) {
        printf("argv[%d] = %s\n", i, argv[i]);
    }
    return 0;
}