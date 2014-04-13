#!/usr/bin/env python
def nth_from_last(arg,k):
	x=iter(arg);
	y=iter(arg);
	for k in range(0,k):
		y.next();
	result=None;
	try:
		while True:
			result=x.next();
			y.next();
	except StopIteration:
		return result;
	else:
		return None;

if __name__=='__main__':
	A=[3,1,4,1,9,2,5,7,9]
	B=nth_from_last(A,3);
	print(B);
