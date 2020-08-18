#include <iostream>
#include <string>

using namespace std;

int main( int argc, const char *argv[] ){

    string Correct, S;
    int N;
    cin >> Correct >> N;
    getchar();
    int Count = 0;
    while(1) {
        /* 用 cin >> S 会通不过测试点2 和 5  */
        getline( cin, S );
        if( S == "#" ) break;
        Count++;
        if( S == Correct ){
            cout << "Welcome in" << endl;
            break;
        } else{
            cout << "Wrong password: " << S << endl;
            if( Count == N ){
                cout << "Account locked" << endl;
                break;
            }
                
        }
    }


    return 0;
}
