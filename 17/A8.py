#!/usr/bin/env python
I=[2, -8, 3, -2, 4, -10];
maxsum=-1000;
cursum=-1000;
for k in I:
	cursum+=k;
	if maxsum<cursum:
		maxsum=cursum;
	if cursum<0:
		cursum=0;
print(maxsum);
