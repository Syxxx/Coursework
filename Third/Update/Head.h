#ifndef Head_H
#define Head_H

/*****��Ҫ����*****/
void generateExpression(int judge, char *addr);//������ʽ 
void calculateResult(int judge, char *addr); //����� 
void checkanswer(int result, char *addr, int judge); //����� 
void print(); //ͳ�ƽ�� 
void scan();//�û����� 
void randomNumber(int judge); //����������� 
void randomOperation(int judge); //�������  
int readFile(char *fp);
void writeFile(char *fp, int out, int n, int result, int judge);

/*�ݹ�����𰸲���*/
void match(char nowsign);
double low();
double mid();
double high();


#endif.