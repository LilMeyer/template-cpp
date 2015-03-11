#ifndef MONEY_H
#define MONEY_H

#include <string>

class Money {
public:
  Money(): m_amount(0), m_currency("EURO") {}
  Money(double amount, std::string currency)
    : m_amount(amount), m_currency(currency) {}

  double getAmount() const {
    return m_amount;
  }

  std::string getCurrency() const {
    return m_currency;
  }

  void helloPrint();
  void afficher() const;

private:
  double m_amount;
  std::string m_currency;
};

#endif
