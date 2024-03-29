/*
 * Program to evaluate face values of cards.
 * Released under the MIT licence.
 * (c)2020 Johan Stjernholm.
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char card_name[3];
	int count = 0;
	do
	{
		puts("Enter the card name: ");
		scanf("%2s", card_name);
		int val = 0;
		switch (card_name[0])
		{
		case 'K':
		case 'Q':
		case 'J':
			val = 10;
			break;
		case 'A':
			val = 11;
			break;
		case 'X':
			continue;
		default:
			val = atoi(card_name);
			if ((val < 1) || (val > 10)) {
				puts("Error: incorrect card value");
				continue;
			}
		}
		/* Check if the value is 3 to 6 */
		if ((val > 2) && (val < 7)) {
			puts("Count has gone up");
			count++;
		}
		/* Otherwise check if the card was 10, J, Q, or K */
		else if( val == 10) {
			puts("Count has gone down");
			count--;
		}
		printf("Current count: %i\n", count);
	} while (card_name[0] != 'X');
	return 0;
}