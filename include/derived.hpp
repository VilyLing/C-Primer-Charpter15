#ifndef DERIVED_HPP
#define DERIVED_HPP

#include "base.hpp"
#include <iostream>
#include <ostream>
#include <string>

class derived : public base {  
public:
    derived(std::string s, int n) : base(s), mem(n) {}
    
    int getMem() const { return mem; }
    
    void print(std::ostream& os = std::cout) const override {
        base::print(os); 
        os << " " << mem; 
    }
    
    ~derived() override = default;
    
private:
    int mem;
};

#endif // DERIVED_HPP