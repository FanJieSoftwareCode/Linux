//使用pthread_exit函数结束一个线程
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
void*task(void*arg)
{
	int i=0;
	for(i=1;i<=20;i++)
	{
		if(i==10)
		{
			printf("\n");
			//终止当前线程
			pthread_exit((void*)15);
			//终止进程
		//	exit(0);
		}
		printf("%d ",i);
	}
	return NULL;
}
int main(void)
{
	pthread_t thread;
	pthread_create(&thread,NULL,task,NULL);
	int pi=0;
	pthread_join(thread,(void*)&pi);
	printf("pi=%d\n",pi);
	return 0;
}
