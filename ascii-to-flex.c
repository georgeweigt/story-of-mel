// emit an array for converting ascii to flexowriter values

#include <stdio.h>

// p for print, converts flexowriter value to ascii

int ptab[128] = {
	0,	0,	'Z',	'z',	')',	'0',	' ',	' ',
	0,	0,	'B',	'b',	'L',	'l',	'_',	'-',
	0,	0,	'Y',	'y',	'*',	'2',	'=',	'+',
	0,	0,	'R',	'r',	'"',	'3',	':',	';',
	'\n',	'\n',	'I',	'i',	0,	'4',	'?',	'/',
	'\b',	'\b',	'D',	'd',	'%',	'5',	']',	'.',
	'\t',	'\t',	'N',	'n',	'$',	'6',	'[',	',',
	0,	0,	'M',	'm',	0,	'7',	'V',	'v',
	0,	0,	'P',	'p',	0,	'8',	'O',	'o',
	0,	0,	'E',	'e',	'(',	'9',	'X',	'x',
	0,	0,	'U',	'u',	'F',	'f',	0,	0,
	0,	0,	'T',	't',	'G',	'g',	0,	0,
	0,	0,	'H',	'h',	'J',	'j',	0,	0,
	0,	0,	'C',	'c',	'K',	'k',	0,	0,
	0,	0,	'A',	'a',	'Q',	'q',	0,	0,
	0,	0,	'S',	's',	'W',	'w',	0,	0,
};

int rtab[128]; // r for read, converts ascii to flexowriter value

int
main()
{
	int c, i;

	rtab['1'] = 6; // ascii 1 same as l

	for (i = 0; i < 128; i++) {
		c = ptab[i];
		if (c)
			rtab[c] = i / 2;
	}

	for (i = 0; i < 128; i++) {
		printf("\t%d,", rtab[i]);
		if (i % 8 == 7)
			printf("\n");
	}
}
