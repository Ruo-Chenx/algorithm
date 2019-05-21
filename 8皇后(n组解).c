//8皇后(n组解)
#include <stdio.h>

int col[8]={0};//记录列 
int left[15]={0};//左斜线 
int right[15]={0};//右斜线 
int Q[8];
int cnt=0;

void Queen(int i)
{
	int j=0;
	for(;j<8;j++)
	{
		if(!col[j] && !left[i+j] && !right[7+i-j])//可以放皇后 
		{
			Q[i]=j;
			col[j]=left[i+j]=right[7+i-j]=1;
			if(i<7)  Queen(i+1);
			else   Print();
				
			j=Q[i];//抹皇后
			col[j]=left[i+j]=right[7+i-j]=0;
				 
		}
	}
}

void Print()
{
	int i,j;
	char a[8][8];
	printf("  第%d组解为:\n",++cnt); 
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			if(Q[i]==j)
				a[i][j]='Q';
			else
				a[i][j]='X';
			printf("%3c",a[i][j]);	
		}
		printf("\n");
	}
	printf("\n");
	//getch();
}

int main(void)
{
	int i=0;
	Queen(i);
	return 0;
} 
