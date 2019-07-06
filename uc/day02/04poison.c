//#pragma GCC poison 的使用
#include<stdio.h>

//进行宏定义,实现瞒天过海
#define GOTO goto
//将goto设置成毒药
#pragma GCC poison goto

int main(){
	ok: 	
		printf("goto就是任性\n");	
		sleep(1);
	GOTO ok;
	return 0;
}
