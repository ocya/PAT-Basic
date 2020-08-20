#include <iostream>
#include <vector>
#include <string>
#include <map>

#define MaxN 1000
#define MaxM 100

using namespace std;

struct Node{
    int Score, CorrectAns;
    int WrongCount[5];      /* 初始值默认为 0 ， C语言里不知道行不行 */
};

int main( int argc, const char *argv[] ){

    int N, M;
    int Hash[] = { 1, 2, 4, 8, 16 };
    int Option[MaxN][MaxM] = { 0 };
    scanf( "%d %d", &N, &M );
    vector<Node> Data( M );
    int Score, TotalCount, CorrectCount;
    char c;
    for( int i = 0 ; i < M ; i++ ){
        scanf( "%d %d %d", &Data[i].Score, &TotalCount, &CorrectCount );
        for( int j = 0 ; j < CorrectCount ; j++ ){
            scanf( " %c", &c );            /* 注意 %c 前面有一个空格 */
            Data[i].CorrectAns += Hash[ c - 'a' ];
        }
    }
    
    int OpCount;
    for( int i = 0 ; i < N ; i++ ){
        double Grade = 0;
        for( int j = 0 ; j < M ; j++ ){
            getchar();                         /* 取出缓冲区的什么？？ 不清楚 */
            scanf( "(%d", &OpCount );
            for( int k = 0 ; k < OpCount ; k++ ){
                scanf( " %c)", &c );            /* 注意 %c 前面有一个空格 */
                Option[i][j] += Hash[ c - 'a' ];
            }
            int el = Option[i][j] ^ Data[j].CorrectAns;         /* 异或 运算符，相同则全0 */
            if( el ){ /* 如果相异， 则 el 二进制对应为 1 的位置代表着错误选项 */
                if( ( Option[i][j] | Data[j].CorrectAns ) == Data[j].CorrectAns ){   /* 非常漂亮的一个判断， 或 运算符，有部分正确答案则有一半分数，有错误答案没有分数 */
                    Grade += Data[j].Score * 1.0 / 2;
                }
                for( int k = 0 ; k < 5 ; k++ )
                    if( el & Hash[k] ) Data[j].WrongCount[k] += 1;        /* 按位与运算，取出 el 的每一位，在二进制上为 1 的那一位，表示错选 */
            }else{
                Grade += Data[j].Score;
            }
        }
        printf( "%.1f\n", Grade );
    }
    int MaxCount = 0;
    for( int i = 0 ; i < M ; i++ )
        for( int j = 0 ; j < 5 ; j++ )
            MaxCount = ( MaxCount < Data[i].WrongCount[j] ) ? Data[i].WrongCount[j] : MaxCount;
    
    if( MaxCount == 0 ) printf( "Too simple\n" );
    else{
        for( int i = 0 ; i < M ; i++ )
            for( int j = 0 ; j < 5 ; j++ ){
                if( MaxCount == Data[i].WrongCount[j] )
                    printf( "%d %d-%c\n", MaxCount, i+1, 'a'+j );
            }        
    }
        
    

    return 0;
}
