#include<omp.h>
#include<iostream>
using namespace std;

int main()
{
	int val=9;
#pragma omp parallel shared(val) 
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
