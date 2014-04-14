#!/usr/bin/env python -i
L=[1,2,3,4,5,6,7,8,9];
H={};
S=10;
for k in L:
	if (S-k) in H:
		print("(%d,%d)"%(k,S-k));
	H[k]=k;
