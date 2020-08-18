#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define MaxN 10000

using namespace std;


struct Node{
    string Name;
    int Height;
};

bool Cmp( struct Node A, struct Node B );
int main( int argc, const char *argv[] ){

    int N, K, Count, Row;
    vector<struct Node> Data;

    cin >> N >> K;
    Data.resize( N );
    for( int i = 0 ; i < N ; i++ ){
        cin >> Data[i].Name >> Data[i].Height;
    }
    sort( Data.begin(), Data.end(), Cmp );

    Row = K;
    int Idx = 0;
    while( Row ){
        if( Row == K )
            Count = N - N / K * ( K - 1 );
        else
            Count = N/K;
        vector<string> Ans( Count );
        Ans[Count/2] = Data[Idx].Name;
        int j = Count/2 - 1;
        for( int i = Idx + 1 ; i < Idx + Count ; i += 2 )
            Ans[j--] = Data[i].Name;
        
        j = Count/2 + 1;
        for( int i = Idx+2 ; i < Idx + Count ; i += 2 )
            Ans[j++] = Data[i].Name;
        Idx += Count;
        Row --;
        for( int i = 0 ; i < Ans.size() ; i++ ){
            if( i != 0 ) cout << ' ';
            cout << Ans[i]; 
        }
        cout << endl;

        
    
    }
    return 0;
}

bool Cmp( struct Node A, struct Node B ){

    if( A.Height == B.Height )
        return A.Name < B.Name;
    else 
        return A.Height > B.Height;
}
