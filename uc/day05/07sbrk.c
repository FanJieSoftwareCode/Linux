//使用sbrk函数调整动态内存的大小

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
	//使用sbrk函数申请一个int类型大小的空间
	void *p1=sbrk(sizeof(int));
	if((void*)-1==p1){
		perror("sbrk"),exit(-1);
	}
	void *p2=sbrk(sizeof(int));
	if((void*)-1==p2){
		perror("sbrk"),exit(-1);
	}
	void *p3=sbrk(sizeof(int));
	if((void*)-1==p3){
	perror("sbrk"),exit(-1);
	}
	printf("p1=%p,p2=%p,p3=%p\n",p1,p2,p3);
	printf("---------------------------\n");
	//获取当前动态内存的末尾地址
	void *cur=sbrk(0);
	printf("cur=%p\n",cur);
	
	//使用sbrk释放4个字节的动态内存
	void *p4=sbrk(-4);
	printf("p4=%p\n",p4);
	
	printf("---------------------------\n");
	cur=sbrk(0);
	printf("cur=%p\n",cur);
	void *p5=sbrk(-4);
	printf("p4=%p\n",p5);
	cur=sbrk(0);
	printf("cur=%p\n",cur);
	
	printf("------------------------------\n");	
	printf("当前进程的进程编号是：%d\n",getpid());
	printf("目前拥有4个字节的动态内存\n");
	getchar();

	sbrk(4093);
	printf("申请了4093个字节的动态内存，此时正好超过1个内存大小的动态内存\n");
	getchar();
	
	sbrk(-1);
	printf("释放了一个字节的动态内存,此时正好剩下超过一个内存页大小的动态内存\n");
	getchar();

	sbrk(-4096);
	printf("此时所有的动态内存释放完毕\n");
	getchar();


	return 0;
}
