#include "Card.h"
Card::Card() {
    currCard = -1;
}
Card::Card(int card){
    currCard = card;
}

string Card::CardName(int card){
    //Checking for spade
    if (card == 1 || card == 5 || card == 9 || card == 13 || card == 17 || card == 21 || card == 25 || card == 29 || card == 33 || card == 37 || card == 41 || card == 45 || card == 49){
        suit = suits[3];
    }
    //Checking for heart
    if (card == 2 || card == 6 || card == 10 || card == 14 || card == 18 || card == 22 || card == 26 || card == 30 || card == 34 || card == 38 || card == 42 || card == 46 || card == 50){
        suit = suits[2];;
    }
    //checking for diamond
    if (card == 3 || card == 7 || card == 11 || card == 15 || card == 19 || card == 23 || card == 27 || card == 31 || card == 35 || card == 39 || card == 43 || card == 47 || card == 51){
        suit = suits[1];;
    }
    //Checking for club
    if (card == 4 || card == 8 || card == 12 || card == 16 || card == 20 || card == 24 || card == 28 || card == 32 || card == 36 || card == 40 || card == 44 || card == 48 || card == 52){
        suit = suits[0];;
    }

    //Checking for Ace
    if (card >= 1 && card <= 4){
        rank = ranks[0];
    }
    //Checking for 2
    if (card >= 5 && card <= 8){
        rank = ranks[1];
    }
    //Checking for 3
    if (card >= 9 && card <= 12){
        rank = ranks[2];
    }
    //Checking for 4
    if (card >= 13 && card <= 16){
        rank = ranks[3];
    }
    //Checking for 5
    if (card >= 17 && card <= 20){
        rank = ranks[4];
    }
    //Checking for 6
    if (card >= 21 && card <= 24){
        rank = ranks[5];
    }
    //Checking for 7
    if (card >= 25 && card <= 28){
        rank = ranks[6];
    }
    //Checking for 8
    if (card >= 29 && card <= 32){
        rank = ranks[7];
    }
    //Checking for 9
    if (card >= 33 && card <= 36){
        rank = ranks[8];
    }
    //Checking for 10
    if (card >= 37 && card <= 40){
        rank = ranks[9];
    }
    //Checking for Jack
    if (card >= 41 && card <= 44){
        rank = ranks[10];
    }
    //Checking for King
    if (card >= 45 && card <= 48){
        rank = ranks[11];
    }
    //Checking for Queen
    if (card >= 49 && card <= 52){
        rank = ranks[12];
    }

    return rank + " of " + suit;
}