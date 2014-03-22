#include<stdio.h>
#include<math.h>
#include"binary.h"
unsigned char isZero(double arg)
{
	return fabs(arg)<pow(2,-32);
//	return !arg;
}
int main()
{
	double value=pow(2,-13)+pow(2,-11)+pow(2,-15);

	value*=pow(2,32);
	double rest=fmod(value,1.0);
	if(isZero(rest))
		binary_write(value,2);
	else
		fprintf(stdout,"Error\n");

	return 0;
}
