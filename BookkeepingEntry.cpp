//
// Created by daraw on 20/04/2020.
//

#include "BookkeepingEntry.h"
using namespace OOP_Hw2;

double BookkeepingEntry::GetPrice() const {// return the price of the deal
    return this->price;
}
const std::string& BookkeepingEntry::GetName() const {// return the name of the customer
    return this->name;
}
const std::string& BookkeepingEntry::GetItem() const {// return the beverage name
    return this->item;
}
bool BookkeepingEntry::IsAccepted() const {// return if the deal was accepted
    return this->is_Accepted;
}
namespace OOP_Hw2 {// print the deal
    std::ostream &operator<<(std::ostream &outStream, const BookkeepingEntry &request) {
        if (request.IsAccepted()) {
            outStream << request.GetName() << " bought" << " '" << request.GetItem() << "' " << "with "
                      << request.GetPrice() << " shekels" << std::endl;
            return outStream;
        } else {
            outStream << request.GetName() << " request for buying" << " '" << request.GetItem() << "' " << "was rejected"
                      << std::endl;
            return outStream;
        }
    }
}

