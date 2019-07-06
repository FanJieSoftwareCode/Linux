#include"circle.h"

int main(){
	float r;
	printf("输入半径：");
	scanf("%g",&r);
	printf("周长是%g\n",circle_length(r));
	printf("面积是%g\n",circle_area(r));
}
