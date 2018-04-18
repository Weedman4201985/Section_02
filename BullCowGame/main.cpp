/*A Console game called Bulls and Cows. 
A Console project from UDEMY course on Unreal.

The program picks an isogram of a certain length and asks the user to guess the word.

the program checks the word enterd against the word chosen.
The program gives a bull for each letter correct and a cow for each letter correct but not in the right place

the program must check for correct word length, correct number of words entered,
if word is not a word, if word is not an isogram, etc

the user gets 10 guesses

if all guesses have been reached then game over

 An isogram (also known as a "nonpattern word") is a word
or phrase without a repeating letter.

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
FText GetValidGuess();
void PrintGuess(FText Guess);
void PrintBullCowCount(int32 Bulls, int32 Cows);
void PrintGameSummary();

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
		PrintGameSummary();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);

	return 0;
	
}


void PlayGame()
{
	const int32 MaxTries = BCGame.GetMaxTries();
	
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries) {
		FText Guess = GetValidGuess(); 								   
		// submit valid guess to the game
		FBullCowCount  BullCowCount = BCGame.SubmitValidGuess(Guess);
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
FText GetValidGuess() 
{	
	FText Guess = "";
	EGuessStatus GuessStatus = EGuessStatus::DEFAULT;
	do
	{
		const int32 MaxTries = BCGame.GetMaxTries();
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << CurrentTry << " of " << MaxTries << ".Your Guess: ";

		std::getline(std::cin, Guess);
		//check validity of guess
		GuessStatus = BCGame.CheckGuessValidity(Guess);

		switch (GuessStatus)
		{
		case EGuessStatus::DEFAULT:
			GuessStatus = BCGame.CheckGuessValidity(Guess);
			break;
		case EGuessStatus::WRONG_LENGTH:
			std::cout << "Please enter a " << BCGame.GetWORD_LENGTH() << " letter word.\n";
			break;
		case EGuessStatus::NOT_ISOGRAM:
			std::cout << "The word entered was not an isogram. Please enter ";
			std::cout << "a word without a repeating letter.\n";
			break;
		case EGuessStatus::NOT_LOWERCASE:
			std::cout << "The word entered was not lowercase. Please enter ";
			std::cout << "all lowercase letters.\n";
			break;
		case EGuessStatus::OK:
			return Guess;
			break;
		default:
			break;			
		}
		std::cout << std::endl;
	} while (GuessStatus != EGuessStatus::OK); // keep looping until a vaild guess
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

//game summary
void PrintGameSummary()
{

	if (BCGame.IsGameWon())
	{
		std::cout << "You Win!!!! \n" << std::endl;
	}
	else
	{
		std::cout << "Sorry You Lose!!!!! \n" << std::endl;
	}
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (Y/N)";
	FText Response;
	std::getline(std::cin, Response);

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
