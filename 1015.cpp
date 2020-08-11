#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct Data Student;
struct Data{
    int Id;
    int Quality;
    int Ability;
    int TotalGrade;
};

void SortAndDisp( vector<Student> &Type );
bool Compare( Student A, Student B );
int main( int argc, const char *argv[] ){
    int N, L, H;
    vector<Student> Type1, Type2, Type3, Type4;
    scanf( "%d %d %d\n", &N, &L, &H );
    for( int i = 0 ; i < N ; i++ ){
        Student Tmp;
        scanf( "%d %d %d", &Tmp.Id, &Tmp.Quality, &Tmp.Ability );
        Tmp.TotalGrade = Tmp.Ability + Tmp.Quality;
        if( Tmp.Quality >= H && Tmp.Ability >= H ) Type1.push_back( Tmp );
        else if( Tmp.Quality >= H && Tmp.Ability >= L ) Type2.push_back( Tmp );
        else if( Tmp.Ability >= L && Tmp.Quality >= L  && Tmp.Quality >= Tmp.Ability ) Type3.push_back( Tmp );
        else if( Tmp.Ability >= L && Tmp.Quality >= L ) Type4.push_back( Tmp );
    }
    int M = Type1.size() + Type2.size() + Type3.size() + Type4.size();
    cout << M << endl;
    SortAndDisp( Type1 );
    SortAndDisp( Type2 );
    SortAndDisp( Type3 );
    SortAndDisp( Type4 );
    return 0;
}

void SortAndDisp( vector<Student> &Type ){
    if( Type.size() != 0 ){
        sort( Type.begin(), Type.end(), Compare );
        for( int i = 0 ; i < Type.size() ; i++ )
            cout << Type[i].Id << ' ' << Type[i].Quality << ' ' << Type[i].Ability  << endl;    
    }

}


bool Compare( Student A, Student B ){
    bool K;
    if( A.TotalGrade == B.TotalGrade ){
        if( A.Quality == B.Quality ){
            if( A.Id < B.Id ) K = true;
            else K = false;
        }else{
            if( A.Quality > B.Quality ) K = true;
            else K = false;
        }
    }else{
        if( A.TotalGrade > B.TotalGrade ) K = true;
        else K = false;
    }
    return K;
}

