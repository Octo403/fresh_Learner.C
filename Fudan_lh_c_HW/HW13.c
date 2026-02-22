// ==========================================
// HW13_1
// ==========================================

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#define N 10
#define M 100

struct intNode{
    int value;
    struct intNode *next;
};

struct intNode *initLink();
struct intNode *copy(struct intNode *h);
struct intNode *copyReversed(struct intNode *h);
struct intNode *copySorted(struct intNode *h);
void outputLink(struct intNode *h);
void freeLink(struct intNode *h);

int main()
{
	struct intNode* h[4];
	int i;

	h[0] = initLink();
	h[1] = copy(h[0]);
	h[2] = copyReversed(h[0]);
	h[3] = copySorted(h[0]);

	char *prompt[] = { "Random list", "List copy", "Reversed list copy", "Sorted list copy" };
	for (i = 0; i < 4; i++) {
		printf("%s: \n", prompt[i]);
		outputLink(h[i]);
	}

	for (i = 0; i < 4; i++)
		freeLink(h[i]);

	return 0;
}
struct intNode *initLink(){
	srand((unsigned)time(NULL));
    struct intNode *h = NULL, *newNode;
	int i=0;
    while(i++<N){
        newNode = (struct intNode *)malloc(sizeof(struct intNode));
        newNode->value = rand()%M;
        newNode -> next = h;
        h = newNode;
    }
    return h;
}
struct intNode *copy(struct intNode *h){
    struct intNode *copy_h = NULL, *tail = NULL, *p,*newNode;
    for( p = h;p;p = p->next){
        newNode = (struct intNode *)malloc(sizeof(struct intNode));
        newNode->value = p->value;
        newNode->next = NULL;
        if(copy_h==NULL){
            copy_h = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }
    return copy_h;
    
}
struct intNode *copyReversed(struct intNode *h){
    struct intNode *cpy_h = copy(h);
    struct intNode *v1,*v2,*p;
    v1 = NULL;
    v2 = cpy_h;
    while(v2){
        p = v2->next;
        v2 ->next = v1;
        v1 = v2;
        v2 = p;
    }
    return v1;
}
struct intNode *copySorted(struct intNode *h){
    struct intNode *sort_h = NULL,*newNode,*p = h,*ps;
    newNode = (struct intNode *)malloc(sizeof(struct intNode));
    newNode->value = p->value;
    newNode->next = NULL;
    sort_h = newNode;
    for(p = h->next;p;p = p->next){
        newNode = (struct intNode *)malloc(sizeof(struct intNode));
        newNode->value = p->value;
        if(p->value < sort_h->value){
            newNode->next = sort_h;
            sort_h = newNode;
        }else{
            ps = sort_h;
            while(ps->next && ps->next->value < p->value){
                ps = ps->next;
            }
            newNode->next = ps->next;
            ps->next = newNode;
        }
    }
    return sort_h;
}
void outputLink(struct intNode *h){
    struct intNode *p;
    for(p = h;p;p = p->next){
        printf("%4d ",p->value);
    }
    printf("\n");
}
void freeLink(struct intNode *h){
    struct intNode *p,*q;
    p = h;
    while(p){
        q = p->next;
        free(p);
        p = q;
    }
}


// ==========================================
// HW13_2
// ==========================================

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define N 10
#define M 100

struct intNode{
    int value;
    struct intNode *next;
};
struct intNode *initLink();
struct intNode *delMin(struct intNode *h);
struct intNode *copy(struct intNode *h);
void outputLink(struct intNode *h);
void freeLink(struct intNode *h);

int main()
{
	struct intNode* h[5];

	h[0] = initLink();
	h[1] = copy(h[0]);
	// h[2] = copyReversed(h[0]);
	// h[3] = copySorted(h[0]);
    h[4] = delMin(h[0]);

	char *prompt[] = { "Random list", "List copy", "Reversed list copy", "Sorted list copy","After deleting the minimun value" };
	
	printf("%s: \n", prompt[0]);
	outputLink(h[0]);
    printf("%s: \n", prompt[4]);
	outputLink(h[4]);

	
	freeLink(h[0]);
    freeLink(h[1]);
    freeLink(h[4]);

	return 0;
}

struct intNode *initLink(){
	srand((unsigned)time(NULL));
    struct intNode *h = NULL, *newNode;
	int i=0;
    while(i++<N){
        newNode = (struct intNode *)malloc(sizeof(struct intNode));
        newNode->value = rand()%M;
        newNode -> next = h;
        h = newNode;
    }
    return h;
}
void outputLink(struct intNode *h){
    struct intNode *p;
    for(p = h;p;p = p->next){
        printf("%4d ",p->value);
    }
    printf("\n");
}
void freeLink(struct intNode *h){
    struct intNode *p,*q;
    p = h;
    while(p){
        q = p->next;
        free(p);
        p = q;
    }
}
struct intNode *copy(struct intNode *h){
    struct intNode *copy_h = NULL, *tail = NULL, *p,*newNode;
    for( p = h;p;p = p->next){
        newNode = (struct intNode *)malloc(sizeof(struct intNode));
        newNode->value = p->value;
        newNode->next = NULL;
        if(copy_h == NULL){
            copy_h = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }   
    }
    return copy_h;
}

struct intNode *delMin(struct intNode *h){
    struct intNode *p, *ran_h,*p_del = NULL,*p_Front,*p_delFront = NULL,*min;
    ran_h = copy(h);
    p_Front = ran_h;
    min = ran_h;
    for(p = ran_h->next;p;p = p->next,p_Front = p_Front->next){
        if(p->value < min->value){
            p_del = p;
            p_delFront = p_Front;
            min = p;
        }
    }
    if(min == ran_h){
        p_del = ran_h;
        ran_h = ran_h->next;
    }
    else
        p_delFront->next = p_del->next;
    free(p_del);
    return ran_h;
}

// ==========================================
// HW13_3
// ==========================================

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct intNode{
    int power;

    struct intNode *next;
};

struct intNode *inipoly();
struct intNode *addpoly(struct intNode *l,struct intNode *k);
void outputpoly(struct intNode *l);
void freepoly(struct intNode *l);

int main(){
    struct intNode *l, *k;

    printf("\t\tPolynomical summation\n");
    printf("\tEnter the power and coefficient of the 1st polynomiacal\n");
    l = inipoly();
    printf("\tEnter the power and coefficient of the 2nds polynomiacal\n");
    k = inipoly();
    printf("\n");
    outputpoly(l);
    printf("+");
    outputpoly(k);
    printf("=");

    l = addpoly(l,k);
    outputpoly(l);
    freepoly(l);
    freepoly(k);

    return 0;

}
struct intNode *inipoly(){
    struct intNode *head = NULL,*p,*newNode,*p_Front;
    int power;

    printf("Power (enter non-numeric character for end) : ");
    while(scanf("%d",&power) > 0){
        newNode = (struct intNode *)malloc(sizeof(struct intNode));
        newNode->power = power;
        printf("Coefficient of power: %d : ",newNode->power);
        scanf("%f",&newNode->coef);
        p = head;
        while(p && p->power > power){
            p_Front = p;
            p = p->next;
        }
        if(p == head){          //首表元前插入
            newNode->next = head;
            head = newNode;
        }else{                  //中间或尾部插入
            newNode->next = p;
            p_Front->next = newNode;
        }
        printf("Power (enter non-numeric character for end) : ");
    }
    while(getchar() != '\n');
    return head;
}
struct intNode *addpoly(struct intNode *l,struct intNode *k){
    struct intNode *lpt,*kpt,*lpt_F = NULL,*newNode;
    lpt = l;
    kpt = k;
    while(lpt&&kpt){
        if(kpt->power == lpt->power){
            lpt->coef = kpt->coef + lpt->coef;
            
            if(lpt->coef == 0){             //系数为零
                struct intNode *temp = lpt;
                lpt = lpt->next;
                if(temp == l){          //首表元系数为零
                    l = lpt;
                }else{
                    lpt_F->next = lpt;
                }
                free(temp);
            }else{
                lpt_F = lpt;
                lpt = lpt->next;
            }
            kpt = kpt->next;
        }else if(lpt->power > kpt->power){
            lpt_F = lpt;
            lpt = lpt->next;
        }else{
            newNode = (struct intNode *)malloc(sizeof(struct intNode));
            newNode->power = kpt->power;
            newNode->coef = kpt->coef;
            newNode->next = lpt;
            if(lpt == l){           //首表元前插入
                l = newNode;
            }else{
                lpt_F->next = newNode;
            }
            lpt_F = newNode;
            kpt = kpt->next;
        }
    }
    while(kpt){                     //k表还有剩余项
        newNode = (struct intNode *)malloc(sizeof(struct intNode));
        newNode->power = kpt->power;
        newNode->coef = kpt->coef;
        newNode->next = NULL;
            if(l == NULL){      //l表为空了
                l = newNode;
                lpt_F = newNode;
            }else{
                lpt_F->next = newNode;
                lpt_F = newNode;
            }
            kpt = kpt->next;
    }
    return l;
}
void outputpoly(struct intNode *l){
    struct intNode *lp = l;
    if(lp){
        printf("(");
       if(lp->power == 0){
                printf("%g",lp->coef);
        }else{
            if(lp->power == 1)
                printf("%gx",lp->coef);
            else{
                printf("%gx^%d",lp->coef,lp->power);
            }
        }
        lp = lp->next;
        while(lp){
            if(lp->coef >= 0){
                printf("+");
            }
            if(lp->power == 0){
                printf("%g",lp->coef);
            }else{
                if(lp->power == 1)
                    printf("%gx",lp->coef);
                else
                    printf("%gx^%d",lp->coef,lp->power);
            }
            lp = lp->next;
        }
        printf(")");
    }else
        printf("0");
}
void freepoly(struct intNode *l){
    struct intNode *p,*q;
    p = l;
    while(p){
        q = p->next;
        free(p);
        p = q;
    }
}




