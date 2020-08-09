#include <iostream>
#include <string>

using namespace std;

int main( int argc, const char *arg[] ){

    int N;
    string S;
    cin >> S >> N;
    int Idx; /* 一直向前移动 */
    for( int i = 1 ; i < N ; i++ ){
        string Tmp;
        for( int j = 0 ; j < S.length() ;  j = Idx ){
            for(  Idx = j ; Idx < S.length() && S[Idx] == S[j] ; Idx++ );
                Tmp += S[j] + to_string( Idx-j );
        }
        S = Tmp;
    }
    cout << S;
    return 0;
}
