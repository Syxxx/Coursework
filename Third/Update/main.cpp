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
	writeFile(argv[2], 0, n,0,0);
	for (int j = 0; j<n; j++)
	{
		int judge = rand() % 4; //���ò�����ʽ�ĸ���  
		randomNumber(judge); //����������� 
		randomOperation(judge); //����������� 
		generateExpression(judge,argv[2]);//������ʽ
		cout << endl;
	}
	print(); //ͳ�ƽ�� 
	system("PAUSE");
	return 0;
}

