//TA-BOT:MAILTO michael.makdah@marquette.edu
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 1024
#define RING_SIZE 27

int getCipherText(char*);
int decoder(char*, int, int*);
int getEs(int*,int);
int decode(char*, int);

int main(){
	char ciphertext [MAX_SIZE];
	int i;
	int freqAr[RING_SIZE] = { 0 };
	int index;

//	bzero(freqAr, RING_SIZE);	//full the frequency array with null

	getCipherText(ciphertext);	//read user input

	for(i=0; i<RING_SIZE; i++){	//run the decode method for the 27 different possible key values
		decoder(ciphertext, i, freqAr); 
	}
	
	index=getEs(freqAr,index);	//method to find key value that gives second largest amount of E's

	printf("Most probable key is %d\n", index);

	decodeKey(ciphertext, index);	//method that decodes with correct key

	printf("All done\n");
	return 0;
}

//method that reads in user input
int getCipherText(char* ciphertext){	
	int i =0;
	char next = 0;

	bzero(ciphertext, MAX_SIZE);	//fill char array with null

	while((next = getchar()) != EOF) {
		next = toupper(next);
		ciphertext[i] = next;
		i++;

		if(i>MAX_SIZE)		//if the index is out of bounds
			exit(-1);
	}

	return 0;
}

//method that decodes the encoded message and counts the number of E's and stores them into an array
int decoder(char* ciphertext, int key, int* freqAr) {	
	int i,j,n;
	int num=0;
	int previous =0;
	char alphabet[RING_SIZE] = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	for(i=0; i<MAX_SIZE; i++){
			if( ciphertext[i] != '\n' && ciphertext[i] != '\0') {		//only looks at valid characters
				for(j=0; j< RING_SIZE; j++){
					if(ciphertext[i] == alphabet[j]){
						num = j - previous - key;		//equation for decoding an encrypted message
						previous = j;
						break;
					}	
				}
				while( num < 0 ){
					num = num + RING_SIZE; }		//in case the number is negative make it wrap around positive
					
				if(alphabet[num] == 'E')		//counts the number of E's and stores them into the frequency array
					freqAr[key]++;
				}
		}
	return 0;
}

//method that returns the key value that gives the sencond largest number of E's
int getEs(int* freqAr, int index){
	int i;
	int maxE;		//maximum value
	int smaxE;		//second largest value
	
	maxE = smaxE = 0;
	index=0;

	//loop that gives the second largest value in the array
	for(i=0; i<RING_SIZE; i++){
		if(maxE < freqAr[i]) {	
 			
				smaxE = maxE;
				maxE = freqAr[i];	
		}
		else if(smaxE<freqAr[i] && freqAr[i] != maxE)
		{
			smaxE = freqAr[i];
		}	
	}

	//loop that finds the corresponding index value given second largest value
	for(i=0; i<RING_SIZE; i++) {
		if(freqAr[i] == smaxE){
			index=i;
			break;	
			}		
	}
return index;
}

//same as the decode ring form the last homework assignment, decodes given a phrase and key value
int decodeKey(char* ciphertext, int key) {
	int i,j,n;
        int num=0;
        int previous =0;
        char alphabet[RING_SIZE] = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";

        for(i=0; i<MAX_SIZE; i++){
                        if( ciphertext[i] != '\n' && ciphertext[i] != '\0') {
                                for(j=0; j< RING_SIZE; j++){
                                        if(ciphertext[i] == alphabet[j]){
                                                num = j - previous - key;
                                                previous = j;
                                                break;
                                }
                        }
                while( num < 0 ){
                        num = num + RING_SIZE; }

                putchar(alphabet[num]);
                }

                else
                        putchar(ciphertext[i]);
                }

              return 0;
        }

