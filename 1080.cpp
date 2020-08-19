#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

typedef struct Node Data;
struct Node{
    std::string Name;
    int PGrade, MGrade, NGrade, Total;
};
bool Compare( Data A, Data B );
int main( int argc, const char *argv[] ){

    int P, M, N;
    std::map<std::string,Data> Grade;

    std::cin >> P >> M >> N;
    std::string S;
    int Score;
    for( int i = 0 ; i < P ; i++ ){
        std::cin >> S >> Score;
        if( Score >= 200 ){
            Data Temp;
            Temp.Name = S;
            Temp.PGrade = Score;
            Temp.NGrade = -1;
            Temp.MGrade = -1;
            Grade[S] = Temp;
        }
    }
 
    for( int i = 0 ; i < M ; i++ ){
        std::cin >> S >> Score;
        if( Grade.find( S ) != Grade.end() ){
            Grade[S].MGrade = Score;
        }
    }
    for( int i = 0 ; i < N ; i++ ){
        std::cin >> S >> Score;
        if( Grade.find( S ) != Grade.end() ){
            Grade[S].NGrade = Score;
        }
    }
    std::vector<Data> Ans;
    int Gmid, Gfinal;
    for( auto i : Grade ){
        Gmid = i.second.MGrade;
        Gfinal = i.second.NGrade;
        if( Gmid > Gfinal ){
            int total = Gmid * 4 + Gfinal * 6;
            i.second.Total = ( total % 10 >= 5 )? total/10+1 : total/10;
        } 
        else i.second.Total = Gfinal;
        if( i.second.Total >= 60 )
            Ans.push_back( i.second );        
    }
    sort( Ans.begin(), Ans.end(), Compare );
    for( int i = 0 ; i < Ans.size() ; i++ ){
        std::cout << Ans[i].Name << ' ' << Ans[i].PGrade << ' ' \
                    << Ans[i].MGrade << ' ' << Ans[i].NGrade << ' '\
                     << Ans[i].Total << std::endl;
    }
    
    return 0;
 
}

bool Compare( Data A, Data B ){
    if( A.Total == B.Total ){
        return ( A.Name < B.Name );
    }else{
        return ( A.Total > B.Total );
    }
}

/*

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

typedef struct Node Data;
struct Node{
    std::string Name;
    int PGrade, MGrade, NGrade, Total;
};
bool Compare( Data A, Data B ){
    return A.Total != B.Total ? A.Total > B.Total : A.Name < B.Name;
}
int main( int argc, const char *argv[] ){

    int P, M, N, Count, Score;
    std::string S;
    std::map<std::string,int> Idx;
    std::vector<Data> GradeInfo;

    std::cin >> P >> M >> N;
    Count = 0;
    for( int i = 0 ; i < P ; i++ ){
        std::cin >> S >> Score;
        if( Score >= 200 ){
           GradeInfo.push_back( Node{ S, Score, -1, -1, 0 } );
           Idx[S] = Count++;
        }
    }
    for( int i = 0 ; i < M ; i++ ){
        std::cin >> S >> Score;
        if( Idx.find( S ) != Idx.end() ) GradeInfo[ Idx[S] ].MGrade = Score;
    }
    for( int i = 0 ; i < N ; i++ ){
        std::cin >> S >> Score;
        if( Idx.find( S ) != Idx.end() ){
            GradeInfo[ Idx[S] ].NGrade = Score;
        } 
    }
    std::vector<Data> Ans;
    int Gmid, Gfinal;
    for( auto i : GradeInfo ){
        Gmid = i.MGrade;
        Gfinal = i.NGrade;
        i.Total = ( Gmid > Gfinal ) ? ( int )( Gmid * 0.4 + Gfinal * 0.6 + 0.5 ) : Gfinal ;
        if( i.Total >= 60 ) Ans.push_back( i );        
    }
    sort( Ans.begin(), Ans.end(), Compare );
    for( int i = 0 ; i < Ans.size() ; i++ ){
        std::cout << Ans[i].Name << ' ' << Ans[i].PGrade << ' ' \
                    << Ans[i].MGrade << ' ' << Ans[i].NGrade << ' '\
                     << Ans[i].Total << std::endl;
    }
    
    return 0;
}



*/
