#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main( int argc, const char *argv[] ){

    int M, N, Tmp;
    char Number[5];
    int Num;
    int Len;
    int Mod;
    scanf( "%d\n", &M );
    for( int i = 0 ; i < M ; i++ ){
        scanf( "%s", Number );
        Len = strlen( Number );
        Mod = pow( 10, Len );
        Tmp = atoi( Number );
        for( N = 1 ; N < 10 ; N++ ){
            Num =  N * Tmp * Tmp ;
            if( Tmp == Num % Mod ){
                printf( "%d %d\n", N, Num );
                break;
            }
        }
        if( N == 10 ) printf( "No\n" );
    }

    return 0;
}
