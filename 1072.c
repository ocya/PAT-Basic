#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MaxItemSize 10

int main( int argc, const char *argv[]){

    int N, M;
    int i, j, k, l;
    char StuName[5];/* 学生姓名 */
    int CheckCnt;/* 当前学生 需要检查的物品数量 */
    int StuCount = 0;/* 存在问题学生人数*/
    int TotalCount = 0; /* 查缴的物品总数 */
    int CheckedItem[MaxItemSize]; /* 存储被查缴的物品的编号 */
    int CheckedCount; /* 当前学生被查缴的物品数量 */
    int Item; /* 待检查的物品 */
    scanf( "%d %d\n", &N, &M );
    int Check[M];
    for( i = 0 ; i < M ; i++ )
        scanf( "%d", &Check[i] );
    getchar();
    
    for( i = 0 ; i < N ; i++ ){
        CheckedCount = 0;
        scanf( "%s %d", StuName, &CheckCnt );
        for( j = 0 ; j < CheckCnt ; j++ ){
            scanf( "%d", &Item );
            for( k = 0 ; k < M ; k++ ){
                if( Check[k] == Item ){
                    TotalCount++;
                    CheckedItem[CheckedCount++] = Item;
                    break;
                }
            }
        }
        /* 学生有物品被查缴，则输出学生名字及相应被查缴的物品编号 */
        if( CheckedCount != 0 ){
            StuCount++;
            printf( "%s:", StuName );
            for( l = 0 ; l < CheckedCount ; l++ )
                printf( " %04d", CheckedItem[l] ); /* 编号为 4 位数， 注意输出编号的格式 */
            printf( "\n");
        }
        getchar();
    }
    printf( "%d %d\n", StuCount, TotalCount );

    return 0;
}
