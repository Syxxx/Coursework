#ifndef Head_H
#define Head_H

/*****��Ҫ����*****/
void generateExpression(int judge);//������ʽ 
void calculateResult(int t,int judge); //����� 
void checkanswer(int result); //����� 
void print(); //ͳ�ƽ�� 
void scan();//�û����� 
void randomNumber(int judge); //����������� 
void randomOperation(int judge); //�������  
int readFile(char *fp);
void writeFile(char *fp);

/*�ݹ�����𰸲���*/
void match(char nowsign);
double low(int t);
double mid(int t);
double high(int t);


#endif.