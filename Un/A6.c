#include<stdio.h>
#include<stdlib.h>
#define __N__ 3
unsigned int to_addr(unsigned int w,unsigned int h,unsigned int N)
{
	return h*N+w;
}
void rotate(char*byte,unsigned int S,unsigned int N)
{
	register char*buffer=memcpy(malloc(S*N*N),byte,S*N*N);
	register unsigned int w,W;
	register unsigned int h,H;
	for(h=0,H=N;h<H;++h)
	{
		for(w=0,W=N;w<W;++w)
		{
			byte[to_addr(w,h,N)]=buffer[to_addr(H-h-1,w,N)];
		}
	}
}
void transpose(char*byte,unsigned int S,unsigned int N)
{
	register unsigned int length = N * N;
	register unsigned int k,K;
	register unsigned int w,h,W,H;
	for(w=0,W=N;w<W;++w)
	{
		for(h=0,H=w;h<H;++h)
		{
			register unsigned int src_index = h*N+w;
			register unsigned int dst_index = w*N+h;
			byte[src_index]^=byte[dst_index];
			byte[dst_index]^=byte[src_index];
			byte[src_index]^=byte[dst_index];
		}
	}
}
void dump(char*byte,unsigned int N)
{
	register unsigned int w,W;
	register unsigned int h,H;
	for(h=0,H=N;h<H;++h)
	{
		for(w=0,W=N;w<W;++w)
		{
			fprintf(stdout,"%2d%c",byte[h*W+w],w==W-1?'\n':',');
		}
	}
}
void shuffle(char*byte,unsigned int N)
{
	register unsigned int k,K;
	for(k=0,K=N*N;k<K;++k)
		byte[k]=k;
}
int main()
{
	const unsigned int N=__N__;
	const unsigned int S=1;
	char*map=malloc(S*N*N);
	shuffle(map,N);
	fprintf(stdout,"src\n");
	dump(map,N);
	rotate(map,S,N);
	//transpose(map,S,N);
	fprintf(stdout,"dst\n");
	dump(map,N);
	free(map);
	return 0;
}
