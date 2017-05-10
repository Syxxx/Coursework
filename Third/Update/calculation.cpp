#include<iostream>
#include<string>
#include<stdlib.h>
#include<time.h>
#include <fstream>
#include"Head.h"
using namespace std;

static char nowsign, sign, signs[10];
static int k = 0, correct = 0, wrong = 0, flag = 0, temp = 0, bracketNum = 0, braO, braT, lan, nums[10], digit, answer;

int readFile(char *fp)
{
	ifstream icin;
	icin.open(fp);
	int questions;
	icin >> questions;//读取文件中的题目数量
	return questions;
}

/*用户输入*/
void scan()
{
//	int n;
	cout << "请选择语言(Please choose language)" << endl; cout << "1.中文 2.English ： ";
	cin >> lan;
/*	switch (lan)
	{
	case 1:cout << "请输入题数："; cin >> n; break;
	case 2:cout << "Please enter a number of questions："; cin >> n; break;
	default:cout << "Error!"; break;
	}*/
//	return n;
}

/*随机产生数字*/
void randomNumber(int judge)
{
	if (judge != 0)
	{
		digit = rand() % 3 + 4;   //数字的个数 
		for (int i = 0; i<digit; i++)
		{
			nums[i] = rand() % 9 + 1;    // 数字
		}
	}
	else if (judge == 0)
	{
		for (int i = 0; i<4;)
		{
			int x = rand() % 9 + 1;    //有可能是分子分母的两个数 
			int y = rand() % 9 + 1;
			if (x != y)
			{

				if (x>y)
				{
					nums[i] = y; nums[i + 1] = x;
				}
				else
				{
					nums[i] = x; nums[i + 1] = y;
				}
				i += 2;
			}
		}
	}
}

/*随机产生符号*/
void randomOperation(int judge )
{
	char c[] = "+-*/";
	if (judge != 0)
	{

		for (int i = 0; i<digit; i++)
		{
			signs[i] = c[rand() % 4]; //符号
		}
		signs[digit - 1] = '=';
	}
	else if (judge == 0)
	{
		signs[0] = c[rand() % 4];
		signs[1] = '=';
	}
}

/*产生算式*/
void generateExpression(int judge,char *addr)
{
	bracketNum = rand() % 2;    //括号个数 
	if (bracketNum == 1)
	{
		flag = 0;
		temp = 0;
		if (((digit - 1) / 2) != 0)
		{
			braO = rand() % ((digit - 1) / 2) + 1;
			braT = braO + rand() % ((digit - 1) / 2) + 2;
		}
		//分别在第几个数加括号 
		//braO+1是第一个括号的位置，braT是第二个括号的位置
	}
	calculateResult(judge,addr);
}

/*运算答案*/
void calculateResult(int judge,char *addr)
{
	double result = 0;
	if (judge != 0)
	{
		k = 0;
		sign = nums[0]; //载入第一个符号
		result = low(); //进行计算
		if (result == (int)result)
		{
			writeFile(addr, 1, 0,0,judge);
			if (bracketNum == 0)
			{
				for (int i = 0; i<digit; i++)
				{
					if (signs[i] == '/')
						cout << nums[i] << "÷";
					else
						cout << nums[i] << signs[i];
				}
				// cout<<result;
			}
			else if (bracketNum == 1)
			{
				for (int i = 0; i<digit; i++) //测试算式
				{
					if (i == braO) cout << "(";
					cout << nums[i];
					if (i == braT - 1) cout << ")";
					if (signs[i] == '/')
						cout << "÷";
					else
						cout << signs[i];
				}
				//		cout<<result; 
			}
			checkanswer(result,addr,judge);
		}
		else if (result != (int)result)
		{
			randomNumber(judge); //产生随机数字 
			randomOperation(judge); //产生随机符号 
			generateExpression(judge,addr);//产生算式
		}
	}
	else if (judge == 0)
	{
		int demo; //分子
		double nume; //分母 
		demo = nums[1] * nums[3];
		nums[0] *= nums[3];
		nums[2] *= nums[1];
		switch (signs[0])
		{
		case '+':nume = nums[0] + nums[2]; break;
		case '-':nume = nums[0] - nums[2]; break;
		case '*':nume = nums[0] * nums[2] / nums[3] / nums[1]; break;
		case '/':nume = (double)nums[0] / (double)nums[2]; break;
		}
		result = nume / (double)demo;
		if (result != (int)result)
		{
			randomNumber(judge); //产生随机数字 
			randomOperation(judge); //产生随机符号 
			generateExpression(judge,addr);//产生算式
		}
		else
		{
			writeFile(addr, 1, 0,0,judge);
			nums[0] /= nums[3];
			nums[2] /= nums[1];
			for (int j = 0, i = 0; i<4; i++) //测试算式
			{
				if (i / 2.0 == i / 2)
				{
					cout << "(";
				}
				cout << nums[i];
				if (i / 2.0 != i / 2)
				{
					cout << ")";
				}
				if (i / 2.0 == i / 2)
				{
					cout << "/";
				}
				else
				{
					if (signs[j] == '/')
						cout << "÷";
					else
						cout << signs[j];
					j++;
				}
			}
			checkanswer(result,addr,judge);
		}
	}
}

void checkanswer(int result,char *addr,int judge) //检验答案 
{
	char ch;
	cin >> answer;
	ch = getchar();
	writeFile(addr, 2, 0,result,judge);
	if ((answer == result) && (ch != 'e'))
	{
		if (lan == 1)
			cout << "     答案正确";
		else
			cout << "     correct";
		correct += 1;
	}
	else if ((answer != result) && (ch != 'e'))
	{
		if (lan == 1)
			cout << "     答案错误，正确答案为:" << result;
		else
			cout << "     wrong answer. The correct answer is:" << result;
		wrong += 1;
	}
	if (ch == 'e')
	{
		print();
	}
}

void match(char nowsign) //匹配符号 
{
	if (bracketNum == 0)
	{
		if (sign == nowsign) //匹配成功，获取下一个标志
		{
			k++;
			if ((k % 2) == 0) //下一位是数字 
				sign = nums[k / 2];
			else    //下一位是符号 
				sign = signs[(k - 1) / 2];
		}
	}
	else if (bracketNum == 1)
	{
		if (sign == nowsign) //匹配成功，获取下一个标志
		{
			k++;
			if ((k == 2 * braO) && (flag == 0))
			{
				sign = '(';
				flag = 1;
				k--;
			}
			else if ((k == braT * 2 - 1) && (temp == 0))
			{
				sign = ')';
				temp = 1;
				k--;
			}
			else if ((k == 2 * braO) && (flag == 1))
				sign = nums[k / 2];
			else if ((k == braT * 2 - 1) && (temp == 1))
				sign = signs[(k - 1) / 2];
			else if (((k % 2) == 0) && (k != 2 * braO)) //下一位是数字 
				sign = nums[k / 2];
			else if (((k % 2) != 0) && (k != braT * 2 - 1))    //下一位是符号 
				sign = signs[(k - 1) / 2];
		}
	}

}

double low() //加减运算 
{
	double result1 = mid(); //计算比加减运算优先级别高的部分
	while ((sign == '+') || (sign == '-'))
		if (sign == '+')
		{
			match('+');     //进行加法运算
			result1 += mid();
			if (k == 2 * digit - 1)
				break;
		}
		else if (sign == '-')
		{
			match('-');    //进行减法运算
			result1 -= mid();
			if (k == 2 * digit - 1)
				break;
		}
	return result1;
}

double mid() //乘除运算 
{
	double result2 = high();
	while ((sign == '*') || (sign == '/'))
		if (sign == '*')
		{
			match('*');     //进行乘法运算
			result2 *= high();
			if (k == 2 * digit - 1)
				break;
		}
		else if (sign == '/')
		{
			match('/');    //进行除法运算
			result2 /= high();
			if (k == 2 * digit - 1)
				break;
		}
	return result2;
}


double high() //括号运算及数字 
{
	double result3;
	if (sign == '(') //带有括号的运算
	{
		match('(');
		result3 = low(); //递归计算表达式
		match(')');
	}
	else if (sign >= 0 && sign <= 9) //实际的数字
	{
		result3 = sign;
		k++;
		if (bracketNum == 0)
		{
			sign = signs[(k - 1) / 2];//下一位是符号 
		}
		else if (bracketNum == 1)
		{
			if ((k == braT * 2 - 1) && (temp == 0))
			{
				sign = ')';
				temp = 1;
				k--;
			}
			else if (((k % 2) != 0) && (k != braT * 2 - 1))    //下一位是符号 
				sign = signs[(k - 1) / 2];
		}

	}
	return result3;
}


void print() //统计结果 
{
	if (lan == 1)
		cout << endl << "做对" << correct << "道题;" << "做错" << wrong << "道题";
	else
		cout << endl << "Correct questions:" << correct << ";Wrong questions:" << wrong;
}

void writeFile(char *fp, int out, int n,int result,int judge)
{
//	std::ofstream out(fp, std::ios::ate | std::ios::out);
	ofstream ocout;
	ocout.open(fp,ios::app);
	if (out == 0)
	{
		ocout << n << endl;
	}
	else if (out == 1)
	{
		if (judge != 0)
		{
			if (bracketNum == 0)
			{
				for (int i = 0; i<digit; i++)
				{
					if (signs[i] == '/')
						ocout << nums[i] << "÷";
					else
						ocout << nums[i] << signs[i];
				}
				ocout << endl;
			}
			else if (bracketNum == 1)
			{
				for (int i = 0; i<digit; i++)
				{
					if (i == braO) ocout << "(";
					ocout << nums[i];
					if (i == braT - 1) ocout << ")";
					if (signs[i] == '/')
						ocout << "÷";
					else
						ocout << signs[i];
				}
				ocout << endl;
			}
		}
		else if (judge == 0)
		{
			for (int j = 0, i = 0; i<4; i++) //测试算式
			{
				if (i / 2.0 == i / 2)
				{
					ocout << "(";
				}
				ocout << nums[i];
				if (i / 2.0 != i / 2)
				{
					ocout << ")";
				}
				if (i / 2.0 == i / 2)
				{
					ocout << "/";
				}
				else
				{
					if (signs[j] == '/')
						ocout << "÷";
					else
						ocout << signs[j];
					j++;
				}				
			}
			ocout << endl;
		}
	}
	else if (out == 2)
	{
		if (lan == 1)
		{
			ocout << "用户答案：" << answer << endl;
			ocout << "正确答案：" << result << endl;
		}
		else if (lan == 2)
		{
			ocout << "Your answer is:" << answer << endl;
			ocout << "The correct answer is:" << result << endl;
			}
	}

	ocout.close();
}