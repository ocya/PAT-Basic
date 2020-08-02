#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MaxN 10000

int main( int argc, const char *argv[]){
    /* 列出所有可能值，下标表示值的大小，bool型表示该值是否出现过 */
    int MaxCount = MaxN/2 + MaxN/3 + MaxN/5  + 1;
    bool Value[MaxCount];
    int N;
    int Tmp;
    int Count = 0;
    scanf( "%d", &N );
    /* 全部初始化为 false */
    for( int i = 0 ; i < MaxCount ; i++ ){
        Value[i] = false;
    }
    /* 注意！！ 题目要求从 1 ~ N ，不是从 0 ~ N-1 */
    for( int i = 1 ; i <= N ; i++ ){
        Tmp = i/2 + i/3 + i/5;
        Value[Tmp] = true;
    }
    for( int i = 0 ; i < MaxCount ; i++ ){
        if( Value[i] ) Count++;
    }
    printf( "%d", Count );
    return 0;
}
