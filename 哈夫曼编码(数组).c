//����������(����)
#include <stdio.h>
#include <stdlib.h>
typedef struct{
	char word;
	int weight;
	int left,right,parent;
	int *code;
}HuffNode;

//������������
void CreateHuffmanTree(HuffNode *F,int n)
{
	//��ʼ��ɭ��
	int i,ch,w,loop,k1,k2;
	for(i=0;i<n;i++)
	{
		fflush(stdin);
		printf("�������%d�������ַ�:",i+1);
		scanf("%c",&ch);
		printf("�������%d������ַ���Ȩֵ:",i+1);
		scanf("%d",&w);
		F[i].word=ch;
		F[i].weight=w;
		F[i].left=F[i].right=F[i].parent=-1;
	}
	//��ʼ�����������
	for(loop=0;loop<n-1;loop++)
	{
		for(k1=0;k1<n+loop && F[k1].parent!=-1;k1++);
		for(k2=k1+1;k2<n+loop && F[k2].parent!=-1;k2++);
		for(i=k2;i<n+loop;i++)
		{
			if(F[i].parent==-1)
			{
				if(F[i].weight<F[k1].weight)
				{
					k2=k1;
					k1=i;
				}
				else if(F[i].weight<F[k2].weight)
					k2=i;
			}
		}
		F[i].word='X';
		F[i].weight=F[k1].weight+F[k2].weight;
		F[i].left=k1;
		F[i].right=k2;
		F[i].parent=-1; 
		F[k1].parent=F[k2].parent=i;	
	} 
}

//ʵ�ֹ���������
void CreateHuffmanCode(HuffNode *F,int n)
{
	int i,c,pa;
	int *p;
	for(i=0;i<n;i++)
	{
		F[i].code=p=(int *)malloc(n*sizeof(int));
		c=i;
		p[0]=0;
		while(F[c].parent!=-1)
		{
			pa=F[c].parent;
			if(F[pa].left==c)
				p[++p[0]]=0;
			else
				p[++p[0]]=1;
			c=pa;
		}	
	}
}
 
//������� 
void Print(HuffNode *F,int n)
{
	int *p;
	int i,j;
	printf("\n\n����Ľ������:\n");
	for(i=0;i<n;i++)
	{
		p=F[i].code;
		printf("%c�ı�����:\t",F[i].word);
		for(j=p[0];j>0;j--)
		{
			printf("%d",p[j]);
		}
		printf("\n");
	} 
}

int main(void)
{
	int n;
	printf("������Ҷ�ӽ��ĸ���:\n");
	scanf("%d",&n);
	//����ɭ��
	HuffNode *F;
	F=(HuffNode *)malloc((2*n-1)*sizeof(HuffNode));	
	//������������
	CreateHuffmanTree(F,n); 
	//ʵ�ֹ���������
	CreateHuffmanCode(F,n);
	//���
	Print(F,n);
	return 0;
} 
