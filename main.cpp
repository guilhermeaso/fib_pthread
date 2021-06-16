#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <pthread.h>

std::vector<int> fibValues;
void routine_size(int *);
void *calc_fib(void *);

int main() {

	int numbers = 0;

	pthread_t child;
	pthread_attr_t attr;
	pthread_attr_init(&attr);

	routine_size(&numbers);
	
	pthread_create(&child, &attr, calc_fib, (void*) &numbers);
	pthread_join(child, NULL);
	
	for(int i = 0; i < numbers - 1; i++ )
		printf("%d\n", fibValues.at(i));

	return 0;
}

void routine_size(int *numbers)
{
   std::cout << "How many Fibonacci numbers (Range 1 ~ 47)? ";
   std::cin >> *numbers;
   if((*numbers <= 0) || (*numbers > 47)) {
	   std::cout << "Invalid value!" << std::endl;;
	   exit(1);
   }
}

void *calc_fib(void *param) 
{
	int i = 0;
	int *pointer;

	pointer = (int *) param; 
	int fibCount = *pointer;	

	int a = 1;
	int b = 0;

	int fibnum = 0;
	
	while( i < fibCount ) {
		b = fibnum;

	    fibnum = a + b;
		fibValues.push_back(fibnum);

		a = b;
		i++;
	}

	pthread_exit(0);
}
