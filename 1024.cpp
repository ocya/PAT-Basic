#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main( int argc, const char *argv[] ){
    
    string Data;
    cin >> Data;
    int EIdx = Data.find_last_of( 'E' );
    string Number = Data[1] +  Data.substr( 3, EIdx - 3);
    string SZero;
    int Exponent = stoi( Data.substr( EIdx+1 ));
    if( Data[0] == '-' ) cout << Data[0];
    if( Exponent < 0 ){
        cout << "0.";
        for( int i = 0 ; i < abs( Exponent ) - 1 ; i++ ) cout << '0';
        cout << Number;
    }else{
        cout << Number[0];
        int i, Cnt = 0;
        for( i = 1 ; i < Number.length() && Cnt < Exponent ; i++ , Cnt++ ) cout << Number[i];
        if( i == Number.length() ){
            for( int j = Cnt ; j < Exponent ; j++ ) cout << '0';
        }else{
            cout << '.';
            for( int j = i; j < Number.length() ; j++ )
                cout << Number[j];
        }
    }



    return 0;
}
