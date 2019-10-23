#include "Card.h"
Card::Card() {
    suit = 0;
    rank = 0;
}
Card::Card(int rank, int suit){
    this->suit = suit;
    this->rank = rank;
}

bool Card::operator> (Card user){
    if (rank == user.rank){
        return suit > user.suit;
    }
    else{
        return rank > user.rank;
    }
}

string Card::CardName(){
    return ranks[rank] + " of " + suits[suit];
}