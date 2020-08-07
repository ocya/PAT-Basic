#include <iostream>
#include <cmath>

using namespace std;

int main( int argc, const char *argv[] ){

    double R1, P1, R2, P2;
    double A, B;
    cin >> R1 >> P1 >> R2 >> P2;
    A = R1 * cos( P1 ) * R2 * cos( P2 ) - R1 * sin( P1 ) * R2 * sin( P2 );
    B = R1 * cos( P1 ) * R2 * sin( P2 ) + R2 * cos( P2 ) * sin( P1 ) * R1;
    if( fabs( A ) < 0.005 ) printf( "0.00" );
    else printf( "%.2f", A );
    if( fabs( B ) < 0.005 ) printf( "+0.00" );
    else{
        if( B >= 0 ) printf( "+");
        printf( "%.2f", B );
    }  

    printf( "i" );
    return 0;
}
