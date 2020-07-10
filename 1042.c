#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 桶排序算法 */

int main( int argc, const char *argv[] ){
    
    int Alphabet[26];
    char Tmp;
    int MaxCount = 0; /* 记录出现最多的次数，初始化为最小值 0 */
    int Idx = 0; /* 记录MaxCount出现在 Alphabet 数组中的下标 */
    for( int i = 0 ; i < 26 ; i++ )
        Alphabet[i] = 0;
    while(1){
        scanf( "%c",&Tmp );
        if(  Tmp >= 'A' && Tmp <= 'Z' ){
            Alphabet[ Tmp - 'A' ]++;
        }else if( Tmp >= 'a' && Tmp <= 'z' ){
            Alphabet[ Tmp - 'a' ]++;
        }else if( Tmp == '\n')
            break;
    }
    for( int i = 0 ; i < 26 ; i++ ){
        if( Alphabet[i] > MaxCount ){ /* 如果有并列，则输出按字母序最小的那个字母 */
            MaxCount = Alphabet[i];     /* 若输出字母序最大的那个字母，判断条件为 >= */
            Idx = i;
        }
    }
    printf( "%c %d",'a' + Idx, MaxCount ); /* 'a' + Idx 得到相应小写字母的 ASCII 码值  */

    return 0;
}
