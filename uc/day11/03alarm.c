//使用alarm函数发送信号
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void fa(int signo){
	//进入到死循环
	printf("捕获到了信号%d\n",signo);
	alarm(1);
}
int main(){
	//1.设置对信号SIGALRM进行自定义处理
	if(SIG_ERR==signal(SIGALRM,fa)){
		perror("signal"),exit(-1);
	}
	//2.设置5秒后发送SIGSLRM信号，用alarm函数
	unsigned int second=alarm(5);
	printf("second=%u\n",second);
	
	sleep(2);
	//调整闹钟为10秒后发送信号
	second=alarm(10);
	printf("second=%u\n",second);
	//取消闹钟
//	second=alarm(0);
//	printf("second=%u\n",second);


	while(1);
	return 0;
}
