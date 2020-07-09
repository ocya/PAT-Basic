#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main( int argc, const char *argv[] ){

    int Score[101]; /* 为0-100分分别创建一个桶，用于统计某一个分数的人数 */
                    /*如 Score[0] 为0分的人数，Score[100] 为100分人数 */
    int N,K;
    int Tmp;
    bool flag = true;
    for( int i = 0 ; i <= 100 ; i++ ) /* 每个桶初始化为0 */
        Score[i] = 0;
    scanf( "%d\n", &N );
    for( int i = 0 ; i < N ; i++ ){
        scanf( "%d", &Tmp );
        Score[Tmp]++; /* 读入一个分数，则将对应桶内人数加1 */
    }
    getchar(); /* 取出缓存中的 '\n' */
    scanf( "%d",&K );
    for( int i = 0 ; i < K ; i++ ){
        scanf( "%d" , &Tmp );
        if( flag ){
            flag = false;
            printf( "%d", Score[Tmp]);
        }else{
            printf( " %d", Score[Tmp]);
        }
    }
       

    return 0;
}
