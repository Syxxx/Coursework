#include<iostream>
#include<string>
#include<stdlib.h>
#include<time.h>

#include "Arithmetic_H.h"

using namespace std;

int main()
{
	srand((unsigned(time(NULL))));
	int lang,n,myans;
	double res;
	UserInteraction user;
	Expression equation;
	Answer ans;
	user.chooseLanguage();
	cin >> lang;
	user.getLaguage(lang);
	user.printNumber();
	cin >> n;
	user.getNumber(n);
	for (int i = 0; i < n; i++)
	{
		equation.randomNumber();
		equation.randomOperation(); //随机符号
		equation.generateExpression();//产生算式
		res = ans.calculateResult(equation);
		while (res != (int)res)
		{
			equation.randomNumber();
			equation.randomOperation(); //随机符号
			equation.generateExpression();//产生算式
			res = ans.calculateResult(equation);
		}
		equation.printequ();
		cin >> myans;
		ans.checkanswer(myans);
	}
	ans.countQuestions();
	system("pause");
	return 0;
}