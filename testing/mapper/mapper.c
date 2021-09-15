#include <stdio.h>
#include <stdlib.h>

int main (int argc, char ** argv) {
		int x = atoi(argv[1]);
		int y = atoi(argv[2]);
		int density = atoi(argv[3]);

		char empty = argv[4][0];
		char obstacle = argv[5][0];
		char full = argv[6][0];

		int invalid = atoi (argv[7]);

		if(invalid != 0)
			invalid = 1;
		if (invalid && rand() % (y+1) == 0)
			return (0);
		printf ("%s%c%c%c\n", argv[2], empty, obstacle, full);
		if (invalid && rand() % (x+1) == 0)
			return (0);
		for (int i= 0; i < y +  invalid * (rand() % (x+1)); i++)
		{
			for (int j= 0; j < x + invalid * (rand() % (y+1)); j++)
			{
				if ((rand() % (y+1)) * 2 < density)
					printf ("%c", obstacle);
				else
					printf ("%c", empty);
				if(invalid && (rand() % (x+1) > 5))
				{
					printf ("%c", (rand() % 127));
				}
			}
			printf ("\n");
		}

	return 0;
}
