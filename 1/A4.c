#include<stdio.h>
#define __BUFFER__SIZE__ 128
void uri_encode(char*src,const char*dst)
{
	while(*dst)
	{
		switch(*dst)
		{
		case ' ':
			*src++='%';
			*src++='2';
			*src++='0';
			break;
		default:
			*src++=*dst;
			break;
		}
		++dst;
	}
}
int main()
{
	char src[__BUFFER__SIZE__]="I love programming!";
	char dst[__BUFFER__SIZE__]={0};
	uri_encode(dst,src);
	fprintf(stdout,"Convert %s into %s\n",src,dst);
	return 0;
}
