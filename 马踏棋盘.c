//��̤����
#include <stdio.h>
int H[12][12];
int cnt,num=0;
int Move[8][2]={{2,1},{1,2},{2,-1},{1,-2},{-1,2},{-2,1},{-2,-1},{-1,-2}};

void Print()
{    
	int i,j;
	printf("  ��%d���Ϊ:\n",++num); 
	for(i=2;i<10;i++)
	{
		for(j=2;j<10;j++)
		{
			printf("%3d",H[i][j]);
		}
		printf("\n");
	}
	printf("\n");	
}

void Horse(int x,int y)
{
	int i,a,b;	
	for(i=0;i<8;i++)//������ߵ�8��λ�� 
	{
		//����a,b
		a=Move[i][0]+x;
		b=Move[i][1]+y; 
		if(H[a][b]==0)//�����̤ 
		{
			H[a][b]=++cnt;
			if(cnt==64)  
				Print();
			else
				Horse(a,b);
			cnt--;
			H[a][b]=0;
		} 
	}	
}

int main(void)
{
	int i,j;
	for(i=0;i<12;i++)
	{
		for(j=0;j<12;j++)
		{
			H[i][j]=-1;
		}
	}
	for(i=2;i<10;i++)
	{
		for(j=2;j<10;j++)
		{
			H[i][j]=0;
		}
	}
	
	for(i=2;i<10;i++)
	{
		for(j=2;j<10;j++)
		{
			cnt=0;
			H[i][j]=++cnt;
			Horse(i,j);	
		}
	}
	return 0;
} 
