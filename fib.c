#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int size = 1000;
const int numbers_to_show = 50000; 

void sum(unsigned char *a, unsigned char *b)
{
    unsigned int s;
    unsigned int carry = 0;
   
    for(int i = 0; i < size; ++i)
    {
        s = (unsigned int)a[i] + (unsigned int)b[i] + carry;

        carry = s / 10;
        s %= 10;

        b[i] = (unsigned char)s;
    }
}

void pfib(unsigned char *a, int n)
{
    printf("\n[%d.]\t", n);
    int x;
    for(int i=size-1; ;i--)
        if(a[i]!=0) 
        {
            x = i;
            break;
        }
    
    for(int i=x; i>=0; i--)
	{
        printf("%c", (a[i]+48));
	}
}

void fib(unsigned char* a, unsigned char* b, int n)
{
    sum(a, b);
    //pfib(c,n);
    if (n < numbers_to_show)
        fib(b , a , ++n);
    else
        //printf("\nTheEnd!\n");
        pfib(b, n);
}

void rc()
{
	printf("reached checkpoint!\n");
}

unsigned char* initialize()
{
	unsigned char* r = (unsigned char*) malloc(sizeof(unsigned char)*size);
	for(int i=0; i<size;i++)
		r[i] = 0;
	r[0] = 1;
	return r;
}

int main()
{
    clock_t begin = clock();
    unsigned char *a,*b; 
	a = initialize();
	b = initialize();

    fib(a,b,3);
    clock_t end = clock();
    printf("\n%f\n", (float)(end-begin)/CLOCKS_PER_SEC);
    free(a);
    free(b);

    return 0;
}