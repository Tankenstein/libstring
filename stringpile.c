#include <stdlib.h>

#include "stringpile.h"
#include "string.h"

StringPile *StringPile_new() {
  StringPile *pile = (StringPile *) malloc(sizeof(StringPile) * __STRINGPILE_STARTING_SIZE);
  if (pile == NULL) {
    return NULL;
  }
  pile->size = __STRINGPILE_STARTING_SIZE;
  pile->filled = 0;
  pile->elements = (String **) malloc(sizeof(String *) * pile->size);
  if (pile->elements == NULL) {
    free(pile);
    return NULL;
  }
  return pile;
}

/**
 * Add room for 2x more strings on a pile.
 * @param  pile Pile to reallocate.
 * @return     Reallocated pile.
 * @private
 */
static StringPile *StringPile_larger(StringPile *pile) {
  pile->size = pile->size * 2;
  pile->elements = (String **) realloc(pile->elements, sizeof(String *) * pile->size);
  if (pile->elements == NULL) {
    free(pile);
    return NULL;
  }
  return pile;
}

void StringPile_destroy(StringPile *pile) {
  free(pile->elements);
  free(pile);
}

String *StringPile_String_new(StringPile *pile, const char *contents) {
  if (pile->filled == pile->size) {
    StringPile_larger(pile);
  }
  String *string = String_new(contents);
  if (string == NULL) {
    return NULL;
  }
  pile->elements[pile->filled++] = string;
  return string;
}

void StringPile_burn(StringPile *pile) {
  for (int i = 0; i < pile->filled; i++) {
    String_destroy(pile->elements[i]);
  }
  pile->filled = 0;
}
