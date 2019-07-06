//使用消息队列实现进程间的通信
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<signal.h>
//定义消息的类型
typedef struct msgbuf{
	long mtype;      //消息的类型
	char buf[20];	//消息的内容
}Msg;

int msqid;
void fa(){
	printf("正在删除请稍后...\n");
	sleep(3);
	int res=msgctl(msqid,IPC_RMID,NULL);
	if(-1==res){
		perror("msgctl"),exit(-1);
	}
	printf("删除成功\n");
	exit(0);
}

int main(){
	//1.获取key值，使用ftok函数
	key_t key=ftok(".",150);
	if(-1==key){
		perror("ftok"),exit(-1);
	}
	printf("key=%#x\n",key);
	//2.创建消息队列，使用msgget函数
	msqid=msgget(key,IPC_CREAT|0664);
	if(-1==msqid){
		perror("msgget"),exit(-1);
	}
	printf("msqid=%d\n",msqid);
	//3.发送消息到消息队列中，使用msgsnd函数
	Msg msg1={1,"hello"};
	Msg msg2={2,"world"};
	int res=msgsnd(msqid,&msg2,sizeof(msg2.buf),0);
	if(-1==res){
		perror("msgsnd"),exit(-1);
	}
	res=msgsnd(msqid,&msg1,sizeof(msg1.buf),0);
	if(-1==res){
		perror("msgsnd"),exit(-1);
	}
	printf("成功发送两条消息到消息队列中\n");
	//4.如果不再使用，则删除消息队列msgctl函数
	printf("删除消息队列请按ctrl+c...\n");
	if(SIG_ERR==signal(SIGINT,fa)){
		perror("signal"),exit(-1);
	}
	while(1);
	return 0;
}
