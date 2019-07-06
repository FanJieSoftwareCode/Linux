//递归打印目录中的所有内容
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<string.h>
#include<sys/stat.h>
#include<dirent.h>
#include<unistd.h>

void print(char *path){
	//1打开目录，使用open函数
	DIR *dir=opendir(path);
	if(NULL==dir){
		return ; //表示结束当前函数
	}
	//2.循环读取目录中的内容
	struct dirent *ent;
	while(ent=readdir(dir)){
	//3.如果读到的是目录，则递归调用
		printf("[%s]\n",ent->d_name);
		if(4==ent->d_type){
			//特殊处理目录 .和..
			if(!strcmp(ent->d_name,".")||!strcmp(ent->d_name,"..")){
				continue;
			}
			//拼接子目录的路径信息
			char buf[100]={0};
			sprintf(buf,"%s/%s",path,ent->d_name);
			//递归打印
			print(buf);
		}
	//如果读到的是普通文件，则打印
		if(8==ent->d_type){
			printf("%s\n",ent->d_name);
		}
	}
	//5.关闭目录，使用close函数
	int res=closedir(dir);
	if(-1==res){
		return ;	//结束当前目录
	}
}
int main(){
	//print("../day08");
	print("./");
	return 0;
}
