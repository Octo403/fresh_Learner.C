// ==========================================
// HW11_1
// ==========================================

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#define N 20
void reverse(int a[],int m);
int main(){
    srand((unsigned)time(NULL));
    int n,m,i,a[N] = {0},j;
    i = j = 0;
    n = 1 + rand() % 20;
    m = rand() % n;
    printf("The integer sequence is:\n");
    while(i++ < n){
        a[i-1] = i;
        printf("%4d",a[i-1]);
    }

    reverse(a,m);
    reverse(&a[m],n-m);
    reverse(a,n);

    printf("\nShift bits:%d\n",m);
    printf("After performing  a circular left shift, the sequence is:\n");
    while(j<n){
        printf("%4d",a[j++]);
    }

    return 0;
}
 void reverse(int a[],int m){
    int i = 0,temp;
    while(i < m/2){
        temp = *(a+i);
        *(a+i) = *(a+m-1-i);
        *(a+m-1-i) = temp;
        i++;
    }
}

// ==========================================
// HW11_2
// ==========================================

#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#define M 20
#define WIDTH 12
void get_rand(int n,int a[]);
void convert(int num,int base,int result[M],int*len);
void printResult(int result[],int len);
int main(){
    srand((unsigned int)time(NULL));
    int n,i,result[M] = {0},len,j,base[6] = {10},a[M] = {0};//result:保存转换结果的数组；len转换后的长度
    i = 0;
    j = 1;
	n = 10 + rand() % 10;
    printf("%d random integers:\n",n);
    get_rand(n,a);               //获取随机数字并数组从小到大排序
    printf("\n\nEnter 5 base numbers:");
    while(i++ < 5){
        scanf("%d",&base[j++]);
    }
    printf("Base-10     ");
    for(i = 1;i <= 5;i++){
        printf("Base-%-7d",base[i]);
    }
    printf("\n");
    for(i = 0;i != n;i++){
        printf("%-*d",WIDTH,a[i]);
        for(j = 1;j != 6;++j){
            convert(a[i],base[j],result,&len);
            printResult(result,len);//对齐输出转换结果
        }
        putchar('\n');
    }

    return 0;
}
void get_rand(int n,int a[]){               //获取随机数字并数组从小到大排序
    int *p,end,temp,pos,j;
    for(p = a;p < a + n;p++){
        *p = rand()%1024;
        printf("%d ",*p);
    }
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
}

void convert(int num,int base,int result[M],int *len){
    int temp,k;
    temp = num;
    k = 0;
    while(temp){			//进制转换
		result[k++] = temp % base;
		temp = temp / base;
		}
        *len = k;
}
void printResult(int result[],int len){
    char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i;
    for(i = len - 1;i >= 0;i--){
        printf("%c",digits[result[i]]);
    }
   for(i = 0;i < 12 - len;i++){
        putchar(' ');
    }
    
}




// ==========================================
// HW11_3
// ==========================================

#include<stdio.h>
#include<string.h>
#include<math.h>
int *search(int (*p)[5],int n, int ID);
void output(int *p);
int main(){
    int list[][5] = {{201001, 75, 85, 77, 59}, {201002, 57, 78, 73, 66}, {201003, 89, 86, 70, 90}, {201004, 47, 70, 82, 73}, {201005, 72, 87, 88, 54}, {201006, 90, 96, 99, 99}, {201007, 81, 97, 99, 67}, {201008, 43, 98, 96, 79}, {201009, 67, 72, 73, 40}, {201010, 77, 70, 82, 65}, {201011, 77, 72, 73, 80}, {201012, 47, 70, 82, 73}, {201013, 77, 82, 83, 50}, {201014, 97, 90, 92, 95}, {201015, 87, 92, 93, 60}, {201016, 47, 90, 92, 73}};
    int i,j,n = sizeof(list) / sizeof(list[0]),ID;
    printf("The grade form is:\n");
    for(i = 0;i < n;i++){
        for(j = 0;j < 5;j++){
            printf("%-8d",list[i][j]);
        }
        putchar('\n');
    }
    printf("\nEnter a student ID:");
    scanf("%d",&ID);
    int *p = search(list, n, ID);
    
    if(p){
        output(p);
    }else{
        printf("Student ID %d not found.",ID);
    }

    return 0;
}
int *search(int (*p)[5],int n, int ID){
    int t;
    for(t = 0;t < n;t++){
        if(ID == p[t][0]){
            return p[t];
        }
    }
    return NULL;
}
void output(int *p){
    int f;
    for(f = 0;f < 5;f++){
        printf("%-8d",p[f]);
    }
}

// ==========================================
// HW11_4
// ==========================================

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
void initArray(int a[],int n);
void outputArray(int a[],int n);
void initPointerArray(int a[],int n,int *pa[]);
void sortByPointer(int *pa[], int n);
void rankArray(int b[], int a[], int *pa[], int n);
int main()
{
	int a[N], b[N], * pa[N];

	initArray(a, N);	//���������ʼ������ 
	printf("Data:\t");
	outputArray(a, N);	//������� 

	initPointerArray(a, N, pa);	//��ʼ��ָ������ 
	sortByPointer(pa, N);		//����ָ����������: pa[0]ָ����С��, ..., pa[N-1]ָ������� 
	rankArray(b, a, pa, N);		//����ָ���������ɱ������ 

	printf("No:\t");
	outputArray(b, N);	//���������� 

	return 0;
}
void initArray(int a[],int n){
	srand((unsigned)time(NULL));
	int i = 0;
	for(;i < n;i++){
		a[i] = rand() % 100;
	}
}
void outputArray(int a[],int n){
	int i = 0;
	for(;i < n;i++){
		printf("%-4d",a[i]);
	}
    putchar('\n');
}
void initPointerArray(int a[],int n,int *pa[]){
	int i = 0;
	for(;i < n;i++){
		pa[i] = &a[i];
	}
}
void sortByPointer(int *pa[], int n){
	int i = 0,end,*temp,pos;
    end = n-1;
	while(end){
        for(pos = i = 0;i < end;i++){
            if(*pa[i] > *pa[i+1]){
                temp = pa[i];
                pa[i] = pa[i+1];
                pa[i+1] = temp;
                pos = i;
            }   
        }
        end = pos;
    }
}
void rankArray(int b[], int a[], int *pa[], int n){
    int i ,j,k;
    for(i = 0;i < n;i++){
       for(j = 0;j < n;j++){
           if(pa[j] == &a[i]){
            k = j;
            while(k > 0 && *pa[k-1] == *pa[k]){
                k--;
                b[i] = k + 1;
            }
            b[i] = k+1; 
            break;
           }
       }
    }
    
}




