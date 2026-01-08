
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef union {
	int i;
	float f;
	char str[20];
} Data;

static void print_bytes(const char *label, const char *buf, size_t n) {
	printf("%s (hex): ", label);
	for (size_t k = 0; k < n; k++)
		printf("%02x ", (unsigned char)buf[k]);
	printf("\n");
}

static void print_union_state(const Data *d) {
	printf("union.i = %d\n", d->i);
	printf("union.f = %f\n", d->f);
	// print string as text: replace non-printable with '.' to avoid garbage
	printf("union.str (as text): \"");
	for (size_t k = 0; k < sizeof(d->str); k++) {
		unsigned char c = (unsigned char)d->str[k];
		putchar(isprint(c) ? c : '.');
	}
	printf("\"\n");
	print_bytes("union.str bytes", d->str, sizeof(d->str));
	printf("---\n");
}

int main(void) {
	Data d;

	printf("--- Union demo (Data) ---\n");

	// Assign integer
	memset(&d, 0, sizeof(d));
	d.i = 123456;
	printf("After assigning d.i = 123456:\n");
	print_union_state(&d);

	// Assign float
	memset(&d, 0, sizeof(d));
	d.f = 3.14159f;
	printf("After assigning d.f = 3.14159:\n");
	print_union_state(&d);

	// Assign string
	memset(&d, 0, sizeof(d));
	strncpy(d.str, "Hello, union!", sizeof(d.str));
	d.str[sizeof(d.str) - 1] = '\0';
	printf("After assigning d.str = \"Hello, union!\":\n");
	print_union_state(&d);

	printf("Note: A union stores a single value; assigning one member overwrites the others.\n");

	return 0;
}

