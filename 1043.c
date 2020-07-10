#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main( int argc, const char *argv[] ){
    
    int PATest[6];
    char Str[7] = "PATest"; /* PATest 数组下标映射到对应英文字母 */
    int Tmp;
    int Cnt = 0;
    for( int i = 0 ; i < 6 ; i++ )
         PATest[i] = 0;
    while( 1 ){ /* 统计 P A T e s t 这6个字母出现的分别出现的次数 和 出现的总次数 */
        scanf( "%c", &Tmp );
        if( Tmp == '\n' )  break;
        switch( Tmp ){
            case 'P': PATest[0]++; Cnt++; break;
            case 'A': PATest[1]++; Cnt++; break;
            case 'T': PATest[2]++; Cnt++; break;
            case 'e': PATest[3]++; Cnt++; break;
            case 's': PATest[4]++; Cnt++; break;
            case 't': PATest[5]++; Cnt++; break; 
        }
    }
    while( Cnt != 0 ){
        for( int i = 0 ; i < 6 ; i++ ){
            if( PATest[i] != 0){
                Cnt--;
                PATest[i]--;
                printf( "%c", Str[i] );
            }                
        }
    }

    return 0;
}
