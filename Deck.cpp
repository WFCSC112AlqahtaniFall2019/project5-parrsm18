#include "Deck.h"
#include "Card.h"
#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

Deck::Deck() {
    cards = new Card[52];
    arraySize = 52;
    cardsLeft = 0;
}

Deck::~Deck() {
    delete[] cards;
}

//Copy Constructor
Deck::Deck(const Deck& deckClass) {
    cout << "Copy constructor called." << endl;
    //cards = new Card; // Allocate sub-object
    //*cards = *(deckClass.cards);

    cards = new Card;
    *cards = *(deckClass.cards);
    arraySize = deckClass.arraySize;
    cardsLeft = deckClass.cardsLeft;
}

//Copy Assignment Operator
Deck& Deck::operator=(const Deck& deckToCopy) {
    Deck temp(deckToCopy); // copy constructor temp
    swap(cards, temp.cards); //built-in swap

    return *this;
}

void Deck::PopulateDeck() {
    for (int i=0; i < 4; i++){
        for (int j=0; j < 13; j++){

            AddCard(Card(j,i));
        }
    }
}

bool Deck::AddCard(Card newCard){
    if (cardsLeft < arraySize) {
        cards[++cardsLeft] = newCard;
    }
}

Card Deck::RemoveCard() {
    return cards[--cardsLeft];
}

void Deck::Shuffle() {
    srand(time(0));
    for(int i = 0; i < pow(cardsLeft,2); i++){
        swap(cards[rand() % 52], cards[rand() % 52]);
    }
}

int Deck::getCardsLeft(){
    return cardsLeft;
}