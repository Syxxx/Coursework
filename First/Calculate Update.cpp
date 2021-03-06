#include<iostream>
#include<string>
#include<stdlib.h>
#include<time.h>
using namespace std;

/*****主要函数*****/
void generateExpression();//产生算式 
void calculateResult (int t); //运算答案 
void checkanswer(int result); //检验答案 
void print(); //统计结果 
int scan();//用户输入 
void randomNumber(); //随机数字 
void randomOperation(); //随机符号  


/*递归运算答案部分*/ 
void match( char nowsign ); 
double low(int t); 
double mid(int t); 
double high(int t); 

char nowsign,sign,signs[10];
int k=0,correct=0,wrong=0,flag=0,temp=0,bracketNum=0,braO,braT,lan,nums[10],digit,judge; 

int main()
{
	srand((unsigned(time(NULL))));
	int n=scan();
	for (int j=0;j<n;j++)
	{
	    judge=rand()%4; //设置产生分式的概念  
		randomNumber(); //产生随机数字 
		randomOperation(); //产生随机符号 
		generateExpression();//产生算式
		cout<<endl;
	}
	print(); //统计结果 
    return 0;
}

/*用户输入*/ 
int scan()
{
	int n;
	cout<<"请选择语言(Please choose language)"<<endl;cout<<"1.中文 2.English ： ";
	cin>>lan;
	switch(lan)
	{
		case 1:cout<<"请输入题数：";cin>>n;break;
		case 2:cout<<"Please enter a number of questions：";cin>>n;break;
		defaul:cout<<"Error!";break; 
	}
	return n;
 } 
 
 /*随机产生数字*/ 
 void randomNumber()
 {
 	if (judge!=0)
 	{
      digit=rand()%3+4;   //数字的个数 
     for(int i=0;i<digit;i++)
     {
          nums[i]=rand()%9+1;    // 数字
     }		
	}
	 else if (judge==0)
	 {
	     for(int i=0;i<4;)
	     {
	         int x=rand()%9+1;    //有可能是分子分母的两个数 
	         int y=rand()%9+1;  
	         if(x!=y)
			 {
			 	  
				  if(x>y)
				  {
				  	nums[i]=y;nums[i+1]=x;
				  }
				  else
				  {
				  	nums[i]=x;nums[i+1]=y;
				  }
				  i+=2;
			 } 
	     }
	 }
 }
 
 /*随机产生符号*/ 
 void randomOperation()
 {
 	char c[]="+-*/";
 	if (judge!=0)
 	{
	  	
	 	for(int i=0;i<digit;i++)
	     {
	          signs[i]=c[rand()%4]; //符号
	     }
	     signs[digit-1]='=';		
	 }
    else if (judge==0)
    {
    	signs[0]=c[rand()%4];
		signs[1]='=';
	}
 }
 
 /*产生算式*/ 
void generateExpression()
{
     bracketNum=rand()%2;    //括号个数 
     if(bracketNum==1)
     {
     	flag=0;
     	temp=0;
        braO=rand()%((digit-1)/2)+1;
        braT=braO+rand()%((digit-1)/2)+2;
  //分别在第几个数加括号 
 //braO+1是第一个括号的位置，braT是第二个括号的位置
     }
    calculateResult(digit);
}

/*运算答案*/ 
void calculateResult (int t)  
{
	double result=0;
	if (judge!=0)
	{
		k=0;
		sign = nums[0]; //载入第一个符号
		result = low(t); //进行计算
		if (result==(int)result)
		{
			if (bracketNum==0)
			{
				for (int i=0;i<t;i++)
	    		{
	     			if (signs[i]=='/')
	     			cout<<nums[i]<<"÷";
	     			else
	     			cout<<nums[i]<<signs[i];
				}
			// cout<<result;
			}
			else if (bracketNum==1)
			{
		    		for(int i=0;i<t;i++) //测试算式
		    		{
		    		    if(i==braO) cout<<"(";
						cout<<nums[i];
						if(i==braT-1) cout<<")";
						if (signs[i]=='/')
						cout<<"÷";
						else
						cout<<signs[i];
		    		}
			//		cout<<result; 
			} 
			checkanswer(result);
		} 
		else if (result!=(int)result)
		{
			randomNumber();
			randomOperation();
			generateExpression();
		}		
	}	
	else if (judge==0)
	{
		int demo; //分子
		double nume; //分母 
		demo=nums[1]*nums[3];
		nums[0]*=nums[3];
		nums[2]*=nums[1];
		switch (signs[0])
		{
			case '+':nume=nums[0]+nums[2];break;
			case '-':nume=nums[0]-nums[2];break;
			case '*':nume=nums[0]*nums[2]/nums[3]/nums[1];break;
			case '/':nume=(double)nums[0]/(double)nums[2];break;
		}
		result=nume/(double)demo;
		if (result!=(int)result)
		{
			randomNumber();
			randomOperation();
			generateExpression();		
		}
		else
		{
		nums[0]/=nums[3];
		nums[2]/=nums[1];
		 for(int j=0,i=0;i<4;i++) //测试算式
	     {
	          if(i/2.0==i/2)
	          {
	          	cout<<"(";
			  }
			  cout<<nums[i];
			  if(i/2.0!=i/2)
			  {
			  	cout<<")";
			  }
	          if(i/2.0==i/2)
	          {
	          	cout<<"/";
			  }
			  else
			  {
			  	if (signs[j]=='/')
			  	cout<<"÷";
				else 
			  	cout<<signs[j];
			  	j++;
			  }
	     }
	    checkanswer(result);
		}
	}
}

void checkanswer(int result) //检验答案 
{
		int answer;
		char ch;
	    cin>>answer;
	    ch=getchar(); 
		if((answer==result)&&(ch!='e')) 
	    {
		    if(lan==1)
		    cout<<"     答案正确";
		    else
		    cout<<"     correct";
			correct+=1;
     	}
      	else if ((answer!=result)&&(ch!='e'))
      	{
      		if(lan==1)
	    	cout<<"     答案错误，正确答案为:"<<result;
	    	else
	    	cout<<"     wrong answer. The correct answer is:"<<result;
	    	wrong+=1;
		}
		if (ch=='e')
		{
			print();
		}
}

void match( char nowsign ) //匹配符号 
{
	if (bracketNum==0)
	{
		if( sign == nowsign ) //匹配成功，获取下一个标志
		{
			k++;
			if ((k%2) == 0) //下一位是数字 
			sign = nums[k/2];
			else    //下一位是符号 
			sign = signs[(k-1)/2];
		}
	}
	else if (bracketNum==1)
	{
		if( sign == nowsign ) //匹配成功，获取下一个标志
		{
			k++;
			if ((k==2*braO)&&(flag==0)) 
			{
				sign = '(';
				flag=1;
				k--;
			}
			else if ((k==braT*2-1)&&(temp==0))
			{
				sign = ')';
				temp=1;
				k--;
			}
			else if ((k==2*braO)&&(flag==1))
			sign = nums[k/2];
			else if ((k==braT*2-1)&&(temp==1))
			sign = signs[(k-1)/2];		
			else if (((k%2) == 0)&&(k!=2*braO)) //下一位是数字 
			sign = nums[k/2];
			else if (((k%2) != 0)&&(k!=braT*2-1))    //下一位是符号 
			sign = signs[(k-1)/2];
		}
	} 

}

double low(int t) //加减运算 
{
	double result1 = mid(t); //计算比加减运算优先级别高的部分
	while(( sign == '+' ) || ( sign == '-' ))
	if ( sign == '+')
	{
		match('+');     //进行加法运算
		result1 += mid(t);
		if (k==2*t-1)
		break;
	}
	else if ( sign == '-')
	{
		match('-');    //进行减法运算
		result1 -= mid(t);
		if (k==2*t-1) 
		break;
	}
	return result1;
}

double mid(int t) //乘除运算 
{
	double result2 = high(t);
		while(( sign == '*' ) || ( sign == '/' ))
	if ( sign == '*')
	{
		match('*');     //进行乘法运算
		result2 *= high(t);
		if (k==2*t-1)
		break;
	}
	else if ( sign == '/')
	{
		match('/');    //进行除法运算
		result2 /= high(t);
		if (k==2*t-1) 
		break;
	}
	return result2;
}


double high(int t) //括号运算及数字 
{
	double result3; 
	if( sign == '(' ) //带有括号的运算
	{
		match( '(' );
		result3 = low(t); //递归计算表达式
		match(')');
	}
	else if (sign >= 0 && sign<= 9) //实际的数字
	{
		result3=sign;
		k++;
		if (bracketNum==0)
		{
			sign = signs[(k-1)/2];//下一位是符号 
		}
		else if (bracketNum==1)
		{
			if ((k==braT*2-1)&&(temp==0))
			{
				sign = ')';
				temp=1;
				k--;
			}
			else if (((k%2) != 0)&&(k!=braT*2-1))    //下一位是符号 
			sign = signs[(k-1)/2];
		}

	}
	return result3;
}


void print() //统计结果 
{
	if(lan==1)
	cout<<endl<<"做对"<<correct<<"道题;"<<"做错"<<wrong<<"道题";
	else
	cout<<endl<<"Correct questions:"<<correct<<";Wrong questions:"<<wrong; 
	exit(0);
}
