#ifndef BASE_HPP
#define  BASE_HPP
#include <iostream>
#include <ostream>
#include <string>
class base{
    std::string basename;
    public:
    base(std::string s = ""):basename(s){}
    std::string name() const {return basename;}
    virtual void print(std::ostream& os = std::cout) const {
        os << this->name();
    }
    virtual ~base() = default;
};


#endif