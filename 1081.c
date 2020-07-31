#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MaxLength 80

int Check( char Password[], int Len );

int main( int argc, const char *argv[]){
    int N;
    char Password[MaxLength+1];
    int Len;
    int Code;
    scanf( "%d\n", &N );
    for( int i = 0 ; i < N ; i++ ){
        gets( Password );
        Len = strlen( Password );
        Code = Check( Password, Len );
        switch( Code ){
            case 0: printf( "Your password is wan mei." ); break;
            case 1: printf( "Your password is tai duan le." ); break;
            case 2: printf( "Your password is tai luan le." ); break;
            case 3: printf( "Your password needs shu zi." ); break;
            case 4: printf( "Your password needs zi mu." );break;
        }
        printf( "\n" );
    }

    return 0;
}

int Check( char Password[], int Len ){
    int ret;
    if( Len < 6){
         ret = 1;
    }else{
        bool Digit, Character, Legal;
        Digit = Character = false;
        Legal = true;
        for( int i = 0 ; i < Len ; i++ ){
            if( ( Password[i] >= 'a' && Password[i] <= 'z' ) ||\
                (Password[i] >= 'A' && Password[i] <= 'Z' ) ){
                    Character = true;
            }else if( Password[i] >= '0' && Password[i] <= '9' ){
                Digit = true;
            }else if( Password[i] != '.' ){
                Legal = false;
            }
        }
        if( !Legal ) ret = 2;
        else if( Legal && Character && !Digit ) ret = 3;
        else if( Legal && !Character && Digit ) ret = 4;
        else if( Legal && Character && Digit ) ret = 0;
    }
    return ret;
}
