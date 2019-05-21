//8�ʺ�(n���)
#include <stdio.h>

int col[8]={0};//��¼�� 
int left[15]={0};//��б�� 
int right[15]={0};//��б�� 
int Q[8];
int cnt=0;

void Queen(int i)
{
	int j=0;
	for(;j<8;j++)
	{
		if(!col[j] && !left[i+j] && !right[7+i-j])//���ԷŻʺ� 
		{
			Q[i]=j;
			col[j]=left[i+j]=right[7+i-j]=1;
			if(i<7)  Queen(i+1);
			else   Print();
				
			j=Q[i];//Ĩ�ʺ�
			col[j]=left[i+j]=right[7+i-j]=0;
				 
		}
	}
}

void Print()
{
	int i,j;
	char a[8][8];
	printf("  ��%d���Ϊ:\n",++cnt); 
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
