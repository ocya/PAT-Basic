#include <iostream>
#include <cmath>

using namespace std;
int gcd( int a,int b ){
    return ( b == 0 ) ? a : gcd( b, a%b );
}

void func(int A,int B ){
    /* A 或 B 等于 0 时 */
    if( A * B == 0 ){
        printf( "%s", ( A == 0 ) ? "0" : "Inf" );
        return;
    }
    /* 判断是否有负号 */
    /* 不能用 A*B < 0 判断，因为相乘结果可能超过long long int范围，导致溢出，判断错误  */
    bool isNegative = ( (A < 0 && B > 0) || ( A > 0 && B < 0 ) ) ? true : false;
    
    /* 负号需要输出 (- */
    if( isNegative ) cout << "(-";
    /* 将 A, B 转化为正数处理 */
    A = abs( A );
    B = abs( B );
    /* 如果有分数则输出分数 */
    if( A/B != 0 ){
        cout << A/B;
        /* 如果不能整除，表示后边还有分数，需要输出空格 */
        if( A%B != 0 ) cout << ' ';
    } 
    /* 如果有分数部分，则输出分数 */
    if( A%B != 0 ){
        /* 找最大公倍数，进行化简 */
       int Tmp = gcd( A%B, B );
        cout<< A%B/Tmp << '/' << B/Tmp;
    }  

    /* 负号需要输出 ) */
    if( isNegative ) cout << ')';
}


int main( int argc, const char *argv[] ){

   int A1, B1, A2, B2;
   int A3, B3;
    scanf( "%d/%d %d/%d", &A1, &B1, &A2, &B2 );
    A3 = A1 * B2 + A2 * B1; B3 = B1 * B2;
    func( A1, B1 ); cout << " + "; func( A2, B2 ); cout << " = "; func( A3, B3 ); cout << endl;
    A3 = A1 * B2 - A2 * B1; B3 = B1 * B2;
    func( A1, B1 ); cout << " - "; func( A2, B2 ); cout << " = "; func( A3, B3 ); cout << endl;
    A3 = A1 *A2; B3 = B1 * B2;
    func( A1, B1 ); cout << " * "; func( A2, B2 ); cout << " = "; func( A3, B3 ); cout << endl;
    A3 = A1 * B2 ; B3 = B1 * A2;
    func( A1, B1 ); cout << " / "; func( A2, B2 ); cout << " = "; func( A3, B3 ); cout << endl;
    

    return 0;
}

