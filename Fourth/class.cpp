#include <iostream>
#include "Arithmetic_H.h"

using namespace std;


void UserInteraction::printNumber()

{
	switch (language)
	{
	case 1:cout << "请输入题数："; break;
	case 2:cout << "Please enter a number of questions："; break;
	defaul:cout << "Error!"; break;
	}
}

UserInteraction::UserInteraction()
{
}

UserInteraction::~UserInteraction()
{
}

void UserInteraction::getNumber(int nums)
{
	n = nums;
}

void UserInteraction::chooseLanguage()
{
	cout << "请选择语言(Please choose language)" << endl; 
	cout << "1.中文 2.English ： ";
}

void UserInteraction::getLaguage(int lan)
{
	language = lan;
}



Expression::Expression()
{
}

Expression::~Expression()
{
}

void Expression::randomNumber()
{
		digit = rand() % 3 + 4;   //数字的个数 
		for (int i = 0; i<digit; i++)
		{
			nums[i] = rand() % 9 + 1;    // 数字
		}
}

void Expression::randomOperation()
{
	char c[] = "+-*/";
		for (int i = 0; i<digit; i++)
		{
			signs[i] = c[rand() % 4]; //符号
		}
		signs[digit - 1] = '=';
}

void Expression::generateExpression()
{
	bracketNum = rand() % 2;    //括号个数 
	if (bracketNum == 1)
	{
		flag = 0;
		temp = 0;
		braO = rand() % ((digit - 1) / 2) + 1;
		braT = braO + rand() % ((digit - 1) / 2) + 2;
		//分别在第几个数加括号 
		//braO+1是第一个括号的位置，braT是第二个括号的位置
	}
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
}

Answer::Answer()
{
}

Answer::~Answer()
{
}
