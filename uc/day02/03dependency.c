//#pragma GCC dependency 的使用
#include<stdio.h>
//当前文件依赖于 01line.c
#pragma GCC dependency "01line.c"

int main(){
	printf("到底会不会产生警告信息呢？？\n");
	return 0;
}
