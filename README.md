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

HW2_2. 编写程序, 要求用户输入一个四位正整数并保存于一个整型变量中, 计算并输出其各位数字之和. 要求: 通过算术运算获得四位数每一位的值.<img width="267" height="46" alt="HW2_2" src="https://github.com/user-attachments/assets/a5c76be1-88a2-40bd-8f13-d9a30f4a9b78" />
HW2_3. 编写程序, 对用户录入的贷款信息计算第一、第二、第三个月还贷后剩余的贷款金额(保留两位小数).  提示: 每个月的贷款余额需要加上利息(上个月贷款余额与月利率的乘积, 月利率是年利率除以12). <img width="1586" height="556" alt="HW2_3" src="https://github.com/user-attachments/assets/1f3ceeb6-d1ea-462e-aacb-663d4046fe0e" />

Homework 3

HW3_1. 欧洲使用13位的欧洲商品编码(European Article Number, EAN), 每个EAN码的最后一位是校验位. 计算校验位的方法为: 首先把第2、4、6、8、10、12位的数字相加; 然后把第1、3、5、7、9、11位的数字相加; 接着把第一次加法的结果乘以3, 再和第二次加法的结果相加; 随后, 再把上述结果减去1; 相减后的结果除以10取余数; 最后用9减去余数得到的就是校验位. 编写程序, 输入一个13位的EAN, 判断校验位是否有效.

Tip. 13位整数已经超出int/long的范围, 所以不能用一个int/long型变量保存EAN码. 本课程未学习long long int类型, 所以也不要使用该类型.![HW3_1_1](https://github.com/user-attachments/assets/3e39cca6-73b0-4b09-b66a-d2bb8f375594)<img width="322" height="41" alt="HW3_1_2" src="https://github.com/user-attachments/assets/fa9561a2-e939-4294-83a6-a3f45c2497ed" />

HW3_2. 编写程序, 输入4个整数, 输出它们中的最大值和最小值.   要求使用尽可能少的if...else...语句或条件(三目)运算表达式, 因为一个条件(三目)运算表达式相当于一个if...else...结构.<img width="1077" height="255" alt="HW3_2_1" src="https://github.com/user-attachments/assets/7447d47f-80bd-4ab2-bae5-9e9097fa7cf4" /><img width="949" height="242" alt="HW3_2_2" src="https://github.com/user-attachments/assets/afff26bf-ceff-475d-994b-c4309b76535e" />

HW3_3.编写程序，输入3对实数，若每对实数分别作为平面坐标系中点的坐标，判断这3个点是否能构成一个三角形。若能构成三角形，判断这个三角形的特征：是直角三角形，等边三角形，等腰三角形还是普通三角形等。Tip. 计算机的浮点数运算存在误差.<img width="504" height="54" alt="HW3_3_1" src="https://github.com/user-attachments/assets/a91533a4-fa2a-4294-ac39-094f73359247" /><img width="504" height="54" alt="HW3_3_2" src="https://github.com/user-attachments/assets/d57fb85a-88ab-4047-9d1d-52834aeec7bb" />
<img width="576" height="53" alt="HW3_3_3" src="https://github.com/user-attachments/assets/4016e913-e444-4c67-9511-82e0f5aa3e3d" /><img width="502" height="55" alt="HW3_3_4" src="https://github.com/user-attachments/assets/86b0f950-e5ca-4603-8ead-45bd9428810e" /><img width="503" height="59" alt="HW3_3_5" src="https://github.com/user-attachments/assets/642e2642-f540-4215-92ca-f227d8f585ab" />
<img width="547" height="57" alt="HW3_3_6" src="https://github.com/user-attachments/assets/f4be60c2-ec7d-420e-a49c-4be7d7fbca79" />




