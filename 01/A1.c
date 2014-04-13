unsigned char unique_test(register const char*string)
{
	unsigned char result=1;
	const char range[2]={0x40,0x7F};
	char map[128]={0};
	while(result&&*string)
	{
		if(*string<range[0]||range[1]<*string);
		else
		{
			if(map[*string])result&=0;
			map[*string]=1;
		}
		++string;
	}
	return result;
} 
unsigned char unique_test_without_map(const char*const string)
{
	register unsigned char result=1;
	register const char*s1=string;
	while(result&&*s1)
	{
		register const char*s2=s1;
		while(result&&*++s2)
		{
			if(*s1==*s2)result=0;
		}
		++s1;
	}
	return result;
}
#include<stdio.h>
int main(int argc,char**argv)
{
	char*test="dictionary";
	unsigned char flag=unique_test_without_map(test);
	fprintf(stdout,"%s\n",flag?"Unique":"Not unique");
	return 0;
}

