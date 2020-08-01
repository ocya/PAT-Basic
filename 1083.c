#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define MaxN 10000

int main( int argc, const char *argv[]){
    /* Number数组记录差值个数，最大差值为N-1，最小差值为0 */
    int Number[MaxN];
    int Tmp;
    int N;
    int Difference;
    scanf( "%d\n", &N );
    /* 差值可以是 0  */
    for( int i = 0 ; i < N ; i++ )
        Number[i] = 0;
    for( int i = 1 ; i <= N ; i++ ){
        scanf( "%d", &Tmp );
        Difference = ( Tmp > i ) ? ( Tmp - i ) : ( i - Tmp );
        Number[Difference]++;
    }
    /* 注意：有重复的差值才纳入输出范围 */
    for( int i = N-1 ; i >= 0 ; i-- ){
        if( Number[i] > 1 ) printf( "%d %d\n", i, Number[i] );
    }

    
    return 0;
}
