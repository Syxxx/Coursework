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
	icin >> questions;//��ȡ�ļ��е���Ŀ����
	return questions;
}

/*�û�����*/
void scan()
{
//	int n;
	cout << "��ѡ������(Please choose language)" << endl; cout << "1.���� 2.English �� ";
	cin >> lan;
/*	switch (lan)
	{
	case 1:cout << "������������"; cin >> n; break;
	case 2:cout << "Please enter a number of questions��"; cin >> n; break;
	default:cout << "Error!"; break;
	}*/
//	return n;
}

/*�����������*/
void randomNumber(int judge)
{
	if (judge != 0)
	{
		digit = rand() % 3 + 4;   //���ֵĸ��� 
		for (int i = 0; i<digit; i++)
		{
			nums[i] = rand() % 9 + 1;    // ����
		}
	}
	else if (judge == 0)
	{
		for (int i = 0; i<4;)
		{
			int x = rand() % 9 + 1;    //�п����Ƿ��ӷ�ĸ�������� 
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

/*�����������*/
void randomOperation(int judge )
{
	char c[] = "+-*/";
	if (judge != 0)
	{

		for (int i = 0; i<digit; i++)
		{
			signs[i] = c[rand() % 4]; //����
		}
		signs[digit - 1] = '=';
	}
	else if (judge == 0)
	{
		signs[0] = c[rand() % 4];
		signs[1] = '=';
	}
}

/*������ʽ*/
void generateExpression(int judge,char *addr)
{
	bracketNum = rand() % 2;    //���Ÿ��� 
	if (bracketNum == 1)
	{
		flag = 0;
		temp = 0;
		if (((digit - 1) / 2) != 0)
		{
			braO = rand() % ((digit - 1) / 2) + 1;
			braT = braO + rand() % ((digit - 1) / 2) + 2;
		}
		//�ֱ��ڵڼ����������� 
		//braO+1�ǵ�һ�����ŵ�λ�ã�braT�ǵڶ������ŵ�λ��
	}
	calculateResult(judge,addr);
}

/*�����*/
void calculateResult(int judge,char *addr)
{
	double result = 0;
	if (judge != 0)
	{
		k = 0;
		sign = nums[0]; //�����һ������
		result = low(); //���м���
		if (result == (int)result)
		{
			writeFile(addr, 1, 0,0,judge);
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
			checkanswer(result,addr,judge);
		}
		else if (result != (int)result)
		{
			randomNumber(judge); //����������� 
			randomOperation(judge); //����������� 
			generateExpression(judge,addr);//������ʽ
		}
	}
	else if (judge == 0)
	{
		int demo; //����
		double nume; //��ĸ 
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
			randomNumber(judge); //����������� 
			randomOperation(judge); //����������� 
			generateExpression(judge,addr);//������ʽ
		}
		else
		{
			writeFile(addr, 1, 0,0,judge);
			nums[0] /= nums[3];
			nums[2] /= nums[1];
			for (int j = 0, i = 0; i<4; i++) //������ʽ
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
						cout << "��";
					else
						cout << signs[j];
					j++;
				}
			}
			checkanswer(result,addr,judge);
		}
	}
}

void checkanswer(int result,char *addr,int judge) //����� 
{
	char ch;
	cin >> answer;
	ch = getchar();
	writeFile(addr, 2, 0,result,judge);
	if ((answer == result) && (ch != 'e'))
	{
		if (lan == 1)
			cout << "     ����ȷ";
		else
			cout << "     correct";
		correct += 1;
	}
	else if ((answer != result) && (ch != 'e'))
	{
		if (lan == 1)
			cout << "     �𰸴�����ȷ��Ϊ:" << result;
		else
			cout << "     wrong answer. The correct answer is:" << result;
		wrong += 1;
	}
	if (ch == 'e')
	{
		print();
	}
}

void match(char nowsign) //ƥ����� 
{
	if (bracketNum == 0)
	{
		if (sign == nowsign) //ƥ��ɹ�����ȡ��һ����־
		{
			k++;
			if ((k % 2) == 0) //��һλ������ 
				sign = nums[k / 2];
			else    //��һλ�Ƿ��� 
				sign = signs[(k - 1) / 2];
		}
	}
	else if (bracketNum == 1)
	{
		if (sign == nowsign) //ƥ��ɹ�����ȡ��һ����־
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
			else if (((k % 2) == 0) && (k != 2 * braO)) //��һλ������ 
				sign = nums[k / 2];
			else if (((k % 2) != 0) && (k != braT * 2 - 1))    //��һλ�Ƿ��� 
				sign = signs[(k - 1) / 2];
		}
	}

}

double low() //�Ӽ����� 
{
	double result1 = mid(); //����ȼӼ��������ȼ���ߵĲ���
	while ((sign == '+') || (sign == '-'))
		if (sign == '+')
		{
			match('+');     //���мӷ�����
			result1 += mid();
			if (k == 2 * digit - 1)
				break;
		}
		else if (sign == '-')
		{
			match('-');    //���м�������
			result1 -= mid();
			if (k == 2 * digit - 1)
				break;
		}
	return result1;
}

double mid() //�˳����� 
{
	double result2 = high();
	while ((sign == '*') || (sign == '/'))
		if (sign == '*')
		{
			match('*');     //���г˷�����
			result2 *= high();
			if (k == 2 * digit - 1)
				break;
		}
		else if (sign == '/')
		{
			match('/');    //���г�������
			result2 /= high();
			if (k == 2 * digit - 1)
				break;
		}
	return result2;
}


double high() //�������㼰���� 
{
	double result3;
	if (sign == '(') //�������ŵ�����
	{
		match('(');
		result3 = low(); //�ݹ������ʽ
		match(')');
	}
	else if (sign >= 0 && sign <= 9) //ʵ�ʵ�����
	{
		result3 = sign;
		k++;
		if (bracketNum == 0)
		{
			sign = signs[(k - 1) / 2];//��һλ�Ƿ��� 
		}
		else if (bracketNum == 1)
		{
			if ((k == braT * 2 - 1) && (temp == 0))
			{
				sign = ')';
				temp = 1;
				k--;
			}
			else if (((k % 2) != 0) && (k != braT * 2 - 1))    //��һλ�Ƿ��� 
				sign = signs[(k - 1) / 2];
		}

	}
	return result3;
}


void print() //ͳ�ƽ�� 
{
	if (lan == 1)
		cout << endl << "����" << correct << "����;" << "����" << wrong << "����";
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
						ocout << nums[i] << "��";
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
						ocout << "��";
					else
						ocout << signs[i];
				}
				ocout << endl;
			}
		}
		else if (judge == 0)
		{
			for (int j = 0, i = 0; i<4; i++) //������ʽ
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
						ocout << "��";
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
			ocout << "�û��𰸣�" << answer << endl;
			ocout << "��ȷ�𰸣�" << result << endl;
		}
		else if (lan == 2)
		{
			ocout << "Your answer is:" << answer << endl;
			ocout << "The correct answer is:" << result << endl;
			}
	}

	ocout.close();
}