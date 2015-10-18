#ifndef STRINGPILE_H
#define STRINGPILE_H
/**
 * Simple string allocation pile.
 *
 * Author: Uku Tammet
 */
#include "string.h"

/**
 * Starting length of pile.
 */
#define __STRINGPILE_STARTING_SIZE 4

/**
 * String pile struct.
 */
typedef struct __stringpile_t {
  String **elements;
  int size, filled;
} StringPile;

/**
 * Constructor, create a new StringPile.
 * @return New StringPile.
 */
extern StringPile *StringPile_new();

/**
 * Destructor, deallocate StringPile.
 * DOES NOT DEALLOCATE STRINGS! You have to burn first.
 * @param pile The StringPile to deallocate.
 */
extern void StringPile_destroy(StringPile *pile);

/**
 * Allocate a new String from a StringPile.
 * @param  pile     Pile to allocate on.
 * @param  contents Contents of string.
 * @return          New string, allocated on stringpile.
 */
extern String *StringPile_String_new(StringPile *pile, const char *contents);
static inline String *SPString_new(StringPile *pile, const char *contents) {
  return StringPile_String_new(pile, contents);
}

/**
 * Deallocate all strings in pile.
 * @param pile The pile to deallocate in.
 */
extern void StringPile_burn(StringPile *pile);

#endif
