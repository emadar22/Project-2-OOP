//
// Created by daraw on 20/04/2020.
//

#ifndef HW2_OOP_BEVERAGEITEM_H
#define HW2_OOP_BEVERAGEITEM_H

#include <iostream>
#include <string>
namespace OOP_Hw2 {
    class BeverageItem {
        std::string name; // string of the name of the item
        double price; // the price of the item
        bool Alcoholic; // boolean 1/0 if the item is alcoholic or not

        BeverageItem(const std::string &name, double price, bool IsAlcoholic):name(name),price(price),Alcoholic(IsAlcoholic){}//default

    public:
        static BeverageItem CreateAlcoholic(const std::string &name, double price);// Alcoholic item constractor

        static BeverageItem CreateNonAlcoholic(const std::string &name, double price);// nonAlcoholic item constractor
        const std::string& GetName()const;// Return the name of the item
        double GetPrice()const; // Return the price of the item
        bool IsAlcoholic()const;// Return if the item is alcoholic or not
        void SetPrice(double newPrice);// set a price for the item
    };
}
#endif //HW2_OOP_BEVERAGEITEM_H
