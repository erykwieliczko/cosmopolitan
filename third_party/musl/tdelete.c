/*-*- mode:c;indent-tabs-mode:t;c-basic-offset:8;tab-width:8;coding:utf-8   -*-│
│vi: set et ft=c ts=8 tw=8 fenc=utf-8                                       :vi│
╚──────────────────────────────────────────────────────────────────────────────╝
│                                                                              │
│  Musl Libc                                                                   │
│  Copyright © 2005-2020 Rich Felker, et al.                                   │
│                                                                              │
│  Permission is hereby granted, free of charge, to any person obtaining       │
│  a copy of this software and associated documentation files (the             │
│  "Software"), to deal in the Software without restriction, including         │
│  without limitation the rights to use, copy, modify, merge, publish,         │
│  distribute, sublicense, and/or sell copies of the Software, and to          │
│  permit persons to whom the Software is furnished to do so, subject to       │
│  the following conditions:                                                   │
│                                                                              │
│  The above copyright notice and this permission notice shall be              │
│  included in all copies or substantial portions of the Software.             │
│                                                                              │
│  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,             │
│  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF          │
│  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.      │
│  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY        │
│  CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,        │
│  TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE           │
│  SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                      │
│                                                                              │
╚─────────────────────────────────────────────────────────────────────────────*/
#include "libc/mem/mem.h"
#include "third_party/musl/search.h"
#include "third_party/musl/tsearch.h"

asm(".ident\t\"\\n\\n\
Musl libc (MIT License)\\n\
Copyright 2005-2020 Rich Felker, et. al.\"");
asm(".include \"libc/disclaimer.inc\"");
// clang-format off


void *tdelete(const void *restrict key, void **restrict rootp,
	int(*cmp)(const void *, const void *))
{
	if (!rootp)
		return 0;

	void **a[MAXH+1];
	struct node *n = *rootp;
	struct node *parent;
	struct node *child;
	int i=0;
	/* *a[0] is an arbitrary non-null pointer that is returned when
	   the root node is deleted.  */
	a[i++] = rootp;
	a[i++] = rootp;
	for (;;) {
		if (!n)
			return 0;
		int c = cmp(key, n->key);
		if (!c)
			break;
		a[i++] = &n->a[c>0];
		n = n->a[c>0];
	}
	parent = *a[i-2];
	if (n->a[0]) {
		/* free the preceding node instead of the deleted one.  */
		struct node *deleted = n;
		a[i++] = &n->a[0];
		n = n->a[0];
		while (n->a[1]) {
			a[i++] = &n->a[1];
			n = n->a[1];
		}
		deleted->key = n->key;
		child = n->a[0];
	} else {
		child = n->a[1];
	}
	/* freed node has at most one child, move it up and rebalance.  */
	free(n);
	*a[--i] = child;
	while (--i && __tsearch_balance(a[i]));
	return parent;
}