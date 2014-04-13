#include<stdio.h>
void reverse(char*str)
{
	register char*s=str;
	register char*e=str;
	while(*++e);
	--e;
	while(s<e)
	{
		*s^=*e;
		*e^=*s;
		*s^=*e;
		++s;
		--e;
	}
}
int main()
{
	char string[]="test string";
	reverse(string);
	fprintf(stdout,"%s\n",string);
	return 0;
}
