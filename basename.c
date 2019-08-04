/*
 * UNG's Not GNU
 *
 * Copyright (c) 2011-2019, Jakob Kaivo <jkk@ung.org>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <libgen.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "");

	while (getopt(argc, argv, "") != -1) {
		return 1;
	}

	if (optind >= argc) {
		printf("basename: missing operand\n");
		return 1;
	}

	if (argc > optind + 2) {
		printf("basename: too many operands\n");
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
