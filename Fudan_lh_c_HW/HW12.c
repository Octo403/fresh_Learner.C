// ==========================================
// HW12_1
// ==========================================

#include<stdio.h>
#include<math.h>
#include<string.h>
#define N 101
int comstr(char s1[],char s2[],char s3[]);
int main(){
    char s1[N],s2[N],s3[N];
    printf("Enter 3 strings (lenth < 100) :\n");
    printf("s1: ");
    gets(s1);
    printf("s2: ");
    gets(s2);
    printf("s3: ");
    gets(s3);
    comstr(s1,s2,s3);

    return 0;
}
int comstr(char s1[],char s2[],char s3[]){
    int len,l,i;
    char substr[N];
    len = strlen(s1);
    for(l = len;l > 0;l--){
        for(i = 0;i <= len - l;i++){
            strncpy(substr,s1 + i,l);
            substr[l] = '\0';
            if (strstr(s2,substr) && strstr(s3,substr)){
                printf("Longest common substring: (%s)",substr);
                return 0;
            }
        }
    }
    printf("No common substring");
    return 0;
}


// ==========================================
// HW12_2.h
// ==========================================


#include <stdio.h>
#include <string.h>
#define N 100

struct Record {
	char name[40];
	int midterm, final;
	int hw[16];
	double grade;	//�����ɼ� 
};

//�Ӽ��̶�������,����ȡ�༶��������ҵ����
void input_records(struct Record students[], int* n, int* m)
{
	char c = '\0';

	*n = 0;
	while ((c = getchar()) != '\n') {  //�ж�ÿ�ж���ĵ�һ���ַ��Ƿ�Ϊ���з�(����) 
		students[*n].name[0] = c;	//�����һ���ַ�
		//�������ֵ����²��ּ����С���ĩ�ɼ� 
		scanf("%s%d%d", students[*n].name[1], &students[*n].midterm, &students[*n].final);
		//����ƽʱ��ҵ�ɼ�(����������1��ƽʱ��ҵ�ɼ�) 
		for (*m = 0;c != '\n';++(*m))	//������ҵ���� 
			scanf("%d%c", students[*n].hw + *m, &c);  //������ҵ�ɼ������Ŀհ��ַ�
		(*n)++;	//����ѧ������ 
	}
}

void calculate_grade(struct Record* pStu, int m)
{
	int i, sum = 0;
	for (i = 0; i < m; i++)
		sum += pStu->hw[i];
	pStu->grade = 0.2 * pStu->midterm + 0.4 * pStu->final + 0.4 * sum / m;
}

int get_max_name_len(struct Record* students, int n)
{
	int len, max_name_len;
	struct Record* p;

	max_name_len = strlen(students[0].name);
	for (p = students + 1; p < students + n; p++) {
		len = strlen(p->name);
		if (len > max_name_len)
			max_name_len = len;
	}
	return max_name_len;
}

//�������ѧ����¼ 
void print_records(struct Record* pStu[], int n, int m, int maxlen)
{
	int i, j;
	for (i = 0; i < n; i++) {
		printf("%-*s", maxlen + 1, pStu[i]->name);
		printf("%-4d%-4d", pStu[i]->midterm, pStu[i]->final);
		for (j = 0; j < m; j++)
			printf("%-4d", pStu[i]->hw[j]);
		printf("\n");
	}
}

//��ѧ����¼��������˳������ 
void sort_by_name(struct Record* pStu[], int n)
{
	int i, j;
	struct Record* p;

	for (i = 1; i < n; i++)
		for (j = 0; j < n - i; j++)
			if (strcmp(pStu[j]->name, pStu[j + 1]->name) > 0) {
				// ����ָ��
				p = pStu[j];
				pStu[j] = pStu[j + 1];
				pStu[j + 1] = p;
			}
}

//������˳�������������ɼ� 
void print_grades(struct Record* pStu[], int n, int maxlen)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%-*s%.1f\n", maxlen + 1, pStu[i]->name, pStu[i]->grade);
	printf("\n");
}

int main()
{
	struct Record students[N], * pStu[N];
	int n, m;  
	int i, max_name_len;

	printf("Enter the original records:\n");
	input_records(students, &n, &m);
	for (i = 0; i < n; i++) {
		pStu[i] = students + i;  		
		calculate_grade(pStu[i], m);	
	}

	printf("All students'records:\n");
	max_name_len = get_max_name_len(students, n);
	print_records(pStu, n, m, max_name_len);

	sort_by_name(pStu, n);

	printf("\nAll students' final grades (sorted by name):\n");
	print_grades(pStu, n, max_name_len);

	return 0;
}


// ==========================================
// HW12_3
// ==========================================
#ifndef HW12_3_H
#define HW12_3_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 常量定义
#define DECK_SIZE 52
#define SUIT_COUNT 4
#define FACE_COUNT 13

// 花色和面值的字符串数
static const char *suits[] = {"Spades", "Hearts", "Diammonds", "Clubs"};
static const char *faces[] = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

// 纸牌结构体
struct Card{
    const char *suit;  // 花色
    const char *face;  // 面值
};

// 函数声明
void initCards(struct Card deck[]);
void shuffle(struct Card deck[]);
void outputCards(struct Card deck[]);
void swapCards(struct Card *a, struct Card *b);

#endif

// ==========================================
// HW12_3
// ==========================================

#include "HW12_3.h"
int main() {
    struct Card deck[SUIT_COUNT * FACE_COUNT];
    printf("                    /* Shuffling Cards Program */\n\n");  
    printf("The initial cards are:\n");
    initCards(deck);                                   
    outputCards(deck);            
    printf("\n\nThe shuffled cards are:\n");        
    shuffle(deck);                                  
    outputCards(deck);                              
    return 0;
}
void initCards(struct Card deck[]){
    int suit,face;
    int count = 0;
    for(suit = 0;suit < SUIT_COUNT;suit++){
        for(face = 0;face < FACE_COUNT;face++){
            deck[count].face = faces[face];
            deck[count].suit = suits[suit];
            count++;
        }
    }
}
void shuffle(struct Card deck[]){
    srand((unsigned int)time(NULL));
    int i;
    for(i=0;i<SUIT_COUNT * FACE_COUNT;i++){
        int key;
        key = rand()%52;
        swapCards(&deck[i],&deck[key]);
    }
}
void swapCards(struct Card *a, struct Card *b){
    struct Card temp = *a;
    *a = *b;
    *b = temp;
}
void outputCards(struct Card deck[]){
    int i;
    for(i = 0;i < SUIT_COUNT * FACE_COUNT;i++){
        printf("%-11s",deck[i].suit);
        printf("%-6s|",deck[i].face);
        if((i+1)%7 == 0){
            putchar('\n');
        }
    }
}

// ==========================================
// HW12_4
// ==========================================

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
int main(){
    int num,i,*p,child,teen,youth,middle,elder,age;
    child = teen = youth = middle = elder = 0;
    srand((unsigned int)time(NULL));
    printf("Enter the number of people:");
    scanf("%d",&num);
    p = (int *)calloc(num,sizeof(int));
    printf("\nGenerate the ages of %d people randomly:\n",num);

    for(i = 0;i < num;i++){
        *(p+i) = rand() % 101;
        printf("%-4d",*(p+i));
        if((i+1) % 10 == 0){
            putchar('\n');
        }
    }
    for(i = 0;i < num;i++){
        age = *(p + i);
        if(age > 65)
            elder++;
        else if(age > 35)
            middle++;
        else if(age > 19)
            youth++;
        else if(age > 12)
            teen++;
        else
            child++;
    }
    
    printf("\nStatistics for each age group:\n");
    printf("Children   : %d",child);
    printf("\nTeenagers  : %d",teen);
    printf("\nYouth      : %d",youth);
    printf("\nMiddle-aged: %d",middle);
    printf("\nElderly    : %d",elder);

    free(p);

    return 0;
}

