//װ������
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define V 100 
//��Ʒ��Ϣ
typedef struct {
	int gno;//��Ʒ��� 
	int gv;//��Ʒ��� 
}ElemG;
//��Ʒ���
typedef struct node{
	int gno;
	struct node * link;
}GoodsLink;
//�������ӽ��
typedef struct box{
	int remainder;//ʣ������ 
	GoodsLink * hg;
	struct box * next; 
}BoxLink;
void BinPacking(ElemG *g,int n)   //װ�� 
{
	//�����������������Ʒ
	int i;
	int cnt=0;
	BoxLink *hbox=NULL,*p,*tail;
	GoodsLink *pnew,*q;
	for(i=0;i<n;i++)
	{
		//����������
		for(p=hbox;p&&p->remainder<g[i].gv;p=p->next);
		if(!p)
		{
			//��������
			p=(BoxLink *)malloc(sizeof(BoxLink));
			p->remainder=V; 
			p->hg=NULL;
			p->next=NULL;
			if(!hbox)     hbox=tail=p;//������
			else tail=tail->next=p;	
		}
		p->remainder-=g[i].gv;//�����
		//����Ʒ
		pnew=(GoodsLink *)malloc(sizeof(GoodsLink));
		pnew->gno=g[i].gno;
		pnew->link=NULL;
		if(!(p->hg))  p->hg=pnew;
		else {
			for(q=p->hg;q->link;q=q->link);
			q->link=pnew;
		}	
	}
	//���
	for(p=hbox;p;p=p->next)
	{
		printf("��%d������:",++cnt);
		for(q=p->hg;q;q=q->link)
		{
			printf("\tװ���˱��Ϊ%d����Ʒ.",q->gno);
		}
		printf("\n");
	} 
}
int main(void)
{
	ElemG * g;
	ElemG t;
	int n=5,i,j,vol;
	g=(ElemG *)malloc(n*sizeof(ElemG));
	for(i=0;i<n;i++)
	{
		fflush(stdin);//�建�� 
	//	printf("�������%d����Ʒ�ı��:",i+1);
	//	scanf("%d",&g[i].gno);
		g[i].gno=i+1;
		printf("�������%d����Ʒ�����:",i+1);
		scanf("%d",&vol);
		g[i].gv=vol;
	}
	for(i=0;i<n-1;i++)//������������� 
	{
		for(j=i+1;j<n;j++)
		{
			if(g[i].gv < g[j].gv)
			{
				t=g[i];
				g[i]=g[j];
				g[j]=t;
			}
		}
	}
	BinPacking(g,n); 
	return 0;
}
