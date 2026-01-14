#pragma once

#include "Quote.hpp"
#include <cstddef>
#include <iostream>
#include <string>
#include <utility>
class Disc_quote:public Quote{
    public:
        Disc_quote() = default;
        Disc_quote(const std::string& book,double price,std::size_t qty, double disc)
                    :Quote(book, price),quantity(qty),discount(disc){}

        double net_price(std::size_t) const = 0;

        std::pair<size_t, double> discount_policy() const {
            return std::make_pair(quantity, discount);
        }
    protected:
        std::size_t quantity = 0;
        double discount = 0.0;
};

double Disc_quote::net_price(std::size_t n) const {
    std::cout << "Disc_quote::net_price()" << std::endl;
    return 0.0;
}