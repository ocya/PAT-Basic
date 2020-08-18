#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

int M, N, TOL;
vector<vector<int>> Data;
int Direction[8][2] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0} ,{1, 1} };
bool Judge( int A, int B );
int main( int argc, const char *argv[] ){

    cin >> M >> N >> TOL;
    Data.resize( N, vector<int>(M) );
    map<int, int> mapp;
    for( int i = 0 ; i < N ; i++ )
        for( int j = 0 ; j < M ; j++ ){
            /* cin 将导致超时 ？？？ */
            scanf( "%d", &Data[i][j]) ;
            mapp[ Data[i][j] ]++;
        }
    int Count = 0;
    int PosX, PosY;
    for( int i = 0 ; i < N ; i++ )
        for( int j = 0 ; j < M ; j++ ){
            if( mapp[ Data[i][j] ] == 1 && Judge( i, j ) == true ){
                Count++;
                PosX = i;
                PosY = j;
            }
        }

    if( Count == 0 )
        cout << "Not Exist";
    else if( Count > 1 ) 
        cout << "Not Unique";
    else{
        cout << '(' << PosY+1 << ", " << PosX+1 << "): " << Data[PosX][PosY];
    }
    
    

    return 0;
}

bool Judge( int A, int B ){
    for( int i = 0 ; i < 8 ; i++ ){
        int X = A +  Direction[i][0];
        int Y = B + Direction[i][1];
        if( X >= 0 && X < N && Y >= 0 && Y < M && abs( Data[A][B] - Data[X][Y] ) <= TOL ) 
            return false;
    }
    return true;
}

