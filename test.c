/**
 * Simple testing class for libstring
 */
#include <stdio.h>

#include "string.h"

int main() {
	String *string = String_new("Hwhadup");
	String_println(string);

	String *temp = String_new("Hwhadup");

	if (String_equals(string, temp)) {
		puts("They are equal!");
	} else {
		puts("They are not equal!");
	}

	String_setContent(string, "Erlich Bachmann");
	String_println(string);

	if (String_equals(string, temp)) {
		puts("They are equal!");
	} else {
		puts("They are not equal!");
	}

	String_destroy(temp);

	String *firstPart = String_new("My name is ");
	String *sum = String_add(firstPart, string);
	String_destroy(firstPart);
	String_destroy(string);

	String_println(sum);
	String_destroy(sum);
	return 0;
}
