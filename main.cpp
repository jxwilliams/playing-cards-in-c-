#include <iostream>
#include "card.h"

int main() {
    // The assignment says create five different cards on the STACK (no new / pointers).
    auto card1 = Card(Card::Value::Seven, Card::Suit::Clubs);
    auto card2 = Card(Card::Value::Six,   Card::Suit::Spades);
    auto card3 = Card(Card::Value::Ace,   Card::Suit::Hearts);
    auto card4 = Card(Card::Value::Seven, Card::Suit::Diamonds);
    auto card5 = Card(Card::Value::Two,   Card::Suit::Clubs);

    // Print each card (tests operator<<).
    std::cout << "Cards:\n";
    std::cout << "  card1: " << card1 << "\n";
    std::cout << "  card2: " << card2 << "\n";
    std::cout << "  card3: " << card3 << "\n";
    std::cout << "  card4: " << card4 << "\n";
    std::cout << "  card5: " << card5 << "\n\n";

    // Demonstrate suit equality test:
    // - same suit example: card1 (Clubs) and card5 (Clubs)
    // - different suit example: card1 (Clubs) and card2 (Spades)
    std::cout << "Suit equality tests (sameSuit):\n";
    std::cout << "  card1 and card5 same suit? " << (card1.sameSuit(card5) ? "true" : "false") << "\n";
    std::cout << "  card1 and card2 same suit? " << (card1.sameSuit(card2) ? "true" : "false") << "\n\n";

    // Demonstrate value comparison operators:
    // 1) equal value: card1 (Seven) and card4 (Seven)
    // 2) first greater than second: card3 (Ace) > card2 (Six)
    // 3) vice-versa: card5 (Two) < card2 (Six)
    std::cout << "Value comparison tests (==, <, >):\n";
    std::cout << "  card1 == card4 ? " << ((card1 == card4) ? "true" : "false") << "\n";

    std::cout << "  card3 > card2  ? " << ((card3 > card2) ? "true" : "false") << "\n";
    std::cout << "  card3 < card2  ? " << ((card3 < card2) ? "true" : "false") << "\n";

    std::cout << "  card5 > card2  ? " << ((card5 > card2) ? "true" : "false") << "\n";
    std::cout << "  card5 < card2  ? " << ((card5 < card2) ? "true" : "false") << "\n";

    return 0;
}