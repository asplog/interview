#include<stdio.h>
int pluto(int n)
{
	return	0<n?pluto(n-1)+pluto(n-2)+pluto(n-3):n<0?0:1;
}
int dp(int n,int*cache)
{
	return	0<n?0<cache[n]?cache[n]:(cache[n]=dp(n-1,cache)+dp(n-2,cache)+dp(n-3,cache)):n<0?0:1;
}
int main()
{
	int n=28;
	int cache[512]={0};
	fprintf(stdout,"p:%d\n",dp(n,cache));
	fprintf(stdout,"p:%d\n",pluto(n));
	return 0;
}

