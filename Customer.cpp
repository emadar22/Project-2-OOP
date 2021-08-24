//
// Created by daraw on 20/04/2020.
//

#include "Customer.h"
using namespace OOP_Hw2;
const std::string& Customer::GetName() const {//return the name of the customer
    return  this->name;
}
const int& Customer::GetAge() const {//return the age of the customer
    return this->age;
}
const int& Customer::GetId() const {//return the ID of the customer
    return this->customer_id;
}