//
// Created by daraw on 20/04/2020.
//
#include "BeverageItem.h"
using namespace OOP_Hw2;
BeverageItem OOP_Hw2::BeverageItem::CreateAlcoholic(const std::string &name, double price) { // nAlcoholic item constractor
    BeverageItem beverageItem(name,price,true);//Default constructor
    return beverageItem;
}
BeverageItem OOP_Hw2::BeverageItem::CreateNonAlcoholic(const std::string &name, double price) {// nonAlcoholic item constractor
    BeverageItem beverageItem(name,price,false);//Default constructor
    return beverageItem;
}
const std::string& OOP_Hw2::BeverageItem::GetName() const {// Return the name of the item
    return this->name;
}
double OOP_Hw2::BeverageItem::GetPrice() const {// Return the price of the item
    return this->price;
}
bool OOP_Hw2::BeverageItem::IsAlcoholic() const {// Return if the item is alcoholic or not
    return this->Alcoholic;
}
void OOP_Hw2::BeverageItem::SetPrice(double newPrice) {// set a price for the item
    this->price=newPrice;
}