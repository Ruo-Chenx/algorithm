//�沨�����ʽ
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
	char *Sop;//�����ջ
	int *Sval;//��ֵջ
	int i,valtop=-1,y,x1,x2;
	int optop=0;
	char op;
	Sop=(char *)malloc(N*sizeof(char));
	Sval=(int *)malloc(N*sizeof(int)); 
	Sop[0]='@';//��ʼ��ջ
	i=0;
	while(s[i])//������׺�ַ��� 
	{
		if(s[i]>='0'&&s[i]<='9')//�����s[i]��ʼ������ 
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
		else if(s[i]=='*'||s[i]=='/'||s[i]=='+'||s[i]=='-')//s[i]Ϊ����� 
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
	printf("������һ����׺���ʽ:");//������׺���ʽ
	gets(ex);
	value=Calculate(ex);//���� 
	printf("%s=%d\n",ex,value);//��� 
	return 0;
} 
