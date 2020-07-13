#include <stdio.h>
#include <stdlib.h>

int main( int argc, const char *argv[] ){
    int N;
    int Grade[1001]; /* 队伍编号从 1 到 1000 */
    int Idx,tmp,Data; 
    int Max,TeamId;
    Max = TeamId = 0;
    scanf( "%d", &N );
    for( int i = 1 ; i < 1001 ; i++ ) /* 将所有队伍的总成绩初始化为 0  */
        Grade[i] = 0;
    for( int i = 0 ; i < N ; i++ ){
        scanf( "%d-%d %d", &Idx, &tmp, &Data ); /* 只用根据队伍号来计算总成绩 */
        Grade[Idx] += Data;
        if( Grade[Idx] > Max ){ /* 在累积成绩过程中记录最大值和对应的队伍编号 */
            Max = Grade[Idx];
            TeamId = Idx;
        }
        getchar();
    }
    printf( "%d %d", TeamId, Max );
    return 0;
}

