//使用on_exit来释放动态内存
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<signal.h>

void fa(int status,void *pv){
	printf("status=%d\n",status);
	free(pv);
	pv==NULL;
}
int main(){
	//1.创建子进程
	pid_t pid=fork();
	if(-1==pid){
		perror("vfork"),exit(-1);
	}
	//2.子进程开始进行
	if(0==pid){
		printf("子进程%d开始执行\n",getpid());
		int *pi=(int*)malloc(sizeof(int));
		//使用on_exit来注册函数
		if(0!=on_exit(fa,pi)){
			perror("exit"),exit(-1);
		}
		printf("请输入一个整形半径:\n");
		scanf("%d",pi);
		printf("周长是：%lg\n",2*3.14*(*pi));
		//终止子进程，并自动释放动态内存
		exit(100);
	}
	//3.父进程等待子进程结束，获取退出状态信息
	printf("父进程开始等待\n");
	int status=0;
	int res=waitpid(pid,&status,0);
	if(-1==res){
		perror("waitpid"),exit(-1);
	}
	if(WIFEXITED(status)){
		printf("父进程等待结束，子进程的退出状态信息：%d\n",res,WEXITSTATUS(status));                   //100
	}
	return 0;
}

