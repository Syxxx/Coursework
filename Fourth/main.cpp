#include <iostream>
#include "Arithmetic_H.h"

using namespace std;

int main()
{
	int lang,n,myans;
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
		equation.randomOperation(); //�������
		equation.generateExpression();//������ʽ 
		cout << endl;
		//cin >> myans;
		//ans.calculateResult(equation);
		//ans.checkanswer(myans);
		//ans.countQuestions();
	}
	system("pause");
	return 0;
}