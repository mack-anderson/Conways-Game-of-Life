#include <string.h>

int removeSpace ( char *line ) { /*name function*/
    int l = 0; /*stores ansi value of character for conversion*/
    int numberOfConversions = 0; /*stores number of conversions*/
    int length = strlen(line); /*creates variable containing number of characters, spaces, and tabs in line*/
    int finalLength; /*stores length of newly created line*/
    int q; /*counter*/
    int i = 0;

    for ( q = 0 ; q < strlen(line) ; q++)
    {   
        l = *( line + q );
        
        if ( l != 32 )
        {   
           *( line + i ) = *( line + q ); /*replaces character with space*/
           i++;
           numberOfConversions++; /*adds to number of conversions*/
        }
        
    }
    *(line+i) = '\0';
    finalLength = strlen(line); /*checks length of newly created line*/
    numberOfConversions = length - finalLength; /*find number of white spaces removed*/

    return (numberOfConversions); /*returns how many digits were replaced*/
}