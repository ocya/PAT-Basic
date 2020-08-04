#include <iostream>
#include <string>
#include <algorithm>

#define MaxN 1000

using namespace std;
int main(int argc, const char *argv[]){

    string A, B;
    bool isPrinted[96] = { false };
    getline( cin, A );
    getline( cin, B );
    
    for( int i = 0 ; i < A.length() ; i++ ){
        if( A[i] == ' ' && isPrinted[95] == false ){
            isPrinted[95] = true;
            cout << A[i];
        }
        if( A[i] != ' ' && isPrinted[A[i] - 32] == false ){
            isPrinted[A[i] - 32] = true;
            cout << A[i];
        }
    }
    for( int i = 0 ; i < B.length() ; i++ ){
        if( B[i] == ' ' && isPrinted[95] == false ){
            isPrinted[95] = true;
            cout << B[i];
        }
        if( B[i] != ' ' && isPrinted[B[i] - 32] == false ){
            isPrinted[B[i] - 32] = true;
            cout << B[i];
        }
    }        

    return 0;
}
