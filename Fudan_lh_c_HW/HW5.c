// ==========================================
// HW5_1
// ==========================================

#include<stdio.h>
#include<math.h>
#define EPSILON 1E-10
int main()
{


	double x, sum, fz, fx, plus, fm, sum2;
	int i;
	
	i = 1;
	sum = fz = fm = plus = 1.0;
	
	printf("Enter x: ");
	scanf("%lf", &x);
	//printf("%f\n",x);
	
	fx = fabs(x);
		
	while(plus > EPSILON){
		fm = fm * i;
		fz = fz * fx;
		plus = fz / fm;
		if(plus <= EPSILON)
			break;
		sum += plus;
		++i;
	}
				
		
	if(x >= 0)	
		printf("e^(%g) = %.15g",x,sum);
	else{
		sum2 = 1 / sum;
		printf("e^(%g) = %.15g",x,sum2);
	
	return 0;
		
	}
}
	
	
	
	
	


// ==========================================
// HW5_2
// ==========================================

#include<stdio.h>
#include<math.h>
#define EPSILON 1E-6
int main()
{
	float m, low, high, fl, fh, fm;
	low = 0;
	high = 3;
	
	
	printf("[low,high]\t\tmid\t\tf_low\t\tf_high\t\tf_mid\n");
	while(fabs(high - low) >= EPSILON){
		m = (low + high) / 2;
		fm = m * m * m - m * m - 1;
		fl = low * low * low - low * low - 1;
		fh = high * high * high - high * high - 1;
		if(fm * fl > 0){
			low = m;
			fl = low * low * low - low * low - 1;
			printf("[%-.6f,%-.6f]\t%-.6f\t%-.6f\t%-.6f\t%-.6f\t\n",low, high, m, fl, fh, fm);
		}else if(fh * fm > 0){
			high = m;
			fh = high * high * high - high * high - 1;
			printf("[%-.6f,%-.6f]\t%-.6f\t%-.6f\t%-.6f\t%-.6f\t\n",low, high, m, fl, fh, fm);
		}else
			printf("[%-.6f,%-.6f]\t%-.6f\t%-.6f\t%-.6f\t%-.6f\t\n", low, high, m, fl, fh, fm);
	}
	printf("%.6f",m);
	
	return 0;
		
} 


// ==========================================
// HW5_3
// ==========================================

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#define N 20
int main()
{
	int i,num,n,k,t,binary[10],temp,count,count1;
	srand((unsigned int)time(NULL));
	n = 10 + rand() % 10;
	printf("In this run,%d random integers in [0,1024) were generated.\n",n);
	printf("\n");
	printf("Decimal       Binary\t\n");
	for(i = 0;i < 10;i++)
		binary[i] = 0;
	for(i = 0;i < n;i++){
		num = rand()%1024;
		temp = num;
		while(temp){
			for(k = count = 0;k < 10 && temp != 0;k++){
				binary[k] = temp % 2;
				temp = temp / 2;
				count++;
			}
		}
		printf("%7d\t",num);
		//printf("%d",count);
		for(count1 = 0;count1 <= 9 - count;count1++)
			printf(" ");
		printf("  ");
		for(t = count - 1;t >= 0;t--){
			printf("%d",binary[t]);
		}
		printf("\n");	
	}
	
	
	return 0;
}


// ==========================================
// HW5_4
// ==========================================

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#define N 20
int main(){
	int n;
	srand((unsigned int)time(NULL));
	n=10+rand()%10;
	printf("In this run,%d random integers in [0,1024) were generated.\n",n);
	printf("\n");
	printf("Decimal\t\tBinary\t\n");
}


