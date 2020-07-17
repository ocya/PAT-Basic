#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MaxSize 10000

bool IsPrime( int X );
void Check( int Data[], bool Checked[], int Key );
int main( int argc, const char *argv[] ){

    int Data[MaxSize]; /* 记录每个 ID 的名次*/
    bool Checked[MaxSize]; /* 记录 ID 是否被访问过 */
    int N, K;
    int Tmp;
    scanf( "%d\n", &N );
    for( int i = 0 ; i < MaxSize ; i++ ){ /* 初始化全部 ID 为 -1 ，表示空  */
        Data[i] = -1;
        Checked[i] = false;
    }
    for( int i = 0 ; i < N ; i++ ){
        scanf( "%d", &Tmp ); /* 以 ID 为下标 */
        Data[Tmp] = i+1; /* 学生排名从 1 开始计数 */
        getchar();
    }

    scanf( "%d\n", &K );
    for( int i = 0 ; i < K ; i++ ){
        scanf( "%d", &Tmp );
        Check( Data, Checked, Tmp ); /* 输出检查的结果 */
    }

    return 0;
}

void Check( int Data[], bool Checked[], int Key ){
    int rank = Data[Key];
    if( rank == -1 )
        printf( "%04d: Are you kidding?", Key );
    else{
        if( Checked[Key] == true )
            printf( "%04d: Checked", Key );
        else{
            Checked[Key] = true;
            if( rank == 1 ) printf( "%04d: Mystery Award", Key );
            else if( IsPrime( rank ) ) printf( "%04d: Minion", Key );
            else printf( "%04d: Chocolate", Key );
        }
    }
    printf( "\n" );
}

bool IsPrime( int X ){ /* 判断是否为素数 */
    if( X == 2 ) return true;
    if( X%2 == 0 ) return false;
    bool ret = true;
    for( int i = 3 ; i <= sqrt( X ) ; i += 2 ){
        if( X % i == 0 ){
            ret = false;
            break;
        }
    }
    return ret;
}

