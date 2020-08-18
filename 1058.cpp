#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Node{
    string Ans;
    int Socre;
    int WrongCount;
};

int main( int argc, const char *argv[] ){

    int N, M;
    scanf( "%d %d\n", &N, &M );
    
    vector<struct Node> Data( M );

    string S;
    for( int i = 0 ; i < M ; i++ ){
        getline( cin, S );
        Data[i].Socre = S[0] - '0';
        Data[i].Ans = S.substr( 6 );
        Data[i].WrongCount = 0;
    }
    int MaxWrongCount = 0;
    for( int i = 0 ; i < N ; i++ ){
        int TotalGrade = 0;
        getline( cin, S );
        for( int j = 0 ; j < M ; j++ ){
            if( Data[j].Ans == S.substr( 3, S.find_first_of( ')') - 3 )){
                TotalGrade += Data[j].Socre;
            }else{
                Data[j].WrongCount += 1;
                if( Data[j].WrongCount > MaxWrongCount ) MaxWrongCount = Data[j].WrongCount;
            }
            if( j != M - 1 )
                S = S.substr( S.find_first_of( ')' ) + 2 );
        }
        cout << TotalGrade << endl;
    }
    if( MaxWrongCount == 0 ) cout << "Too simple";
    else{
        cout << MaxWrongCount;
        for( int i = 0 ; i < M ; i++ ){
            if( Data[i].WrongCount == MaxWrongCount ){
                cout << ' ' << i+1;
            }
        }
    }
    

    return 0;
}
