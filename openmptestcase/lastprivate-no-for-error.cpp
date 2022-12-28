#include<omp.h>
#include<iostream>
using namespace std;
// firstprivate 取个val的局部变量，同时还初始化, 但是不把数据赋值给原始的val
// lastprivate用来实现在退出并行区域时将私有变量的值赋给共享变量
/*lastprivate的意思是将“相关循环的顺序最后一次迭代，
或词汇上最后一个节构造[…]分配给原始列表项。”
因此，对于纯平行构造来说，它没有任何意义。
使用“退出并行构造的最后一个线程”这样的含义不是一个好主意——这将是一个竞争条件。
*/
int main()
{
	int val=9;
#pragma omp parallel lastprivate(val) 
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
