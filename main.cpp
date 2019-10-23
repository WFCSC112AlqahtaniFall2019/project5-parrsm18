#include <iostream>
#include <string>
#include <ctime>
#include <cctype>
#include "Card.h"
#include "Deck.h"
using namespace std;

int main() {

    Deck newgame; //Creates a new deck
    Deck discard; //Creates a new deck to be filled with the discard pile
    newgame.PopulateDeck(); //Populates the deck with 52 Cards
    newgame.Shuffle(); //Shuffles deck

    //Creates two card objects to be compared throughout the game
    Card user;
    Card computer;

    cout << "Welcome to Blind Man's Bluff" << endl << endl;
    bool play, invalid, guessedHigher;
    string response;
    int compValue, userValue, nWin = 0, nLoss = 0, nTie = 0;
    srand(time(NULL));


    play = true;
    while (play) {
        //Removes the user's card and computer's card from top of deck and adds them to the discard deck
        user = newgame.RemoveCard();
        computer = newgame.RemoveCard();
        discard.AddCard(user);
        discard.AddCard(computer);

        // get user's bet
        cout << "Computer's value is " << computer.CardName() << endl;
        invalid = true;
        while (invalid) {
            cout << "Do you think your number is higher or lower? (H/L)" << endl;
            cin >> response;
            if (toupper(response.at(0)) == 'H') {
                // continue playing
                guessedHigher = true;
                invalid = false;
            } else if (toupper(response.at(0)) == 'L') {
                // break out of while(play) loop
                guessedHigher = false;
                invalid = false;
            } else {
                // invalid response, ask again
                cout << "Invalid response..." << endl;
                invalid = true;
            }
        }

        // determine outcome
        if ((user > computer && guessedHigher) || (computer > user && !guessedHigher)) {
            cout << "Great! You're right:" << endl;
            nWin++;
        } else if ((computer > user && guessedHigher) || (user > computer && !guessedHigher)) {
            cout << "Sorry, you're wrong:" << endl;
            nLoss++;
        } else {
            cout << "It's a tie:" << endl;
            nTie++;
        }
        cout << "\tyour value is " << user.CardName() << endl;

        //Testing Discard Object
        //cout << "Cards in discard pile: " << discard.getCardsLeft() << endl;


        // ask user to play again
        invalid = true;
        while (invalid) {
            cout << "Play again? (Y/N)" << endl;
            cin >> response;
            if (toupper(response.at(0)) == 'Y') {
                // continue playing
                play = true;
                invalid = false;
            } else if (toupper(response.at(0)) == 'N') {
                // break out of while(play) loop
                play = false;
                invalid = false;
            } else {
                // invalid response, ask again
                cout << "Invalid response..." << endl;
                invalid = true;
            }
        }
        /*if ((nWin+nLoss+nTie) == 26){
            break;
        }*/
        if (newgame.getCardsLeft() == 0) {
            cout << "No cards left in deck!" << endl;
            cout << "Thanks for playing!" << endl;
            cout << "Your record was " << nWin << "-" << nLoss << "-" << nTie << " (W-L-T)" << endl;
            return 0;
        }
    }
    
    // output stats
    cout << "Thanks for playing!" << endl;
    cout << "Your record was " << nWin << "-" << nLoss << "-" << nTie << " (W-L-T)" << endl;

    return 0;
}
