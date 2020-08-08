#include <iostream>
#include <array>
#include <iomanip>
#include <vector>

#define MaxId 100000
#define MaxM 10000
using namespace std;

int InCompare( const void *a, const void *b);
int main( int argc, const char *argv[] ){

    vector<int> Ans;
    array< int, MaxId> Couple = { -1 };
    int N, M;
    int A, B;
    cin >> N;
    for( int i = 0; i < N ; i++ ){
        cin >> A >> B;
        Couple[A] = B;
        Couple[B] = A;
    }
    cin >> M;
    // array< int, MaxM > Guests; 
    int Guests[MaxM];
    array<bool, MaxId> Appeared = { false };
    for( int i = 0 ; i < M ; i++ ){
        cin >> Guests[i];
        Appeared[ Guests[i] ] = true;
    }
    // qsort( Guests, Guests.size(), sizeof( Guests[0] ), InCompare );
    int DogCount = 0;
    qsort( Guests, M, sizeof( Guests[0] ), InCompare );
    for( int i = 0 ; i < M ; i++ ){
        if( Couple[ Guests[i] ] != -1 ){
            if( Appeared[ Couple[ Guests[i] ] ] == false ){
                DogCount++;
                Ans.push_back( Guests[i] );
            }           
        }else{
            DogCount++;
            Ans.push_back( Guests[i] );            
        }
    }
    cout << DogCount << endl;
    bool isFirst = true;
    for( int i = 0 ; i < Ans.size() ; i++ ){
        if( isFirst ){
            isFirst = false;
            cout << setfill( '0' ) << setw( 5 ) << Ans[i];
        }else cout << ' ' << setfill( '0' ) << setw( 5 ) <<  Ans[i] ;
    }
    return 0;
}

int InCompare( const void *a, const void *b){
    return *(const int *)a - *( const int* )b;
}
