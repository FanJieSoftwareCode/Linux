//使用pthread_cancel函数取消指定的线程
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
void*task(void*arg)
{
	pthread_setcancelstate(PTHREAD_CANCEL_ENABLE,NULL);
	while(1)
	{
		printf("I am superman!\n");
		sleep(1);
	}
	return NULL;
}
void *task1(void*thread)
{
	printf("正在取消线程，请稍后....\n");
	sleep(3);
	//发送真正的取消请求
	pthread_cancel(*(pthread_t*)thread);
	printf("取消线程成功\n");
}
int main(void)
{
	//1.创建子线程，使用pthread_create函数
	pthread_t thread;
	pthread_create(&thread,NULL,task,NULL);
	//2.等待子线程结束
	pthread_t thread1;
	pthread_create(&thread1,NULL,task1,(void*)&thread);
	pthread_join(thread,NULL);
	return 0;
}
