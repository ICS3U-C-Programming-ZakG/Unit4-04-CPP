// Copyright (c) 2023 Zak Goneau All rights reserved.
//
// Created by: Zak Goneau
// Date Created: Nov. 15, 2023
// This program generates a random number from 0-9 and the
// user must guess it. It uses while true loops and a break statement.

#include <cstdlib>
#include <iostream>
#include <string>

int main() {
    // introduce program to user
    std::cout << "This program gets a number from the user and will ";
    std::cout << "tell them the factorial of it.\n";

    // declare variables
    int correctGuess;
    int userGuessInt;
    float userGuessFloat;
    std::string userGuessStr;

    // Providing a seed value
    srand((unsigned)time(NULL));

    // Generate random number
    correctGuess = rand() % 10;

    do {
        // get user input
        std::cout << "Please enter a positive integer: ";
        std::cin >> userGuessStr;

        try {
            // try converting string input to integer
            userGuessInt = std::stoi(userGuessStr);

            // cast user input string to a float
            userGuessFloat = std::stof(userGuessStr);

            // check if casted integer and float are not the same
            if (userGuessInt != userGuessFloat) {

                // tell user they cannot enter a decimal
                std::cout << "" << userGuessFloat << " is not an integer\n";

                // check if user input is a negative
            } else if (userGuessInt < 0) {

                // tell user if they inputted negative number
                std::cout << "" << userGuessInt << " is an invalid input ";
                std::cout << "it must be a positive integer\n ";

                // check if user guess equals correct guess
            } else if (userGuessInt == correctGuess) {
                std::cout << "You guessed correctly!\n";

                // if correct break out of loop
                break;

            // if incorrect guess tell user then loop again
            } else {
                std::cout << "" << userGuessInt << " is not the correct";
                std::cout << " guess, please try again!\n" << std::endl;
            }

            // catch invalid inputs
            } catch (std::invalid_argument) {
                std::cout << "" << userGuessStr;
                std::cout << " is not a positive integer.\n";
            }

    // loop as long as users guess does not equal the correct guess
    } while (userGuessInt != correctGuess);
}
