//测试不同进程之间的虚拟地址之间的不同之处
#include<stdio.h>

int main(){
	int num=20;
	printf("num=%d,&num=%p\n",num,&num);
	while(1);
	return 0;
}
