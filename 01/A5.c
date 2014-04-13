#include<stdio.h>
#define __BUFFER__SIZE__ 256
void compress(char*s2,const char*s1)
{
	register char*dst=s2;
	register const char*src=s1;
	while(*src)
	{
		register unsigned int count = 1;
		register char temp[__BUFFER__SIZE__],*p=temp;
	
		while(src[0]==src[count])++count;
		*dst++=*src;
		src+=count;

		while(count)*p++='0'+count%10,count/=10;	
		while(temp<p)*dst++=*--p;
	}
	if(src-s1<dst-s2)
	{
		while(*s1)*s2++=*s1++;
		*s2=0;
	}
}
int main()
{
	{
		char	raw[__BUFFER__SIZE__]="aaabbbbbbbbbbbbbbbbbbbbbbbbcccccc";
		char	enc[__BUFFER__SIZE__]="";
		compress(enc,raw);
		fprintf(stderr,"Compress %s into %s\n",raw,enc);
	}
	{
		char	raw[__BUFFER__SIZE__]="abcd";
		char	enc[__BUFFER__SIZE__]="";
		compress(enc,raw);
		fprintf(stderr,"Compress %s into %s\n",raw,enc);
	}
	return 0;
}
