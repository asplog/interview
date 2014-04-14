#!/usr/bin/env python 
def badd(a,b):
	d=a^b;
	c=(a&b)<<1;
	return badd(d,c) if c else d;
a=1314;
b=33131;
print(a+b);
print(badd(a,b))

