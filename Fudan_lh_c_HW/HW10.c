// ==========================================
// HW10_1
// ==========================================

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#define N 100
int main(){
    srand((unsigned)time(NULL));
    int n,*p,a[N],*max,*min,sum;
    float ave;
    sum = 0;
    n = rand()%101;
    printf("Random integer array (%d elements):\n",n);
    for(p = a;p < a + n;p++){
        *p = rand() % 101;
        if(p == a){
            max = min = p;
        }
        printf("%-4d",*p);
        sum += *p;
        if((p - a + 1) % 10 == 0)
            printf("\n");
        if(*p > *max)
            max = p;
        else if(*p < *min)
            min = p;
    }
    ave = (float)sum / n;
    printf("\nMaximam integer: %d\n",*max);
    printf("Minimum integer: %d\n", *min);
    printf("Average : %.1f",ave);

    return 0;
}

// ==========================================
// HW10_2
// ==========================================

#include<stdio.h>
#include<string.h>
#include<math.h>
#define N 1000
int main(){
    char s[N],*p,*q;
    int value = 0;
    printf("Enter some text:\n");
    gets(s);
    printf("(int)strlen(s) = %d\n",(int)strlen(s));
    printf("\nAfter removing unnecessary whitespace characters:\n");
    for(p = q = s;*p;p++){
        if(*p ==' '){
           if(value == 1){
            *q++ = *p;
            value = 0;
           }else{
            value = 0;
            continue;
           }
        }else{
            value = 1;
            *q++ = *p;
        }
    }
    if(q > s && *(q-1)==' '){
        q--;
    }
    *q = '\0';
    printf("%s",q = s);
    printf("\n(int)strlen(s) = %d\n",(int)strlen(s));

    return 0;
}

// ==========================================
// HW10_3
// ==========================================

#include<stdio.h>
#include<math.h>
#include<string.h>
#define N 10
int judge_k(unsigned int i);
int main(){
    unsigned int num,i;
    printf("Enter n ([10, 1000000]): ");
    scanf("%d",&num);
    printf("K-numbers within %d",num);
    for(i = 10;i < num;i++){
        judge_k(i);
    }
    return 0;
}
int judge_k(unsigned int i){
    int j  = 0,a[N] = {0};
    int *bp,*p1,*p2;
    unsigned int num1,num2,mltp,temp;
    
    temp = i;
    while(temp){
        a[j++] = temp%10;
        temp = temp / 10;

    }
    for(bp = a + 1;bp < a + j;bp++){
        num1 = num2 = 0;
        for(p1 = bp - 1;p1 >= a;p1--){
            num1 = num1 * 10 + *p1;
        }
       
        for(p2 = a + j - 1;p2 >= bp;p2--){
            num2 = num2 * 10 + *p2;
        }
        
        mltp = (num1 + num2) * (num1 + num2);
        if(i == mltp){
            printf("\n%d = (%d + %d)^2",i,num2,num1);
            return 1;
            
        }
    }
    return 0;

}

