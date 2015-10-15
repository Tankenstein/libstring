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

	String *repeated = String_new("wtfplfplwtf");

	String **wtfpl = String_split(repeated, "f");
	String **pos = wtfpl;
	while (*pos != NULL) {
		String_println(*pos++);
	}

	String_destroy(repeated);

	String *firstPart = String_new("My name is ");
	String *sum = String_add(firstPart, string);
	String_destroy(firstPart);

	String_println(sum);
	String_destroy(sum);

	String_setContent(string, "abcdeefgh");
	String *searchable = String_new("dee");
	String *unSearchable = String_new("hg");
	String *unSearchableBig = String_new("abaowijdaoiwjd");

	printf("Index is %d (should be 3)\n", String_indexOf(string, searchable));
	printf("Index is %d (should be -1)\n", String_indexOf(string, unSearchable));
	printf("Index is %d (should be -1)\n", String_indexOf(string, unSearchableBig));

	String_destroy(searchable);
	String_destroy(unSearchable);
	String_destroy(unSearchableBig);

	String_destroy(string);
	return 0;
}
