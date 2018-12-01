//装箱问题
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define V 100 
//物品信息
typedef struct {
	int gno;//商品编号 
	int gv;//商品体积 
}ElemG;
//物品结点
typedef struct node{
	int gno;
	struct node * link;
}GoodsLink;
//创建箱子结点
typedef struct box{
	int remainder;//剩余的体积 
	GoodsLink * hg;
	struct box * next; 
}BoxLink;
void BinPacking(ElemG *g,int n)   //装箱 
{
	//遍历所有已排序的物品
	int i;
	int cnt=0;
	BoxLink *hbox=NULL,*p,*tail;
	GoodsLink *pnew,*q;
	for(i=0;i<n;i++)
	{
		//遍历箱子链
		for(p=hbox;p&&p->remainder<g[i].gv;p=p->next);
		if(!p)
		{
			//开新箱子
			p=(BoxLink *)malloc(sizeof(BoxLink));
			p->remainder=V; 
			p->hg=NULL;
			p->next=NULL;
			if(!hbox)     hbox=tail=p;//挂箱子
			else tail=tail->next=p;	
		}
		p->remainder-=g[i].gv;//减体积
		//放物品
		pnew=(GoodsLink *)malloc(sizeof(GoodsLink));
		pnew->gno=g[i].gno;
		pnew->link=NULL;
		if(!(p->hg))  p->hg=pnew;
		else {
			for(q=p->hg;q->link;q=q->link);
			q->link=pnew;
		}	
	}
	//输出
	for(p=hbox;p;p=p->next)
	{
		printf("第%d个箱子:",++cnt);
		for(q=p->hg;q;q=q->link)
		{
			printf("\t装入了编号为%d的物品.",q->gno);
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
		fflush(stdin);//清缓存 
	//	printf("请输入第%d个商品的编号:",i+1);
	//	scanf("%d",&g[i].gno);
		g[i].gno=i+1;
		printf("请输入第%d个商品的体积:",i+1);
		scanf("%d",&vol);
		g[i].gv=vol;
	}
	for(i=0;i<n-1;i++)//按体积降序排列 
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
