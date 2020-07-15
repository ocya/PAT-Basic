#include <stdio.h>
#include <math.h>
int main( int argc, const char *argv[] ){

	int N;
	scanf( "%d\n", &N );
	double temp;
	long long  Last = 0; /* Last 为读入新元素后需要累加的增量 */
	long long  sum  = 0; /* sum 保存累加和 */
	
	for( int i = 1 ; i <= N ; i++ ){
		scanf( "%lf", &temp ); /* 直接用 double 类型计算会损失精度 */
		Last += ( long long )( temp * 1000 ) * i;
		sum += Last;
	}
	
	printf( "%.2lf", sum / 1000.0); /* 除以1000.0 转换成原浮点数 */
	return 0;
}

