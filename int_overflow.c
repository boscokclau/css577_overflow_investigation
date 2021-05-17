#include <stdio.h>
#include <limits.h>

int main( int argc, char *argv ){
	int max_int = INT_MAX;
	int min_int = INT_MIN;

	printf("max_int = %d | %x\n", max_int, max_int);
	printf("\tsize = %d\n", sizeof(max_int));
	

	printf("min_int = %d | %x\n", min_int, min_int);
	printf("\tsize = %d\n", sizeof(min_int));

	printf("\n");


	printf("Value using %%d. Notice the wrap-around fron +ve to -ve or vice versa. Only 1 correct answer.\n");
	printf("max_int + 1       = %11d | %08x     <- Wrap-around to -ve because MSB is 1.\n", max_int + 1, max_int + 1);
	printf("min_int - 1       = %11d | %08x     <- Wrap-around to +ve because MSB is 0.\n", min_int - 1, min_int - 1);
	printf("max_int + min_int = %11d | %08x     <- Only correct calculation.\n", max_int + min_int, max_int + min_int);
	printf("max_int * 2       = %11d | %08x     <- Left shift causing MSB to 1, making result -ve.\n", max_int * 2, max_int * 2);
	printf("min_int * 2       = %11d | %08x     <- Left shift moves 8 beyond MSB truncated, leaving\n", min_int * 2, min_int * 2);
	printf("                                                  leaving all bits 0s.\n");

	printf("\n");

	printf("Value using %%u. Notice that any calculations involving min_int are wrong\n");
	printf("max_int + 1       = %11u | %08x     <- Correct answer. MSB is 1, but value is promoted\n", max_int + 1, max_int + 1);
	printf("                                                  to unsigned. Result is correcty +ve.\n");
	printf("min_int - 1       = %11u | %08x     <- Wrong answer. INT_MIN is no longer considered\n", min_int - 1, min_int - 1);
	printf("                                                  -ve after promotionto unsigned int. The\n");
	printf("                                                  calculation becomes (INT_MAX + 1) - 1.\n");
	printf("max_int + min_int = %11u | %08x     <- Wrong answer. min_int is no longer considered\n", max_int + min_int, max_int + min_int);
	printf("                                                  -ve after promotionto unsigned int. The\n");
	printf("                                                  calculation becomes INT_MAX + (INT_MAX + 1).\n");
	printf("max_int * 2       = %11u | %08x     <- Correct answer. MSB is 1, but value is promoted\n", max_int * 2, max_int * 2);
	printf("                                                  to unsigned. Result is correcty +ve.\n");
	printf("min_int * 2       = %11u | %08x     <- Wrong answer. INT_MIN has become +ve after type\n", min_int * 2, min_int * 2);
	printf("                                                  promotion. *2 makes a left shift. 8 moved\n");
	printf("                                                  beyong MSB truncated, leaving all bit 0s.\n");
	printf("max_int * 2 + 1   = %11u | %08x     <- Right answer. Max value possible.\n", max_int * 2 + 1, max_int * 2 + 1);
	printf("max_int * 2 + 2   = %11u | %08x     <- Wrong answer. 8 beyond MSB truncated, leaving\n", max_int * 2 + 2, max_int * 2 + 2);
	printf("                                                  all bit 0s.\n");

	printf("\n");


	long long int max_int_long = INT_MAX;
	long long int min_int_long = INT_MIN;

	printf("max_int_long = %lld | %016llx\n", max_int_long, max_int_long);
	printf("\tsize = %d\n", sizeof(max_int_long));
	

	printf("min_int_long = %lld | %016llx\n", min_int_long, min_int_long);
	printf("\tsize = %d\n", sizeof(min_int_long));

	printf("\n");


	printf("Value using %%lld. Results are all correct as long long int has double size than that if int\n");
	printf("                  in Linux 32-bit systems.\n");
	printf("(long long int)INT_MAX + 1                      = %21lld | %016llx\n", max_int_long + 1, max_int_long + 1);
	printf("(long long int)INT_MIN - 1                      = %21lld | %016llx\n", min_int_long - 1, min_int_long - 1);
	printf("(long long int)INT_MAX + (long long int)INT_MIN = %21lld | %016llx\n", max_int_long + min_int_long, max_int_long + min_int_long);
	printf("(long long int)INT_MIN * 2                      = %21lld | %016llx\n", max_int_long * 2, max_int_long * 2);
	printf("(long long int)INT_MAX * 2                      = %21lld | %016llx\n", min_int_long * 2, min_int_long * 2);

	printf("\n");

	printf("Value using %%llu. Notice calculations involving (long long int)INT_MIN are wrong becoming +ve.\n");
	printf("(long long int)INT_MAX + 1                      = %21llu | %016llx\n", max_int_long + 1, max_int_long + 1);
	printf("(long long int)INT_MIN - 1                      = %21llu | %016llx\n", min_int_long - 1, min_int_long - 1);
	printf("(long long int)INT_MAX + (long long int)INT_MIN = %21llu | %016llx\n", max_int_long + min_int_long, max_int_long + min_int_long);
	printf("(long long int)INT_MAX * 2                      = %21llu | %016llx\n", max_int_long * 2, max_int_long * 2);
	printf("(long long int)INT_MIN * 2                      = %21llu | %016llx\n", min_int_long * 2, min_int_long * 2);

	printf("\n");

	printf("int to short. Notice the trucation in hex.\n");
	short short_int = (short)INT_MAX;
	printf("INT_MAX: %d | %x\n", INT_MAX, INT_MAX);
	printf("(short)INT_MAX with %%d: %d | %x\n", short_int, short_int);
	printf("INT_MAX with %%hd | %%hx, %hd | %hx\n", INT_MAX, INT_MAX);
}