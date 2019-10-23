#include "Card.h"
Card::Card() { //Default constructor
    suit = 0;
    rank = 0;
}
Card::Card(int rank, int suit){ //Alternate constructor
    this->suit = suit;
    this->rank = rank;
}

bool Card::operator> (Card user){
    if (rank == user.rank){ //if ranks are equal then suits will be compared to determine winner
        return suit > user.suit;
    }
    else{ //if suits are equal then ranks will be compared to determine winner
        return rank > user.rank;
    }
}

string Card::CardName(){ //Returns card name in for "Jack of Hearts"
    return ranks[rank] + " of " + suits[suit];
}