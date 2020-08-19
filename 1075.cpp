#include <iostream>
#include <vector>
#include <array>


#define MaxN 100000


int main( int argc, const char *argv[] ){

    int First, N, K;
    std::array<int, MaxN> Address, Value, Next;
    std::vector<int> Front, Mid, Rear;
    std::cin >> First >> N >> K;
    int TempAddress;

    for( int i = 0 ; i < N ; i++ ){
        std::cin >> TempAddress;
        std::cin >> Value[TempAddress] >> Next[TempAddress]; 
    }
    int Idx = 0;
    while( First != -1 ){
        if( Value[First] < 0 ) Front.push_back( First );     
        else if( Value[First] >= 0 && Value[First] <= K ) Mid.push_back( First );
        else Rear.push_back( First );
        First = Next[First];
    }
    for( auto i : Mid )
        Front.push_back( i );
    for( auto i : Rear )
        Front.push_back( i );
    
    for( int i = 0 ; i < Front.size(); i++ ){
        if( i != Front.size() - 1 )
            printf( "%05d %d %05d\n",Front[i] ,Value[ Front[i] ], Front[ i+1 ] );
        else
            printf( "%05d %d -1\n",Front[i] ,Value[ Front[i] ] );
    }
 
}
