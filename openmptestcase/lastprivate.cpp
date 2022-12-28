#include<omp.h>
#include<iostream>
using namespace std;
// firstprivate 取个val的局部变量，同时还初始化, 但是不把数据赋值给原始的val
// lastprivate用来实现在退出并行区域时将私有变量的值赋给共享变量
int main()
{
	int val=9;
#pragma omp parallel  for lastprivate(val) 
	for(int i=0; i<5; ++i )
	{
		if( 1&i )
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
