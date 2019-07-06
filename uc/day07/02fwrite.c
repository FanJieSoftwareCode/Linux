//使用标c的文件操作函数写入数据1~100万
#include<stdio.h>
#include<stdlib.h>

int main(){
	//1.创建/清空文件num.dat，使用fopen函数
	FILE *p=fopen("num.dat","wb");
	if(NULL==p){
		perror("fopen"),exit(-1);
	}
	printf("创建/清空文件成功\n");
	//2.写入数据，使用fwrite函数
	int i;
	for(i=1;i<=1000000;i++){
		fwrite(&i,sizeof(int),1,p);
	}
	printf("写入数据成功\n");
	//3.关闭文件num.dat，使用fclose函数
	int res=fclose(p);
	if(res)
		perror("fclose"),exit(-1);
	}
//	p=NULL;

