
/* 用 cout 测试点3, 4 会超时 */
/* printf不能直接输出 string 类型的字符串，需要调用S.c_str() */
/* 在比较函数中，使用引用类型可以减少函数参数传递的开销 */
/* 
例如：       
    cin >> Order >> S;
    printf( "Case %d: %d %s\n", i+1, Order, S.c_str() );
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map> /* 用 map 会超时 */

using namespace std;

struct Node{
    string Id;
    int Grade;
};

vector<struct Node> Information;
vector<struct Node> Ans;

void Fun1( string S );
void Fun2( string S );
void Fun3( string S );
/* 在比较函数中，使用引用类型可以减少函数参数传递的开销 */
bool Compare1( struct Node &A, struct Node &B );
int main( int argc, const char *argv[] ){

    int N, M;
    cin >> N >> M;
    Information.resize( N );
    
    for( int i = 0 ; i < N ; i++ ){
        cin >> Information[i].Id >> Information[i].Grade;
    }

    string S;
    int Order;

    for( int i = 0 ; i < M ; i++ ){
        cin >> Order >> S;
        printf( "Case %d: %d %s\n", i+1, Order, S.c_str() );
        switch( Order ){
            case 1: Fun1( S ); break;
            case 2: Fun2( S ); break;
            case 3: Fun3( S ); break;
        }
    }


    return 0;
}

void Fun3( string S ){
    unordered_map<string,int> Count;
    for( int i = 0 ; i < Information.size() ; i++ ){
        if( (Information[i].Id).substr( 4, 6 ) == S ){
            Count[ (Information[i].Id).substr( 1, 3 ) ] += 1;
        }
    }
    /* map的迭代器和 vector构造器搭配使用 */
    for( auto iter : Count ){
        Ans.push_back( {iter.first, iter.second} );
    }
    if( Ans.size() == 0 ) printf( "NA\n" );
    else{
        sort( Ans.begin(), Ans.end(), Compare1 );
        for( int i = 0 ; i < Ans.size() ; i++ ){
            printf( "%s %d\n", Ans[i].Id.c_str(), Ans[i].Grade );
        }
    }

    Ans.clear();
}

void Fun2( string S ){
    int Count, Sum;
    Count = Sum  = 0;

    for( int i = 0 ; i < Information.size() ; i++ ){
        if( Information[i].Id.substr( 1, 3 ) == S ){
            Count++;
            Sum += Information[i].Grade;
        }
    }
    if( Count == 0 ) printf( "NA\n" );
    else printf( "%d %d\n", Count, Sum );
    
}

void Fun1( string S ){

    for( int i = 0 ; i < Information.size() ; i++ ){
        if( (Information[i].Id)[0] == S[0] )
            Ans.push_back( Information[i] );
    }
    if( Ans.size() == 0 ) printf( "NA\n" );
    else{
        sort( Ans.begin(), Ans.end(), Compare1 );
        for( int i = 0 ; i < Ans.size() ; i++ ){
            printf( "%s %d\n", Ans[i].Id.c_str(), Ans[i].Grade );
        }
    }
    Ans.clear();
}

bool Compare1( struct Node &A, struct Node &B ){
    return (A.Grade == B.Grade) ? A.Id < B.Id : A.Grade > B.Grade;
}
