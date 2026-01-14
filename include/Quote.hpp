#ifndef QUOTE_HPP
#define QUOTE_HPP

#include <iostream>
#include <string>
class Quote {
public:
  Quote() = default;
  Quote(const std::string &book, double sales_price):bookNo(book), price(sales_price){}

  Quote(const Quote&) = default;
  Quote(Quote&&) noexcept = default;
  Quote& operator=(const Quote&) = default;
  Quote& operator=(Quote&&) noexcept = default;

  std::string isbn() const { return bookNo;}
  virtual double net_price(std::size_t n) const { return n * price; };
  virtual ~Quote() = default;

  virtual void debug() const {std::cout << "bookNo: " << bookNo 
                                        << " price: " << price 
                                        << std::endl;}
private:
    std::string bookNo;
protected:
  double price = 0.0;
};

#endif // QUOTE_HPP