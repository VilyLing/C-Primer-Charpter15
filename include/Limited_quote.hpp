#ifndef LIMITED_QUOTE_HPP
#define LIMITED_QUOTE_HPP

#include "Disc_quote.hpp"
#include "Quote.hpp"
#include <cstddef>
#include <string>
class Limited_quote : public Disc_quote{
    public:
        Limited_quote(const std::string& book, double price, std::size_t n, double dis):Disc_quote(book, price,n,dis){}

        double net_price(std::size_t n) const override{
            if (n > quantity) {
                return quantity * (1 - discount) * price + (n - quantity) * price;;
            }else {
                return n * (1 - discount) * price;
            }
        }

};

#endif// LIMITED_QUOTE_HPP