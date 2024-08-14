/** @file
    Generic list.

    Copyright (C) 2018 Christian Zuckschwerdt

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.
*/

#ifndef INCLUDE_list2_H_
#define INCLUDE_list2_H_

#include <stddef.h>

/// Dynamically growing list, elems is always NULL terminated, call list2_ensure_size() to alloc elems.
typedef struct list {
    void **elems;
    size_t size;
    size_t len;
} list2_t;

typedef void (*list2_elem_free_fn)(void *);

/// Alloc elems if needed and ensure the list has room for at least min_size elements.
void list2_ensure_size(list2_t *list, size_t min_size);

/// Add to the end of elems, allocs or grows the list if needed and ensures the list has a terminating NULL.
void list2_push(list2_t *list, void *p);

/// Adds all elements of a NULL terminated list to the end of elems, allocs or grows the list if needed and ensures the list has a terminating NULL.
void list2_push_all(list2_t *list, void **p);

/// Remove element from the list, frees element with fn.
void list2_remove(list2_t *list, size_t idx, list2_elem_free_fn elem_free);

/// Clear the list, frees each element with fn, does not free backing or list itself.
void list2_clear(list2_t *list, list2_elem_free_fn elem_free);

/// Clear the list, free backing, does not free list itself.
void list2_free_elems(list2_t *list, list2_elem_free_fn elem_free);

#endif /* INCLUDE_list2_H_ */
