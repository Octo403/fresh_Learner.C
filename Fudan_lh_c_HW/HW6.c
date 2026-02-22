#include <stdlib.h>
#include <time.h>
// ==========================================
// HW6_1
// ==========================================

#include<stdio.h>
#include<math.h>
int main(){
	unsigned int num, i, t, j;
	int a[32] = {0},count,temp,flag = 0,flag2=0;
	
	printf("Enter a positive integer n (1 <= n <= 2147483647): ") ;
	scanf("%u", &num);
	
	temp = num;
	for(i = 2,j = 0;i * i <= num; i++){
		if(temp % i == 0){
			a[j] = i;
			temp /= i;
			i = i - 1;
			j++;
			flag = 1; 
		}
	}
	if((unsigned long long)temp * temp > num){		//>sqrt num
			a[j] = temp;
			flag2=1;
	}
	printf("%d = ",num);
	if(flag&&!flag2){					//composite number
		for(t = 0;t < j-1; t++)
			printf("%d * ",a[t]);
		printf("%d",a[j-1]);
	}else if(flag&&flag2){
		for(t=0;t<j;t++){
				printf("%d * ",a[t]);
		printf("%d",a[j]);
		}
		
	}else
		printf("%d",num);		//prime number 
	
//	printf("%d\n",count);
//	printf("%d\n",j);
//	printf("%d",num);
	return 0;
}


// ==========================================
// Content from HW6_1_25803050364model.c
// ==========================================

#include<stdio.h>
#include<math.h>
int main(){
    int n ,i = 2;
    printf("Enter an integer n(1 <= n <= %d): ",(1u << 31)-1);
    scanf("%d",&n);

    printf("%d=",n);
    while(i < n / i){
        if(n % i == 0){
            printf("%d * ",i);
            n /= i;
        }else
            ++i;
    }
    if(i >= n / i)
        printf("%d\n",n);

    return 0;
}

// ==========================================
// HW6_2
// ==========================================

#include<stdio.h>
#include<math.h>
#include<time.h>
#define N 10
#define M 20
int main()
{
	int i, n, bin[N] = {0}, temp, count, count1, count2, count3, a[M]={0}, end, pos, j, t, k, six[N] = {0};
	srand((unsigned int)time(NULL));
	n = 10 + rand() % 10;
	printf("%d random integers\n",n);
	for(i = 0;i < n;i++){  			//get n random numbers 
		a[i] = rand()%1024;
		printf("%d ",a[i]);
	}
	printf("\n");
	printf("\n");
	printf("    Decimal     Binary    Seximal");
	printf("\n");
	end = n-1;					//order of small to large
	while(end > 0){
		for(pos = j = 0;j < end;j++){
			if(a[j] > a[j + 1]){
				temp = a[j];a[j] = a[j + 1];a[j+1] = temp;
				pos = j;
			}
		
		}
		end = pos;
	}
	for(i = 0;i < n;i++){
		temp = a[i];
		while(temp){			//bin
			for(k = count = 0;k < 10 && temp != 0;k++){
				bin[k] = temp % 2;
				temp = temp / 2;
				count++;
			}
		}
		temp = a[i];				//six
		while(temp){
			for(k = count2 = 0;k < 10 && temp != 0;k++){
				six[k] = temp%6;
				temp = temp/6;
				count2++;
			}
		}
		
		printf("%11d",a[i]);
		printf(" ");
		for(count1 = 0;count1 <= 9 - count;count1++)
			printf(" ");
		
		for(t = count - 1;t >= 0;t--){
			printf("%d",bin[t]);}
			
		printf(" ");
		
		for(count3 = 0;count3 <= 9 - count2;count3++)
			printf(" ");
		
		for(t = count2 - 1;t >= 0;t--)
			printf("%d",six[t]) ;
		printf("\n");
			
	}
//	for(t=0;t<n;t++)
//		printf("%d\n",a[t]);
//	printf("\n"); 
	
	return 0;
}


// ==========================================
// HW6_3
// ==========================================

#include<stdio.h>
#include<math.h>
#define N 120
int main(){
	int i = 0, key, count = 0, j, k, visited[N] = {0}, t, m;
	char s[N], ch, result[N];
	
	printf("Enter source text: ");
	do{
		scanf("%c",&ch);
		if(ch == '\n')
			break;
		s[i++] = ch;
		count++;
	}while(1);
	s[i] = '\0';
	printf("Enter key: ");
	scanf("%d",&key);
	for(t = 0;t <= count;t++){
		visited[t] = 1;
	}
	j = 0;
	m = 0;
	for(i = 0;i < count;i++){
		k = 0;
		while(k<key){
			if(visited[j]) k++;
			if(k == key){
				result[m] = s[j];
				//printf("%c",s[j-1]);
				visited[j] = 0;
				m++;
			}
		j=(j + 1) % count;
		}
	}
	result[count] = '\0';
	printf("Cypher text: %s",result);
	//printf("%s",s);
	return 0;
}


// ==========================================
// HW6_4
// ==========================================

#include<stdio.h>
#include<math.h>
#define N 30
int main(){
	int n, top = 0,left = 0,bottom, right, matrix[N][N] = {0},num, i, j;
	printf("Enter n (1<n<=30): ");
	scanf("%d",&n);
	num = 1;
	bottom = right = n-1;
	while(num <= n*n){
		for(i = left;i <= right && num <= n * n;i++){
			matrix[top][i] = num;
			num++;
		}
		top++;
		for(i = top;i <= bottom && num <= n * n;i++){
			matrix[i][right] = num;
			num++;
		}
		right--;
		for(i = right;i >= left && num <= n * n;i--){
			matrix[bottom][i] = num;
			num++; 
		}
		bottom--;
		for(i = bottom;i >= top && num <= n * n;i--){
			matrix[i][left] = num;
			num++;
		}
		left++;
	}
	for(i = 0;i < n;i++){
		for(j = 0;j < n;j++){
			printf("%-4d",matrix[i][j]);
		}
		printf("\n");
	}
	return 0;
}


