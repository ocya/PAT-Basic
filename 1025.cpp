#include <iostream>
#include <array>
#include <algorithm>

#define MaxN 100000

using namespace std;

int main( int argc, const char *argv[] ){

    int FirstAddress, N, K;
    array<int, MaxN> Address, Value, NextAddress;
    cin >> FirstAddress >> N >> K;

    int TmpAddress;
    for( int i = 0 ; i < N ; i++ ){
        cin >> TmpAddress;
        cin >> Value[TmpAddress] >> NextAddress[TmpAddress];
    }

    int Sum = 0;
    int P = FirstAddress;
    while( P != -1 ){
        Address[Sum++] = P;
        P = NextAddress[P];
    }

    for( int i = 0 ; i < Sum - Sum%K ; i += K )
        reverse( begin( Address ) + i, begin( Address ) + i + K );

    for( int i = 0 ; i < Sum - 1 ; i++ )
        printf( "%05d %d %05d\n", Address[i], Value[Address[i]], Address[i+1] );
    printf( "%05d %d -1", Address[Sum-1], Value[Address[Sum-1]] );
    

    return 0;
}
