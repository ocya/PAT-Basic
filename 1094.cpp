#include <iostream>
#include <string>
#include <cmath>
using namespace std;
bool isPrime( int N );
int main(int argc, const char *argv[]){

    int L, K;
    bool isExist = false;
    string Number;
    cin >> L >> K >> Number;
    /* 
    循环中值条件是 i <= L - K ;或者写成  i <=(int) Number.length() - K;
        
     Number.length()返回的是unsigned int 型，
    减去 K 会变成很大的正数，将导致进入循环
    */
    for( int i = 0 ; i <= L - K ; i++ ){
        string SubKNumber = Number.substr( i, K );
        int SubNumber = stoi( SubKNumber );
        if( isPrime( SubNumber ) ){
            /* 注意这里输出的是字符串，因为需要输出前导0 */
            /* 直接输出整数将导致前导0未输出 */
            cout << SubKNumber ;
            isExist = true;
            break;
        }
    }
    if( ! isExist ) cout << 404;


    return 0;
}

bool isPrime( int N ){
    /* 要判断 0 和 1 的情形 */
    if( N < 2 ) return false;
    if( N == 2 ) return true;
    else if( N%2 == 0 ) return false;
    for( int i = 3 ; i <= sqrt( N ) ; i += 2 )
        if( N%i == 0 ) return false;
    return true;        
}
