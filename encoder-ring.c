// TA-BOT:MAILTO michael.makdah@marquette.edu

#include <stdio.h>
#include <ctype.h>
#define RINGSIZE 27		//ringsize never changes
int main(int argc, char *argv[])
{
	int userkey;		//key variable that user will input

	if (argc > 2)
	{
		printf("Too many arguments\n");		//if user inputs more than one key value
		return 0;
	}
	
	if (argc == 1)
	{
		 userkey = 0;			//default key value is 0 if no argument
	}

	else
	{
		userkey = atoi(argv[1]);		//atoi converts string to int
	}

	int c;
	int i = 0;
	int encode = 0;

	char alphabet[RINGSIZE] = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";	//alphabet array to check against
	while( (c = getchar() ) != EOF) {
		c = toupper(c);
		if(c != '\n') {
			for(i =0; i<=RINGSIZE; i++) {
				if( c== alphabet[i]) {
					encode = encode + userkey + i;		//encode value formula
					break;
				}	
			}
		encode = encode%RINGSIZE;				//if encode value is greater than 27 use modulo
		putchar(alphabet[encode]);
		}
		else
			putchar(c);
	}
return 0;
}
