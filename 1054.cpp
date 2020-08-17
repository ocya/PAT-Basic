/* 测试点2 未通过 */
#include <iostream>
#include <string>

using namespace std;

int main( int argc, const char *argv[] ){
    int N;
    double Sum = 0;
    string S;
    bool isLegal;
    int DotCount;
    int LegalCount = 0;
    scanf( "%d\n", &N );
    for( int i = 0 ; i < N ; i++ ){
        cin >> S;
        isLegal = true;
        DotCount = 0;
        
        if( S[0] != '-' &&  (S[0] < '0' ||  S[0] > '9') ) isLegal = false;
        if( S.length() == 1 && ( S[0] < '0' ||  S[0] > '9') ) isLegal = false;
        if( isLegal ){
            for( int j = 1 ; j < S.length() ; j++ ){
                if( S[j] < '0' || S[j] > '9' ){
                    if( S[j] == '.' ){
                        DotCount++;
                        // if( S[j-1] < '0' || S[j-1] > '9' )
                        //     isLegal = false;
                    } 
                    else{
                        isLegal = false;
                        break;
                    }
                }
            }
        }
        if( isLegal && DotCount < 2 ){

            if( DotCount == 0 ){/* 整数 */
               int Tmp = stoi( S );
               if( Tmp < -1000 || Tmp > 1000 ) isLegal = false;
               else{
                   Sum += (double)Tmp;
                   LegalCount++;
               }
            }else{
                if( S.find_first_of( '.' ) + 2 < ( S.length()-1 ) ) isLegal = false;
                else{
                    double Tmp = stod( S );
                    if( Tmp < -1000 || Tmp > 1000 ) isLegal = false;
                    else{
                        Sum += Tmp;
                        LegalCount++;
                    }
                    
                }                
            } 
        }else isLegal = false;
        if( !isLegal )  cout << "ERROR: " << S << " is not a legal number" << endl;
        

    } 

    cout << "The average of " << LegalCount;
    if( LegalCount == 0 ){
         cout << " numbers is Undefined" << endl;
    }else if( LegalCount == 1 ){
        cout << " number is "; /* 当只有一个是，输出的是 number */
        printf( "%.2f\n", Sum );
    }else {
        double Average = Sum / (double) LegalCount;
        cout <<" numbers is ";
        printf( "%.2f\n", Average );
    }


    return 0;
} 

/* AC */
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main( int argc, const char *argv[] ){

    int N;
    cin >> N;
    /* 测试点2，超长字符串 */
    char StrA[50], StrB[50];
    double Sum, Num, Average;
    int LegalCount = 0;
    
    Sum = 0;

    for( int i = 0 ; i < N ; i++ ){
        Num = 0;
        scanf( "%s", StrA );
        sscanf( StrA, "%lf", &Num ); /* 从StrA 中读取浮点数，赋值给Num */
        sprintf( StrB, "%.2f", Num );/* 将浮点数 Num,作为值写入字符串 StrB中 */
        bool isLegal = true;
        for( int j = 0 ; j < strlen( StrA ) ; j++ ) /* 如果StrA 是合法的字符串，StrA等于StrB */
            if( StrA[j] != StrB[j] )  isLegal = false;
        if( !isLegal || Num > 1000 || Num < - 1000 )
            cout << "ERROR: " << StrA << " is not a legal number" << endl; 
        else{
            LegalCount++;
            Sum += Num;
        }
    }
    if( LegalCount == 0 ) cout << "The average of 0 numbers is Undefined";
    else if( LegalCount == 1 ) printf( "The average of 1 number is %.2f", Sum );
    else{
        Average = Sum / LegalCount;
        cout << "The average of " << LegalCount << " numbers is ";
        printf( "%.2f", Average );
    }
    
    return 0;
}
