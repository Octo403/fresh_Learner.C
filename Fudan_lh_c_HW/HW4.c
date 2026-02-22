// ==========================================
// HW4_1
// ==========================================

#include<stdio.h>
#include<math.h>
int main()
{
	int count0, count1, count2, count3, count4, count5, count6, count7, count8, count9;	
	char num;
	
	printf("Enter an integer:\n");
	while((num = getchar()) == ' '||num ==  '\n' ||num == '\t');
	//printf("%d",num);
	
	count0 = count1 = count2 = count3 = count4 = count5 = count6 = count7 = count8 = count9 = 0;
	
	while((num)!= ' ' && num != '\n' && num != '\t'){
		
		switch (num){
			case '0': ++count0;	break;
			case '1': ++count1;	break;
			case '2': ++count2;	break;
			case '3': ++count3;	break;
			case '4': ++count4;	break;
			case '5': ++count5;	break;
			case '6': ++count6;	break;
			case '7': ++count7;	break;
			case '8': ++count8;	break;
			case '9': ++count9;	break;
		}
		num = getchar();
		
	}
		
	printf("Digit\tOccurrences\n");
	if(count0 > 0)
		printf("0\t%d\n",count0);
	if(count1 > 0)
		printf("1\t%d\n",count1);
	if(count2 > 0)
		printf("2\t%d\n",count2);
	if(count3 > 0)
		printf("3\t%d\n",count3);
	if(count4 > 0)
		printf("4\t%d\n",count4);
	if(count5 > 0)
		printf("5\t%d\n",count5);
	if(count6 > 0)
		printf("6\t%d\n",count6);
	if(count7 > 0)
		printf("7\t%d\n",count7);
	if(count8 > 0)
		printf("8\t%d\n",count8);
	if(count9 > 0)
		printf("9\t%d\n",count9);
	

	return 0;

 } 


// ==========================================
// HW4_2
// ==========================================

#include<stdio.h>
#include<math.h>
int main()
{
	int num,i,sum;
	printf("Enter an integer: ");
	scanf("%d",&num);
	while(num){
		i = num % 10;
		sum = sum * 10 + i;
		num /= 10;
	}
	
	printf("The reversal is: %d",sum);
	
	return 0;
	
		
}


// ==========================================
// HW4_3
// ==========================================

#include<stdio.h>
#include<math.h>
int main()
{
	int a1,a2,b1,b2,fz,fm,gcd,i,min,new_fz,new_fm;
	printf("Enter 2 fractions separated by a plus sign:");
	scanf("%d/%d+%d/%d",&a1,&a2,&b1,&b2);
	
	fz = a1 * b2 + a2 * b1;
	fm = a2 * b2;
	
	if (fz <= fm)
		min = fz;
	else
		min = fm;
	
	//printf("%d\n",min);
	gcd = 1;
	for(i = min;i >= 1;i--){
		if(fz % i == 0&&fm % i == 0){
			gcd=i;
			break;
		}
		
	}
	//printf("%d\n",gcd);
	new_fz = fz/gcd;
	new_fm = fm/gcd;
	//printf("%d%d",new_fz,new_fm);
	
	if(new_fm == 1)
		printf("%d/%d+%d/%d=%d",a1,a2,b1,b2,new_fz);
	else
		printf("%d/%d+%d/%d=%d/%d",a1,a2,b1,b2,new_fz,new_fm);
		
	return 0;
}


