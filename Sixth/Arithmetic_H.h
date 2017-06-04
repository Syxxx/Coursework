#include <iostream>
#include <string.h>
#ifndef Arithmetic_H
#define Arithmetic_H

using namespace std;

class UserInteraction //�������û����� 
{
private:
	int n;//���� 
	int language;
	int ans;//��
public:
	friend class Expression;
	UserInteraction();
	~UserInteraction();
	void getNumber(int nums);//��ȡ����
	void printNumber();
	void getLaguage(int lan);
	void chooseLanguage();//ѡ������ 
};

class Expression //�������ʽ�йص� 
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
	void randomNumber(); //�������
	void randomOperation(); //�������
	void generateExpression();//������ʽ 
	void printequ();
};

class Answer //��������йصĲ��� 
{
private:
	double result;
	int right;
	int wrong;
public:
	Answer();
	~Answer();
	double calculateResult(Expression &c); //�����
	void checkanswer(int userans); //�����
	void countQuestions();//ͳ�ƽ��
};


#endif
