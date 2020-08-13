#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main( int argc, const char *argv[] ){

    string Key, S;
    getline( cin, Key );
    getline( cin, S );

    for( int i = 0 ; i < S.length() ; i++ ){
        if( Key.find( toupper( S[i] )) != string::npos ) continue;
        if( isupper( S[i] ) && Key.find( '+' ) != string::npos ) continue;
        cout << S[i];
    }

    return 0;
}
