#include<stdio.h>
int N=1920;
double change(int rest,int coin,double*cache)
{
	int match=0,smaller=0,k,K;
	switch(coin)
	{
	case 500:
		smaller=100;
		break;
	case 100:
		smaller=50;
		break;
	case  50:
		smaller=10;
		break;
	case  10:
		smaller=5;
		break;
	case   5:
		smaller=1;
		break;
	case   1:
		match=1;
		break;
	}
	if(smaller)
	{
		for(k=0;k*coin<=rest;++k)
		{
//			if(cache[rest-k*coin])
//				match+=cache[rest-k*coin];
//			else
				match+=(cache[rest-k*coin]=change(rest-k*coin,smaller,cache));
		}
	}
	return match;
}
int main()
{
	int n=N;
	double cache[4096]={0};
	double match=change(n,500,cache);
	fprintf(stdout,"P: %lf\n",match);
	return 0;
}
