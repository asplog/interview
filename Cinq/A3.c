#include<stdio.h>
#include"binary.h"
int main()
{
	unsigned int value = 0x0f18;//binary_from_string("110001111000");
	unsigned int p,n;
	{
		unsigned int c0=0,c1=0;			
		c0=binary_ntf(value);
		c1=binary_ntt(value>>c0);
		n=value+(1<<c0)+(1<<(c1-1))-1;
		fprintf(stderr,"%12u:",n);
		binary_write(n,2);
		int pop=binary_pop(n);
		fprintf(stderr,"%d bit\n",pop);
	}
	fprintf(stderr,"%12d:",value);
	binary_write(value,2);
	int pop=binary_pop(value);
	fprintf(stderr,"%d bit\n",pop);
	{
		unsigned int v=value;
		unsigned int c0=0,c1=0;
		c1=binary_ntt(v);
		v>>=c1;
		c0=binary_ntf(v);
		p=value-(1<<c1)-(1<<(c0-1))+1;
		fprintf(stderr,"%12d:",p);
		binary_write(p,2);
		unsigned int pop=binary_pop(p);
		fprintf(stderr,"%u bit\n",pop);		
	}	
	if(0)
	{
		unsigned int var=binary_from_string("0111111");
		binary_write(var,2);
		fprintf(stderr,"%d bit\n",binary_ntf(var));
	}
	if(0)
	{
		unsigned int var=binary_from_string("00111111111111111111111111110000");
		binary_write(var,2);
		fprintf(stderr,"%d bit\n",binary_ntt(var));
	}
	if(0)
	{
		unsigned int var=binary_from_string("0");
		binary_write(var,2);
		fprintf(stderr,"%d bit\n",binary_ntf(var));
	}
	return 0;
}
