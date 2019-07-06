#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
char *buf[5];
int pos;
//1.定义互斥量
pthread_mutex_t mutex;

void*task(void*pv)
{
	//使用互斥量进行加锁
	pthread_mutex_lock(&mutex);
	//访问共享资源
	buf[pos]=(char*)pv;
	sleep(1);
	pos++;
	//使用互斥量进行解锁
	pthread_mutex_unlock(&mutex);
}
int main(void)
{
	//2.初始化互斥量
	pthread_mutex_init(&mutex,NULL);
	//创建子线程，存放字符串“zhangfei”到数组中
	pthread_t thread;
	pthread_create(&thread,NULL,task,(void*)"zhangfei");
	pthread_t thread2;
	pthread_create(&thread2,NULL,task,(void*)"guanyu");
	pthread_t thread3;
	pthread_create(&thread3,NULL,task,(void*)"liubei");
	//
	pthread_join(thread,NULL);
	pthread_join(thread2,NULL);
	pthread_join(thread3,NULL);
	//
	int i=0;
	for(i=0;i<pos;i++)
	{
		printf("%s\n",buf[i]);
	}
	//如果不再使用，则销毁互斥量
	pthread_mutex_destroy(&mutex);
	return 0;
}

