/**
 * Simple testing class for libstring
 */
#include <stdio.h>

#include "string.h"
#include "stringpile.h"

int main() {
	StringPile *pile = StringPile_new();
	String *string = String_new("Hwhadup");
	String_println(string);

	if (String_equals(string, SPString_new(pile, "Hwhadup"))) {
		puts("They are equal!");
	} else {
		puts("They are not equal!");
	}

	StringPile_burn(pile);

	String **wtfpl = String_split(SPString_new(pile, "wtfplfplwtf"), "f");
	String **pos = wtfpl;
	while (*pos != NULL) {
		String_println(*pos++);
	}

	StringPile_burn(pile);

	String *sum = String_new("");
	String_add(sum, SPString_new(pile, "My name is "), string);
	StringPile_burn(pile);

	String_println(sum);
	String_destroy(sum);

	String_setContent(string, "abcdeefgh");

	printf("Index is %d (should be 3)\n", String_indexOf(string, SPString_new(pile, "dee")));
	printf("Index is %d (should be -1)\n", String_indexOf(string, SPString_new(pile, "hg")));
	printf("Index is %d (should be -1)\n", String_indexOf(string, SPString_new(pile, "abaowijdaoiwjd")));

	StringPile_burn(pile);

	String_setContent(string, "grehtk zroelkat");

	String *sliced = String_slice(SPString_new(pile, ""), string, 0, -1, 2);
	String_println(sliced);
	StringPile_burn(pile);

	String_setContent(string, "thAAcA AAcA sparta!");
	
	String *replaced = SPString_new(pile, "");
	String_replace(replaced, string, SPString_new(pile, "AAcA"), SPString_new(pile, "is"));
	String_println(replaced);
	StringPile_burn(pile);

	String_destroy(string);
	return 0;
}
