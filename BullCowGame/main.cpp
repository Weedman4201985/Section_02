/*A Console game called Bulls and Cows. 
A Console project from UDEMY course on Unreal.

The program picks an isogram of a certain length and asks the user to guess the word.

the program checks the word enterd against the word chosen.
The program gives a bull for each letter correct and a cow for each letter correct but not in the right place

the program must check for correct word length, correct number of words entered,
if word is not a word, if word is not an isogram, etc

the user gets 10 guesses

if all guesses have been reached then game over
*/

/*  This is the console exe that makes use of the BullCow class. 
	This acts as the view in a MVC pattern and is responsible for all user interaction.
	For game logic see the FBullCowGame class.
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

//Prototyping functions
void PrintIntro();
void PlayGame();
FText GetGuess();
void PrintGuess(FText Guess);
void PrintBullCowCount(int32 Bulls, int32 Cows);

bool AskToPlayAgain();


FBullCowGame BCGame; // instantiate a new game


//Main method
int main()
{
	bool bPlayAgain{ false };
	do
	{
		BCGame.Reset();
		
		PrintIntro();
		PlayGame();

		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);

	return 0;
	
}


void PlayGame()
{
	const int32 MaxTries = BCGame.GetMaxTries();
	//for loop for looping through NUM_OF_TRIES
	//TODO change from for to while loop once we are validating tries
	for (int32 i = 1; i <= MaxTries; i++) {
		FText Guess = GetGuess(); // TODO make loop check for valid guess

		// submit valid guess to the game
		FBullCowCount  BullCowCount = BCGame.SubmitGuess(Guess);

		//print guess and number of bulls and cows
		PrintGuess(Guess);
		int32 Bulls{ BullCowCount.Bulls };
		int32 Cows{ BullCowCount.Cows };
		PrintBullCowCount(Bulls,Cows);
	}
		
}

//Game intro
void PrintIntro()
{
	
	std::cout << "Welcome to Bulls and Cows\n";
	std::cout << "Can you guess the " << BCGame.GetWORD_LENGTH();
	std::cout << " letter isogram I'm thinking of within ";
	int32 MaxTries = BCGame.GetMaxTries();
	std::cout << MaxTries;
	std::cout << " Tries? \n" << std::endl;
	return;
}

//Get guess from console
FText GetGuess()
{
	
	const int32 MaxTries = BCGame.GetMaxTries();
	int32 CurrentTry = BCGame.GetCurrentTry();
	FText Guess = "";

	std::cout << "Try " << CurrentTry << " of " << MaxTries << ".Your Guess: ";
	
	std::getline(std::cin, Guess);
	
	return Guess;
}



//print guess to console
void PrintGuess(FText Guess)
{	
	std::cout << "\nPlayer entered: " << Guess << "\n" << std::endl;
	return;
}

//print bulls and cows to console
void PrintBullCowCount(int32 Bulls,int32 Cows)
{
	std::cout << "Bulls: " << Bulls << " Cows: " << Cows << "\n" << std::endl;
	return;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (Y/N)";
	FText Response;
	std::getline(std::cin, Response);

	/* TODO Refine if statement for better input handling. Things to check will be make sure correct letter has been selected(Y/N), make sure no int was entered,etc
	   Advise user to enter letter(Y/N) again if incorrect, repeat until correct letter is entered.
	*/
	if (Response[0] == 'y' || Response[0] == 'Y') 

	{
		std::cout << std::flush;
		system("CLS");
		return true;
	}
	else
		std::cout << "Goodbye \n";
		return false;

}
