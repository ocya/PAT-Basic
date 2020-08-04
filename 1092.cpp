#include <iostream>
#include <string>
#include <algorithm>

#define MaxN 1000

using namespace std;
int main(int argc, const char *argv[]){
    int N, M;
    int TotalCount[MaxN] = { 0 };
    int  MaxTotalCount = 0;
    bool isFirst = true;
    cin >> N >> M ;   
    for( int i = 0 ; i < M ; i++ ){
        int Count;
        for( int j = 0 ; j < N ; j++ ){
            cin >> Count;
            TotalCount[j] += Count;
            MaxTotalCount = max( MaxTotalCount, TotalCount[j] );
        }
    }
    
    cout << MaxTotalCount << endl;
    for( int i = 0 ; i < N ; i++ ){
        if( TotalCount[i] == MaxTotalCount ){
            if( isFirst ){
                isFirst = false;
                cout << i+1;
            }else cout << ' ' << i+1;
        }
    }
        

    return 0;
}
