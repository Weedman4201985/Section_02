#include "FBullCowGame.h"



//Constructor
FBullCowGame::FBullCowGame()
{
	Reset();
	My_Hidden_Word = "crap";

}


//Getters
int32 FBullCowGame::GetMaxTries() const {return MyMaxTries;}

int32 FBullCowGame::GetCurrentTry() const {return MyCurrentTry;}

int32 FBullCowGame::GetWORD_LENGTH() const {return My_Hidden_Word.length();}


//Resetting the game
void FBullCowGame::Reset()
{
	constexpr  int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;
	MyCurrentTry = 1;	
	return;
	
}

//function for checking if game is won
bool FBullCowGame::bIsGameWon() const 
{
	return false;
}

//function to check for the validity of a guess
bool FBullCowGame::bCheckGuessValidity(FString)
{
	//TODO input handling. Things to check will be: correct word length, no numbers, if word is an isogram.
	//TODO message to console telling error is invalid word is entered
	return false;
}

//recieves a VALID guess, increments turn and return count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{	
	// increment the turn number
	MyCurrentTry++;
	//setup a return variable
	FBullCowCount FBullCowCount{ 0 };
	//TODO setup an error handling variable
	int32 HiddenWordLength = My_Hidden_Word.length();

	//loop through all letters in the guess and compare each letter in the guess against the hidden word
	for (int32 GChar = 0; GChar < HiddenWordLength; GChar++) 
	{
		//if guess matches the hidden word
		if (Guess == My_Hidden_Word)
		{
			//if letters in same place
			if (Guess[GChar] == My_Hidden_Word[GChar])
			{
				FBullCowCount.Bulls++; //increment bulls
			}
		}

		//if letter matches but word doesnt match
		else if (Guess[GChar] == My_Hidden_Word[GChar]) 
		{
			FBullCowCount.Bulls++; //increment bulls
		}
		else
		{
			FBullCowCount.Cows++; //increment ows
		}			
	}
	return FBullCowCount;	
}



















