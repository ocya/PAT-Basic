#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool Check( char LuckyGuys[][21], char Candidate[] ,int N);

int main( int argc, const char *argv[]){
    
    int M, N, S;
    int Cnt;
    bool NextFlag;
    char Candidate[21];
    scanf( "%d %d %d\n", &M, &N, &S );
    char LuckyGuys[M][21]; /* 存储已经中奖的用户昵称 */
    Cnt = 0; /* 记录已经中奖的用户个数 */
    NextFlag = false; /* 当前用户重复中奖， 顺延判断下一个用户是否中奖 */
    for( int i = 1 ; i <= M ; i++ ){
        scanf( "%s", Candidate );
        if( i == S ){ /* 起始点处，选择第一个中奖用户 */
            strcpy( LuckyGuys[Cnt++], Candidate );
        }else if( ( i > S && ( i-S ) % N == 0 ) || NextFlag ){
            /* 间隔中奖 或 顺延中奖 进入判断程序 */
            NextFlag = false; /* 重置顺延中奖标志位 */
           if( Check( LuckyGuys, Candidate, Cnt ) ){ /* 检查是否重复中奖 */
               strcpy( LuckyGuys[Cnt++], Candidate );
               S = i; /* 将当前位置设为起始位，再寻找间隔 N 的中奖候选人 */
           }else NextFlag = true; /* 重复中奖顺延检查下一位 */
        }
        getchar();
    }
    if( Cnt == 0 )  printf( "Keep going...\n");
    for( int i = 0 ; i < Cnt ; i++ )
        printf( "%s\n", LuckyGuys[i] );
    
    return 0;
    
}

bool Check( char LuckyGuys[][21], char Candidate[] ,int N ){
    bool ret = true;
    for( int i = 0 ; i < N ; i++ )
        if( strcmp( LuckyGuys[i], Candidate ) == 0 ){
            ret = false;
            break;
        }
    
    return ret;
}

