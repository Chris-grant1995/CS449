//Chris Grant
//CS 449 Project 2 MyStrings
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE * f;
	int i;
	int x;
	char s;
	char *str;
	if(argc==1)
	{
		printf("No File Specified \n");
		return 0;
	}
	f= fopen(argv[1], "r"); 
    if(f== NULL) 
    {
        printf("File Not Found, Please run again with an actual file\n");
        return 0;
    }
    
    while(!feof(f))
    {
    	fread(&s, 1,1,f);
    	if(s<=126 && s>=32)
    	{
    		i++;
    	}
    	else{
    		if(i>=4)
    		{
    			str =(char *) malloc(i+1);//Plus one bc of null terminator
    			fseek(f, (i*-1)-1, SEEK_CUR);
    			//fread(&str, i, 1, f);
    			for(x=0; x<i; x++)
    			{
    				fread(&s, 1,1,f);
    				str[x]=s;
    			}
    			str[i]=0;//Adding null terminator 
    			printf("%s\n", str);
                free(str);
    		}
    		i=0;
    	}
    }
    return 0;

}