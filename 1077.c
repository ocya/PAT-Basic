#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


void InsertionSort( int Grade[], int N );
int main( int argc, const char *argv[]){

    int N, M;
    int G1, G2;
    int TotalGrade; /* 总成绩 */
    int Tmp;
    int Count; /* 合理分数个数 */
    scanf( "%d %d\n", &N, &M );
    int Grade[N-1];
    for( int i = 0 ; i < N ; i++ ){
        Count = 0; /* 每一轮开始前合理分数为 0  */
        G1 = 0; 
        scanf( "%d", &G2 );
        for( int j = 0 ; j < N-1 ; j++ ){
            scanf( "%d", &Tmp ); /* 读取合理的分数并记录个数 */
            if( Tmp >= 0 && Tmp <= M ) Grade[Count++] = Tmp;
        } 
        InsertionSort( Grade, Count ); /* 增序排序，去掉最低分和最高分 */
        for( int k = 1 ; k < Count - 1 ; k++ )
            G1  += Grade[k];
        G1 *= 10; /* 乘10 保留计算结果小数点后一位 */
        G1 /= Count - 2;
        TotalGrade = ( G1 + G2 * 10 ) / 2;
        if( TotalGrade % 10 >= 5 ) TotalGrade += 10; /* 结果需要四舍五入 */
        TotalGrade /= 10; 
        printf( "%d\n", TotalGrade );
        getchar();
        
    }
    
    return 0;
}

/* 插入排序 */
void InsertionSort( int Grade[], int N ){
    int Tmp;
    int i, j;
    for( i = 1 ; i < N ; i++ ){
        Tmp = Grade[i];
        for( j = i ; j > 0 && Grade[j-1] > Tmp ; j-- )
            Grade[j] = Grade[j-1];
        Grade[j] = Tmp;
    }
}
