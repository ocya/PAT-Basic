#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



int main( int argc, const char *argv[] ){

    int N;
    bool Num[37]; /* 所有数字小于 10000 ，则最大值为9999，各位累加和为 36 */
    char TempData[5]; /* 数字长度为 4 位 */
    char *Key; /* 处理字符串时的移动指针 */
    int Sum; /* 各位数字的累加和 */
    bool flag = true; /* 末尾空格字符控制 */
    int cnt = 0; /* 统计朋友证号的个数 */
    scanf( "%d\n", &N );
    for( int i = 0 ; i < 37 ; i++ )
        Num[i] = false; /* 初始化数组初值为false，代表该数字未出现 */
    for( int i = 0 ; i < N ; i++ ){
        Sum = 0; /* 在每一轮的读取字符串之前，需要重置Sum 和 Key */
        scanf( "%s", TempData );
        Key = TempData;
        while( *Key != '\0' )
            Sum += ( *Key++ - '0' ); /* 移位，累加每一位 */
        Num[Sum] = true;
    }
    for( int i = 0 ; i < 37 ; i++ )
        if( Num[i] == true ) /* 统计共出现多少个朋友数 */
             cnt++;
    printf( "%d\n", cnt );
    for( int i = 0 ; i < 37 ; i++ ) /* 从小到大依次输出 */
        if( Num[i] == true ){
            if( flag ){
                printf( "%d", i );
                flag = false;
            }else
                printf( " %d", i );
        } 

    return 0;
}
