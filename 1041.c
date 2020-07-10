#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 考生信息的结构体 */
struct LNode{
    char Str[17]; /* 准考证号 */
    int X;  /* 试机座位号 */
    int Y; /* 考试座位号  */
};

int main( int argc, const char *argv[] ){
    int N,M;
    int Xtmp;
    scanf( "%d\n", &N );
    struct LNode Data[N+1]; /* 数组下标从 1 开始计算， 对应存储每个试机号 */
    struct LNode TmpNode;
    
    for( int i = 0 ; i < N ; i++ ){
        scanf( "%s %d %d",TmpNode.Str, &TmpNode.X, &TmpNode.Y );
        getchar();
        Data[TmpNode.X] = TmpNode; /* 因为试机号是唯一的，则可以按照该编号对应存进数组中，如：试机号为 2 ，则存储在 Data[2]数组上 */
    }
    scanf( "%d\n", &M ); /* 时间复杂度为 O(1) */
    for( int i = 0 ; i < M ; i++ ){
        scanf( "%d", &Xtmp );
        printf( "%s %d\n", Data[Xtmp].Str, Data[Xtmp].Y );
    }


    return 0;
}
