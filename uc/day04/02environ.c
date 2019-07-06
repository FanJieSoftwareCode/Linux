//遍历打印环境表中的所有环境信息
#include<stdio.h>
//#include<string.h>
//外部变量的声明
extern char **environ;

int main(){
	//指定临时变量作为全局变量的替身
	char **ppc=environ;
	char buf[20]={0};
	//使用循环打印环境表中的信息
	while(NULL!=*ppc){
		printf("%s\n",*ppc);
		ppc++;
	}
	printf("------------------------------\n");
	ppc=environ;
	while(NULL!=*ppc){
		if(0==strncmp(*ppc,"SHELL",5)){
			strcpy(buf,*ppc+6);
			break;
		}
		ppc++;
	}
	printf("%s\n",buf);
	return 0;
}
