//使用pthread_join函数获取目标线程的退出状态
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
void *task(void *pv)
{
	char*pc="hello";
	return (void*)pc;
}
int main(void)
{
	//1.创建子线程，使用pthread_create函数
	pthread_t thread;
	int errno=pthread_create(&thread,NULL,task,NULL);
	if(errno)
	{
		printf("pthread_create:%s\n",strerror(errno));
		exit(-1);
	}
	//2.等待子线程结束，并获取退出状态信息
	char*ps=NULL;
	errno=pthread_join(thread,(void**)&ps);
	if(errno)
	{
		printf("pthread_join:%s\n",strerror(errno));
		exit(-1);
	}
	printf("子线程的退出状态信息是：%s\n",ps);//hello
	return 0;
}
