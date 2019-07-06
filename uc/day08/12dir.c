//变成实现目录的基本操作
#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>

int main(){
	//1.打开目录，使用opendir函数
	DIR *dir=opendir("../day08");
	if(NULL==dir){
		perror("opendir"),exit(-1);
	}
	printf("成功打开目录\n");
	//2循环读取目录中的内容，使用readdir函数
	struct dirent *ent=NULL;
	while(ent=readdir(dir)){
//		ent=readdir(dir);
	/*	if(!strcmp(ent->d_name,".")||!strcmp(ent->d_name,"..")){
			continue;
		}
	*/	printf("%s\n",ent->d_name);
	//	printf("%c,%s\n",ent->d_type,ent->d_name);
	}
	//3.关闭目录，使用closedir函数
	int res=closedir(dir);
	if(-1==res){
		perror("close"),exit(-1);
	}
	printf("成功关闭目录\n");
	return 0;
}
