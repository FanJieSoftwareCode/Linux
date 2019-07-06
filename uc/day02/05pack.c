//#pragma pack的使用

#include<stdio.h>
//设置结构体按照2的倍数进行对齐和补齐
//#pragma pack(2) //8
//#pragma pack(1)  //6
//#pragma pack(3)   //12，必须是2的较低次方
//#pragma pack(4)		//默认的计算方式
#pragma pack(8)		//超过4按照4计算
int main(){
	struct s{
		char c1;
		int i;
		char c2;
	};
	printf("%d\n",sizeof(struct s));
	return 0;
}
