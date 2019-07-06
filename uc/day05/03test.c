//测试虚拟地址是否可用
#include<stdio.h>

int main(){
	int *pi=(int*)0xbfd2399c;
	printf("*pi=%d\n",*pi);
	return 0;
}
