//使用信号量
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
char *buf[5];
int pos;
//1.定义互斥量
//pthread_mutex_t mutex;
//1.定义信号量
sem_t sem;
void*task(void*pv)
{
	//使用互斥量进行加锁
	//pthread_mutex_lock(&mutex);
	//获取一个信号量，信号量的数值减1
	sem_wait(&sem);
	//访问共享资源
	buf[pos]=(char*)pv;
	sleep(1);
	pos++;
	//使用互斥量进行解锁
	//pthread_mutex_unlock(&mutex);
	//释放一个信号量
	sem_post(&sem);
}
int main(void)
{
	//2.初始化互斥量
	//pthread_mutex_init(&mutex,NULL);
	//2.初始化信号量
	sem_init(&sem,0,/*线程的个数*/1);
	//创建子线程，存放字符串“zhangfei”到数组中
	pthread_t thread;
	pthread_create(&thread,NULL,task,(void*)"zhangfei");
	pthread_t thread2;
	pthread_create(&thread2,NULL,task,(void*)"guanyu");
	//
	pthread_join(thread,NULL);
	pthread_join(thread2,NULL);
	//
	int i=0;
	for(i=0;i<pos;i++)
	{
		printf("%s\n",buf[i]);
	}
	//如果不再使用，则销毁互斥量
	//pthread_mutex_destroy(&mutex);
	//如果不再使用，则销毁信号量
	sem_destroy(&sem);
	return 0;
}

