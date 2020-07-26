#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


int main( int argc, const char *argv[]){

    int N;
    char Ans[16];
    scanf( "%d\n", &N );
    for( int i = 0 ; i < N ; i++ ){
        gets( Ans );
        for( int j = 2 ;  ; j += 4 )
            if( Ans[j] == 'T' ){
                printf( "%d", Ans[j-2] - 'A' + 1 );
                break;
            } 
    }
    return 0;
}
