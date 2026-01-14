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


double print_total(const Quote &item, std::size_t n) {
  double ret = item.net_price(n);
  std::cout << "ISBN: " << item.isbn() << " # sold: " << n
            << " total due: " << ret << std::endl;
  return ret;
}

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

  Base::Base b;
  Base::Pub_Derv pub;
  Base::Priv_Derv priv;
  Base::Prot_Derv prot;

  pub.memfcn(b);
  priv.memfcn(b);
  prot.memfcn(b);
  // Base::Pub_Derv_Use_Base(b, pub);
  // Base::Priv_Derv_Use_Base(b, priv);
  // Base::Prot_Derv_Use_Base(b, prot);

  std::cout <<"Test" << std::endl;
  std::cin.get();
  return 0;
}
