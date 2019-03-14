/*
 * UNG's Not GNU
 * 
 * Copyright (c) 2011-2017, Jakob Kaivo <jkk@ung.org>
 * 
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 */

#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <string.h>
#include <libgen.h>
#include <unistd.h>

/*d Give the non-directory portion of a pathname d*/
/*a string a*/
/*a [suffix] a*/

int main(int argc, char *argv[])
{
	while (getopt(argc, argv, "") != -1) {
		return 1;
	}

	if (optind > argc || argc > optind + 2) {
		return 1;
	}

	char *path = basename(argv[optind]);
	char *suffix = argv[optind+1];

	if (suffix != NULL && strcmp(suffix, path)) {
		size_t slen = strlen(suffix);
		size_t plen = strlen(path);
		if (!strcmp(&path[plen - slen], suffix)) {
			path[plen - slen] = '\0';
		}
	}

	printf("%s\n", path);
	return 0;
}
