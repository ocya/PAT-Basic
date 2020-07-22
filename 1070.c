#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MaxSize 10000
#define NegInfinity -65536
typedef int ElementType;
typedef int Position;

typedef struct HNode *Heap;
struct HNode{
    int Capacity;
    int CurrentSize;
    ElementType *Data;
};

Heap CreatEmptyMinHeap( int Size );
void BuildMinHeap( Heap H );
void PercDown( Heap H, Position P );
ElementType DeleteMinHeap( Heap H );
void InsertMinHeap( Heap H, ElementType Item );
int main( int argc, const char *argv[]){
    
    int N;
    ElementType Sum;
    scanf( "%d\n", &N );
    Heap H = CreatEmptyMinHeap( N );
    for( int i = 1 ; i <= N ; i++ )
        scanf( "%d", &H->Data[i] );
    BuildMinHeap( H );
    while( H->CurrentSize != 1 ){
        Sum = 0;
        Sum += DeleteMinHeap( H ) + DeleteMinHeap( H );
        Sum /= 2;
        InsertMinHeap( H, Sum );
    }
    printf( "%d", H->Data[1] );

    return 0;
    
}

Heap CreatEmptyMinHeap( int Size ){
    Heap H = ( Heap )malloc( sizeof(struct HNode) );
    H->CurrentSize = Size;
    H->Capacity = MaxSize;
    H->Data = (ElementType *)malloc(sizeof(ElementType)*(H->CurrentSize));
    H->Data[0] = NegInfinity;
    return H;
}

void BuildMinHeap( Heap H ){
    Position P = H->CurrentSize / 2;
    for( ; P > 0 ; P-- )
        PercDown( H, P );
}


void PercDown( Heap H, Position P ){
    ElementType Item = H->Data[P];
    Position Parent,Child;
    for( Parent = P ; Parent * 2 <= H->CurrentSize ; Parent = Child ){
        Child = Parent*2;
        if( Child != H->CurrentSize && H->Data[Child] > H->Data[Child+1] )
            Child++;
        if( Item > H->Data[Child] ) H->Data[Parent] = H->Data[Child];
        else break;
    }
    H->Data[Parent] = Item;
}
ElementType DeleteMinHeap( Heap H ){
    if( H->CurrentSize > 0 ){
        ElementType Item = H->Data[1];
        H->Data[1] = H->Data[H->CurrentSize--];
        PercDown( H, 1 );
        return Item;
    }
}

void InsertMinHeap( Heap H, ElementType Item ){
    if( H->CurrentSize != H->Capacity ){
        H->Data[++H->CurrentSize] = Item;
        Position P;
        for( P = H->CurrentSize ; H->Data[P/2] > Item ; P /= 2 )
            H->Data[P] = H->Data[P/2];
        H->Data[P] = Item;
    }
}

/* 快速排序实现 */
// int CmpInc( const void *A, const void *B );
// int main( int argc, const char *argv[]){
    
//     int N;
//     int Sum = 0;
//     scanf( "%d\n", &N );
//     int Data[N];
//     for( int i = 0 ; i < N ; i++ )
//         scanf( "%d", &Data[i] );
//     qsort( Data, N, sizeof(int), CmpInc );
    
//     for( int i = 0 ; i < N ; i++ ){
//         if( i == 0 ) Sum += Data[i];
//         else Sum = ( Sum  + Data[i] ) / 2;
//     }
        
//     printf( "%d", Sum );
//     return 0;
    
// }

// int CmpInc( const void *A, const void *B ){
//     return *(int *)A - *(int *)B;
// }
