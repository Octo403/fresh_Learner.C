# fresh_Learner.C
本科程序设计所学

Homework 1

HW1_1.输出 To C, or not to C: that is the question.

HW1_2.两数之和

以下为 Hw1_2程序运行时的样例(下划线部分代表键盘输入的内容，\n代表回车):

输出：Input x and y:
键盘输入：374612 4738\n
输出：374612+4738=379350

HW1_3.华氏温度与摄氏温度对照表（运行样例如下）
![HW1_3 (1)](https://github.com/user-attachments/assets/36cb6c78-747a-4468-97d7-91aac299eeb7)

Homework 2

HW2_1. 编写程序, 对用户录入的产品信息进行格式化输出.  其中, 产品编号和日期项采用左对齐方式, 单位价格假设最大取值为$9999.99并采用右对齐方式. 提示: 各列之间使用制表符控制.
![HW2_1_1](https://github.com/user-attachments/assets/7278737c-f82e-43dc-b265-95fe920f3148)
<img width="1608" height="556" alt="HW2_1_2" src="https://github.com/user-attachments/assets/9cdc33ae-fe19-4030-8708-4ef30ff07d4c" />

HW2_2. 编写程序, 要求用户输入一个四位正整数并保存于一个整型变量中, 计算并输出其各位数字之和. 要求: 通过算术运算获得四位数每一位的值.

<img width="267" height="46" alt="HW2_2" src="https://github.com/user-attachments/assets/a5c76be1-88a2-40bd-8f13-d9a30f4a9b78" />
HW2_3. 编写程序, 对用户录入的贷款信息计算第一、第二、第三个月还贷后剩余的贷款金额(保留两位小数).  提示: 每个月的贷款余额需要加上利息(上个月贷款余额与月利率的乘积, 月利率是年利率除以12).

<img width="1586" height="556" alt="HW2_3" src="https://github.com/user-attachments/assets/1f3ceeb6-d1ea-462e-aacb-663d4046fe0e" />

Homework 3

HW3_1. 欧洲使用13位的欧洲商品编码(European Article Number, EAN), 每个EAN码的最后一位是校验位. 计算校验位的方法为: 首先把第2、4、6、8、10、12位的数字相加; 然后把第1、3、5、7、9、11位的数字相加; 接着把第一次加法的结果乘以3, 再和第二次加法的结果相加; 随后, 再把上述结果减去1; 相减后的结果除以10取余数; 最后用9减去余数得到的就是校验位. 编写程序, 输入一个13位的EAN, 判断校验位是否有效.

Tip. 13位整数已经超出int/long的范围, 所以不能用一个int/long型变量保存EAN码. 本课程未学习long long int类型, 所以也不要使用该类型.

![HW3_1_1](https://github.com/user-attachments/assets/3e39cca6-73b0-4b09-b66a-d2bb8f375594)

<img width="322" height="41" alt="HW3_1_2" src="https://github.com/user-attachments/assets/fa9561a2-e939-4294-83a6-a3f45c2497ed" />

HW3_2. 编写程序, 输入4个整数, 输出它们中的最大值和最小值.   要求使用尽可能少的if...else...语句或条件(三目)运算表达式, 因为一个条件(三目)运算表达式相当于一个if...else...结构.

<img width="1077" height="255" alt="HW3_2_1" src="https://github.com/user-attachments/assets/7447d47f-80bd-4ab2-bae5-9e9097fa7cf4" />

<img width="949" height="242" alt="HW3_2_2" src="https://github.com/user-attachments/assets/afff26bf-ceff-475d-994b-c4309b76535e" />

HW3_3.编写程序，输入3对实数，若每对实数分别作为平面坐标系中点的坐标，判断这3个点是否能构成一个三角形。若能构成三角形，判断这个三角形的特征：是直角三角形，等边三角形，等腰三角形还是普通三角形等。Tip. 计算机的浮点数运算存在误差.

<img width="504" height="54" alt="HW3_3_1" src="https://github.com/user-attachments/assets/a91533a4-fa2a-4294-ac39-094f73359247" />

<img width="504" height="54" alt="HW3_3_2" src="https://github.com/user-attachments/assets/d57fb85a-88ab-4047-9d1d-52834aeec7bb" />

<img width="576" height="53" alt="HW3_3_3" src="https://github.com/user-attachments/assets/4016e913-e444-4c67-9511-82e0f5aa3e3d" />

<img width="502" height="55" alt="HW3_3_4" src="https://github.com/user-attachments/assets/86b0f950-e5ca-4603-8ead-45bd9428810e" />

<img width="503" height="59" alt="HW3_3_5" src="https://github.com/user-attachments/assets/642e2642-f540-4215-92ca-f227d8f585ab" />

<img width="547" height="57" alt="HW3_3_6" src="https://github.com/user-attachments/assets/f4be60c2-ec7d-420e-a49c-4be7d7fbca79" />

Homework 4

HW4_1.编写一个程序，输入一个整数，输出0~9各个数字在该整数中出现的次数。要求: 1) 用switch...case结构实现各数字的计数; 2) 跳过输入中的前导空白符(参照示例); 3) 没有出现过的数字不输出(参照示例). 

![HW4_1 ](https://github.com/user-attachments/assets/86c0a005-b594-43cf-9651-77d70ead0a5e)

HW4_2. 编写程序, 输入一个正整数(在int值范围内, 用一个int型变量保存), 逆序输出该正整数. 要求: 循环计算整数的每一位数值并输出. 注意: 原数若以0结尾, 逆序时不输出0, 但原数中间包含的0原样输出.

![HW4_2_1](https://github.com/user-attachments/assets/be54170f-0f69-4b0e-8bbb-7f82b9d895b9)
![HW4_2_2](https://github.com/user-attachments/assets/ed619800-2bd3-4f2f-bd8a-77bfdde87e3a)

HW4_3. 编写程序, 要求用户输入两个由分子和分母构成的分数, 中间用加号隔开, 计算这两个分数的和, 仍旧以分数的形式输出. 要求: 最终结果须化简.

<img width="544" height="50" alt="HW4_3_1" src="https://github.com/user-attachments/assets/257c7a43-cbde-480a-b24f-05b7f04dedcf" />

<img width="542" height="46" alt="HW4_3_2" src="https://github.com/user-attachments/assets/2d84c18c-fe82-474d-8332-6e5fb937bb9c" />

Homework 5

HW5_1. 编写程序，用泰勒公式计算自然对数底e的值。e = 1 + 1/1! + 1/2! + 1/3!...

要求:

1) 按公式计算直到某项小于等于10-10.  注意: n!和x高次幂都会产生溢出. 

2) 输出结果保留15位有效数字, 但不输出无意义的0

Tip. 尽管泰勒公式适用于x<0的情况, 但是由于浮点数的精度有限, 导致大数相减时会丢失有效数字. 因此, x<0时，可利用e^x = 1/e^-x计算, 从而避免大数相减.

<img width="275" height="42" alt="HW5_1_1" src="https://github.com/user-attachments/assets/38c0a620-651d-4070-9bbc-c05eaf3027ec" />

HW5_2. 编写程序,已知自变量x在区间[0，3]上，函数f(x) = x^3-x^2-1有一个实根，试用二分法求该函数的根。
精度为10-6. 要求输出中间结果.  

Tip. 以下两种输出结果都正确. 按照题目描述: 循环直至|high-low|小于指定精度. 此时, 我们认为high与low已然相等, 但四舍五入的结果在小数点后第6位并不相同.

<img width="2934" height="1753" alt="HW5_2_1" src="https://github.com/user-attachments/assets/e7a7dc43-99cf-4daa-9441-c2a83d662097" />

HW5_3. 随机产生[0, 20)个[0, 1024)整数, 将它们转换为二进制数并右对齐输出. 要求: 

1) 按照第二章课件P5给出的方法, 从十进制整数转化为二进制数; 

2) 定义数组binary[]保存二进制数的每一位. 例如: (10)10 = (1010)2, 按照转换顺序(由低位向高位依次计算), 数组binary[]的前4个元素为0、1、0、1 ; 再如: (358)10 = (101100110)2, 按照转换顺序, 数组binary[]的前9个元素为0、1、1、0、0、1、1、0、1 . 输出二进制数时, 逆序输出数组的每个元素即可. 

3) 十进制数的输出宽度为8, 二进制数的输出宽度为10, 两列之间间隔2个空格. 注意: 不要为了使用%[width]d对齐输出, 而把二进制数转换为十进制数!

<img width="2182" height="1249" alt="HW5_3_1" src="https://github.com/user-attachments/assets/543fe898-d96e-4dac-9636-9c69dd91bbb9" />

Homework 6

HW6_1. 编写程序，输入自然数n（n > 1),输出该数的质因数分解式。注意: 即使待分解的数较大, 程序也能秒出分解结果(参见示例3和4).

<img width="445" height="37" alt="HW6_1_1" src="https://github.com/user-attachments/assets/213ed884-8978-4a34-bb6c-0e53155c528a" />

<img width="471" height="36" alt="HW6_1_2" src="https://github.com/user-attachments/assets/f467af84-6771-4e2b-aaa3-2992e03ed61a" />

<img width="524" height="38" alt="HW6_1_3" src="https://github.com/user-attachments/assets/41bd8f46-0696-45ac-8bf9-be0a10cab0d1" />

<img width="521" height="36" alt="HW6_1_4" src="https://github.com/user-attachments/assets/b36f3b52-5a27-46b0-afd9-50f894335b1e" />

HW6_2. 基于HW5_3, 随机产生[10,20)个[0, 1024)整数, 冒泡法排序之后，将它们转换为二进制和六进制并对齐输出. 要求:

1) 按照第二章课件P5给出的方法, 从十进制整数转化为二进制数; 从十进制转换为六进制的方法类似;

2) 定义两个工作数组bin[]和six[]分别保存二进制数和六进制数的每一位. 例如: (10)10 = (1010)2 = (14)6, 按照转换顺序(由低位向高位依次计算获得), 数组bin[]的前4个元素为0、1、0、1 , 数组oct[]的前2个元素为4、1. 再如: (358)10 = (101100110)2 = (1354)6, 按照转换顺序, 数组bin[]的前9个元素为0、1、1、0、0、1、1、0、1 , 数组oct[]的前4个元素为4、5、3、1. 输出时, 逆序输出即可. 

3) 每列的输出宽度为11(含列间隔). 注意: 不要为了使用%[width]d对齐输出, 而把二进制数和六进制数转换为十进制数!

<img width="1743" height="1202" alt="HW6_2_1" src="https://github.com/user-attachments/assets/18dd4aa0-49c3-405a-8284-84e7d93b1b57" />

HW6_3. 编写程序, 利用密钥key加密一行英文文本(长度<120). 加密过程与报数出列相仿.

<img width="854" height="247" alt="HW6_3_1" src="https://github.com/user-attachments/assets/0b9eb548-4bfb-43b7-9e78-b2f78ee7c6cd" />

HW6_4.n<=30.生成如下方阵

<img width="909" height="544" alt="HW6_4_1" src="https://github.com/user-attachments/assets/11477a54-9a16-4629-b604-1635f8271fe4" />

Homework 7

HW7_1. 输入2个字符串, 求最长公共子串并输出. 如: "aabcde"与"ababc"的最长公共子串是"abc".  如果有多个最长公共字串，输出找到的第一个.

<img width="242" height="61" alt="HW7_1_2" src="https://github.com/user-attachments/assets/dd02a2a1-9b5a-4cd9-9b43-461f7709ea3b" />

<img width="253" height="76" alt="HW7_1_3" src="https://github.com/user-attachments/assets/8af7db6d-9d5f-4f22-bdbe-79b7b2d82a50" />

HW7_2.设数组的每个元素只存储0~9的数，把该数组的前n个整数的排列看做是一个n位的长整数的一种表示。现要求编写程序，对数组中的元素做调整，产生一个新的排列，使新排列表示的长整数前的长整数大（如果可能），但又是所有更大的表示中最小的。例如，a[]={3,2,6,5,4,1},则更大又是最小的排列为{3，4，1，2，5，6}。程序运行时, 先读入一个n位数, 保存到数组中, 然后再求更大的最小数.

<img width="415" height="48" alt="HW7_2_1" src="https://github.com/user-attachments/assets/b9abee91-99a2-43c1-a171-bdac7ee15e79" />

<img width="511" height="48" alt="HW7_2_2" src="https://github.com/user-attachments/assets/398a4061-61b7-485d-b462-1bc638f7ad10" />

<img width="508" height="49" alt="HW7_2_3" src="https://github.com/user-attachments/assets/fcee2a4b-d523-4edd-a9ba-3ed9c91d5582" />

HW7_3. 猜数游戏. 程序随机产生[1,100]的某个整数, 让用户在有限次数([5,7]随机产生)内猜这个数. 猜中时输出猜对信息, 未猜中时输出太大/太小信息, 并提示用户还有几次机会. 要求: 猜数过程用函数实现, 函数参数为要猜的那个随机整数和随机产生的有限次数.

<img width="1969" height="1128" alt="HW7_3_1" src="https://github.com/user-attachments/assets/e80dddfd-a917-4613-93cb-7ebeb280fc79" />

<img width="1981" height="1194" alt="HW7_3_2" src="https://github.com/user-attachments/assets/f9da299e-9623-4546-bd40-0d77eaafe4e0" />

HW7_4. 第4章习题, 第11题.对于n=2,3,4,...,50,输出1/n的十进制表示的字符串。要求每当十进制小数的第一个循环周期输出后，就结束该数的输出。 要求: 把计算并输出1/x的功能定义为函数, 主函数如下:

int main()
{
    int x;

    for (x = 2; x <= 100; ++x) {
        printReciprocal(x);
        printf("\n");
    }

    return 0;
}

因为循环小数的循环节开始位置不一定是小数点后第一位(如: 
), 为了清晰地看到循环节, 输出时, 用左右圆括号标示循环节的开始和结束, 如: 1/6=0.1(6).

<img width="960" height="1794" alt="HW7_4" src="https://github.com/user-attachments/assets/30b1065c-d7ed-4cfd-b7b9-59394a77f2c2" />

Homework 8

HW8_1. 第五章习题, 第2题.2.为低年级小学生编写一个两个整数乘法的测验程序。程序利用随机函数产生两个整数,并给出算式请小学生输入解答。程序对正确的解答给予鼓励;对不正确的解答给出正确的答案。另外，为了让程序更有实用性，输入整数的范围也可由用户指定，如一位数乘法、两位数乘法等。使用随机函数的程序有以下要求:
(1)在程序前面包含以下代码:#include<stdlib.h>#include<time.h> /*有关时间库函数*(2)主函数先用以下代码为随机函数初始化:srand(time(NULL));
(3)用以下代码随机取1~9的整数k:
k=1+rand()号9;
为了提高小学生的学习兴趣,程序的回答也希望有所改变,如对正确的回答可以有多种选择如“Very good!”、“Excellent!”、“Keep up the good work!”等。同样，对于错误的响应也可以有多种选择，如“No. Please try again.”、“Wrong. Try once more.”、“No.Keep trying:”等。利用随机函数选择一种回答。 要求:

1) 将输出和选择菜单项的功能定义为函数menu(), 菜单内容参见运行示例.

2) 随机生成乘法的两个因数. 注意: 两位数乘法至少有一个乘数为两位数.

3) 程序对正确答案和错误答案的响应字符串(参见课本)保存到二维字符数组中, 根据答案正确/错误随机选择响应字符串并输出. 
