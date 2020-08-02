#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main( int argc, const char *argv[]){

    int A, B;
    int C;
    scanf( "%d %d", &A, &B );
    C = A * B;
    /* 10 * 10 = 100, 结果应该输出 1 */
    while( C%10 == 0 ){
        C /= 10;
    }
    while( C > 0 ){
        printf( "%d", C%10 );
        C /= 10;
    }

    
    return 0;
}
