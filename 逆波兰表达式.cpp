//逆波兰表达式
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 100
int Level(char ch)
{
	switch(ch)
	{
		case '*':  
		case '/':  return 2;
		case '+':  
		case '-':  return 1;
		case '(':  return 0;
		case '@':  return -1;
	}
}
int Cal(int x1,int x2,char op)
{
	switch(op)
	{
		case '*':  return x2*x1;   
		case '/':  return x2/x1;  
		case '+':  return x2+x1;  
		case '-':  return x2-x1; 
	}
}
int Calculate(char s[])
{
	char *Sop;//运算符栈
	int *Sval;//数值栈
	int i,valtop=-1,y,x1,x2;
	int optop=0;
	char op;
	Sop=(char *)malloc(N*sizeof(char));
	Sval=(int *)malloc(N*sizeof(int)); 
	Sop[0]='@';//初始化栈
	i=0;
	while(s[i])//遍历中缀字符串 
	{
		if(s[i]>='0'&&s[i]<='9')//处理从s[i]开始的整数 
		{
			y=0;
			while(s[i]>='0'&&s[i]<='9')
			{
				y=y*10+s[i]-'0';
				i++;
			}
			Sval[++valtop]=y;
			i--;
		}
		else if(s[i]=='*'||s[i]=='/'||s[i]=='+'||s[i]=='-')//s[i]为运算符 
		{
			while(Level(s[i])<=Level(Sop[optop]))
			{
				op=Sop[optop--];
				x1=Sval[valtop--];
				x2=Sval[valtop--];
				Sval[++valtop]=Cal(x1,x2,op);
			}
			Sop[++optop]=s[i];
		}
		else if(s[i]=='(')
		{
			Sop[++optop]=s[i];
		}
		else if(s[i]==')')
		{
			while(Sop[optop]!='(')
			{
				op=Sop[optop--];
				x1=Sval[valtop--];
				x2=Sval[valtop--];
				Sval[++valtop]=Cal(x1,x2,op);	
			}
			optop--;
		}
		i++; 
	}
	while(optop)
	{
		op=Sop[optop--];
		x1=Sval[valtop--];
		x2=Sval[valtop--];
		Sval[++valtop]=Cal(x1,x2,op);	
	} 
	return Sval[0];
}
int main(void)
{
	char ex[N];
	int value;
	printf("请输入一个中缀表达式:");//输入中缀表达式
	gets(ex);
	value=Calculate(ex);//计算 
	printf("%s=%d\n",ex,value);//输出 
	return 0;
} 
