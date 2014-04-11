#!/usr/bin/env python
L=['a','ab','b','ba','c'];
S=sorted(L,cmp=lambda x,y:0 if sorted(x)==sorted(y) else -1 if sorted(x)<sorted(y) else 1);
print(S);
