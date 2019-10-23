#ifndef BLINDMANSBLUFF_DECK_H
#define BLINDMANSBLUFF_DECK_H

#include "Card.h"


class Deck {
public:
    Deck();
    ~Deck();
    Deck(const Deck& deckClass);
    Deck& operator=(const Deck& deckToCopy);
    void PopulateDeck();
    bool AddCard(Card newCard);
    Card RemoveCard();
    void Shuffle();
    int getCardsLeft();


private:
    Card* cards;
    int arraySize;
    int cardsLeft;
};


#endif //BLINDMANSBLUFF_DECK_H
