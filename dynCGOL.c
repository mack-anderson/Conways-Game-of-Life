#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cgol.h"

int main( int argc, char *argv[] ) {

    
    
    
    FILE*f1;
    int i;
    
    int dynCounter;
    int j;
    int numberOfRows;
    int numberOfColumns;
    char fileName[25];
    int neighbours;
    int counter;
    int ticks;
    int yes;
    int yesNoCheck;
    char yesOrNo[20];
    int VerticalSize;
    int horizontalSize;
    int q;
    
    

    if ( argc < 4 )
    {
        printf("please enter a seed file, grid size, and number of ticks\nExample Input: ./dynCGOL file.seed verticalSize horizontalSize ticks\n");
        return(0);
    }
    
    else if ( argc < 3)
    {
        ticks = 50;
        if ( atoi(argv[2]) < 0 || atoi(argv[2]) > 32767 )
        {
            printf("please enter a vertical world size between 0 and 32767\n");
            return(0);
        }
        if ( atoi(argv[3]) < 0 || atoi(argv[3]) > 32767 )
        {
            printf("please enter a horizontal world size between 0 and 32767\n");
            return(0);
        }
    }
    
    else if ( atoi(argv[4]) < 0 || atoi(argv[4]) > 32767 )
    {
        printf("please enter a number of ticks between 0 and 32767\n");
    }
    
    else
    {
        ticks = atoi( argv[4] );
        VerticalSize = atoi( argv[2] );
        horizontalSize = atoi( argv[3] );
    }
    
    char input[VerticalSize][horizontalSize];
    char calculatedInput[VerticalSize][horizontalSize];
    char output[VerticalSize][horizontalSize];
    char temp[500];
    
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
        numberOfColumns = numberOfColumns - 1;
    
    for ( i = 0; i < VerticalSize; i++)
    {
        if ( i < numberOfRows )
        {   
            for ( q = numberOfColumns; q < horizontalSize; q++)
                {   
                    input[i][q] = '0';
                }
        }
        else if ( i > numberOfRows - 1 )
        {   
            for ( j = 0; j < horizontalSize; j++)
                {
                    input[i][j] = '0';
                }
        }
        
        
        
        
    }
    

    for ( i = 0; i < VerticalSize; i++)
            {
                for ( j = 0; j < horizontalSize; j++)
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
    horizontalBoarder(horizontalSize);
        
        for ( i = 0; i < VerticalSize; i++)
        {
            for ( j = 0; j < horizontalSize; j++)
            {
                if ( j == 0)
                {
                    printf( "|%c",output[i][j]);
                }
                else if ( j == ( horizontalSize -1 ) )
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

    horizontalBoarderCounter(horizontalSize, 0);
    
    

    
    
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
            
            for ( i = 0; i < VerticalSize; i++)
            {   
                
                for ( j = 0; j < horizontalSize; j++)
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
                        if ( (i + 1) < (VerticalSize ) && (j-1) > -1 )
                        {
                                if ( input[i+1][j-1] == '1' )
                            {
                                neighbours++;
                            }
                        }
                        if ( (i + 1) < (VerticalSize))
                        {
                                if ( input[i+1][j] == '1' )
                            {
                                neighbours++;
                            }
                        }
                        if ( (i - 1) > -1 && (j + 1) < (horizontalSize))
                        {
                                if ( input[i-1][j+1] == '1' )
                            {
                                neighbours++;
                            }
                        }
                        if ( (j + 1) < (horizontalSize))
                        {
                                if ( input[i][j+1] == '1' )
                            {
                                neighbours++;
                            }
                        }
                        if ( (j + 1) < ( horizontalSize ) && (i + 1) < (VerticalSize))
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
                        if ( (i + 1) < ( VerticalSize ) && (j-1) > -1 )
                        {
                                if ( input[i+1][j-1] == '1' )
                            {
                                neighbours++;
                            }
                        }
                        if ( (i + 1) < ( VerticalSize))
                        {
                                if ( input[i+1][j] == '1' )
                            {
                                neighbours++;
                            }
                        }
                        if ( (i - 1) > -1 && (j + 1) < (horizontalSize))
                        {
                                if ( input[i-1][j+1] == '1' )
                            {
                                neighbours++;
                            }
                        }
                        if ( (j + 1) < (horizontalSize))
                        {
                                if ( input[i][j+1] == '1' )
                            {
                                neighbours++;
                            }
                        }
                        if ( (j + 1) < (horizontalSize) && (i + 1) < (VerticalSize))
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
            for ( i = 0; i < VerticalSize; i++)
            {
                for ( j = 0; j < horizontalSize; j++)
                {   
                    if ( input[i][j] != calculatedInput[i][j] )
                    {
                        compare++;
                    }
                    if ( ( j == horizontalSize - 1 ) && ( i == VerticalSize - 1 ) && ( compare == 0 ) )
                    {
                        return(0);
                    }
                    
                }
            
            }

            for ( i = 0; i < VerticalSize; i++)
            {
                for ( j = 0; j < horizontalSize; j++)
                {
                    input[i][j] = calculatedInput[i][j];
                }
            
            }
            counter++;

            for ( i = 0; i < VerticalSize; i++)
            {
                for ( j = 0; j < horizontalSize; j++)
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

        horizontalBoarder(horizontalSize);
        
        for ( i = 0; i < VerticalSize; i++)
        {
            for ( j = 0; j < horizontalSize; j++)
            {
                if ( j == 0)
                {
                    printf( "|%c",output[i][j]);
                }
                else if ( j == ( horizontalSize -1 ) )
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

        horizontalBoarderCounter(horizontalSize, counter+dynCounter);
        
        
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
