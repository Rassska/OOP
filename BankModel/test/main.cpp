//
//  main.cpp
//  Banks
//
//  Created by Sara Nikolić on 06.12.2020.
//

#include <iostream>
#include "Banks.hpp"

int main() {
    try{
        SystemUtility su;
        su.addBank("Banca Intesa", 5000, 3000, 0.04, 0.02); // bank id
        
        Builder* build = new ClientBuilder();
        build->setClient("Sherlock", "Holmes");
        build->setAddress("Baker Street 221B");
        Client* cli = build->getClient(); // client ID - 1
        su.addClient("Banca Intesa", cli);
        build->setPassport("00001111");
        su.addAccount("Banca Intesa", 1, debit); // client ID - 1; account ID - 1
        su.addAccount("Banca Intesa", 1, credit); // client ID - 1; account ID - 2
        
        Builder* build2 = new ClientBuilder();
        build2->setClient("John", "Watson");
        build2->setAddress("Baker Street 221B");
        Client* cli2 = build2->getClient(); // client ID - 2
        su.addClient("Banca Intesa", cli2);
        su.addAccount("Banca Intesa", 2, credit); // client ID - 2; account ID - 1
        su.addAccount("Banca Intesa", 2, deposit); // client ID - 2; account ID - 2
//        su.takeMoney("Banca Intesa", 2);
        
//        su.transferMoney("Banca Intesa", 1, 2);
        su.putMoney("Banca Intesa", 2);
//        su.transferMoney("Banca Intesa", 1, 2);
        build2->setPassport("00002222");
//        su.takeMoney("Banca Intesa", 2);
        su.cancelOperation("Banca Intesa", 1);
//        su.takeMoney("Banca Intesa", 2);
//        su.putMoney("Banca Intesa" , 2);
        
        su.print();
    } catch (std::runtime_error& error){
        std::cout << "\nRuntime error occurred...\n" << error.what() << "\n";
    }
    
    
    return 0;
}
