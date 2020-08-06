#include <iostream>
#include <string>
#include <array>
using namespace std;

int main( int argc, const char *argv[] ){

    array<string, 13> Earth2Mars{ "tret", "jan", "feb", 
        "mar", "apr", "may", "jun", "jly", "aug", 
        "sep", "oct", "nov", "dec" };
    array<string, 12> CarrierMars{ "tam", "hel", "maa", "huh", "tou", "kes", 
    "hei", "elo", "syy", "lok", "mer", "jou" };
    string Data;
    int N, Earth, Mars;
    cin >> N;
    getchar();
    for( int i = 0 ; i < N ; i++ ){
        getline( cin, Data );
        if( Data[0] >= '0' && Data[0] <= '9' ){
            /* 注意换行符和空格的输出 */
            Earth = stoi( Data );
            if( Earth < 13 ) cout << Earth2Mars[Earth] << endl;
            else {
                cout << CarrierMars[Earth/13 - 1];
                if( Earth % 13 != 0 )
                    cout << ' ' << Earth2Mars[Earth%13] << endl;
                else
                    cout << endl;
            }          
        }else{
            Mars = 0;
            if( Data.length() == 7 ){
                string Sub = Data.substr( 0, 3 );
                for( int Idx = 0 ; Idx < CarrierMars.size() ; Idx++ ){
                    if( Sub == CarrierMars[Idx] ){
                        Mars = 13 * ( Idx + 1 );
                        break;
                    }
                }
                Data = Data.substr( 4 );
            }
            for( int Idx = 0 ; Idx < Earth2Mars.size() ; Idx++ ){
                if( Data == Earth2Mars[Idx] ){
                    Mars +=  Idx;
                    break;
                }
            }
            if( Data != Earth2Mars[0] && Mars == 0 ){
                for( int Idx = 0 ; Idx < CarrierMars.size() ; Idx++ ){
                    if( Data == CarrierMars[Idx] ){
                        Mars = 13 * ( Idx + 1 );
                        break;
                    }
                }                
            }
            cout << Mars << endl;            
        }
    }
    

    return 0;
}
