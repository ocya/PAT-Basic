#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



int main( int argc, const char *argv[] ){

    int N,M;
    int TmpAnswer,TmpSum;
    scanf( "%d %d\n", &N, &M );
    int Grade[M],Answer[M];
    for( int i = 0 ; i < M ; i++ )  
        scanf( "%d", &Grade[i] ); /* 读入每题分数 */
    getchar();

    for( int i = 0 ; i < M ; i++ )
        scanf( "%d", &Answer[i] ); /* 读入正确答案 */
    getchar();

    for( int i = 0 ; i < N ; i++ ){
        TmpSum = 0; /* 依次累加回答正确题目所对应的分数 */
        for( int j = 0 ; j < M ; j++ ){
            scanf( "%d", &TmpAnswer );
            TmpSum += ( Answer[j] == TmpAnswer ) ? Grade[j] : 0;
        }
        printf( "%d\n", TmpSum ); /* 输出成绩 */
        getchar();
    }

    return 0;
}
