#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Node{
    string School;
    int B, A, T, Sum, Rank, Count;
};
void Standarlize( string &S );
bool Compare( Node A, Node B );
int main( int argc, const char *argv[] ){

    int N;
    map<string, struct Node> Data;
    cin >> N;

    string Id, School;
    int Score;
    for( int i = 0 ; i < N ; i++ ){
        cin >> Id >> Score >> School;
        Standarlize( School );
        switch( Id[0] ){
            case 'A': Data[School].A += Score; break;
            case 'B': Data[School].B += Score; break;
            case 'T': Data[School].T += Score; break;
        }
        Data[School].Count += 1;
        Data[School].School = School;
    }
    vector<struct Node> RankList;
    for( auto &i : Data ){
        i.second.Sum =(int)( i.second.A + i.second.B / 1.5 + i.second.T * 1.5 );
        RankList.push_back( Data[i.first] );
    }
    sort( RankList.begin(), RankList.end(), Compare );
    cout << RankList.size() << endl;
    int Rank = 1;
    for( int i = 0 ; i < RankList.size() ; i++ ){
        if( i == 0 ) RankList[i].Rank = 1;
        else{
            if( RankList[i].Sum != RankList[i-1].Sum ) Rank = i + 1;
            RankList[i].Rank = Rank;
        }
        cout << RankList[i].Rank << ' ' << RankList[i].School << ' ' << RankList[i].Sum << ' ' << RankList[i].Count << endl;
    }
    return 0;
}

void Standarlize( string &S ){

    for( int i = 0 ; i < S.length() ; i++ )
        S[i] = tolower( S[i]);

}

bool Compare( Node A, Node B ){
    if( A.Sum == B.Sum ){
        if( A.Count == B.Count ) return A.School < B.School;
        else return A.Count < B.Count;
    }else{
        return A.Sum > B.Sum;
    }
}
