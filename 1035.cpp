#include <iostream>
#include <algorithm>

using namespace std;

int main( int argc, const char *argv[] ){

    int N, a[100], b[100], i, j;
    cin >> N;
    for( int i = 0 ; i < N ; i++ )
        cin >> a[i];
    for( int i = 0 ; i < N ; i++ )
        cin >> b[i];
    for( i = 0 ; i < N-1 && b[i] <= b[i+1] ; i++ );
    for( j = i+1 ; a[j] == b[j] && j < N ; j++ );
    if( j == N ){
        cout << "Insertion Sort" << endl;
        sort( a, a + i + 2 );
    }else{
        cout << "Merge Sort" << endl;
        int length = 1;
        bool isOK = false;
        while( !isOK ){
            isOK = true;
            for( int i = 0 ; i < N ; i++ ){
                if( a[i] != b[i] )
                    isOK = false;
            }
            length *= 2;
            for( i = 0 ; i < N / length ; i++ )
                sort( a + i * length, a + ( i + 1 )*length  );
            sort( a + i*length, a + N );
        }
    }
    for( i = 0 ; i < N ; i++ ){
        if( i != 0 ) cout << ' ';
        cout << a[i];
    }

    return 0;
}
