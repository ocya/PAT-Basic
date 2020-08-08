#include <iostream>
// #include <iomanip>
#include <cmath>
using namespace std;

int main( int argc, const char *argv[] ){

    int N;
    int Radius, MaxRadius;
    int A, B;
    MaxRadius = 0;
    cin >> N;
    for( int i = 0 ; i < N ; i++ ){
        cin >> A >> B;
        Radius = A*A + B*B;
        if( Radius > MaxRadius ) MaxRadius = Radius;
    }
    printf( "%.2f", sqrt( MaxRadius ) );
    return 0;
}
