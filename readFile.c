#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int readFile( char fileName[25], char *input[][22], int *numberOfColumns, int *numberOfRows ) { /*name function*/

    FILE*f1;
    int i;
    int j;
    char temp[500];
    if ( (f1 = fopen( *fileName, "r")) != NULL ) 
    {   
        i = 0;
        while ( fgets(temp, 500, f1) != NULL ) {
            removeSpace(temp);
            j = 1;
            *input[i][0] = '0';
            while((temp[j] !='\n'))
            {   
                *input[i][j] = temp[j];;
                j++;
                *numberOfColumns = j;
            }
            i++;
            *numberOfRows = i;
        }
        fclose( f1 );
    } 
    *numberOfColumns = *numberOfColumns - 1;

    return (1); /*returns how many digits were replaced*/
}