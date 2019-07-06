//使用pthread_create创建子线程
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
void*task(void*arg)
{
	int i=1;
	//静态局部变量
//	static int sum=0;
	int sum=0;
	for(i=1;i<=100;i++)
	{
		sum=sum+i;
	}
	//永远不要返回一个局部变量的地址
	//return (void*)&sum;
	return (void*)sum;
}
int main(void)
{
	//1.创建子线程，计算1~100的和
	pthread_t thread;
	//int *sum=NULL;
	int sum=0;
	int errno=pthread_create(&thread,NULL,task,NULL);
	if(errno)
	{
		printf("pthread_create:%s\n",strerror(errno));
		exit(-1);
	}
	//使用pthread_detach函数设置线程为分离状态
	errno=pthread_detach(thread);
	if(errno)
	{
		printf("pthread_detach:%s\n",strerror(errno));
		exit(-1);
	}
	//2.等待子线程结束，打印子线程结果
	//errno=pthread_join(thread,(void**)&sum);
	errno=pthread_join(thread,(void**)&sum);
	if(errno)
	{
		printf("pthread_join:%s\n",strerror(errno));
		exit(-1);
	}
	//printf("计算结果是:%d\n",*sum);
	printf("sum=%d\n",sum);
	return 0;
}
