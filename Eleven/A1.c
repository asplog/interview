#include<stdio.h>
int appendWithSortInplace(int*a,int la,const int*b,int lb)
{
	int length=la+lb,dst=length;
	while(lb)
	{
		if(a[la-1]<b[lb-1])
			a[--dst]=b[--lb];//,fprintf(stderr,"%d:Done\n",b[lb]);
		else
			a[--dst]=a[--la];//,fprintf(stderr,"%d:Done\n",a[la]);
	}
	return	length;
}
int main()
{
	int a[256]={1,3,5,7,11,13,17,19,23,29,31,37,41,47};
	int b[]={2,4,8,16,32};
	int k,K;
	int ap=5,la=sizeof(a)/sizeof(*a);while(!a[--la]);++la;
	int bp=5,lb=sizeof(b)/sizeof(*b);
	la=appendWithSortInplace(a,la,b,lb);
	for(k=0,K=la;k<K;++k)
		fprintf(stderr,"%d%c",a[k],k<la-1?',':'\n');
	return 0;
}
