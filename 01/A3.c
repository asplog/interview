#include<stdio.h>
#include<memory.h>
#define __MAP__SIZE__ 128
void count(unsigned int*map,register const char*s)
{
	while(*s)
	{
		++map[*s];
		++s;
	}
}
unsigned char map_is_same(unsigned int*map1,unsigned int*map2,unsigned int size)
{
	register unsigned char result=1;
	register unsigned int k=0;
	while(result&&k<size)
	{
		result&=map1[k]==map2[k];
		++k;
	}
	return result;
}
unsigned char anagram(const char*s1,const char*s2)
{
	unsigned int map[2][__MAP__SIZE__]={0};
	count(map[0],s1);
	count(map[1],s2);
	return map_is_same(map[0],map[1],__MAP__SIZE__);
}
int main()
{
	{
		char*s1="123";
		char*s2="312";
		unsigned char result=anagram(s1,s2);
		fprintf(stdout,"\"%s\" and \"%s\" are %s\n",s1,s2,result?"anagram":"not anagram");
	}
	{
		char*s1="111";
		char*s2="312";
		unsigned char result=anagram(s1,s2);
		fprintf(stdout,"\"%s\" and \"%s\" are %s\n",s1,s2,result?"anagram":"not anagram");
	}
	return 0;
}
