#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
int main(){
	int *p1=(int*)sbrk(sizeof(int));
	*p1=66;
	double *p2=(double*)sbrk(sizeof(double));
	*p2=3.14;
	char *p3=(char*)sbrk(sizeof(char)*10);
//	strcpy(p3,"hello");
	p3="hello";
	printf("%d\n",*p1);
	printf("%lg\n",*p2);
	printf("%s\n",p3);
	
	brk(p3);
	brk(p2);
	brk(p1);
	printf("%p\n",sbrk(0));
	return 0;
}
