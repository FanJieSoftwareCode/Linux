//使用pthread_create函数创建新线程
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include<unistd.h>
void *task(void*arg)
{
	//判断thread变量中的线程ID是否与pthread_self函数获取的线程ID相等；
	if(pthread_equal(*(pthread_t*)arg,pthread_self()))
	{
		printf("两种方式获取的线程编号相等\n");
	}
	else
	{
		printf("两种方式获取的线程编号不相等\n");
	}
	int i=0;
	for(i=0;i<10;i++)
	{
		printf("我是新创建出来的线程\n");
		sleep(1);
	}
	return NULL;
}
int main(void)
{
	//1.准备存储线程编号的变量
	pthread_t thread=0;
	//2.创建新线程，使用pthread_create函数
	//int errno=pthread_create(&thread,NULL,task,NULL);
	int errno=pthread_create(&thread,NULL,task,(void*)&thread);
	if(errno)
	{
		printf("pthread_create:%s\n",strerror(errno));
		exit(-1);
	}
	sleep(10);
	printf("子线程的线程编号是：%lu,主线程的线程编号是：%lu\n",thread,pthread_self());
	return 0;
}
