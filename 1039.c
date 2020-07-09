#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void InitializeArray( int Array[], int Size );
bool CheckArray( int Array[], int Size, int *Plus, int *Minus ) ;
int main( int argc, const char *argv[] ){

    bool flag = true;
    int Plus,Minus; /* Plus 表示多余的珠子，Minus 表示缺少的珠子 */
    char Tmp;
    int Digit[10],Small[26],Big[26]; /* 为不同的颜色创建 ‘桶’ , Digit为数字 0-9 , Small为字母 a-z , Big为字母 A-Z */
    Plus = Minus = 0;
    InitializeArray( Digit, 10 ); /* 将每个颜色桶的数量初始化为 0  */
    InitializeArray( Small, 26 );
    InitializeArray( Big, 26 );

    while(1){ /* 将每个颜色的珠子放入对应的桶中 */
        scanf( "%c", &Tmp );
        if( Tmp >= '0' && Tmp <= '9')
            Digit[ Tmp-'0' ]++;
        else if( Tmp >= 'a' && Tmp <= 'z')
            Small[ Tmp - 'a' ]++;
        else if( Tmp >= 'A' && Tmp <= 'Z')
            Big[ Tmp - 'A' ]++;
        else 
            break;
    }

    while(1){ /* 根据要购买的颜色, 从对应桶中取出珠子 */
        scanf( "%c", &Tmp );
        if( Tmp >= '0' && Tmp <= '9')
            Digit[ Tmp-'0' ]--;                       
        else if( Tmp >= 'a' && Tmp <= 'z')
            Small[ Tmp - 'a' ]--;
        else if( Tmp >= 'A' && Tmp <= 'Z')
            Big[ Tmp - 'A' ]--;
        else 
            break;
    }

    flag = CheckArray( Digit, 10, &Plus, &Minus ) & CheckArray ( Small, 26, &Plus, &Minus ) & CheckArray ( Big, 26, &Plus, &Minus );

    if( flag ) printf( "Yes %d",Plus );
    else printf( "No %d",Minus );

    return 0;
}

void InitializeArray( int Array[], int Size ){
    for( int i = 0 ; i < Size ; i++ )
        Array[i] = 0;
}

bool CheckArray( int Array[], int Size, int *Plus, int *Minus ){
    bool flag = true;
    for( int i = 0 ; i < Size ; i++ ){
        if( Array[i] > 0 )
            ( *Plus ) += Array[i] ; /* 统计剩余多的珠子 */
        else if( Array[i] < 0 ){
            flag = false;           /* 若某个桶中的珠子数量为负数，表示缺少对应颜色的珠子 ，则 不能买*/
            ( *Minus ) -= Array[i]; /* 统计缺少的珠子的总数 */
        }
    }
    return flag;
}
