#include <iostream>
#include <sstream>
#include <stdlib.h>
#include<time.h>

using namespace std;

class Random
{
protected:
    int digit;
public:
    Random(){digit = rand() % 3 + 4;}
    ~Random(){}
    void random();
};

class RandomNumber:public Random
{
protected:
    int digit2;
    int nums[10];
public:
    RandomNumber(){digit2=digit;}
    ~RandomNumber(){}
    void randomN();
};

void RandomNumber::randomN()
{
for (int i = 0; i<digit; i++)
{
    nums[i] = rand()%9+1;    // 数字
}
}

class RandomOperation:public Random
{
protected:
    char signs[10];
public:
    RandomOperation(){}
    ~RandomOperation(){}
    void randomO(); 
};

void RandomOperation::randomO()
{
    char c[] = "+-*/";
    for (int i = 0; i<digit; i++)
    {
        signs[i] = c[rand() % 4]; //符号
    }
    signs[digit] = '=';
}

class Expression:public RandomOperation,public RandomNumber
{
private:
    string equ;
    stringstream str;
public:
    Expression(){}
    ~Expression(){}
    void getExpression();
};

void Expression::getExpression()
{   
int braO,braT;
randomN();
randomO(); 
int bracketNum =rand()%2;    //括号个数 
if (bracketNum == 1)
{
    braO = rand() % (digit2 - 2) + 1;
    braT = braO + rand() % (digit2 - braO) + 1;
    //braO是第一个括号的位置，braT是第二个括号的位置
}
for (int i = 0; i<digit2; i++)
{
    if (bracketNum != 0 && i == braO - 1)
        str << "(";
    str << nums[i];
    if (bracketNum != 0 && i == braT - 1)
        str << ")";
    if (i != digit2 - 1)
        str << signs[i + 1];
}
str << "="; 
str >> equ;
cout<<equ;
}

int main()
{
srand((unsigned(time(NULL))));
Expression exp;
exp.getExpression();
return 0;
} 
