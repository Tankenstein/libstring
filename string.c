#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "string.h"

String *String_new(const char *content) {
	String *string = (String *) malloc(sizeof(String));
	if (string == NULL) {
		return NULL;
	}
	int length = strlen(content);
	string->content = (char *) malloc(sizeof(char) * length);
	if (string->content == NULL) {
		return NULL;
	}
	strcpy(string->content, content);
	string->length = length;
	return string;
}

void String_destroy(String *string) {
	free(string->content);
	free(string);
}

void String_setContent(String *string, const char *content) {
	int length = strlen(content);
	void *ptr = realloc(string, length);
	if (ptr == NULL) {
		// FIXME: alert user somehow
	}
	strcpy(string->content, content);
	string->length = length;
}

bool String_equals(String *first, String *second) {
	if (first->length != second->length) {
		return false;
	}
	for (int i = 0; i < first->length; i++) {
		if (first->content[i] != second->content[i]) {
			return false;
		}
	}
	return true;
}

int String_indexOf(String *string, String *search) {
	// TODO: implement
	return -1;
}

String *String_add(String *original, String *addString) {
	int tempCounter = 0;
	char *temp = malloc(sizeof(char) * (original->length + addString->length));
	for (int i = 0; i < original->length; i++, tempCounter++) {
		temp[tempCounter] = original->content[i];
	}
	for (int i = 0; i < addString->length; i++, tempCounter++) {
		temp[tempCounter] = addString->content[i];
	}
	String *newString = String_new(temp);
	free(temp);
	return newString;
}

void String_print(String *string) {
	fputs(string->content, stdout);
}

void String_println(String *string) {
	puts(string->content);
}
