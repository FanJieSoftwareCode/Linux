//使用brk函数调整动态内存的大小
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
	//使用sbrk函数获取一个有效的地址
	void *pv=sbrk(0);
	printf("cur=%p\n",pv);
	//使用brk函数申请4个字节的动态内存
	int res=brk(pv+4);
	if(-1==res){
		perror("brk"),exit(-1);
	}
	void *cur=sbrk(0);
	printf("cur=%p\n",cur);
	
	//申请4个字节的动态内存
	brk(pv+8);
	cur=sbrk(0);
	printf("cur=%p\n",cur);
	
	//释放所有的动态内存
	brk(pv);
	cur=sbrk(0);
	printf("cur=%p\n",cur);

	return 0;
}
