#!/usr/bin/env python -i
def mul(a,b):
	result=0;
	for k in range(b):
		result=result+a
	return	result
def div(a,b):
	result=-1;
	while result*b<=a:
		result=result+1;
	return result-1;
def sub(a,b):
	result=0;
	while result+b<a:
		result=result+1;
	return result;
