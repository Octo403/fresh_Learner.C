// ==========================================
// HW1_1
// ==========================================

#include<stdio.h>
int main()
{
	printf("To C, or not to C: that is the question.\n");
	
	return 0;
 } 


// ==========================================
// HW1_2
// ==========================================

#include<stdio.h>
int main()
{
	int x, y, sum;
	printf("Input x and y\n");
	scanf("%d%d", &x, &y);
	sum = x + y;
	printf("x + y = %d\n", sum);
	
	return 0;
}


// ==========================================
// HW1_3
// ==========================================

#include<stdio.h>
int main()
{
	double f, c;
	int lower, upper, step;
	lower = 0; upper = 100; step = 10; f = lower;
	printf("华氏温度和摄氏温度的对照表如下：\n");
	while (f <= upper)
	{
		c = 5.0/9.0*(f - 32.0);
		printf("\t%7.0f\t%7.1f\n", f, c);
		f = f + step;
	}
		
		return 0;
	
}


