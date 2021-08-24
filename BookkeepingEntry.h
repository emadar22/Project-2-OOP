//
// Created by daraw on 20/04/2020.
//

#ifndef HW2_OOP_BOOKKEEPINGENTRY_H
#define HW2_OOP_BOOKKEEPINGENTRY_H

#include <string>
#include <iostream>
namespace OOP_Hw2{
    class BookkeepingEntry{
        const std::string name;// string of the name of the customer
        const std::string item;// string for the name of the beverage
        double price;// the price the custumer should pay
        bool is_Accepted;// boolean if the request was accepted or not

    public:
        BookkeepingEntry(const std::string& name,const std::string& item,double price,bool is_Accepted):name(name),
                                                                                                        item(item),price(price),is_Accepted(is_Accepted){}// constractor
        const std::string& GetName()const;// return the name of the customer
        const std::string& GetItem()const;// return the beverage
        double GetPrice()const; // return the price of the deal
        bool IsAccepted()const; // return if the deal was accepted
        friend std::ostream& operator<<(std::ostream& outStream,const BookkeepingEntry& request) ; // print the deal
    };

}
#endif //HW2_OOP_BOOKKEEPINGENTRY_H
