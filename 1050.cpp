#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
bool Compare( int a, int b );
int main( int argc, const char *argv[] ){

    int N;
    int m, n;
    vector<int> Data;
    cin >> N;   
    Data.resize( N );
    n = m = sqrt( N );
    while( ( n * m ) != N ){
        m++;
        if( ( n*m ) > N ){
            n--;
            m = sqrt( N );
        }
    }
    vector< vector<int> > Ans(m, vector<int>(n) );
    for( int i = 0 ; i < N ; i++ )
        cin >> Data[i];
    sort( Data.begin(), Data.end(), Compare );
    int Level;
    Level = m/2 + m%2;
    int Idx = 0;
    for( int i = 0 ; i < Level ; i++ ){
        for( int j = i ; j <= n - 1 - i && Idx <= N-1 ; j++ )
            Ans[i][j] = Data[Idx++];
        for( int j = i + 1 ; j <= m - 2 -i && Idx <= N-1 ; j++ )
            Ans[j][n- 1 - i] = Data[Idx++];
        for( int j = n - 1 - i ; j >= i && Idx <= N-1 ; j-- )
            Ans[m - 1 - i][j] = Data[Idx++];          
        for( int j = m - 2 - i ; j >= i + 1 && Idx <= N-1 ; j-- )
            Ans[j][i] = Data[Idx++];
    }

    for( int i = 0; i < m ; i++ ){
        for( int j = 0 ; j < n ; j++ ){
            if( j != 0 ) cout << ' ';
            cout << Ans[i][j];
        }
        cout << endl;
    }

    return 0;
}

bool Compare( int a, int b ){
    return a>b;
}
