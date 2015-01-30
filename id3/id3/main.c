//
//  main.c
//  id3
//
//  Created by Chris Grant on 1/30/15.
//  Copyright (c) 2015 Chris Grant. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

/* Flag set by `--verbose'. */
static int verbose_flag;

int
main (int argc, char *argv[])
{
    int a,b,s;
    while (1)
    {
        static struct option long_options[] =
                {
                        /* This option set a flag. */
                        {"verbose", 0,NULL, 'v'},
                        /* These options don't set a flag.
                           We distinguish them by their indices. */
                        {"blip",    1,       NULL, 'b'},
                        {"slip",    1,       NULL, 's'},
                        {"alip",    1,       NULL, 'a'},
                        {NULL,         0, NULL,  0}
                };
        /* getopt_long stores the option index here. */
        int option_index = 0;

        int c = getopt_long (argc, argv, "bsa", long_options, &option_index);

        /* Detect the end of the options. */
        if (c == -1)
            break;

        switch (c)
        {
            case 0:
                /* If this option set a flag, do nothing else now. */
                if (long_options[option_index].flag != 0)
                    break;
                printf ("option %s", long_options[option_index].name);
                if (optarg)
                    printf (" with arg %s", optarg);
                printf ("\n");
                break;
            case 'b':
                puts ("option -b\n");
                b=1;
                break;

            case 's':
                puts ("option -s\n");
                break;
            case 'a':
                puts ("option -a\n");
                a=1;
                break;
            case '?':
                /* getopt_long already printed an error message. */
                break;

            default:
                abort ();
        }
    }

    if (verbose_flag)
        puts ("verbose flag is set");

    if (optind < argc)
    {
        //printf ("non-option ARGV-elements: ");
        printf("Song Name: %s \n", argv[optind++]);
        if(b){
            printf ("Song Year: %s \n", argv[optind++]);

        }
        if(a){
            printf ("Artist: %s \n", argv[optind++]);
        }


    }

    return 0;
}

