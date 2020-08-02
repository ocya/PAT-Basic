#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void Judge( double A, double B );
int main( int argc, const char *argv[]){
    int M, X, Y;
    int A, B;
    double C;/* 丙可能是小数，需要用double */
    bool exit = false;
    scanf( "%d %d %d", &M, &X, &Y );
    for( A = 99 ; A > 9 ; A-- ){
        B = A%10 * 10 + A/10;
        if( abs( A - B )* Y == B*X ){
            exit = true;
            break;
        } 
    }
    if( exit ){
        C = (double)B/Y;
        printf( "%d", A );
        Judge( M, A );
        Judge( M, B );
        Judge( M, C );
    }else printf( "No Solution");
    

    return 0;
}

/* 考虑到C可能为小数，这里参类型定义为double,以免损失精度 */
void Judge( double A, double B ){
    if( B > A ) printf( " Cong" );
    if( B == A ) printf( " Ping" );
    if( B < A ) printf( " Gai" );
}
