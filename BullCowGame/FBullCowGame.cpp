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

bool FBullCowGame::IsGameWon() const { return bIsGameWon; }



//Resetting the game
void FBullCowGame::Reset()
{
	constexpr  int32 MAX_TRIES = 3;
	MyMaxTries = MAX_TRIES;
	MyCurrentTry = 1;
	bIsGameWon = false;
	
	return;
	
}

//function to check for the validity of a guess
EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess)
{
	if (false) { return EGuessStatus::NOT_ISOGRAM; }  //if guess is not isogram
		
	else if (false) { return EGuessStatus::NOT_LOWERCASE; }  //if guess all lower case
		
	else if (GetWORD_LENGTH() != Guess.length()) { return EGuessStatus::WRONG_LENGTH; }  //if guess not correct length
		
	else {return EGuessStatus::OK;}
}

//recieves a VALID guess, increments turn and return count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	FBullCowCount FBullCowCount{ 0 };
	int32 WordLength = My_Hidden_Word.length(); // assuming same length of guess
	
	//loop through all letters in the hidden word
	for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++)
	{
		// compare letters against the guess
		for (int32 GChar = 0; GChar < WordLength; GChar++)
		{			
			// if they match then
			if (Guess[GChar] == My_Hidden_Word[MHWChar])
			{  
				// if they're in the same place
				if (MHWChar == GChar) { FBullCowCount.Bulls++;} else { FBullCowCount.Cows++; }
				//if bulls reach length of hidden word, game is won
				if (FBullCowCount.Bulls == Guess.length()) { bIsGameWon = true; }
				//if current tries are greater than maximun tries then game is lost
				
			}
			
		}
	}	
	MyCurrentTry++;	
	return FBullCowCount;
}