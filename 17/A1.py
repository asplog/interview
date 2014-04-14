#!/usr/bin/env python -i
def swap(a,b):
	a^=b;
	b^=a;
	a^=b;
	return a,b;

