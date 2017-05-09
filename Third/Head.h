#ifndef Head_H
#define Head_H

/*****主要函数*****/
void generateExpression(int judge);//产生算式 
void calculateResult(int t,int judge); //运算答案 
void checkanswer(int result); //检验答案 
void print(); //统计结果 
void scan();//用户输入 
void randomNumber(int judge); //产生随机数字 
void randomOperation(int judge); //随机符号  
int readFile(char *fp);
void writeFile(char *fp);

/*递归运算答案部分*/
void match(char nowsign);
double low(int t);
double mid(int t);
double high(int t);


#endif.