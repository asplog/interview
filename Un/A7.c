#include<stdio.h>
#include<stdlib.h>
typedef char byte;
unsigned int to_addr(unsigned int n,unsigned int N,unsigned int m,unsigned int M)
{
	return m*N+n;
}
void order(byte*data,unsigned int N,unsigned int M)
{
	register unsigned int n,m;
	for(n=0;n<N;++n)
	{
		for(m=0;m<M;++m)
		{
			unsigned int addr=to_addr(n,N,m,M);
			data[addr]=rand()%12-6;
		}
	}
}
void dump(byte*data,unsigned int N,unsigned int M)
{
	register unsigned int n,m;
	for(n=0;n<N;++n)
	{
		for(m=0;m<M;++m)
		{
			unsigned int addr=to_addr(n,N,m,M);
			fprintf(stdout,"%3d%c",data[addr],m==M-1?'\n':',');
		}
	}	
}
void rowcol_zero(byte*map,unsigned int N,unsigned int M)
{
	register unsigned int n,m;
	register unsigned char*n_encounter=calloc(1,N);
	register unsigned char*m_encounter=calloc(1,M);
	for(n=0;n<N;++n)
	{
		for(m=0;m<M;++m)
		{
			register unsigned int addr = to_addr(n,N,m,M);
			n_encounter[n]|=!map[addr];
			m_encounter[m]|=!map[addr];
		}
	}
	for(n=0;n<N;++n)
	{
		for(m=0;m<M;++m)
		{
			if(n_encounter[n]||m_encounter[m])map[to_addr(n,N,m,M)]=0;
		}
	}
	free(m_encounter);
	free(n_encounter);
}
int main()
{
	const unsigned int N = 8;
	const unsigned int M = 12;
	byte*data=malloc(1*M*N);
	order(data,N,M);
	fprintf(stdout,"src\n");
	dump(data,N,M);
	rowcol_zero(data,N,M);
	fprintf(stdout,"dst\n");
	dump(data,N,M);
	free(data);
	return 0;
}

