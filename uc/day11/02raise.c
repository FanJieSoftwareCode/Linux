//使用raise函数发送一个指定的信号
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void fa(int signo){
	printf("捕获到了信号%d\n",signo);
}

int main(){
	//1.设置对信号SIGINT进行自定义处理
	if(SIG_ERR==signal(SIGINT,fa)){
		perror("signal"),exit(-1);		
	}
	//2.5秒后使用raise函数发送信号SIGINT
	unsigned int second=sleep(5);
	if(0==second){
		printf("美美的睡了一觉\n");
	}else{
		printf("睡眠被打断，还有%d秒没来得及睡\n",second);
	}
	int res=raise(SIGINT);
	if(0!=res){
		perror("raise"),exit(-1);
	}
	return 0;
}
