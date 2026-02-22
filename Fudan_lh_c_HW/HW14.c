// ==========================================
// HW14_1
// ==========================================

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#define N 20
#define MAX 1000

typedef struct node{
    int value;
    struct node *next,*nextod;
}NODE;

int *iniNum(int a[],int n);
void outputNum(int a[],int n);
void output(NODE *h);
void output_od(NODE *h);
void freeLink(NODE *h);
NODE *iniLink(int a[],int n);
NODE *orderLink(int a[],int n,NODE *h);

int main(){
    srand((unsigned int)time(NULL));

    int a[N] = {0},n;
    NODE *h;

    n = rand() % 10 + 10;
    iniNum(a,n);
    printf("Randomly generate %d integers:\n",n);
    outputNum(a,n);

    h = iniLink(a,n);
    orderLink(a,n,h);

    printf("Linked list by generation order:\n");
    output(h);

    printf("Linked list by ascending order:\n");
    output_od(h);

    freeLink(h);

    return 0;
}
int *iniNum(int a[],int n){         //生成随机数，存于数组a中
    int i;
    for(i = 0; i < n; i++){
        a[i] = rand() % 100;
    }
    return a;
}
NODE *iniLink(int a[],int n){       //将数组a中的元素按顺序存入链表
    NODE *h, *newNode,*p;
    int i = 0;

    h = (NODE *)malloc(sizeof(NODE));   //辅助表元
    p = h;
    h->next = NULL;
    h->nextod = NULL;
    while(i < n){
        newNode = (NODE *)malloc(sizeof(NODE));
        newNode->value = *(a + i);
        p->next = newNode;
        p = newNode;
        newNode->next = NULL;
        newNode->nextod = NULL;
        i++;
    }

    return h;
    
}

NODE *orderLink(int a[],int n,NODE *h){
    int i, min,p,k;
    NODE *p_min,*pod;
    pod = h;
    for(k = 0;k < n;k++){           //循环n次，每次找出最小值并链接
        i = 0;
        p_min = h->next;
        min = MAX - 1;
        while(i < n){               //找出当前数组a中的最小值及其位置
            if(a[i] < min){
                min = a[i];
                p = i;
            }
            i++;
        }
        i = 0;
        while(i++ < p){             //找到对应的结点
            p_min = p_min->next;
        }
        a[p] = MAX;
        
        pod->nextod = p_min;
        pod = p_min;
        
    }
    pod->nextod = NULL;

    return h;
}
void outputNum(int a[],int n){      //输出数组a中的元素
    int i = 0;
    while(i < n){
        printf("%-3d",*(a + i));
        i++;
    }
    printf("\n");
}

void output(NODE *h){              //按生成顺序输出链表中的元素
    NODE *p;
    for(p = h->next;p;p = p->next){
        printf("%-3d",p->value);
    }
    printf("\n");
}

void output_od(NODE *h){            //按升序输出链表中的元素
    NODE *p;
    for(p = h->nextod;p;p = p->nextod){
        printf("%-3d",p->value);
    }
    printf("\n");
}

void freeLink(NODE *h){             //释放链表所占内存
    NODE *p,*q;
    p = h;
    while(p){
        q = p->next;
        free(p);
        p = q;
    }
}


// ==========================================
// HW14_2
// ==========================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1000
#define ENCRYPT 1  //标志常量, 代表加密 
#define DECRYPT 2  //标志常量, 代表解密 

//环形链表的表元类型 
typedef struct node
{
	int i;
	struct node* next;
}Node;

Node *makeLoop(char original[]);
char *process(char pher[],int key,char pro_pher[],int flag);
void freeLink(Node *h);
int main()
{
	int key;
	char original[N], cipher[N], decipher[N];

	printf("Enter some text (length < %d):\n", N);
	gets(original);
	printf("Enter the key: ");
	scanf("%d", &key);

	process(original, key, cipher, ENCRYPT);  //加密 
	printf("The cipher:\n%s\n", cipher);
	process(cipher, key, decipher, DECRYPT);  // 解密 
	printf("The decipher:\n%s\n", decipher);
    // freeLink(makeLoop(original));
	return 0;
}
Node *makeLoop(char original[]){
	Node *h, *newNode,*p;
	int n,k = 1;
	n = strlen(original);
	h = (Node *)malloc(sizeof(Node));
	h->next = NULL;
    h->i = 0;
    p = h;
	while(k < n){
		newNode = (Node *)malloc(sizeof(Node));
		newNode->i = k;
		p->next = newNode;
		p = newNode;
		p->next = NULL;

		k++;

	}
	p->next = h;

	return h;
}
char *process(char pher[],int key,char pro_pher[],int flag){
	Node *p,*t,*h;
	int i,n,k;
    n = strlen(pher);
    h = makeLoop(pher);

	for(p = h; p->next != h;p = p->next);   //p->next指向0

    for(k = 0;k < n;k++){
		for(i = 1 ; i < key;i++){       //报数key-1次
			p = p->next;
		}
        t = p->next;
        if(flag == ENCRYPT){
            pro_pher[k] = pher[t->i];
        }else{
            pro_pher[t->i] = pher[k];
        }
        p->next = t->next;
        t->next = NULL;
            
        if(t == p){
            p = NULL;
        }
        free(t);
	    
    }
    if(flag == ENCRYPT){
        pro_pher[k] = '\0';
        return pro_pher;
    }else{
        pro_pher[k] = '\0';
        return pro_pher;
    }

}
// void freeLink(Node *h){             //释放链表所占内存
//     Node *p,*q;
//     p = h;
//     while(p){
//         q = p->next;
//         free(p);
//         p = q;
//     }
// }



// ==========================================
// HW14_3
// ==========================================

/*
* 
* 难点:如何获取班级人数及作业次数?
* 解决方法:读入学生记录的同时,更新人数和作业次数;通过指针形参,返回人数和作业次数.
* 
*/

#include <stdio.h>
#include <string.h>
#define N 100
#define FNAME "students.csv"
#define FNAME_OUT "grades.csv"

struct Record {
	char name[40];
	int midterm, final;
	int hw[16];
	double grade;	//总评成绩 
};

//从键盘读入数据,并获取班级人数和作业次数
// void input_records(struct Record students[], int* n, int* m)
// {
// 	char c = '\0';

// 	*n = 0;
// 	while ((c = getchar()) != '\n') {  //判断每行读入的第一个字符是否为换行符(空行) 
// 		students[*n].name[0] = c;	//保存第一个字符
// 		//读入名字的余下部分及期中、期末成绩 
// 		scanf("%s%d%d", students[*n].name + 1, &students[*n].midterm, &students[*n].final);
// 		//读入平时作业成绩(假设至少有1次平时作业成绩) 
// 		for (*m = 0; c != '\n'; ++(*m))	//更新作业次数 
// 			scanf("%d%c", students[*n].hw + *m, &c);  //读入作业成绩及其后的空白字符
// 		(*n)++;	//更新学生人数 
// 	}
// }

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

//对齐输出学生记录 
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

//对学生记录按照名字顺序排序 
void sort_by_name(struct Record* pStu[], int n)
{
	int i, j;
	struct Record* p;

	for (i = 1; i < n; i++)
		for (j = 0; j < n - i; j++)
			if (strcmp(pStu[j]->name, pStu[j + 1]->name) > 0) {
				// 交换指针
				p = pStu[j];
				pStu[j] = pStu[j + 1];
				pStu[j + 1] = p;
			}
}

//按名字顺序对齐输出总评成绩 
void print_grades(struct Record* pStu[], int n, int maxlen)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%-*s%.1f\n", maxlen + 1, pStu[i]->name, pStu[i]->grade);
	printf("\n");
}

void finput_records(char *fname, struct Record students[], int* n, int* m){
	FILE *fp;
	if((fp = fopen(fname,"r")) == NULL){
		printf("can't open file %s.\n", fname);
		return;
	}
	*n = 0;
	char c = ',';
	int k;

	while (fscanf(fp, " %c",&c) == 1) {  //判断每行读入的第一个字符是否为换行符(空行) 
		students[*n].name[0] = c;
		k = 1;
		while(fscanf(fp,"%c",&c) == 1 && c != ','){
			students[*n].name[k++] = c;
		}
		students[*n].name[k] = '\0';
		
		fscanf(fp,"%d,%d,",&students[*n].midterm,&students[*n].final);
		//读入平时作业成绩(假设至少有1次平时作业成绩) 
		*m = 0;
		do{
			fscanf(fp,"%d%c",&students[*n].hw[*m],&c);
			(*m)++;
		}while(c != '\n' && c != EOF && !feof(fp));

		(*n)++;	//更新学生人数 
	}
    fclose(fp);


}
void foutput_records(char *fname_out,struct Record *pStu[],int n){
	FILE *fp;
	int i;

	if((fp = fopen(fname_out,"w")) == NULL){
		printf("can't open file %s.\n", fname_out);
		return;
	}
	for(i = 0;i < n; i++){
		fprintf(fp,"%s,%.1f\n",pStu[i]->name,pStu[i]->grade);
	}
	fclose(fp);

}

int main()
{
	struct Record students[N], * pStu[N];
	int n, m;  //n保存人数, m保存作业次数
	int i, max_name_len;

	char fname[40] = FNAME;
	char fname_out[40] = FNAME_OUT;
	
	
	// printf("Enter the original records:\n");
	finput_records(fname,students,&n, &m);
	for (i = 0; i < n; i++) {
		pStu[i] = students + i;  		//给指针数组元素赋值
		calculate_grade(pStu[i], m);	//计算每位学生的总评成绩 
	}

	printf("All students'records:\n");
	max_name_len = get_max_name_len(students, n);
	print_records(pStu, n, m, max_name_len);

	sort_by_name(pStu, n);

	printf("\nAll students' final grades (sorted by name):\n");
	print_grades(pStu, n, max_name_len);
    foutput_records(fname_out,pStu,n);
	return 0;
}




// ==========================================
// HW14_3_show
// ==========================================

/*
* 
* �ѵ�:��λ�ȡ�༶��������ҵ����?
* �������:����ѧ����¼��ͬʱ,������������ҵ����;ͨ��ָ���β�,������������ҵ����.
* 
*/

#include <stdio.h>
#include <string.h>
#define N 100
#define FNAME "students.csv"
#define FNAME_OUT "grades.csv"

struct Record {
	char name[40];
	int midterm, final;
	int hw[16];
	double grade;	//�����ɼ� 
};

//�Ӽ��̶�������,����ȡ�༶��������ҵ����
// void input_records(struct Record students[], int* n, int* m)
// {
// 	char c = '\0';

// 	*n = 0;
// 	while ((c = getchar()) != '\n') {  //�ж�ÿ�ж���ĵ�һ���ַ��Ƿ�Ϊ���з�(����) 
// 		students[*n].name[0] = c;	//�����һ���ַ�
// 		//�������ֵ����²��ּ����С���ĩ�ɼ� 
// 		scanf("%s%d%d", students[*n].name + 1, &students[*n].midterm, &students[*n].final);
// 		//����ƽʱ��ҵ�ɼ�(����������1��ƽʱ��ҵ�ɼ�) 
// 		for (*m = 0; c != '\n'; ++(*m))	//������ҵ���� 
// 			scanf("%d%c", students[*n].hw + *m, &c);  //������ҵ�ɼ������Ŀհ��ַ�
// 		(*n)++;	//����ѧ������ 
// 	}
// }

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

void finput_records(char *fname, struct Record students[], int* n, int* m){
	FILE *fp;
	if((fp = fopen(fname,"r")) == NULL){
		printf("can't open file %s.\n", fname);
		return;
	}
	*n = 0;
	char c = ',';
	int k;

	while (fscanf(fp, " %c",&c) == 1) {  //�ж�ÿ�ж���ĵ�һ���ַ��Ƿ�Ϊ���з�(����) 
		students[*n].name[0] = c;
		k = 1;
		while(fscanf(fp,"%c",&c) == 1 && c != ','){
			students[*n].name[k++] = c;
		}
		students[*n].name[k] = '\0';
		
		fscanf(fp,"%d,%d,",&students[*n].midterm,&students[*n].final);
		//����ƽʱ��ҵ�ɼ�(����������1��ƽʱ��ҵ�ɼ�) 
		*m = 0;
		do{
			fscanf(fp,"%d%c",&students[*n].hw[*m],&c);
			(*m)++;
		}while(c != '\n' && c != EOF && !feof(fp));

		(*n)++;	//����ѧ������ 
	}
    fclose(fp);


}
void foutput_records(char *fname_out,struct Record *pStu[],int n){
	FILE *fp;
	int i;

	if((fp = fopen(fname_out,"w")) == NULL){
		printf("can't open file %s.\n", fname_out);
		return;
	}
	for(i = 0;i < n; i++){
		fprintf(fp,"%s,%.1f\n",pStu[i]->name,pStu[i]->grade);
	}
	fclose(fp);

}

int main()
{
	struct Record students[N], * pStu[N];
	int n, m;  //n��������, m������ҵ����
	int i, max_name_len;

	char fname[40] = FNAME;
	char fname_out[40] = FNAME_OUT;
	
	
	// printf("Enter the original records:\n");
	finput_records(fname,students,&n, &m);
	for (i = 0; i < n; i++) {
		pStu[i] = students + i;  		//��ָ������Ԫ�ظ�ֵ
		calculate_grade(pStu[i], m);	//����ÿλѧ���������ɼ� 
	}

	printf("All students'records:\n");
	max_name_len = get_max_name_len(students, n);
	print_records(pStu, n, m, max_name_len);

	sort_by_name(pStu, n);

	printf("\nAll students' final grades (sorted by name):\n");
	print_grades(pStu, n, max_name_len);
    foutput_records(fname_out,pStu,n);
	return 0;
}




// ==========================================
// HW14_3_toshow
// ==========================================

/*
* 
* �ѵ�:��λ�ȡ�༶��������ҵ����?
* �������:����ѧ����¼��ͬʱ,������������ҵ����;ͨ��ָ���β�,������������ҵ����.
* 
*/

#include <stdio.h>
#include <string.h>
#define N 100
#define FNAME "students.csv"
#define FNAME_OUT "grades.csv"

struct Record {
	char name[40];
	int midterm, final;
	int hw[16];
	double grade;	//�����ɼ� 
};

//�Ӽ��̶�������,����ȡ�༶��������ҵ����
// void input_records(struct Record students[], int* n, int* m)
// {
// 	char c = '\0';

// 	*n = 0;
// 	while ((c = getchar()) != '\n') {  //�ж�ÿ�ж���ĵ�һ���ַ��Ƿ�Ϊ���з�(����) 
// 		students[*n].name[0] = c;	//�����һ���ַ�
// 		//�������ֵ����²��ּ����С���ĩ�ɼ� 
// 		scanf("%s%d%d", students[*n].name + 1, &students[*n].midterm, &students[*n].final);
// 		//����ƽʱ��ҵ�ɼ�(����������1��ƽʱ��ҵ�ɼ�) 
// 		for (*m = 0; c != '\n'; ++(*m))	//������ҵ���� 
// 			scanf("%d%c", students[*n].hw + *m, &c);  //������ҵ�ɼ������Ŀհ��ַ�
// 		(*n)++;	//����ѧ������ 
// 	}
// }

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

void finput_records(char *fname, struct Record students[], int* n, int* m){
	FILE *fp;
	if((fp = fopen(fname,"r")) == NULL){
		printf("can't open file %s.\n", fname);
		return;
	}
	*n = 0;
	char c = ',';
	int k;

	while (fscanf(fp, " %c",&c) == 1) {  //�ж�ÿ�ж���ĵ�һ���ַ��Ƿ�Ϊ���з�(����) 
		students[*n].name[0] = c;
		k = 1;
		while(fscanf(fp,"%c",&c) == 1 && c != ','){
			students[*n].name[k++] = c;
		}
		students[*n].name[k] = '\0';
		
		fscanf(fp,"%d,%d,",&students[*n].midterm,&students[*n].final);
		//����ƽʱ��ҵ�ɼ�(����������1��ƽʱ��ҵ�ɼ�) 
		*m = 0;
		do{
			fscanf(fp,"%d%c",&students[*n].hw[*m],&c);
			(*m)++;
		}while(c != '\n' && c != EOF && !feof(fp));

		(*n)++;	//����ѧ������ 
	}
    fclose(fp);


}
void foutput_records(char *fname_out,struct Record *pStu[],int n){
	FILE *fp;
	int i;

	if((fp = fopen(fname_out,"w")) == NULL){
		printf("can't open file %s.\n", fname_out);
		return;
	}
	for(i = 0;i < n; i++){
		fprintf(fp,"%s,%.1f\n",pStu[i]->name,pStu[i]->grade);
	}
	fclose(fp);

}

int main()
{
	struct Record students[N], * pStu[N];
	int n, m;  //n��������, m������ҵ����
	int i, max_name_len;

	char fname[40] = FNAME;
	char fname_out[40] = FNAME_OUT;
	
	
	// printf("Enter the original records:\n");
	finput_records(fname,students,&n, &m);
	for (i = 0; i < n; i++) {
		pStu[i] = students + i;  		//��ָ������Ԫ�ظ�ֵ
		calculate_grade(pStu[i], m);	//����ÿλѧ���������ɼ� 
	}

	printf("All students'records:\n");
	max_name_len = get_max_name_len(students, n);
	print_records(pStu, n, m, max_name_len);

	sort_by_name(pStu, n);

	printf("\nAll students' final grades (sorted by name):\n");
	print_grades(pStu, n, max_name_len);
    foutput_records(fname_out,pStu,n);
	return 0;
}




