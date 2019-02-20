// TA-BOT:MAILTO michael.makdah@marquette.edu
//
#include <stdio.h>
#include <ctype.h>
#define RINGSIZE 27
int main(int argc, char *argv[])
{
	int userkey;	//this is the key value the user will input at the start of the program
	
	if (argc > 2)
	{		//if there is more than one argument for key value, throw an error message
		printf("Too many arguments\n");
		return 0;
	}

	if (argc == 1)
	{
		userkey = 0;  //this is the defualt value for the key if there is not user input
	}
	
	else
	{
		userkey = atoi(argv[1]); //atoi converts a string to an integer
	}

	int c;
	int i = 0;
	int decode = 0;
	int previous = 0;
	
	char alphabet[RINGSIZE] = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";	//alphabet array
	while( (c = getchar() ) != EOF) {
		c = toupper(c);						//function to uppercase character
		if( c != '\n') {					//ignore newline char
			for(i = 0; i <= RINGSIZE; i++) {
				if( c == alphabet[i] ) {
					decode = i - previous  - userkey;	//formula for decoding
					previous = i;
					break;
				}
			}
		while( decode < 0) {
			decode = decode + 27; }			//if decode value is negative add 27 until it is

		putchar(alphabet[decode]);
		}
		else
			putchar(c);
	}
return 0;
}
