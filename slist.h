/*
	This is part of pyahocorasick Python module.
	
	<short info>

	Author    : Wojciech Mu�a, wojciech_mula@poczta.onet.pl
	WWW       : http://0x80.pl/proj/pyahocorasick/
	License   : 3-clauses BSD (see LICENSE)
	Date      : $Date$

	$Id$

*/
#ifndef ahocorasick_slist_h_included
#define ahocorasick_slist_h_included

#include "common.h"

/** base structure for list */
#define LISTITEM_data struct ListItem* __next;

/** list item node */
typedef struct ListItem {
	LISTITEM_data
} ListItem;

/** Create new item */
ListItem* list_item_new(const size_t size);

/** Deallocate list item. */
void list_item_delete(ListItem* item);

/** Returns pointer to next item */
#define list_item_next(item) (((ListItem*)(item))->__next)

/** Set new pointer to next item */
#define list_item_setnext(item, next) list_item_next(item) = (ListItem*)(next)


/** List.

	const time of:
	* append
	* prepend
	* pop first
	* get first/last
*/
typedef struct {
	ListItem*	head;	///< first node
	ListItem*	last;	///< last node
} List;


/** Initialize list. */
void list_init(List* list);

/** Deallocate all elements of list. */
int list_delete(List* list);

/** Append item at the end of list. */
ListItem* list_append(List* list, ListItem* item);

/** Prepend item at front of list. */
ListItem* list_push_front(List* list, ListItem* item);

/** Unlink first item from list. */
ListItem* list_pop_first(List* list);

/** Test if list is empty. */
#define list_empty(list) ((list)->head == NULL)


#endif
