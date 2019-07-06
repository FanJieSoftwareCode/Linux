//根据错误编号寻找错误信息
#include<stdio.h>
#include<errno.h>
#include<string.h>
int main(){
	printf("出错之前：errno=%d\n",errno);
	printf("strerror:%s\n",strerror(errno));
	perror("perror");
	printf("----------------------------\n");
	//1.打开文件/etc/passwd，使用fopen函数
	FILE *p=fopen("/etc/passwd","wb");
	if(!p){
		printf("打开文件失败\n");
		printf("出错之后：errno=%d\n",errno);
		printf("strerror:%s\n",strerror(errno));
		perror("fopen");
	//	printf("%m");
		//return -1;
	}
	//2.关闭文件/etc/passwd使用fclose函数
//	fclose(p);
	//作业：使用fopen函数以wb的方式打开文件/etc/passwd，并判断打开是否失败，若失败则两种方式打印错误信息
	//思考：考虑能不能直接使用errno作为判断函数调用是否失败的依据，为什么？
	return 0;
}

