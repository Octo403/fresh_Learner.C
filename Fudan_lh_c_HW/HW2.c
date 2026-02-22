// ==========================================
// HW2_1
// ==========================================

#include<stdio.h>
int main()
{
	int item_number;
	float unit_price;
	int month, date,year;
	printf("Enter item number: ");
	scanf("%d",&item_number);
	printf("Enter unit price: ");
	scanf("%f",&unit_price);
	printf("Enter purchase date(mm/dd/yyyy): ");
	scanf("%d/%d/%d",&month, &date, &year);
	printf("\n");
	
	printf("Item\tUnit\t\tPurchase\t");
	printf("\n\tPrice\t\tDate\t");
	printf("\n%-d\t$%7.2f\t%-d%02d%02d", item_number, unit_price, year, month, date);
	
	return 0;
 } 


// ==========================================
// HW2_2
// ==========================================

#include<stdio.h>
int main()
{
	int number;
	int ge;
	int shi;
	int bai;
	int qian;
	int sum;
	printf("Enter a 4-digit number: ");
	scanf("%d", &number);
	ge=number % 10;
	shi=((number - ge) / 10) % 10;
	bai=(((number - ge) / 10 - shi) / 10) % 10;
	qian=(((((number - ge) / 10 - shi) / 10) - bai) / 10) % 10;
	sum=ge + shi + bai + qian;
	printf("%d+%d+%d+%d=%d",qian, bai, shi, ge, sum);
	
	return 0;
}
	
	




// ==========================================
// HW2_3
// ==========================================

#include<stdio.h>
#include<math.h>
int main()
{
	float loan;
	float rate;
	float monthly_payment;
	float month_one;
	float month_two;
	float month_three;
	float m_rate;
	
	printf("Enter amount of loan:");
	scanf("%f", &loan);
	printf("Enter interest rate:");
	scanf("%f", &rate);
	printf("Enter monthly payment:");
	scanf("%f", &monthly_payment);
	printf("\n");
	m_rate=rate/12/100;
	month_one=loan*(m_rate+1)-monthly_payment;
	month_two=month_one*(m_rate+1)-monthly_payment;
	month_three=month_two*(m_rate+1)-monthly_payment;
	
	printf("Banlance remaining after 1 month: $%.2f\n", month_one);
	printf("Banlance remaining after 2 month: $%.2f\n", month_two);
	printf("Banlance remaining after 3 month: $%.2f\n", month_three);
	
	return 0;
 } 


