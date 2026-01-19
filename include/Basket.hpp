#ifndef BASKET_HPP
#define BASKET_HPP
#include "Quote.hpp"
#include <memory>
#include <ostream>
#include <set>
#include <utility>
#pragma once


class Basket{
    public:
        void add_item(const std::shared_ptr<Quote>& sale){ items.emplace(sale->clone());}
        void add_item(std::shared_ptr<Quote>&& sale){items.emplace(std::move(sale)->clone());}
        double total_receipt(std::ostream&) const;
    private:
        struct CompareBasket{
            bool operator()(const std::shared_ptr<Quote>& lhs, const std::shared_ptr<Quote>& rhs) const{
                return lhs->isbn() < rhs->isbn();
            }
        };

        std::multiset<std::shared_ptr<Quote>,CompareBasket> items;
};

double Basket::total_receipt(std::ostream& os) const{
    double sum = 0.0;
    for (auto iter = items.cbegin(); iter!= items.cend(); ++iter) {
        sum += print_total(**iter, items.count(*iter));
    }

    os << "Total Sale: " << sum << std::endl;
    return sum;
}
#endif