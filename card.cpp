#include "card.h"

#include <ostream>
#include <array>

namespace {
    // I store names in fixed arrays so printing is O(1) and simple.
    // The array order MUST match the enum order above.
    constexpr std::array<const char*, 4> SUIT_NAMES = {
        "Clubs", "Diamonds", "Hearts", "Spades"
    };

    constexpr std::array<const char*, 13> VALUE_NAMES = {
        "Two", "Three", "Four", "Five", "Six", "Seven", "Eight",
        "Nine", "Ten", "Jack", "Queen", "King", "Ace"
    };

    // Helper to safely convert an enum to an index.
    // This is “defensive”: if something ever goes out of range, I avoid undefined behavior.
    template <typename EnumT>
    constexpr std::size_t toIndex(EnumT e) noexcept {
        return static_cast<std::size_t>(e);
    }
}

Card::Card(Value v, Suit s)
    : m_suit{s}, m_value{v} // member initializer list is REQUIRED because members are const
{
    // I don't throw here because the input is enum-typed, so "invalid" is basically impossible
    // unless someone does a bad cast. The defensive checks are handled when printing.
}

bool Card::sameSuit(const Card& other) const noexcept {
    return m_suit == other.m_suit;
}

bool operator==(const Card& lhs, const Card& rhs) noexcept {
    // The assignment focuses on VALUE comparisons, so == checks value equality.
    return lhs.m_value == rhs.m_value;
}

bool operator<(const Card& lhs, const Card& rhs) noexcept {
    return toIndex(lhs.m_value) < toIndex(rhs.m_value);
}

bool operator>(const Card& lhs, const Card& rhs) noexcept {
    return toIndex(lhs.m_value) > toIndex(rhs.m_value);
}

std::ostream& operator<<(std::ostream& os, const Card& c) {
    const std::size_t v = toIndex(c.m_value);
    const std::size_t s = toIndex(c.m_suit);

    // Edge-case handling: if enums were corrupted (bad cast), I still print something safe.
    const char* valueStr = (v < VALUE_NAMES.size()) ? VALUE_NAMES[v] : "UnknownValue";
    const char* suitStr  = (s < SUIT_NAMES.size())  ? SUIT_NAMES[s]  : "UnknownSuit";

    // Required formatting: "Six of Spades"
    os << valueStr << " of " << suitStr;
    return os;
}