/*
最大32ビットの整数NとM，ビットの位置を示す値iとjが与えられています．
このとき，Nのjビット目からiビット目にMを挿入する

入力: 0b100 0000 0000, M=10011, i=2, j=6
出力: 0b100 0100 1100
*/
#include<stdio.h>
#include"binary.h"
int main()
{
	unsigned int n=binary_from_string("10000000000");
	unsigned int m=binary_from_string("10011");
	unsigned int i=2;
	unsigned int j=6;
	unsigned int k,K;
	unsigned int mask=0;
	for(k=0,K=j-i;k<K;++k)
	{
		mask<<=1;
		mask|=1;
	}
	binary_write(n,1);
	binary_write(m,1);
	mask<<=i;
	m<<=i;
	n=(n&(~mask))|m;

	binary_write(n,1);
	return 0;
}
