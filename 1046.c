#include <stdio.h>
#include <stdlib.h>

int main( int argc, const char *argv[] ){
    int N;
    int A1,A2,B1,B2;/* 分别记录 甲、乙 的 喊 和 划 */
    int Sum;
    int Cnt1,Cnt2; /* 记录输的一方喝酒的杯数 */
    Cnt1 = Cnt2 = 0;
    scanf( "%d\n", &N );
    for( int i = 0 ; i < N ; i++ ){
        scanf( "%d %d %d %d", &A1, &A2, &B1, &B2 );
        getchar();
        Sum = A1 + B1; 
        if( A2 != B2 ){ /* 当且仅当甲、乙划拳数不相等时才可能喝酒 */
            if( Sum == A2) Cnt2++;
            else if( Sum == B2 ) Cnt1++;
            /* Sum != A2 || Sum != B2 时都不用喝酒 */
        }
    }
    printf( "%d %d", Cnt1, Cnt2 );

    return 0;
}
