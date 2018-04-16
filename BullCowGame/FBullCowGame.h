#pragma once
#include <string>

using FString = std::string;
using int32 = int;


// Struct is the same as a class except all members are public while classes can have private members
struct FBullCowCount
{
	int32 Bulls{ 0 };
	int32 Cows{ 0 };
};

enum class EGuessStatus
{
	DEFAULT,
	OK,
	NOT_ISOGRAM,
	WRONG_LENGTH,
	NOT_LOWERCASE,
	

};


class FBullCowGame
{

public:
	FBullCowGame(); //constructor

	// Public method declarations
	//const means it is not modifiable

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetWORD_LENGTH() const;
	
	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FString);
	

	

	
	FBullCowCount SubmitValidGuess(FString);



	//error checking/handling(What if wrong word is typed, number inputted, to many letters, etc
	void Reset(); // TODO make more rich return value
	
//
// ^^ Please try and ignore this
private:

	//refer to constructor definintion for initialization.
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString My_Hidden_Word;
	bool bIsGameWon;
};
