#include <stdio.h>
#include <stdbool.h>

int main( int argc, const char *argv[] ){
	int N,D,K;
	float e;
	int LowPowerCnt;/* 电量低于阈值的天数 */
	float Tmp;
	bool PossibileEmpty,Empty;/* 可能空 和 空 的标志位 */
	int PCnt,ECnt;/* 可能空的 和 空 的天数 */
	PCnt = ECnt = 0;
	scanf( "%d %f %d\n", &N, &e, &D );

	for( int i = 0 ; i < N ; i++ ){
		scanf( "%d", &K );
		LowPowerCnt = 0; /* 每一轮读取数据之前将统计低电量的天数置零 */
		for( int j = 0 ; j < K ; j++ ){
			scanf( "%f", &Tmp );
			if( Tmp < e )
				LowPowerCnt++;
		}
		/* 根据条件置位 标志位 */
		PossibileEmpty = ( LowPowerCnt >  K / 2 ) ? true : false;
		Empty = ( K > D  && PossibileEmpty ) ? true : false;
		if( Empty ) ECnt++;
		else if( PossibileEmpty ) PCnt++;	
		getchar();
	}
	/* 输出百分比，在 printf 中需要 '%%' 来输出 '%' */
	printf( "%.1f%% %.1f%%", (float)PCnt / N * 100, (float)ECnt / N * 100 );
}


