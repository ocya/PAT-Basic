#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MaxLength 1000


int main( int argc, const char *argv[]){
    char Command;
    char Data[MaxLength+1];
    int Cnt = 0;
    int Length;
    int i, j;
    i = j = 0;
    /**/
    scanf( "%c", &Command );
    getchar(); 
    /**/
    /* 注意 */
    /* 开始的代码
    scanf( "%c\n", &Command );
    导致测试点2，3不通过
    */
    gets( Data );
    Length = strlen( Data );

    if( Command == 'C'){
        /* i 表示待压缩的字符最初位置下标 */
        while( j < Length ){
            while( Data[j] == Data[i] )/* 遇到连续相同的字符，j 向后移动直到字符不相同*/
                j++;
            if( j - i  == 1 ) printf( "%c", Data[i] );/* j - i 为相同的字符个数，只有一个连续相同字符时，只需要输出这个字符*/
            else  printf( "%d%c", j - i , Data[i] );
            i = j;/* 更新 i  */
        }
    }else{
        while( i < Length ){
            Cnt = 0; /* 计算字符串对应的数字 */
            while( Data[i] >= '0' && Data[i] <= '9'){
                Cnt *= 10;
                Cnt += Data[i] - '0';
                i++;
            }
            if( Cnt == 0 ) Cnt = 1; /* 未进入 while 循环，表示当前是一个单独的字符，数量为 1  */
            for( int k = 0 ; k < Cnt ; k++ )
                printf( "%c", Data[i] );
            i++; /* 重要！！ 若只是在 while 循环中累加 i ，将导致未进入 while 循环时，i 停止不动 */
        }

    }

    return 0;
}

