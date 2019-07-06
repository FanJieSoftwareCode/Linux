#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>

typedef struct {
	long mtype;
	char buf[20];
}Msg;

int main(){
	//1.获取key值，使用ftok函数
	key_t key=ftok(".",150);
	if(-1==key){
		perror("ftok"),exit(-1);
	}
	printf("key=%#x\n",key);
	//2.获取消息队列，使用msgget函数
	int msqid=msgget(key,0);
	if(-1==msqid){
		perror("msgget"),exit(-1);
	}
	printf("msqid=%d\n",msqid);
	//3.接收消息队列中的数据，使用msgrcv函数
	Msg msg={0};
//	int res=msgrcv(msqid,&msg,sizeof(msg.buf),0,0);
	//接受消息队列中第一个类型为1的消息
		int res=msgrcv(msqid,&msg,sizeof(msg.buf),0,IPC_NOWAIT);
	printf("res=%d\n",res);
	if(-1==res){
		perror("msgrcv"),exit(-1);
	}
	printf("%s\n",msg.buf);
	
	return 0;	
}
