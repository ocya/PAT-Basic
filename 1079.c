#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MaxLength 1011 /* 十次迭代中，每次都可能产生进位位，初始长度为1000，循环结束为1010，加上结束位，要不然测试点6过不了 */
#define MaxStep 10

bool Check( char Number[], int Length );
int Add( char Number[], int Length);
int main( int argc, const char *argv[]){

    char Number[MaxLength];
    int Length;
    int i;
    scanf( "%s", Number );
    Length = strlen( Number );
    for( i = 0 ; i < MaxStep ; i++ ){
        if( Check( Number, Length ) ){ /* 每一轮循环中，判断是否为回文数 */
            printf( "%s is a palindromic number.", Number ); /* 是回文数输出结果，结束循环 */
            break;
        }else Length = Add( Number, Length ); /* 不是回文数则累加输出 */
    }
    if( i == MaxStep ) printf( "Not found in 10 iterations.");
    return 0;
}

int Add( char Number[], int Length){
 
    char Reverse[MaxLength];
    int Carrier = 0;

    printf( "%s + ", Number );
    for( int i = Length-1 ; i >= 0 ; i-- ){ /* Reverse,并输出 */
        Reverse[Length-1-i] = Number[i];
        printf( "%c", Number[i] );
    }
    printf( " = ");
    for( int i = Length-1 ; i >= 0 ; i-- ){
        Number[i] += Reverse[i] + Carrier - '0'; /* 非常重要！！ 一定要减去 '0' ，在ASCII 码基础上对 Number[i] 累加 */
        if( Number[i] > '9' ){
            Number[i] -= 10;
            Carrier = 1;
        }else Carrier = 0; /* 设置进位位 */
    }
    if( Carrier == 1 ){
        strcpy( Reverse+1, Number ); /* 重要！！！ 如果有进位，将Number复制到 Reverse+1的字符串，即首地址从Reverse[1] 开始 */
        Reverse[0] = '1'; /* 将Reverse[0] 置为 1 */
        strcpy( Number, Reverse ); /* 将进位后的数重新复制到Number */
        Length += 1; /* 注意此时长度加一 */
    }
    printf( "%s\n", Number );
    
    return Length; /* 进位时长度会更新 */

}

bool Check( char Number[], int Length ){
    bool ret = true;
    for( int i = 0 ; i < Length/2 ; i++ )
        if( Number[i] != Number[Length-1-i] ){
            ret = false;
            break;
        }
    return ret;
}
