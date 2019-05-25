//迷宫问题(一组解)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define R 7
#define C 8

int M[R+2][C+2]={0};//迷宫数组 
int t[R+2][C+2]={0};//记录走过的位置 
int Move[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

int Maze(int x,int y)
{
	int i,a,b,tag;
	if(x==7&&y==8)
		return 1;
	for(i=0;i<4;i++)
	{
		a=x+Move[i][0];
		b=y+Move[i][1];
		if(M[a][b]==0 && t[a][b]==0)
		{
			tag=Maze(a,b);
			t[a][b]=1;
			if(tag==1)
			{
				printf("(%d,%d)",a,b);
				return 1;
			}
		}
	} 
	return 0;
}

int main(void)
{
	int i,j,tag;
	srand(time(NULL));
	for(i=0;i<R+2;i++)
	{
		for(j=0;j<C+2;j++)
		{
			if(i==0||j==0||i==R+1||j==C+1)
			{
				M[i][j]=1;
				t[i][j]=1;
			}
		}
	}
	for(i=1;i<R+1;i++)
	{
		for(j=1;j<C+1;j++)
		{
			M[i][j]=rand()%2;
		}
	}
	M[R][C]=0;
	for(i=0;i<R+2;i++)
	{
		for(j=0;j<C+2;j++)
		{
			printf("%3d",M[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("\n");
	tag=Maze(1,1);
	printf("(%d,%d)",1,1);
	/*srand(time(NULL));
	x=rand()%100;*/
	return 0;
} 
