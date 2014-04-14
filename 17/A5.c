#include<stdio.h>
int H(const char*d,const char*s)
{
	int k,K,h=0;
	for(k=0,K=4;k<K;++k)
		h+=(d[k]==s[k]);
	return	h;
}
int B(const char*d,const char*s)
{
	int w,W,b=0;
	for(w=0,W=4;w<W;++w)
	{
		int h,H;
		for(h=0,H=4;h<H;++h)
		{
			b+=(w!=h)&&(d[w]==s[w]);
		}
	}
	return	b;
}
int main()
{
	const char*e="GGRR";
	const char*f="RGBY";
	printf("%d hit, %d blow\n",H(e,f),B(e,f));
	return	0;
}
