#include <stdio.h>

int main( int argc, char *argv ){

	printf("sizeof(float) = %d\n", sizeof(float));

	float a = 1.234;
	float a_prev = a;
	int i = 0;
	int j = 0;

	printf("%f | %x\n", a, *(unsigned int*)&a);
	printf("Press any key to continue\n");
	getchar();

	do{
		a_prev = a;
		a = a + 1.0;
		if( i % 1000000 == 0 ){
			printf("%20d: %f | %x\n", i, a, *(unsigned int*)&a);
		}

		i++;
	}while( a != a_prev);

	printf("i = %d; a = %f | %x\n", i, a, *(unsigned int*)&a);

	printf("Press any key to continue\n");
	getchar();

	a = 1.1234;
	a_prev = a;
	j = i - 5;
	i = 0; /* reset i */
	do{
		a_prev = a;
		a = a + 1.0;
		if( i >= j ){
			printf("%20d: %f | %x\n", i, a, *(unsigned int*)&a);
		}
		i++;
	}while( a != a_prev);

	printf("Press any key to continue\n");
	getchar();

	a_prev = a;
	for(j = i; j < i + 10; j++){
		a = a + 1.0;
		a_prev = a;
		printf("%20d: %f | %x\n", j, a, *(unsigned int*)&a);
	}
}