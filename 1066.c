#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main( int argc, const char *argv[] ){
    
    int  N, M, A, B, V;
    int temp;
    bool flag = true;
    scanf( "%d %d %d %d %d\n", &N, &M, &A, &B, &V );
    for( int i = 0 ; i < N ; i++ ){
        for( int j = 0 ; j < M ; j++ ){
            scanf( "%d", &temp );
            if( flag ){
                flag = false; /* 输出变量格式为 %03d */
                if( temp >= A && temp <= B ) printf( "%03d", V );
                else printf( "%03d", temp );       
            }else{
                if( temp >= A && temp <= B ) printf( " %03d", V );
                else printf( " %03d", temp );                  
            }
        }
        flag = true; /* 每输出完一行时，需要重置末尾空格控制flag */
        printf( "\n");
        getchar();
    }
        

    return 0;
}
