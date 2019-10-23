#include "Deck.h"
#include "Card.h"
#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

Deck::Deck() { //Constructor
    cards = new Card[52];
    arraySize = 52;
    cardsLeft = 0;
}

//Destructor
Deck::~Deck() {
    cout << "Destructor called" << endl;
    delete[] cards;
}

//Copy Constructor
Deck::Deck(const Deck& deckClass) {
    cout << "Copy constructor called." << endl;
    arraySize = deckClass.arraySize;
    cardsLeft = deckClass.cardsLeft;
    cards = new Card[arraySize];
    for (int i = 0; i < arraySize; i++){
        cards[i] = deckClass.cards[i];
    }
}

//Copy Assignment Operator
Deck &Deck::operator=(Deck deckToCopy) {// copy constructor temp
    cout << "Copy assignment operator called" << endl;
    swap(cards, deckToCopy.cards); //built-in swap
    arraySize = deckToCopy.arraySize;
    cardsLeft = deckToCopy.cardsLeft;
    return *this;
}

void Deck::PopulateDeck() { //Populates deck with 52 cards using nested for loops. One for loop for suit and the other for rank
    for (int i=0; i < 4; i++){
        for (int j=0; j < 13; j++){
            AddCard(Card(j,i));
        }
    }
}

bool Deck::AddCard(Card newCard){ //Adds new card to the deck
    if (cardsLeft == 52){ //Ensures that new card will not be added to deck with 52 cards
        return false;
    }
    if (cardsLeft < arraySize) {
        cards[++cardsLeft] = newCard;
    }
}

Card Deck::RemoveCard() { //Removes a card from the deck
    return cards[--cardsLeft];
}

void Deck::Shuffle() { //Shuffles the deck by swapping two cards cardsLeft^2 times
    srand(time(0));
    for(int i = 0; i < pow(cardsLeft,2); i++){
        swap(cards[rand() % 52], cards[rand() % 52]);
    }
}

int Deck::getCardsLeft(){ //Returns the number of cards remaining the deck
    return cardsLeft;
}