/* 重复代码待优化 */

#include <iostream>
#include <string>
#include <array>

using namespace std;

int main( int argc, const char *argv[] ){

    array< string, 10> Hand{};
    array< string, 10> Eyes{};
    array< string, 10> Mouth{};
    int HandCount, EyesCount, MouthCount;
    string S;
    int Left,Right;
    HandCount = EyesCount = MouthCount = 0;
    getline( cin, S );
    for( int i = 0 ; i < S.length() ; i++ ){
        if( S[i] == '[' ){
            string Sub;
            for( int j = i+1 ; S[j] != ']'; j++ ){
                Sub += S[j];
            }
            Hand[HandCount++] = Sub;
        }
    }
    getline( cin, S );
    for( int i = 0 ; i < S.length() ; i++ ){
        if( S[i] == '[' ){
            string Sub;
            for( int j = i+1 ; S[j] != ']'; j++ ){
                Sub += S[j];
            }
            Eyes[EyesCount++] = Sub;
        }
    }
    getline( cin, S );
    for( int i = 0 ; i < S.length() ; i++ ){
        if( S[i] == '[' ){
            string Sub;
            for( int j = i+1 ; S[j] != ']'; j++ ){
                Sub += S[j];
            }
            Mouth[MouthCount++] = Sub;
        }
    }
    int K;
    scanf( "%d\n", &K );
    int Emoji[5];
    bool isExist;
    //cout << HandCount << EyesCount << MouthCount << endl;
    for( int i = 0 ; i < K ; i++ ){
        isExist = true;
        for( int j = 0 ; j < 5 ; j++ ){
            cin >> Emoji[j];
            Emoji[j] -= 1;
            if( Emoji[j] < 0 ) isExist = false; /* !!! 要不然监测点2、3过不了 */
            if( ( j == 0 || j == 4 ) && ( Emoji[j] >= HandCount ) )   
                isExist = false;
            if( ( j == 1 || j == 3 ) && ( Emoji[j] >= EyesCount ) )
                isExist = false;
            if( ( j == 2 ) && ( Emoji[j]>= MouthCount ) )
                isExist = false;
        }
        if( !isExist ) cout << "Are you kidding me? @\\/@" << endl;
        else{ 
            cout << Hand[ Emoji[0] ] << '(' << Eyes[ Emoji[1] ]
             << Mouth[ Emoji[2] ] << Eyes[ Emoji[3] ] << ')'
             << Hand[ Emoji[4] ] << endl;
            
        }
    }
    return 0;
}


