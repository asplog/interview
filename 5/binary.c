#include<unistd.h>
#include<stdio.h>
#include"binary.h"
void binary_write(unsigned int value,int fd)
{
	register unsigned int k,K;
	for(k=0,K=sizeof(value)*8;k<K;++k,value<<=1)
		write(fd,value&(1<<(sizeof(value)*8-1))?"1":"0",1);
	write(fd,"\n",1);
}
unsigned int binary_from_string(const char*str)
{
	register unsigned int result=0;
	register unsigned int k,K;
	for(k=0,K=sizeof(result)*8;k<K;++k)
	if(*str)
		result=(result<<1)|!((*str++)=='0');
	return result;
}
unsigned int binary_pop(unsigned int x)
{
	x=(x&0x55555555)+((x>> 1)&0x55555555);
	x=(x&0x33333333)+((x>> 2)&0x33333333);
	x=(x&0x0f0f0f0f)+((x>> 4)&0x0f0f0f0f);
	x=(x&0x00ff00ff)+((x>> 8)&0x00ff00ff);
	x=(x&0x0000ffff)+((x>>16)&0x0000ffff);
	return x;
}
unsigned int binary_nlt(unsigned int x)
{
	unsigned int n=0;
	if((x&0xffff0000)==0xffff0000)n+=16,n<<=16;
	if((x&0xff000000)==0xff000000)n+= 8,n<<= 8;
	if((x&0xf0000000)==0xf0000000)n+= 4,n<<= 4;
	if((x&0xc0000000)==0xc0000000)n+= 2,n<<= 2;
	if((x&0x80000000)==0x80000000)n+= 1,n<<= 1;
	return n+(x&1);
}
unsigned int binary_nlf(unsigned int x)
{
	unsigned int n=0;
	if(!(x>>16))n+=16,x<<=16;
	if(!(x>>24))n+= 8,x<<= 8;
	if(!(x>>28))n+= 4,x<<= 4;
	if(!(x>>30))n+= 2,x<<= 2;
	if(!(x>>31))n+= 1,x<<= 1;
	return n+(!x);
}
unsigned int binary_ntt(unsigned int x)
{
	unsigned int n=0;
	if((x&0x0000ffff)==0x0000ffff)n+=16,x>>=16;
	if((x&0x000000ff)==0x000000ff)n+= 8,x>>= 8;
	if((x&0x0000000f)==0x0000000f)n+= 4,x>>= 4;
	if((x&0x00000003)==0x00000003)n+= 2,x>>= 2;
	if((x&0x00000001)==0x00000001)n+= 1,x>>= 1;
	return n+(x&1);
}
unsigned int binary_ntf(unsigned int x)
{
	unsigned int n=0;
	if(!(x<<16))n+=16,x>>=16;
	if(!(x<<24))n+= 8,x>>= 8;
	if(!(x<<28))n+= 4,x>>= 4;
	if(!(x<<30))n+= 2,x>>= 2;
	if(!(x<<31))n+= 1,x>>= 1;
	return n+(!x);
}
unsigned int binary_dozu(unsigned int x,unsigned int y)
{
	return (x-y)&~(((((~x&y)|((~x^y)&(x-y)))+(1<<31))>>31)-1);
}
int binary_doz(int x,int y)
{
	return (x-y)&((~(x-y)^((x^y)&((x-y)^x)))>>31);
}
