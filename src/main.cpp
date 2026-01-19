#include "Base.h"
#include "Bulk_quote.hpp"
#include "Disc_quote.hpp"
#include "Quote.hpp"
#include "base.h"
#include "base.hpp"
#include "derived.hpp"
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <memory>
#include <ostream>
#include <string>
#include <vector>
#include "Basket.hpp"


double print_total_use_parm(const Quote item, std::size_t n) {
  double ret = item.net_price(n);
  std::cout << "ISBN: " << item.isbn() << " # sold: " << n
            << " total due: " << ret << std::endl;
  return ret;
}


int main() {
  // Quote q ("abcd", 4.99);
  // print_total(q, 50);
  // print_total_use_parm(q, 50);
  // Bulk_quote bq("efgh", 9.99, 10, 0.15);
  // print_total(bq, 30);
  // print_total_use_parm(bq, 30);

  Bulk_quote bulk("Core Python Programming",39.99,10,0.19);
  Quote base("C++ Primer",128.0);


 
  Basket basket;

  
    basket.add_item(bulk.clone());
    basket.add_item(std::make_shared<Quote>(base));
    basket.add_item(std::make_shared<Quote>(Bulk_quote("C++ Primer",128.0,10,0.25)));
    basket.add_item(std::make_shared<Quote>(Bulk_quote("Core Python Programming",39.99,10,0.19)));

    basket.total_receipt(std::cout);
  
  std::cin.get();

  return 0;
}
