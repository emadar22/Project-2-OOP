//
// Created by daraw on 20/04/2020.
//

#ifndef HW2_OOP_BEVERAGESTORE_H
#define HW2_OOP_BEVERAGESTORE_H

#include <iostream>
#include "DynamicArray.h"
#include "Customer.h"
#include "BookkeepingEntry.h"
#include "BeverageItem.h"

namespace OOP_Hw2 {
    class BeverageStore {
        DynamicArray<BeverageItem> beverages; // array of beverages
        DynamicArray<int> members_IDs;// array of members ID
        DynamicArray<BookkeepingEntry> requests; //array that keeps all the dealings of the store

        double clubMembersDiscountPercent;// the percent that gets the club member


    public:
        explicit BeverageStore(double clubMembersDiscountPercent = 0.0); //Default Constructor

        BeverageStore &AddClubMember(int id);// add member for the club

        BeverageStore &AddBeverage(const BeverageItem &beverage);// add beverage to the store

        bool BuyBeverage(const std::string &beverageName, const Customer &customer);// make the buying deal to the customer after checking if he can buy the item or not1

        double TotalIncome() const;// calculate the total income

        friend std::ostream& operator<<(std::ostream &outputStream, const BeverageStore &beverageStore);//print all the deals
    };
}
#endif //HW2_OOP_BEVERAGESTORE_H
