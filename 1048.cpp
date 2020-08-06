#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main( int argc, const char *argv[] ){

    string A, B, C;
    cin >> A >> B;
    int Alen, Blen;
    Alen = A.length();
    Blen = B.length();
    reverse( A.begin(), A.end() );
    reverse( B.begin(), B.end() );
    if( Alen > Blen )
        B.append( Alen - Blen, '0' );
    else
        A.append( Blen - Alen, '0' );
    char str[14] = { "0123456789JQK" };
    for( int i = 0 ; i < B.length() ; i++ ){

        if( i%2 == 1 ){
            int Tmp = B[i] - A[i];
            if( Tmp < 0 ) Tmp += 10;
            C += str[Tmp];
        }else{
            C += str[ ( A[i] - '0' + B[i] - '0' )% 13 ];
        }
    }
    reverse( C.begin(), C.end() );
    cout << C << endl;


    return 0;
}
