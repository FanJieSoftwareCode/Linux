//使用线程处理函数计算圆形的周长和面积
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>
void* task(void *arg)
{
	int ra=*(int*)arg;
	printf("圆形的周长是:%g\n",ra*2*3.14);
	printf("圆形的面积是:%g\n",ra*ra*3.14);
	return NULL;
}
int main(void)
{
	//1.申请动态内存
	int*radium=(int*)malloc(sizeof(int));
	if(NULL==radium)
	{
		perror("malloc"),exit(-1);
	}
	printf("动态内存申请成功\n");
	//读取用户的输入
	printf("请输入圆形的半径：\n");
	scanf("%d",radium);
	//2.创建子线程，计算圆形的周长和面积
	pthread_t thread=0;
	int res=pthread_create(&thread,NULL,task,(void*)radium);
	if(res)
	{
		printf("pthread_create:%s\n",strerror(res));
	}
	printf("子线程创建成功\n");
//	sleep(2);
	int errno=pthread_join(thread,NULL);
	if(0!=errno)
	{
		printf("pthread_join:%s\n",strerror(errno));
		exit(-1);
	}
//3.等待子线程结束，释放动态内存
	free(radium);
	radium=NULL;
	return 0;
}
