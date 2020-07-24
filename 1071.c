#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


int main( int argc, const char *argv[]){

    int T, K;
    int n1, b, t, n2;
    scanf( "%d %d\n", &T, &K );
    
    for( int i = 0 ; i < K ; i++ ){
        scanf( "%d %d %d %d", &n1, &b, &t, &n2 );
        getchar();
        if( t > T ){
             printf( "Not enough tokens.  Total = %d.\n", T );
             continue; /* 当押注数大于筹码数时，本轮作废 */
        }
        if( ( b == 0 && n1 > n2 ) || ( b == 1 && n1 < n2 ) ){
            T += t;
            printf( "Win %d!  Total = %d.\n", t, T);
        }else{
            T -= t;
            printf( "Lose %d.  Total = %d.\n", t, T );
        }

        if( T == 0 ){
            printf( "Game Over.\n" );
             break;
        }
    }

    return 0;
}
