#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include <stdlib.h>

int num=10;

void fa(){
	printf("signal:%d\n",num);
	alarm(1);
}

void thread_fun(){
	if(SIG_ERR==signal(SIGALRM,fa)){
		perror("signal"),exit(-1);
	}
	alarm(1);
	while(1);


}

int main(){

	pthread_t pid;
	pthread_create(&pid,NULL,(void*)thread_fun,NULL);

	pthread_join(pid,NULL);
	return 0;
}


