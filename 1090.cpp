#include <iostream>
#include <map>
#include <vector>
#include <set>


using namespace std;

int main( int argc, const char *argv[] ){

    int N, M, K;
    map<int, vector<int>> ConflictPair;
    cin >> N >> M;
    int A, B;
    for( int i = 0 ; i < N ; i++ ){
        cin >> A >> B;
        ConflictPair[A].push_back( B );
        ConflictPair[B].push_back( A );
    }
    map<int,int> CheckList;
    int Check;
    for( int i = 0 ; i < M ; i++ ){
        cin >> K;
        for( int j = 0 ; j < K ; j++ ){
            cin >> Check;
            if( ConflictPair.find( Check ) != ConflictPair.end() ){
                CheckList[Check] += 1;
            }
        }
        bool isSafe = true;
        for( auto iter = ConflictPair.begin() ; iter != ConflictPair.end() ; ++iter ){
            if( !isSafe ) break;
            for( int j = 0 ; j < (iter->second).size() ; j++ ){
                if( !isSafe ) break;
                if( CheckList[iter->first] != 0 && CheckList[ (iter->second)[j] ] != 0 ) isSafe = false;
            }
        }
        if( isSafe ) cout << "Yes" << endl;
        else cout << "No" << endl;
        CheckList.clear();
    }

    

    return 0;
}
