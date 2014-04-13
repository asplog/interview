#include<stdio.h>
int abs(int x)
{
	return x-((x<<1)&(x>>31));
}
int c(char*indices,int d,const int D)
{
	int	n,k,result=1;
	for(n=d;n<D;++n)
	{
		for(k=n+1;k<D;++k)
		{
			result&=indices[k]!=indices[n];
			result&=(k-n)!=abs(indices[k]-indices[n]);
		}
	}
	return	result;
}
int R(char*indices,int d,const int D)
{
	int	sum=0,k;
	if(c(indices,d,D))
	{
		if(--d<0)
			sum=1;
		else
		for(k=0;k<D;++k)
		{
			indices[d]=k;
			sum+=R(indices,d,D);
		}
	}
	return	sum;
}
int main(int argc,char**argv)
{
	char indices[8]={0};
	printf("8 queen: %d pattern\n",R(indices,8,8));
	return 0;
}
