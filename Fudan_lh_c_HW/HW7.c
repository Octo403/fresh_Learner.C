// ==========================================
// HW7_1
// ==========================================

#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define N 100

int main(){
	char str1[N],str2[N],comstr[N];
	int count[N][N], i, j, max = 0, end, len1, len2, start;
	
	printf("Enter 2 strings (lenth < 100) : \n");
	gets(str1);
	gets(str2);
	len1 = strlen(str1);
	len2 = strlen(str2);
	for(i = 0;i < len1;i++){
		for(j = 0;j < len2;j++){
			if(str1[i] == str2[j]){
				if(i == 0 || j == 0){
					count[i][j] = 1;
				}else{
					count[i][j] = count[i - 1][j - 1] + 1;
				}if(count[i][j] > max){
				max = count[i][j];
				end = i;
				}
			
			}else{
				count[i][j] = 0;
			}
		}
	}
	start = end - max + 1;
	if(max){
		strncpy(comstr,&str1[start],max);
		comstr[max] = '\0';
		printf("The longest common substring is:\n");
		printf("%s",comstr);
	}else{
		printf("There is no common charcacter.");
	}
	return 0;
} 


// ==========================================
// HW7_2
// ==========================================

#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define N 10^100 
#define M 101

int main(){
	int i = 0, c, lenth, change_p, switch_p;
	char num[N],a[M],temp;
	printf("Enter an integer n (1<= n < 10^100):");
	gets(num);									//get num and save 
	lenth = strlen(num);
	//printf("%d",lenth);
	for(i = 0;i < lenth;i++){
		a[i] = num[i];
		//printf("%c",a[i]);
	}
	for(i = lenth - 2;i > 0;){					
		if(a[i] - a[i + 1] >= 0){
			i--;
			change_p = i; 
		}else
		break;
	} 
	//printf("%d",i); 
	for(i = change_p + 1;i < lenth;){
		if(a[i] > a[change_p]){
			i++;
			switch_p = i - 1;
		}else
		break;
	}
	//printf("%d",switch_p);
	temp = a[change_p];
	a[change_p] = a[switch_p];
	a[switch_p] = temp;
	if(change_p == 0 || lenth == 1){
		printf("No larger integer exists");
	}else{
		for(i = 0;i <= change_p;i++){
		printf("%c",a[i]);
	}
	for(i = lenth - 1;i > change_p;i--)			
		printf("%c",a[i]);
	}
	
	return 0;	
}


// ==========================================
// HW7_3
// ==========================================

#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<time.h> 

void GuessGame(int num,int n){
	int i,guess_n;
	for(i = n;i > 0;i--){
		printf("Guess:");
		scanf("%d",&guess_n);
		
		if(guess_n == num){
			printf("Yeh!:D");
			break; 
		}else{
			if(guess_n > num&&i>1){								//still have chances
				printf("Bigger. %d chances left.\n",i-1);
			}else if(guess_n<num&&i>1){
				printf("Smaller. %d chances left.\n",i-1);
			}else{												//last chance
				if(guess_n > num){
					printf("Bigger. 0 chances left\n");
				}else{
					printf("Smaller. 0 chances left\n");
				}
				printf("Oops...It's %d. Good luck next time.\n",num);
				break; 
			}
		}
	}
}
int main(){
	int n, num;
	printf("========Bulls and Cows========\n");
	printf("Instruction: Please guess a number between 1 and 100.\n");
	srand((unsigned int)time(NULL));
	n = 5 + rand() % 2;
	num = rand() % 100 + 1;
	printf("You have %d chances.\n",n);
	printf("\n");
	GuessGame(num,n);
	
	return 0;
}


// ==========================================
// HW7_4
// ==========================================

#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define N 200 

char printReciprocal(int x){
	int a[N],temp,left,get,flag,i,j,start_p,end_p;
	left = 1;
	flag = 0;
	for(i = 0;i < N && flag == 0;i++){
		get = left * 10 / x;
		a[i] = get;
		left = (left * 10) % x; 
		a[i+1] = left * 10 / x;
		if(a[i] == 0 && a[i+1] == 0){          //terminating decimal
			end_p = i - 1;
			break;
		}
		for(j = 0;j < i;j++){					//recuring decimal 
			if(a[i] == a[j] && a[i+1] == a[j+1]){
				end_p = i-1; 
				start_p = j;
				flag = 1;
			}
		}
	}
	printf("1/%d=0.",x);
	for(i = 0;i <= end_p && flag == 0;i++){		//print terminating decimal
		printf("%d",a[i]);
	}
	if(flag){									//print recuring decimal
		for(i = 0;i < start_p;i++){
			printf("%d",a[i]);
		}
		printf("(");
		for(i = start_p;i <= end_p;i++){
			printf("%d",a[i]);
		}
		printf(")");
	}

	return 0;	
}

int main(){
	int x;
	for(x = 2;x <= 100;++x){
		printReciprocal(x);
		printf("\n");
	}
	return 0;
}



