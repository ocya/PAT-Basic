#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
/*

遍历字符串后对于每一A，它前面的P的个数和它后面的T的个数的乘积就是能构成的PAT的个数。
把对于每一个A的结果相加即可

第一次遍历字符串数一数有多少个T,得到TCount
第二次遍历：
每遇到一个T则TCount-–;
每遇到一个P则PCount++;
遇到字母A则 计算 PCount * TCount,把这个结果累加到Sum

‘乘法’ 和 ‘累加’ 操作需要对10000000007取余

*/

#define MaxLength 100000

int main( int argc, const char *argv[] ){
    
    int Idx;
    int PCount,ACount,TCount;
    int Sum = 0;
    PCount = ACount = TCount = 0;
    char Str[MaxLength+1];
    scanf( "%s",Str );


    for( Idx = 0 ; Str[Idx] != '\0' ; Idx++ )
        if( Str[Idx] == 'T' )
            TCount++;
    
    for( Idx = 0 ; Str[Idx] != '\0' ; Idx++ ){
        switch( Str[Idx] ){
            case 'P':PCount++; break;
            case 'A':Sum = ( Sum + ( PCount * TCount ) % 1000000007 ) % 1000000007 ; break;
            case 'T':TCount--;break;
        }
    }
    
    printf( "%d", Sum);

    return 0;
}
