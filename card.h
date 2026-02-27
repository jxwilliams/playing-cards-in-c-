#ifndef CARD_H
#define CARD_H

#include <iosfwd> // faster compile than including iostream

class Card {
public:
    // I keep these enums public because the assignment says the user of the class needs access.
    enum class Suit {
        Clubs,
        Diamonds,
        Hearts,
        Spades
    };

    // I list these in increasing order because the assignment says Two Ace.
    enum class Value {
        Two,
        Three,
        Four,
        Five,
        Six,
        Seven,
        Eight,
        Nine,
        Ten,
        Jack,
        Queen,
        King,
        Ace
    };

    // Constructor signature matches the assignment example style: Card Value v, Suit s
    Card(Value v, Suit s);

    // I use this to test suit equality the assignment wants a method that takes the other card only.
    bool sameSuit(const Card& other) const noexcept;

    // These getters are not required, but they help with debugging/testing without breaking const.
    Suit suit() const noexcept { return m_suit; }
    Value value() const noexcept { return m_value; }

    // Friend operators (required by assignment.
    friend bool operator==(const Card& lhs, const Card& rhs) noexcept;
    friend bool operator<(const Card& lhs, const Card& rhs) noexcept;
    friend bool operator>(const Card& lhs, const Card& rhs) noexcept;

    friend std::ostream& operator<<(std::ostream& os, const Card& c);

private:
    // The assignment says suit/value should not change for the lifetime of the object -> const members.
    const Suit  m_suit;
    const Value m_value;
};

#endif