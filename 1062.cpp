#include <iostream>

using namespace std;

int gcd( int a, int b ){
    return b == 0 ? a : gcd( b, a % b );
}

int main( int argc, const char *argv[] ){

    int N1, M1, N2, M2, K;
    scanf( "%d/%d %d/%d %d", &N1, &M1, &N2, &M2, &K );

    if( N1 * M2 > N2 * M1 ){
        swap( N1, N2 );
        swap( M1, M2 );
    }
    bool isFirst = true;
    for( int i = 1 ; i < K ; i++ ){
        if( (i*M1 > N1*K) && (i*M2 < K*N2) ){
            if( gcd( i, K ) == 1 ){
                if( isFirst ){
                    isFirst = false;
                    cout << i << '/' << K;
                }else{
                    cout << ' ' << i << '/' << K;
                }
            }
        }
    }
    


    return 0;
}
