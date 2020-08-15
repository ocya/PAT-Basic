#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main( int argc, const char *argv[] ){

    int N;
    vector<int> Data;
    vector<int> Sorted;
    vector<int> Ans;
    cin >> N;
    Data.resize( N );
    
    for( int i = 0 ; i < N ; i++ )
        cin >> Data[i];
    Sorted = Data;
    sort( Sorted.begin(), Sorted.end() );
    int Max = 0;
    for( int i = 0 ; i < N ; i++ ){
        if( Sorted[i] == Data[i] && Data[i] >= Max ){
            Ans.push_back( Data[i] );
        }
        if( Data[i] > Max ){
            Max = Data[i];
        }
    }
    cout << Ans.size() << endl;
    for( int i = 0 ; i < Ans.size() ; i++ ){
        if( i != 0 ) cout << ' ';
        cout << Ans[i];
    }
    if( Ans.size() == 0 ) cout << endl;
    

    return 0;
}



// void _QSort( vector<int> &Data, int Left, int Right ){
//     int Pivot, Cutoff, Low, High;
//     if( Cutoff <= Right - Left ){
//         Pivot = Median3( Data, Left, Right );
//         Low = Left, High = Right-1;
//         while( 1 ){
//             while( Data[++Low] < Pivot );
//             while( Data[--High] > Pivot );
//             if( Low < High ) swap( Data[Low], Data[High] );
//             else break;
//         }
//         swap( Data[Low], Data[Right-1] );
//         _QSort( Data, Left, Low-1 );
//         _QSort( Data, Low+1, Right );
//     }else{
//         InsertionSort( Data, Left, Right );
//     }

// }

// void InsertionSort( vector<int> &Data, int Left, int Right ){
//     int TempData;
//     int i, j;
//     for(i = Left+1 ; i <= Right ; i++ ){
//         TempData = Data[i];
//         for(j = i ; j > Left && Data[j-1] > TempData ; j-- )
//             Data[j] = Data[j-1];
//         Data[j] = TempData;
//     }
// }

// int Median3( vector<int> &Data, int Left, int Right ){
    
//     int Center = ( Right + Left ) / 2;
//     if( Data[Left] > Data[Center] ) swap( Data[Left], Data[Right] );
//     if( Data[Left] > Data[Right] ) swap( Data[Left], Data[Right] );
//     if( Data[Center] > Data[Right] ) swap( Data[Center], Data[Right] );

//     swap( Data[Center], Data[Right-1] );
//     return Data[Right-1]; 
// }
