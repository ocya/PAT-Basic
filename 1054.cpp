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

/*

- -.123

*/
