#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main( int argc, const char *argv[] ){

    string Table;
    string A, B;
    string Ans;
    getline( cin, Table );
    getline( cin, A );
    getline( cin, B );

    reverse( Table.begin(), Table.end() );
    reverse( A.begin(), A.end() );
    reverse( B.begin(), B.end() );
    Table.append( 1, '0' );
    int LenA = A.length();
    int LenB = B.length();
    ( LenA < LenB ) ?  A.append( LenB - LenA, '0' ) : B.append( LenA - LenB, '0' );

    int Carrier = 0;
    int Value;
    int TableValue;
    bool isZero = true;/* 判断最后结果是不是全部为 0  */
    for( int i = 0 ; i < A.length() ; i++ ){
        Value = A[i] - '0' + B[i] - '0' + Carrier;
        if( Table[i] != '0' ) TableValue = Table[i] - '0';
        else TableValue = 10;
        Carrier = Value / TableValue;
        Value %= TableValue;
        if( Value != 0 ) isZero = false;
        Ans += to_string( Value );
    }
    /* 最高位有进位产生 */
    if( Carrier != 0 ){
        isZero = false;
        Ans += to_string( Carrier );
    }
    if( isZero ){
        cout << '0' << endl;
    }else{
        reverse( Ans.begin(), Ans.end() );  
        cout << Ans.substr( Ans.find_first_not_of( '0' ) ) << endl;
    }

    

    return 0;
}
// 30527
// 00000
// 000
