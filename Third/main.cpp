#include<iostream>
#include <fstream>
#include<string>
#include<stdlib.h>
#include<time.h>
#include"Head.h"
using namespace std;

int main(int argc, char *argv[])
{
	srand((unsigned(time(NULL))));
	int n = readFile(argv[1]);
	scan();
	for (int j = 0; j<n; j++)
	{
		int judge = rand() % 4; //设置产生分式的概念  
		randomNumber(judge); //产生随机数字 
		randomOperation(judge); //产生随机符号 
		generateExpression(judge);//产生算式
		cout << endl;
	}
	print(); //统计结果 
	writeFile(argv[2]);
	system("PAUSE");
	return 0;
}

