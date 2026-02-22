// ==========================================
// HW9_1
// ==========================================

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#define N 1000
int main(){
    int i, w_count, lenth[N] = {0}, max, start, end, pos, inword, j, t;
    char word[N][N], str[N];
    pos = inword = w_count = max = 0;

    printf("Enter some text:\n");
    gets(str);

    for(i = 0;i <= (int)strlen(str);i++){
        if(isalpha(str[i]) && inword == 0){
            inword = 1;
            start = i;
        }else if(!isalpha(str[i])  && inword == 1){
            inword = 0;
            end = i;
            w_count++;
            lenth[w_count-1] = end - start;
            for(t = 0;t < lenth[w_count-1];t++){
                word[w_count-1][t] = str[start+t];
            }
            word[w_count-1][lenth[w_count-1]] = '\0';
            if(lenth[w_count-1]>max){
            max = lenth[w_count-1];
            pos = w_count-1;
        }
        
        }
        }
        
        
    
    printf("Word list:\n");
    for(i = 0;i < w_count;i++){
        printf("%-s",word[i]);
        for(j = lenth[i];j <= max;j++){
            printf(" ");
        }
        if((i+1) % 5 == 0){
            printf("\n");
        }
    }
    printf("\n");
    printf("Total number of words: %d\n",w_count);
    printf("Longest word:%s",word[pos]);
    return 0;
}


// ==========================================
// HW9_2
// ==========================================

#include<stdio.h>
#include<math.h>
#define N 200
int main(){
    int i, a[N]={0}, n, top, mul,add1,add2;
    a[0] = a[1] = 1;
    top = 1;
    printf("Enter n:");
    scanf("%d",&n);
    for(mul = 1; mul <= n;mul++){
        add1 = 0;
        for(i = 1; i <= top + 2;i++){
            add2 = a[i] * mul + add1;
            a[i] = add2%10;
            add1 = add2/10;
        }
        if(a[top+1] && !a[top+2]) top++;
        else if(a[top+2] && !a[top+3]) top += 2;
    }
    a[0] = top;
    printf("%d! = ",n);
    for(i = top;i > 0;i--)
        printf("%d",a[i]);
    printf("\nIt's a %d-digit number",a[0]);

    return 0;

}


// ==========================================
// Content from HW9_3_1_25803050364.c
// ==========================================

#include<stdio.h>
#include<math.h>
void back(int n);
void order(int n);
int main(){
    int n;
    printf("Enter a positive integer:");
    scanf("%d",&n);
    printf("Output in normal order:\n");
    order(n);
    printf("\n");
    printf("\nOutput in reverse order:\n");
    back(n);
}
void back(int n){
    printf("%d ",n % 10);
    if(n < 10) return;
    back(n/10);
}
void order(int n){
    if(n < 10){
        printf("%d ",n);
        return;
    }
    order(n / 10);
    printf("%d ",n % 10);
}

// ==========================================
// Content from HW9_3_2_25803050364.c
// ==========================================

#include<stdio.h>
#include<math.h>
void back(int n);
void order(int n);
int main(){
    int n;
    printf("Enter a positive integer:");
    scanf("%d",&n);
    printf("Output in normal order:\n");
    order(n);
    printf("\n");
    printf("\nOutput in reverse order:\n");
    back(n);
}
void back(int n){
    static int layer_xsl = 0;
    layer_xsl++;
    printf("Recursion Level %d, parameter n = %d\n",layer_xsl,n);
    printf("%d\n",n % 10);
    if(n < 10) {
        printf("Recursion Level %d return\n",layer_xsl);
        layer_xsl--;
        return;
    }

    back(n / 10);
    printf("Recursion Level %d return\n",layer_xsl);
    layer_xsl--;
}
void order(int n){
    static int layer_zyf=0;
    layer_zyf++;
    printf("Recursion Level %d, parameter n = %d\n",layer_zyf,n);
    if(n < 10){
        printf("%d\n",n);
        printf("Recursion Level %d return\n",layer_zyf);
        layer_zyf--;
        return;
    }
    order(n / 10);
    printf("%d\n",n % 10);
    printf("Recursion Level %d return\n",layer_zyf);
    layer_zyf--;
    
}

