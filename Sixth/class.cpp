#include <iostream>
#include "Arithmetic_H.h"
#include <sstream>
#include <stack>

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
		signs[digit] = '=';
}


void Expression::generateExpression()
{
	stringstream str;
	bracketNum = 1;//=rand()%2;    //���Ÿ��� 
	if (bracketNum == 1)
	{
		braO = rand() % (digit - 2) + 1;
		braT = braO + rand() % (digit - braO) + 1;
		//braO�ǵ�һ�����ŵ�λ�ã�braT�ǵڶ������ŵ�λ��
	}
	for (int i = 0; i<digit; i++)
	{
		if (bracketNum != 0 && i == braO - 1)
			str << "(";
		str << nums[i];
		if (bracketNum != 0 && i == braT - 1)
			str << ")";
		if (i != digit - 1)
			str << signs[i + 1];
	}
	str >> equ;
	//cout << equ<<"=";
}

void Expression::printequ()
{
	cout << equ <<"=" ;
}

Answer::Answer()
{
	right = 0;
	wrong = 0;
}

Answer::~Answer()
{
}



double Answer::calculateResult(Expression &c)
{
	stack<double> stan;//����ջ
	stack<char> stac;//����ջ
	int length1, lenth, i, j;
	string hzequ;//��׺���ʽ
	length1 = c.equ.length();//���ɵ���ʽ���� 
	hzequ.clear();
	for (i = 0; i<length1; i++)
	{
		if (c.equ[i] <= '9'&&c.equ[i] >= '0')
		{
			hzequ.push_back(c.equ[i]);
		}
		else
		{
			if (stac.size() == 0 || c.equ[i] == '(')
			{
				stac.push(c.equ[i]);
			}
			else
			{
				char temp1 = stac.top();
				if (c.equ[i] == ')')
				{
					lenth = stac.size();
					while (lenth)
					{
						char temp2 = stac.top();
						stac.pop();
						if (temp2 == '(')
							break;
						else
							hzequ.push_back(temp2);
						lenth--;
					}
				}
				else
				{
					if (temp1 == '*' || temp1 == '/' || temp1 == '-' || temp1 == '+')
					{
						if ((c.equ[i] == '*' || c.equ[i] == '/'))
						{
							if (temp1 != '/'&&temp1 != '*')
								stac.push(c.equ[i]);
							else
							{
								hzequ.push_back(temp1);
								stac.pop();
							stac.push(c.equ[i]);
							}
						}
						else
						{
							lenth = stac.size();
							while (lenth)
							{
								char temp = stac.top();
								if (temp != '(')
								{
									hzequ.push_back(temp);
									stac.pop();
								}
								lenth--;
							}
							stac.push(c.equ[i]);
						}
					}
					else
					{
						stac.push(c.equ[i]);
					}
				}
			}
		}
	}

	if (stac.size() != 0)
	{
		lenth = stac.size();
		while (lenth)
		{
			char temp = stac.top();
			hzequ.push_back(temp);
			stac.pop();
			lenth--;
		}
	}
	//cout <<endl<< hzequ << endl;
	//�ɺ�׺���ʽ������ʽֵ
	int hzlength = hzequ.size();
	double t1, t2,t3;
	for (i = 0; i<hzlength; i++)
	{
		if (hzequ[i] <= '9'&&hzequ[i] >= '0')
		{
			double number = hzequ[i] - '0';
			stan.push(number);
		}
		else
		{
			t1 = stan.top();
			stan.pop();
			t2 = stan.top();
			stan.pop();
			switch (hzequ[i])
			{
			case '+':t3 = t1 + t2; break;
			case '-':t3 = t2 - t1; break;
			case '*':t3 = t1*t2; break;
			case '/':t3 = t2 / t1; break;
			default:break;
			}
			stan.push(t3);
		}
	}
	//cout << stan.top() << endl;
	result = stan.top();
	return result;
}

void Answer::checkanswer(int userans)
{
	if (userans == result)
	{
		right++;
		cout << "����ȷ��" << endl;
	}
	else
	{
		wrong++;
		cout << "�𰸴�����ȷ�𰸣�" << result<<endl;
	}
}

void Answer::countQuestions()
{
	cout << "��ȷ������" << right<<endl;
	cout << "����������" << wrong << endl;
}