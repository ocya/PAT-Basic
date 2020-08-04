#include <iostream>
#include <string>
#include <algorithm>

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
//#include <iostream>
// #include <string>
// #include <algorithm>



// using namespace std;
// int main(int argc, const char *argv[]){

//     string A, B;
//     bool isPrinted[200] = { false };
//     getline( cin, A );
//     getline( cin, B );
//     string S = A + B;
//     for( int i = 0 ; i < S.length() ; i++ ){
//         if( isPrinted[ S[i] ] == false ) cout << S[i];
//         isPrinted[ S[i] ] = true;
//     }

//     return 0;
// }
