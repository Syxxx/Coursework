#include <iostream>
#include "Arithmetic_H.h"

using namespace std;


void UserInteraction::printNumber()

{
	switch (language)
	{
	case 1:cout << "������������"; break;
	case 2:cout << "Please enter a number of questions��"; break;
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
	cout << "��ѡ������(Please choose language)" << endl; 
	cout << "1.���� 2.English �� ";
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
		digit = rand() % 3 + 4;   //���ֵĸ��� 
		for (int i = 0; i<digit; i++)
		{
			nums[i] = rand() % 9 + 1;    // ����
		}
}

void Expression::randomOperation()
{
	char c[] = "+-*/";
		for (int i = 0; i<digit; i++)
		{
			signs[i] = c[rand() % 4]; //����
		}
		signs[digit - 1] = '=';
}

void Expression::generateExpression()
{
	bracketNum = rand() % 2;    //���Ÿ��� 
	if (bracketNum == 1)
	{
		flag = 0;
		temp = 0;
		braO = rand() % ((digit - 1) / 2) + 1;
		braT = braO + rand() % ((digit - 1) / 2) + 2;
		//�ֱ��ڵڼ����������� 
		//braO+1�ǵ�һ�����ŵ�λ�ã�braT�ǵڶ������ŵ�λ��
	}
	if (bracketNum == 0)
	{
		for (int i = 0; i<digit; i++)
		{
			if (signs[i] == '/')
				cout << nums[i] << "��";
			else
				cout << nums[i] << signs[i];
		}
		// cout<<result;
	}
	else if (bracketNum == 1)
	{
		for (int i = 0; i<digit; i++) //������ʽ
		{
			if (i == braO) cout << "(";
			cout << nums[i];
			if (i == braT - 1) cout << ")";
			if (signs[i] == '/')
				cout << "��";
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
