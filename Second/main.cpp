#include <iostream>
#include "Circle_H.h"

using namespace std;

int main()
{
	double s=0,r=0; //s：面积 r：半径
	cin >> r;      //输入半径
	s = calculate(r); //计算面积
	cout << s << endl; //输出面积
	return 0;
}