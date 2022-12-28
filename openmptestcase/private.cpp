#include<omp.h>
#include<iostream>
using namespace std;
// private 只是同时取个val的局部变量，连初始化都没有
int main()
{
	int val=9;
#pragma omp parallel private(val) 
	{
		if( 1&omp_get_thread_num() )
		{
			val*=(-1);
		}
		else
		{
			val-=1;
		}
		printf("from thread num=%d, cur val=%d\n", 
				omp_get_thread_num(), val);
	}

	printf("last val=%d\n", val);
	return 0;
}
