#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int Decrement( const void *p1, const void *p2 );

int main( int argc, const char *argv[] ){

    int N,E;
    int i;
    int Count = 0;
    scanf( "%d\n", &N );
    int Data[N];
    for( i = 0 ; i < N ; i++ ){
        scanf( "%d", &Data[i] );
    }
    qsort( Data, N, sizeof(int), Decrement );
    /* 数列是递减序，E 从 最大值 N 遍历到 1 */
    /*若 Data[E-1] > E 成立，则有 E 个 骑行距离大于 E */
    for( E = N ; E > 0 ; E-- ){ /* 给出 N 个 非负整数，则 E 可能为 0， E = 0 时自动跳出循环 */
        if( Data[E-1] > E ) break; /* 注意骑行距离需要大于 E */
    }
    printf( "%d", E );
    return 0;
}

/* 快速排序的比较函数，递减序 */
int Decrement( const void *p1, const void *p2 ){
    return *(int *)p2 - *(int *)p1;
}
