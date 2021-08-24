//
// Created by daraw on 20/04/2020.
//
#include "BeverageStore.h"
using namespace std;
using  namespace OOP_Hw2;
OOP_Hw2::BeverageStore::BeverageStore(double clubMembersDiscountPercent) {// construct for the store
    beverages=DynamicArray<BeverageItem>();
    members_IDs=(DynamicArray<int>());
    requests=(DynamicArray<BookkeepingEntry>());
    this->clubMembersDiscountPercent=clubMembersDiscountPercent;
}
BeverageStore& OOP_Hw2::BeverageStore::AddBeverage(const BeverageItem &beverage) {// adding beverage to the store
    this->beverages+=beverage;
    return *this;
}
BeverageStore& OOP_Hw2::BeverageStore::AddClubMember(int id) {// adding a member to the club members
    this->members_IDs+=id;
    return *this;
}
bool OOP_Hw2::BeverageStore::BuyBeverage(const std::string &beverageName, const OOP_Hw2::Customer &customer) {// making a deal
    int item_index=-1;
    double priceToPay=0.0;
    bool requestAccepted=true;
    for(int i=0; i<beverages.size();i++)// searching for the beverage
    {

        if(beverages[i].GetName()==beverageName)
        {
            item_index=i;
            priceToPay=beverages[item_index].GetPrice();
        }

    }
    if(item_index==-1||(customer.GetAge()<18&&beverages[item_index].IsAlcoholic()))// check if the item in the store and if the customer can buy it
    {
        requestAccepted=false;
        priceToPay=0;
    }
    if(requestAccepted){// if the request Accepted calculating the price
        for(int j =0; j<members_IDs.size();j++)
        {
            if (customer.GetId() == members_IDs[j]) {
                priceToPay=priceToPay*((100.0-clubMembersDiscountPercent)/100.0);
            }

        }
    }
    requests+=BookkeepingEntry(customer.GetName(),beverageName,priceToPay,requestAccepted);// saving the deal
    return requestAccepted;
}
double OOP_Hw2::BeverageStore::TotalIncome() const {// calculating the incomes
    double sum=0.0;
    for(int i=0 ; i < requests.size();i++)
    {
        sum+=requests[i].GetPrice();

    }
    return sum;
}
namespace OOP_Hw2 {
    ostream&  operator<<(ostream &outputStream, const BeverageStore &beverageStore) { // printing all the deals
        for (int i = 0; i < beverageStore.requests.size(); i++) {

            outputStream << i + 1 << ") ";
            outputStream << (beverageStore.requests[i]);

        }
        return outputStream;

    };
}