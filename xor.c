/* xor.c - xor two files
 *
 * author: Hanno Böck, https://hboeck.de/
 * license: CC0 / public domain
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	FILE *f1, *f2, *fo;
	size_t s1, s2;
	unsigned char *buf1, *buf2;

	if (argc < 3) {
		printf("Usage:\n");
		printf("xor [input file 1] [input file 2] [output file]\n");
		return -1;
	}

	f1 = fopen(argv[1], "r+");
	f2 = fopen(argv[2], "r+");

	fseek(f1, 0, SEEK_END);
	s1 = ftell(f1);
	fseek(f2, 0, SEEK_END);
	s2 = ftell(f2);

	if (s1 < s2) {		/* Make sure s1 / f1 point to larger file */
		s1 = s1 ^ s2;
		s2 = s1 ^ s2;
		s1 = s1 ^ s2;
		fo = f1;
		f1 = f2;
		f2 = fo;
	}

	fo = fopen(argv[3], "w");

	fseek(f1, 0, SEEK_SET);
	buf1 = malloc(s1);
	fread(buf1, s1, 1, f1);
	fseek(f2, 0, SEEK_SET);
	buf2 = malloc(s2);
	fread(buf2, s2, 1, f2);

	do {
		s2--;
		buf1[s2] ^= buf2[s2];
	} while (s2 != 0);

	fwrite(buf1, s1, 1, fo);

	free(buf1);
	free(buf2);

	fclose(f1);
	fclose(f2);
	fclose(fo);

	return 0;
}
