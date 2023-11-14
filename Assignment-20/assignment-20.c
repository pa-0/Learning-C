#include <stdio.h>
#include <stdlib.h>

struct holder {
	int member_int;
	char member_char;
	float member_float;
};

int main(void) {
	struct holder var_holder = {50, 'W', 3.14};
	printf(
			"This is the int: %d, this is the char: %c, this is the float: %.2f",
		  	var_holder.member_int,
			var_holder.member_char,
			var_holder.member_float
	);
	return EXIT_SUCCESS;
}
