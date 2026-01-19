#pragma once

#include "Quote.hpp"
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <string>
#include <utility>
class Disc_quote : public Quote {
public:
  Disc_quote(){LOG("Disc_Quote()");};
  Disc_quote(const std::string &book, double price, std::size_t qty,
             double disc)
      : Quote(book, price), quantity(qty), discount(disc) { LOG("Disc_Quote(parameter list...)");}
  Disc_quote(const Disc_quote&);
  Disc_quote(Disc_quote&&) noexcept;
  Disc_quote& operator=(const Disc_quote&);
  Disc_quote& operator=(Disc_quote&&) noexcept;

  double net_price(std::size_t) const = 0;

  std::pair<size_t, double> discount_policy() const {
    return std::make_pair(quantity, discount);
  }
 
  // 抽象类可以不实现基类的普通虚函数 直接使用基类
  // Disc_quote* clone() const & override {return new Disc_quote(*this);}
  // Disc_quote* clone() && override{return new Disc_quote(std::move(*this));}

  ~Disc_quote() { std::cout << "~Disc_quote()" << std::endl; }

protected:
  std::size_t quantity = 0;
  double discount = 0.0;
  void swap(Disc_quote &rhs) {
    using std::swap;
    Quote::swap(rhs);
    swap(quantity, rhs.quantity);
    swap(discount, rhs.discount);
  }
};

double Disc_quote::net_price(std::size_t n) const {
  std::cout << "Disc_quote::net_price()" << std::endl;
  return 0.0;
}

Disc_quote::Disc_quote(const Disc_quote& rhs):Quote(rhs),quantity(rhs.quantity),discount(rhs.discount)
{LOG("Disc_quote(const Disc_quote&)");}
Disc_quote::Disc_quote(Disc_quote&& rhs) noexcept
    :Quote(rhs),quantity(std::move(rhs.quantity)),discount(std::move(rhs.discount))
    {LOG("Disc_quote(Disc_quote&&)");}
Disc_quote& Disc_quote::operator=(const Disc_quote& rhs){
    LOG("Disc_quote& operator=(const Disc_quote&)");
    if (this != &rhs) {
        Quote::operator=(rhs);
        quantity = rhs.quantity;
        discount = rhs.discount;
    }
    return *this;
}

Disc_quote& Disc_quote::operator=(Disc_quote&& rhs) noexcept{
    LOG("Disc_quote& operator=(Disc_quote&&)");
    if (this != &rhs) {
        Quote::operator=(rhs);
        swap(rhs);
    }
    return *this;
}