#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main( int argc, const char *argv[] ){

    int m, M, N;
    /* p的范围是 10^9 因此需要用long long 来保存 */
    /* 最后一个测试点 */
    long long p;
    vector<int> Data;
    cin >> N >> p;

    Data.resize( N );
    for( int i = 0 ; i < N ; i++ )
        cin >> Data[i];

    sort( Data.begin(), Data.end() );

    int Count, MaxCount;
    MaxCount = 0;
    int j = 0;
    for( int i = 0 ; i < N - MaxCount ; i++ ){
        while( Data[++j] <= Data[i]*p && j < N);
        Count = j - i;
        if( Count > MaxCount )
            MaxCount = Count; 
    }
    cout << MaxCount;
    return 0;
}
