#include"add.h"
//#include"../add.h"

int main(){
	int a,b;
	printf("输入两个整数：");
	scanf("%d%d",&a,&b);
	printf("%d+%d=%d\n",a,b,add_int(a,b));
	return 0;
}
