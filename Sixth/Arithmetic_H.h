#include <iostream>
#include <string.h>
#ifndef Arithmetic_H
#define Arithmetic_H

using namespace std;

class UserInteraction //负责与用户交互 
{
private:
	int n;//题数 
	int language;
	int ans;//答案
public:
	friend class Expression;
	UserInteraction();
	~UserInteraction();
	void getNumber(int nums);//获取题数
	void printNumber();
	void getLaguage(int lan);
	void chooseLanguage();//选择语言 
};

class Expression //负责和算式有关的 
{
private:
	char signs[10];
	int nums[10];
	char sign[4];
	int digit, flag, temp, braO, braT;
	int bracketNum;
	string equ;
	friend class Answer;
public:
	Expression();
	~Expression();
	void randomNumber(); //随机数字
	void randomOperation(); //随机符号
	void generateExpression();//产生算式 
	void printequ();
};

class Answer //负责跟答案有关的部分 
{
private:
	double result;
	int right;
	int wrong;
public:
	Answer();
	~Answer();
	double calculateResult(Expression &c); //运算答案
	void checkanswer(int userans); //检验答案
	void countQuestions();//统计结果
};


#endif
