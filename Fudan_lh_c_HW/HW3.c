// ==========================================
// HW3_1
// ==========================================

#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j,k,l,m;
	int result1;
	int result2;
	
	printf("Enter a 13-digit EAN: ");
	scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d",&a,&b,&c,&d,&e,&f,&g,&h,&i,&j,&k,&l,&m);
	result1=3 * (b + d + f + h + j + l) + a + c + e + g + i + k - 1;
	result2=9 - (result1 % 10);
	
	if(result2==m)
		printf("VALID");
	else
		printf("INVALID");
	
	return 0;
 } 


// ==========================================
// HW3_2
// ==========================================

#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,c,d;
	printf("Enter 4 integers: ");
	scanf("%d%d%d%d", &a, &b, &c, &d);
	
	int max1, max2;
	int min1, min2;
	
	if(a >= b)
	{
		max1 = a;
		min1 = b;
	}
		
	else
	{
		max1 = b;
		min1 = a;
	}
	
	if(c >= d)
	{
		max2 = c;
		min2 = d;
	}
	else
	{
		max2 = d;
		min2 = c;
	}
	
	printf("Maximum: %d\n",max1 >= max2 ? max1 : max2);
	printf("Minimum: %d\n",min1 <= min2 ? min1 : min2);
	
	return 0;
}


// ==========================================
// HW3_3
// ==========================================

#include<stdio.h>
#include<math.h>

#define EPSILON 1e-6 

int main()
{
	float a1,a2,b1,b2,c1,c2;
	printf("Enter 3 couples of coordinates: ");
	scanf("(%f,%f)(%f,%f)(%f,%f)",&a1, &a2, &b1, &b2, &c1, &c2);//Step1:save three couples of coordinates
	
	float lenth1,lenth2,lenth3;
	lenth1 =  sqrt((a1 - b1) * (a1 - b1) + (a2 - b2) * (a2 - b2));//Step2:calculate the lenths of three sides  
	lenth2 =  sqrt((a1 - c1) * (a1 - c1) + (a2 - c2) * (a2 - c2));
	lenth3 =  sqrt((c1 - b1) * (c1 - b1) + (c2 - b2) * (c2 - b2));
	
	float max,mid,min;
	if(lenth1 >= lenth2)//Step3:排序三条边 
	{
		if(lenth2 >= lenth3)
		{
			max = lenth1;
			min = lenth3;
			mid = lenth2;
		}
		else
		{
			if(lenth1 > lenth3)
			{
				max = lenth1;
				mid = lenth3;
				min = lenth2;
			}
			else 
			{
				max = lenth3;
				mid = lenth1;
				min = lenth2;
			}
		}
	}
	else
	{
		if(lenth2 <= lenth3)
		{
			max = lenth3;
			mid = lenth2;
			min = lenth1;
		}
		else
		{
			if(lenth1 >= lenth3)
			{
				max = lenth2;
				mid = lenth1;
				min = lenth3; 
			}
			else
			{
				max = lenth2;
				mid = lenth3;
				min = lenth1;
			}
		}
	}
	
	if(max - (mid - min) > EPSILON && max - (mid + min) <- EPSILON) //Step4:判断三角形 
	{
		if(max==mid||mid==min)
		{
			if(max==min)
				printf("Equilateral triangle");
			else if(fabs(max * max - mid * mid - min * min) < EPSILON)
				printf("Isosceles right triangle");
			else
				printf("Isosceles triangle");
		}
		else
		{
			if(fabs(max * max - mid * mid - min * min) < EPSILON)
				printf("Right triangle");
			else
				printf("Triangle");
		}	
	}
	else
		printf("Can not make a triangle");
	
	return 0; 
}


