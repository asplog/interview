#!/usr/bin/env python
def cut(arg,dict={}):
	if arg:
		hd=arg.pop();
		tail=cut(arg);
		return tail if hd in tail else tail+[hd];	
	else:	
		return [];	

if __name__=='__main__':
	A=[3,1,4,1,9,2,5,7,9]
	B=cut(A);
	print(B);
