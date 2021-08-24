//
// Created by daraw on 20/04/2020.
//

#ifndef HW2_OOP_CUSTOMER_H
#define HW2_OOP_CUSTOMER_H

#include <iostream>
#include <string>
namespace OOP_Hw2{
    class Customer{
        const std::string name;// string for the name of the customer
        const int age;// the age of the customer
        const int customer_id; // the ID of the customer
    public:
        Customer(const std::string& name,const int age,const int customer_id):name(name),
                                                                              age(age),customer_id(customer_id){}// constractor
        const std::string& GetName()const;//return the name of the customer
        const int& GetId()const;//return the ID of the customer
        const int& GetAge()const;//return the age of the customer
    };
}
#endif //HW2_OOP_CUSTOMER_H
