#include <stdio.h>
#include <stdlib.h>
#include <math.h>// log() and ceil()


int main(void){
	
	//Declare variables
	int lowRange = 1;
	int highRange = 100;
	int possibleGuesses = highRange + lowRange - 1; //Range of possible guesses or numbers left
	int maxTurns = ceil(log(possibleGuesses) / log(2) ); // log base 2 of possible guesses rounded up
	int guess; // The number that the computer guesses
	int player; //(1) yes, you guessed my number, (2) No, guess a lower number, (3) No, guess a higher number
	int numTurns = 1; //Keep track of the number of turns/guesses
	
	printf("Think of a number from %d to %d, I can guess your number within %d turns \n", lowRange, highRange, maxTurns);
	
	//Do a divide and conquer algorithm
	//The actual guessing game
	do{
		//create or update the new range or possible number of guesses
		possibleGuesses = highRange + lowRange - 1;
		guess = (int)ceil(possibleGuesses / 2.0);
		
		printf("Is your number %d ? \n", guess);
		printf("(1) yes, you guessed my number \n");
		printf("(2) No, guess a lower number \n");
		printf("(3) No, guess a higher number \n");
		scanf("%d", &player);// Get the players feed back
		
		
		if(player == 3)
		  lowRange = guess + 1;//Update the new low range
		else if(player == 2)
		  highRange = guess - 1; //update the new high range
		else if(player == 1)
		  break; //break out of the loop, because we guessed the players number
		
		numTurns++; //Increment the number of turns
		
	}while(player != 1 && numTurns <= maxTurns);
	
	//Print the results
	if(numTurns > maxTurns)
	   printf("You made a mistake, you've exceeded the maximum number of turns \n");
	else
	   printf("I guessed your number in %d turns! \n", numTurns);
	
}
