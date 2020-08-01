#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>


int main( int argc, const char *argv[]){

    int N;
    int X, Y;
    double Distance;
    int Winner, Loser, Tmp ;
    double Max, Min;
    Max = 0;
    Min = 100 * sqrt( 2 );
    scanf( "%d\n", &N );

    for( int i = 0 ; i < N ; i++ ){
        scanf( "%d %d %d", &Tmp, &X, &Y );
        Distance = sqrt( X*X + Y*Y );
        if( Distance > Max ){
            Loser = Tmp;
            Max = Distance;
        }
        /* 注意！！ 一开始写的else if导致测试点2通不过 */
        /* 测试点2 是N=1的情形，即冠军和菜鸟是同一个人 */
        if( Distance < Min ){
            Winner = Tmp;
            Min = Distance;
        }
        getchar( );
    }
    printf( "%04d %04d\n", Winner, Loser );
    return 0;
}
