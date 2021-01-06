#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cgol.h"

int main( int argc, char *argv[] ) {

    FILE*f1;
    char temp[100];
    char input[VERTICAL][HORIZONTAL];
    char calculatedInput[VERTICAL][HORIZONTAL];
    char output[VERTICAL][HORIZONTAL];
    int i;
    int j;
    int dynCounter;
    char fileName[25];
    int neighbours;
    int counter;
    int ticks;
    int yes;
    int yesNoCheck;
    char yesOrNo[20];
    int numberOfColumns;
    int numberOfRows;
    
    

    if ( argc < 2 )
    {
        printf("please enter a seed file");
    }
    
    else if ( argc < 3)
    {
        ticks = 50;
    }
    
    else if ( atoi(argv[2]) < 0 || atoi(argv[2]) > 32767 )
    {
        printf("please enter a number of ticks between 0 and 32767");
    }
    
    else
    {
        ticks = atoi( argv[2] );
    }
    
    
    strcpy(fileName, argv[1]);
        strcpy(fileName, argv[1]);
        if ( (f1 = fopen( fileName, "r")) != NULL ) 
        {   
            i = 0;
            while ( fgets(temp, 500, f1) != NULL ) {
                removeSpace(temp);
                j = 0;
                while((temp[j] !='\n'))
                {   
                    input[i][j] = temp[j];
                    j++;
                    numberOfColumns = j;
                }
                i++;
                numberOfRows = i;
            }
            fclose( f1 );
        }
        else {
        printf ( "Cannnot open %s\n", argv[1] );
        return ( -2 );
    }
        

    for ( i = 0; i < 20; i++)
            {
                for ( j = 0; j < 40; j++)
                {
                    if (input[i][j] == '0')
                    {
                        output[i][j] = ' ';
                    }
                    else if (input[i][j] == '1')
                    {
                        output[i][j] = 'X';
                    }
                    
                    
                }
            
            }
    horizontalBoarder(40);
        
        for ( i = 0; i < 20; i++)
        {
            for ( j = 0; j < 40; j++)
            {
                if ( j == 0)
                {
                    printf( "|%c",output[i][j]);
                }
                else if ( j == ( 40 -1 ) )
                {
                    printf( "%c|",output[i][j]);
                }
                else
                {
                printf( "%c",output[i][j]);
                }  
            }
            
                printf( "\n");
            
            
             
        }

    horizontalBoarderCounter(40, 0);
    
    yesNoCheck = 1;
    while ( yesNoCheck == 1 )
        {
            printf( "Start? (y or n)\n"); /*retrieves desired rank from user*/
            fgets(yesOrNo,500,stdin);
            if ( ( strcmp(yesOrNo, "N\n") != 0 ) & ( strcmp(yesOrNo, "Y\n") != 0 ) & ( strcmp(yesOrNo, "y\n") != 0 ) & ( strcmp(yesOrNo, "n\n") != 0 ))
                {
                    printf( "Only the single characters Y or N are acceptable.\n" );
                }
            else
                {
                    yesNoCheck = 0;
                }
        }  
    if ( ( strcmp(yesOrNo, "Y\n") == 0 ) || ( strcmp(yesOrNo, "y\n") == 0 ))
        {
            yes = 1;
        }
    else if (  ( strcmp(yesOrNo, "N\n") == 0 ) || ( strcmp(yesOrNo, "n\n") == 0 ) )
        {
            return(0);
        }     

    dynCounter = 0;
    while ( yes == 1 )
    {
    
        counter = 0;
        while ( counter < ticks )
        {
            system( "clear");
            
            for ( i = 0; i < 20; i++)
            {   
                
                for ( j = 0; j < 40; j++)
                {   
                    
                    if (input[i][j] == '1')
                    {   
                        neighbours = 0;
                        
                        if ( (i-1) > -1 )
                        {
                            if ( input[i-1][j] == '1' )
                            {
                                neighbours++;
                            }
                        }
                        if ( (i-1) > -1 && (j-1) > -1 )
                        {
                                if ( input[i-1][j-1] == '1' )
                            {
                                neighbours++;
                            }
                        }
                        if ( (j-1) > -1 )
                        {
                                if ( input[i][j-1] == '1' )
                            {
                                neighbours++;
                            }
                        }
                        if ( (i + 1) < (20 ) && (j-1) > -1 )
                        {
                                if ( input[i+1][j-1] == '1' )
                            {
                                neighbours++;
                            }
                        }
                        if ( (i + 1) < (20))
                        {
                                if ( input[i+1][j] == '1' )
                            {
                                neighbours++;
                            }
                        }
                        if ( (i - 1) > -1 && (j + 1) < (40))
                        {
                                if ( input[i-1][j+1] == '1' )
                            {
                                neighbours++;
                            }
                        }
                        if ( (j + 1) < (40))
                        {
                                if ( input[i][j+1] == '1' )
                            {
                                neighbours++;
                            }
                        }
                        if ( (j + 1) < (40) && (i + 1) < (20))
                        {
                                if ( input[i+1][j+1] == '1' )
                            {
                                neighbours++;
                            }
                        }


                        if ( neighbours < 2 )
                        {
                            calculatedInput[i][j] = '0';
                            
                        }
                        else if ( neighbours > 3 )
                        {
                            calculatedInput[i][j] = '0';
                        
                        }
                        else if ( neighbours == 3 )
                        {
                            calculatedInput[i][j] = '1';
                            
                        }
                        else if ( neighbours == 2 )
                        {
                            calculatedInput[i][j] = '1';
                        
                        }
                        else
                        {
                            calculatedInput[i][j] = '1';
                            
                        }
                    }
                    
                    else if (input[i][j] == '0')
                    {   
                        neighbours = 0;
                        if ( (i-1) > -1 )
                        {
                            if ( input[i-1][j] == '1' )
                            {
                                neighbours++;
                            }
                        }
                        if ( (i-1) > -1 && (j-1) > -1 )
                        {
                                if ( input[i-1][j-1] == '1' )
                            {
                                neighbours++;
                            }
                        }
                        if ( (j-1) > -1 )
                        {
                                if ( input[i][j-1] == '1' )
                            {
                                neighbours++;
                            }
                        }
                        if ( (i + 1) < (20 ) && (j-1) > -1 )
                        {
                                if ( input[i+1][j-1] == '1' )
                            {
                                neighbours++;
                            }
                        }
                        if ( (i + 1) < (20))
                        {
                                if ( input[i+1][j] == '1' )
                            {
                                neighbours++;
                            }
                        }
                        if ( (i - 1) > -1 && (j + 1) < (40))
                        {
                                if ( input[i-1][j+1] == '1' )
                            {
                                neighbours++;
                            }
                        }
                        if ( (j + 1) < (40))
                        {
                                if ( input[i][j+1] == '1' )
                            {
                                neighbours++;
                            }
                        }
                        if ( (j + 1) < (40) && (i + 1) < (20))
                        {
                                if ( input[i+1][j+1] == '1' )
                            {
                                neighbours++;
                            }
                        }
                        
                        if ( neighbours == 3 )
                        {
                            calculatedInput[i][j] = '1';
                            
                        }
                        else
                        {
                            calculatedInput[i][j] = '0';
                            
                        }
                    }
                        
                        
                    
                }
            }
            int compare = 0;
            for ( i = 0; i < 20; i++)
            {
                for ( j = 0; j < 40; j++)
                {   
                    if ( input[i][j] != calculatedInput[i][j] )
                    {
                        compare++;
                    }
                    if ( ( j == 40 - 1 ) && ( i == 20 - 1 ) && ( compare == 0 ) )
                    {
                        return(0);
                    }
                    
                }
            
            }

            for ( i = 0; i < 20; i++)
            {
                for ( j = 0; j < 40; j++)
                {
                    input[i][j] = calculatedInput[i][j];
                }
            
            }
            counter++;

            for ( i = 0; i < 20; i++)
            {
                for ( j = 0; j < 40; j++)
                {
                    if (calculatedInput[i][j] == '0')
                    {
                        output[i][j] = ' ';
                    }
                    else if (calculatedInput[i][j] == '1')
                    {
                        output[i][j] = 'X';
                    }
                    
                    
                }
            
            }

        horizontalBoarder(40);
        
        for ( i = 0; i < 20; i++)
        {
            for ( j = 0; j < 40; j++)
            {
                if ( j == 0)
                {
                    printf( "|%c",output[i][j]);
                }
                else if ( j == ( 40 -1 ) )
                {
                    printf( "%c|",output[i][j]);
                }
                else
                {
                printf( "%c",output[i][j]);
                }  
            }

                printf( "\n");
            
        }

        horizontalBoarderCounter(40, counter+dynCounter);
        
        
        system( "sleep 0.25" );
        
        }
        yesNoCheck = 1;
        while ( yesNoCheck == 1 )
                {
                    printf( "Continue?(y or n)\n"); /*retrieves desired rank from user*/
                    fgets(yesOrNo,500,stdin);
                    if ( ( strcmp(yesOrNo, "N\n") != 0 ) & ( strcmp(yesOrNo, "Y\n") != 0 ) & ( strcmp(yesOrNo, "y\n") != 0 ) & ( strcmp(yesOrNo, "n\n") != 0 ))
                    {
                    printf( "Only the single characters Y or N are acceptable.\n" );
                    }
                    else
                    {
                        yesNoCheck = 0;
                    }
                    }                   
                    if ( ( strcmp(yesOrNo, "Y\n") == 0 ) || ( strcmp(yesOrNo, "y\n") == 0 ))
                    {
                        yes = 1;
                        dynCounter = dynCounter + ticks;
                    }
                    else if (  ( strcmp(yesOrNo, "N\n") == 0 ) || ( strcmp(yesOrNo, "n\n") == 0 ) )
                    {
                        return(0);
                    }

    }
    
return(0);
}
