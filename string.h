#ifndef STRING_H
#define STRING_H
/**
 * Simple string library for personal use.
 *
 * NONE of the methods except String_destroy deallocate
 * strings, so you have to be careful to deallocate everything
 * yourself.
 */
#include <stdbool.h>

/**
 * String struct, holds a pointer to content and length.
 */
typedef struct __string_t {
	char *content;
	int length;
} String;

/**
 * Constructor, creates new string.
 * @param  content String contents.
 * @return         New string.
 */
extern String *String_new(const char *content);

/**
 * Destructor, deallocates string.
 * @param string The string to deallocate.
 */
extern void String_destroy(String *string);

/**
 * Set the content of a string.
 * @param  string  The string to set content of.
 * @param  content The new contents of the string.
 */
extern void String_setContent(String *string, const char *content);

/**
 * Check if two strings are equal.
 * @param  first  The first string.
 * @param  second The second string.
 * @return        If the strings are equal.
 */
extern bool String_equals(String *first, String *second);

/**
 * Get the index of search in string.
 * @param  string The string to search in.
 * @param  search The string to search for.
 * @return        The index of the string or -1 if not found.
 */
extern int String_indexOf(String *string, String *search);

/**
 * Add two strings together, returning a new string.
 * @param  original  String to add to.
 * @param  addString The string to add.
 * @return New string, the sum of the two strings.
 */
extern String *String_add(String *original, String *addString);

/**
 *
 */
extern String **String_split(String *original, const char *separator);

/**
 * Print a string.
 * @param string The string to print.
 */
extern void String_print(String *string);

/**
 * Print a string, appending a newline.
 * @param string The string to print.
 */
extern void String_println(String *string);

#endif
