#pragma once 
#include <string>

class Customer{
protected:
    static int CustomerID;
    int thisCustomerID;
    std::string nameCustomer;
    std::string surnameCustomer;
    std::string addressCustomer;
    std::string passportCustomer;
public:
    ~Customer();
    Customer(const std::string& name, const std::string& surname);
    Customer(const Customer& a) : thisCustomerID(a.thisCustomerID), nameCustomer(a.nameCustomer), surnameCustomer(a.surnameCustomer), addressCustomer(a.addressCustomer), passportCustomer(a.passportCustomer) { } // copy ctor
    
    int getIDCustomer() const;
    std::string getNameCustomer() const;
    std::string getSurnameCustomer() const;
    std::string getAddressCustomer() const;
    std::string getPassportCustomer() const;
    
    void setAddressCustomer(const std::string& pass);
    void setPassportCustomer(const std::string& pass);
};