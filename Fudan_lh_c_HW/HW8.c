// ==========================================
// HW8_1
// ==========================================

#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
int menu(int choice);
void play(int choice);
void praise(int get);
void encourage(int get);
int main(){
    int choice;

    printf("* * * * * * * * * * * *\n");
    printf("*                     *\n");
    printf("* Multiplication Quiz *\n");
    printf("*                     *\n");
    printf("* * * * * * * * * * * *\n");
    srand((unsigned)time(NULL));
    for(;;){
        choice = menu(choice);
        
        play(choice);                   //start playing
    
        if(choice == 3){                //exit
            break;
        }
    }
    return 0;
}
int menu(int choice){
    
    printf("Pls choose:\n");
        printf("    1. One-digit multiplication\n");
        printf("    2. Two-digit multiplication\n");
        printf("    3.Exit\n");
        scanf("%d", &choice);
        
        return choice;
}
void play(int choice){
       
        int k1, k2, ans, get;
        get = rand() % 4;
    if(choice == 1){                     //one-digit multiplication
        
        k1 = 1 + rand() % 9;
        k2 = 1 + rand() % 9;
        
        printf("Pls calculate:\n");
        printf("%d*%d=",k1,k2);
        scanf("%d",&ans);

        if(ans == (k1 * k2)){           //correct answer
            praise(get);
        }else{
            encourage(get);             //wrong answer
            printf("%d*%d=%d\n",k1,k2,(k1 * k2));
        }

    }else if(choice == 2){              //two-digit multiplication
        k1 = 1 + rand() % 99;
        if(k1 < 10){                    //ensure k2 is two-digit when k1 is one-digit
            k2 = 10 + rand() % 90;
        }else{                          //k1 is two-digit
            k2 = 1 + rand() % 99;
        }
        get = rand() % 4;
        printf("Pls calculate:\n");
        printf("%d*%d=",k1,k2);
        scanf("%d",&ans);
        if(ans == (k1 * k2)){           //correct answer
            praise(get);
        }else{
            encourage(get);             //wrong answer
            printf("%d*%d=%d\n",k1,k2,(k1*k2));
        }

    }else{
        printf("Bye~~");
    }
}
void praise(int get){
    char prases[4][30] = {"Very good!","Excellent!","Nice work!","Keep up the good work!"};
    printf("%s\n",prases[get]);
    printf("\n");
}
void encourage(int get){
    char encourages[4][50] = {"No. Please try again.","Wrong. Try once more.","Don't give up!","No. Keep trying."};
    printf("%s\n",encourages[get]);
    printf("\n");
    }



// ==========================================
// HW8_2
// ==========================================

#include<stdio.h>
#include<math.h>
unsigned int gcd(unsigned int a,unsigned int b);
int main(){
    unsigned int a,b,result;
    printf("/*** Find the greastest common divisor of two integers ***/\n\n");
    printf("Enter 2 integers: \n");
    scanf("%u%u", &a, &b);
    
    result = gcd(a,b);
    printf("The grestest common divisor of %u and %u is %u",a,b,result);

    //printf("%d %d",num1,num2);
    return 0;

}

unsigned int gcd(unsigned int a,unsigned int b){
    static int layer = 1;
    unsigned int result = 1;
    printf("Recursive layer %d: a = %u, b = %u\n",layer,a,b);
    layer++;
    if(a == b){
        result = a;   
    }else if(a>b){
        result = gcd(a - b,b);   
    }else{
        result = gcd(a,b - a);   
    }
    
    return result;
    

}


// ==========================================
// HW8_3
// ==========================================

#include<stdio.h>
#include<math.h>
#include<string.h>
#define N 30
int main(){
    int a[N][N]={0},n,row = 0,col = 0,flag = 1,i,j;
    printf("Enter n :");
    
    scanf("%d",&n);
    printf("\n");

    for(i = 1; i <= n * n; i++){            //fill top-left triangle matrix
        a[row][col] = i;
        row = row + flag;
        col = col - flag;
        if(row > n - 1 ||col > n - 1){      //finish
            break;
        }
        if(col < 0){                        //left boundary
            col += 1;
            flag = -flag;
        }else if(row < 0){                  //top boundary
            row += 1;
            flag = -flag;
        }else{

        }
    }
    row = n-1;                              //fill bottom-right triangle matrix
    col = n-1;
    flag = 1;
    for(i = n * n;;i--){
        a[row][col] = i;
        row = row - flag;
        col = col + flag;
        if(row == 0 || col == 0 ){          //finish
            break;
        }
        if(col == n){                       //right boundary
            col -= 1;
            flag =- flag;
        }else if(row == n){                 //bottom boundary
            row -= 1;
            flag = -flag;
        }else{

        }
        
    }
    for(i = 0; i < n; i++){                 //print matrix
        for(j = 0; j < n; j++){
            printf("%4d",a[i][j]);
        }
        printf("\n");
    }
    return 0;

}

