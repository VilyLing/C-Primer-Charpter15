#ifndef BASE_H
#define BASE_H

#include <iostream>
namespace Base {
class Base {
public:
    void pub_mem(){
        std::cout << "Base" << std::endl;
    };
protected:
    int prot_mem;
private:
    char priv_mem;
};

struct Pub_Derv : public Base{
    friend void Pub_Derv_Use_Base(Base&,Pub_Derv&);
    int f(){return prot_mem;}
    // char g(){return priv_mem;}

    void memfcn(Base& b) {b = *this;}
};

struct Priv_Derv: private Base{
    using Base::prot_mem; // 添加权限这样派生类也能使用
    friend void Priv_Derv_Use_Base(Base&,Priv_Derv&);
    int f1() const { return prot_mem;}
    void memfcn(Base& b) {b = *this;}

};

struct Prot_Derv:protected Base{
    friend void Prot_Derv_Use_Base(Base&,Prot_Derv&);
    int f2() const {return prot_mem;}
    void memfcn(Base& b) {b = *this;}

};

struct Dervied_from_Public: public Pub_Derv{
    int use_base(){return prot_mem;}
    void memfcn(Base& b) {b = *this;}

};

struct Dervied_from_Private: private Priv_Derv{
    int use_base(){return prot_mem;}
    // void memfcn(Base& b) {b = *this;}
};

struct Dervied_from_Protected: protected Prot_Derv{
    int use_base(){return prot_mem;}
    void memfcn(Base& b) {b = *this;}
};
}


void Base::Pub_Derv_Use_Base(Base& lhs,Pub_Derv& rhs){
    lhs = rhs;
    lhs.pub_mem();
}
void Base::Priv_Derv_Use_Base(Base& lhs,Priv_Derv& rhs){
    lhs = rhs;
    lhs.pub_mem();
}

void Base::Prot_Derv_Use_Base(Base& lhs,Prot_Derv& rhs){
    lhs = rhs;
    lhs.pub_mem();
}
#endif