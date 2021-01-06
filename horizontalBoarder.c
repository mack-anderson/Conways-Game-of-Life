#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int horizontalBoarder ( int numberOfColumns ) { /*name function*/

    int i;
    
        for ( i = 0; i < numberOfColumns; i++ )
    {   
        if ( i == 0 )
        {
            printf(" ");
        }
        
        if ( i == (numberOfColumns) )
        {
            printf("-\n");
        }
        else
        {
            printf("-");
        }
        
    }
    printf("\n");

    return(1);
}