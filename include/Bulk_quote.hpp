#pragma once

#include "Disc_quote.hpp"
#include "Quote.hpp"
#include <iostream>
#include <string>
class Bulk_quote : public Disc_quote{
    public:
    Bulk_quote() = default;
    Bulk_quote(const std::string& book,double price,std::size_t qty,double disc):Disc_quote(book, price, qty, disc){}
    //price 是 基类的 protected 成员 可以直接访问
    double net_price(std::size_t n) const override{
        if (n > quantity) {
            return  n * (1 - discount) * price;
        } else {
            return price * n;
        }
    }
    void debug() const override {
        std::cout << "min_qty: " << quantity 
                  << " discount: " << discount
                  << std::endl;
    }
};