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
	void *ptr = realloc(string, sizeof(char) * length);
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
	// FIXME: use Knuth-Morris-Pratt algorithm instead of naive linear search
	for (int i = 0; i < string->length - search->length; i++) {
		if (string->content[i] == search->content[0]) {
			for (int j = 0; j < search->length && i + j < string->length; j++) {
				if (string->content[i + j] != search->content[j]) {
					break;
				} else if (j == search->length - 1) {
					return i;
				}
			}
		}
	}
	return -1;
}

String *String_add(String *original, String *addString) {
	int tempCounter = 0;
	char *temp = (char *) malloc(sizeof(char) * (original->length + addString->length));
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

String *String_slice(String *string, int start, int end, int step) {
	int actualLength = 0;
	char *temp = (char *) malloc(sizeof(char) * string->length);
	if (temp == NULL) {
		return NULL;
	}
	if (end < 0) {
		end = string->length + end + 1;
	}
	for (int i = start, tempIndex = 0; i < end; i += step, tempIndex++) {
		temp[tempIndex] = string->content[i];
		actualLength++;
	}
	void *ptr = realloc(temp, actualLength);
	if (ptr == NULL) {
		return NULL;
	}
	String *sliced = String_new("");
	String_setContent(sliced, temp);
	free(temp);
	return sliced;
}

String **String_split(String *original, const char *separator) {
	// FIXME: split this fucker out a bit maybe
	int sepLength = strlen(separator);
	String **stringList = (String **)malloc(sizeof(String *));
	int listElement = 0, tmpSplitElements = 0;
	char *tmpSplit = (char *)malloc(sizeof(char));
	for (int i = 0; i < original->length; i++) {
		char *currentChar = &original->content[i];
		if (*currentChar == separator[0]) {
			int sepCounter = 1;
			char checkNextChar = *(currentChar + sepCounter);
			while (i + sepCounter < original->length
					&& sepCounter < sepLength
					&& checkNextChar == separator[sepCounter]) {
				sepCounter++;
			}
			if (sepCounter == sepLength) {
				stringList = (String **)realloc(stringList, sizeof(stringList) + sizeof(String *));
				stringList[listElement++] = String_new(tmpSplit);
				tmpSplit = (char *)malloc(sizeof(char));
				tmpSplitElements = 0;
				i += sepLength - 1;
			}
		} else {
			tmpSplit = (char *)realloc(tmpSplit, sizeof(tmpSplit) + sizeof(char));
			tmpSplit[tmpSplitElements++] = *currentChar;
		}
	}
	if (listElement) {
		stringList[listElement++] = String_new(tmpSplit);
	}
	free(tmpSplit);
	stringList[listElement] = NULL;
	if (stringList[0] == NULL) {
		stringList[0] = original;
	}
	return stringList;
}

void String_print(String *string) {
	fputs(string->content, stdout);
}

void String_println(String *string) {
	puts(string->content);
}
