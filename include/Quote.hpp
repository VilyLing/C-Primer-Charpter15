#ifndef QUOTE_HPP
#define QUOTE_HPP

#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <utility>

#define LOG(X) std::cout << X << std::endl

class Quote {
public:
  Quote() { LOG("Quote()"); }
  Quote(const std::string &book, double sales_price)
      : bookNo(book), price(sales_price) {
    LOG("Quote(parameter list...)");
  }
  Quote(const Quote &);
  Quote(Quote &&) noexcept;
  Quote &operator=(const Quote &);
  Quote &operator=(Quote &&) noexcept;
  std::string isbn() const { return bookNo; }
  virtual double net_price(std::size_t n) const { return n * price; };
  virtual ~Quote() { std::cout << "~Quote()" << std::endl; }

  virtual std::shared_ptr<Quote> clone() const &{ return std::make_shared<Quote>(*this);}
  virtual std::shared_ptr<Quote> clone() && { return std::make_shared<Quote>(std::move(*this));}

  virtual void debug() const {
    std::cout << "bookNo: " << bookNo << " price: " << price << std::endl;
  }

private:
  std::string bookNo;

protected:
  double price = 0.0;

  void swap(Quote &rhs) {
    using std::swap;
    swap(bookNo, rhs.bookNo);
    swap(price, rhs.price);
  }
};

Quote::Quote(const Quote &rhs) : bookNo(rhs.bookNo), price(rhs.price) {
  LOG("Quote(const Quote&)");
}
Quote::Quote(Quote &&rhs) noexcept
    : bookNo(std::move(rhs.bookNo)), price(std::move(rhs.price)) {
  LOG("Quote(Quote&&)");
}
Quote &Quote::operator=(const Quote &rhs) {
  LOG("Quote& operator=(const Quote&)");
  if (this != &rhs) {
    bookNo = rhs.bookNo;
    price = rhs.price;
  }
  return *this;
}
Quote &Quote::operator=(Quote &&rhs) noexcept {
  LOG("Quote& operator=(Quote&&)");

  if (this != &rhs) {
    swap(rhs);
    rhs.bookNo = std::string();
    rhs.price = 0;
  }
  return *this;
}


double print_total(const Quote &item, std::size_t n) 
{
  double ret = item.net_price(n);
  std::cout << "ISBN: " << item.isbn() << " # sold: " << n
            << " total due: " << ret << std::endl;
  return ret;
}


#endif // QUOTE_HPP