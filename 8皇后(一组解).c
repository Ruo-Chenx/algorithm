
//8皇后(一组解)
#include <stdio.h>
#include <stdlib.h>

int col[8]={0};//记录列的 
int left[15]={0};//左斜线 
int right[15]={0};//右斜线 
int Q[8]={0};

void Queen()
{
	int i=0;
	int top=-1;
	int j=0;
	while(top!=7)
	{
		for(;j<8;j++)
		{
			if(!col[j] && !left[i+j] && !right[7+i-j])//可以放皇后 
			{
				Q[++top]=j;
				col[j]=left[i+j]=right[7+i-j]=1;
				i++;
				j=0;
				break;
			}
		}
		//放不了皇后,回溯
		if(j==8)
		{
			i--;
			j=Q[top--];//抹皇后
			col[j]=left[i+j]=right[7+i-j]=0;
			j++; 
		} 
	}
}

void Print()
{
	int i,j;
	char a[8][8];
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
}

int main(void)
{
	Queen();
	Print(); 
	return 0;
} 
