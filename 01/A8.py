#!/usr/bin/env python
def isSubString(s1,s2):
	return s1 in s2;

if __name__=='__main__':
	s1='waterbottle';
	s2='erbottlewat';
	print(isSubString(s2,s1+s1))
