#include <iostream>
#include <vector>

using namespace std;

int main( int argc, const char *argv[] ){
    int N;
    cin >> N;
    vector<int> Data( N+1 );

    for( int i = 1 ; i <= N ; i++ ) cin >> Data[i];
    
    
    for( int i = 1 ; i < N ; i++ ){
        for( int j = i+1 ; j <= N ; j++ ){
            /* 在 for 循环里面定义 Checklist, 是因为每次指定的 false(狼人）不同 */
            /* 在循环外面定义，会导致上一轮循环中定义的 false 未被初始化为 true */
            vector<bool> CheckList( N+1, true );
            vector<int> LiedIdx;
            CheckList[i] = CheckList[j] = false;
            /* 按顺序指定两个人为狼人，即置 CheckList 对应位为 false */
            /* 从1 ~ N 检查每个人的说谎情况 */
            for( int k = 1 ; k <= N ; k++ ){
                if( Data[k] < 0 && CheckList[ abs( Data[k] ) ] == true ) LiedIdx.push_back( k );
                if( Data[k] > 0 && CheckList[ Data[k] ] == false ) LiedIdx.push_back( k );
            }
            if( LiedIdx.size() == 2  && ( CheckList[ LiedIdx[0] ] !=  CheckList[ LiedIdx[1] ])){
                cout << i << ' ' << j << endl;
                return 0;
            }
                
        }
    }
    cout << "No Solution" << endl;

    return 0;
}

