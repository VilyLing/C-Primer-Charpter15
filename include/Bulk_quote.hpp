#pragma once

#include "Disc_quote.hpp"
#include "Quote.hpp"
#include <iostream>
#include <memory>
#include <string>
#include <utility>
class Bulk_quote : public Disc_quote{
    public:
    using Disc_quote::Disc_quote;
    // Bulk_quote(){LOG("Bulk_quote()");};
    // Bulk_quote(const std::string& book,double price,std::size_t qty,double disc):Disc_quote(book, price, qty, disc){
    //     LOG("Bulk_quote(parameter list...)");
    // }

    // Bulk_quote(const Bulk_quote& rhs);
    // Bulk_quote& operator=(const Bulk_quote& rhs);
    // Bulk_quote(Bulk_quote&& rhs) noexcept;
    // Bulk_quote& operator=(Bulk_quote&& rhs) noexcept;
    
    // ~Bulk_quote(){LOG("~Bulk_quote()");}
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
    
    std::shared_ptr<Quote> clone() const &  override {return std::make_shared<Bulk_quote>(*this);}
    std::shared_ptr<Quote> clone() && override { return std::make_shared<Bulk_quote>(std::move(*this));}
};

    // Bulk_quote::Bulk_quote(const Bulk_quote& rhs):Disc_quote(rhs){
    //     LOG("Bulk_quote(const Bulk_quote&)");
    // }
    // Bulk_quote& Bulk_quote::operator=(const Bulk_quote& rhs){
    //     Disc_quote::operator=(rhs);
    //     LOG("Bulk_quote operator=(const Bulk_quote&)");

    // }
    // Bulk_quote::Bulk_quote(Bulk_quote&& rhs) noexcept:Disc_quote(rhs){
    //     LOG("Bulk_quote(Bulk_quote&&)");
    // }
    // Bulk_quote& Bulk_quote::operator=(Bulk_quote&& rhs) noexcept{
    //     Disc_quote::operator=(rhs);
    //     LOG("Bulk_quote operator=(Bulk_quote&&)");

    // }