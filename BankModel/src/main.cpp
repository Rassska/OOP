#include <iostream>
#include "Functionality.h"
#include "Builder.h"
#include "CustomerBuilder.h"
#include "Customer.h"



int main() {
    try{
        Functionality func;
        func.addBank("Bank of America", 5000, 3000, 0.04, 0.02); // name // CredLimit // suspLim // proc // comm
        
        Builder* build = new CustomerBuilder();
        build->setCustomer("Sergey", "Kozlov");
        build->setAddress("The main street");
        
        Customer* cli = build->getCustomer(); 
        func.addCustomer("Bank of America", cli);

        func.addAccount("Bank of America", 1, "debit"); // client ID - 1; account ID - 1
        func.putMoney("Bank of America", 1);
        func.addAccount("Bank of America", 1, "deposit"); // client ID - 1; account ID - 2
        func.addAccount("Bank of America", 1, "credit"); // client ID - 1; account ID - 2
        func.takeMoney("Bank of America", 1); // ограничение кредита within susp
        func.takeMoney("Bank of America", 1);

        // build->setPassport("00001111");
    
         Builder* build2 = new CustomerBuilder();
        build2->setCustomer("Niko", "Kovach");
        build2->setAddress("The main street 25B");
        Customer* cli2 = build2->getCustomer(); // client ID - 2
        func.addCustomer("Bank of America", cli2);

        func.addAccount("Bank of America", 2, "credit"); // client ID - 2; account ID - 1
        func.addAccount("Bank of America", 2, "debit"); // client ID - 2; account ID - 2 
        func.putMoney("Bank of America", 2); // put to debit

        build2->setPassport("00002222");
//        func.takeMoney("Banca Intesa", 2);
        func.cancelOperation("Bank of America", 1);
//        func.takeMoney("Banca Intesa", 2);
//        func.putMoney("Banca Intesa" , 2);
        
        func.print();
    } catch (std::runtime_error& error){
        std::cout << "\nRuntime error occurred...\n" << error.what() << "\n";
    }
    
    
    return 0;
}
