//
//  Banks.hpp
//  Banks
//
//  Created by Sara Nikolić on 06.12.2020.
//

#ifndef Banks_hpp
#define Banks_hpp

#include <stdio.h>
#include <map>
#include <string>
#include <vector>
#include <tuple>
#include <chrono>

enum Accounts { debit, credit, deposit };

class Date{
private:
    tm time;
public:
    Date(){}
    Date(int mday, int mon);
    Date(tm time);
    
    time_t getTime();
    bool operator<(Date& another);
    bool operator==(Date& another);
    static Date getNow();
    int getDay();
};

class Account{
protected:
    Accounts nameAccount;
    int thisAccountID;
    double commission;
    double interestRate;
    long money_;
    bool suspicious;
public:
    Account();
    
    int getAccountID() const;
    double getCommission() const;
    double getInterestRate() const;
    Accounts getNameAccount() const;
    std::string getNameAccountString() const;
    long getMoneyAccount() const;
    bool isSuspicious() const;
    
    void setSuspicious(bool var);
    virtual void setInterestRate(double IR) = 0;
    virtual void setCommission(double comm) = 0;
    virtual void addIRDay() = 0;
    virtual void addIRMonth() = 0;
    
    virtual void takeMoney(long money);
    virtual void putMoney(long money);
    virtual void transferMoney(Account* ac, long money);
};

class Debit : public Account {
protected:
    double pocket;
public:
    Debit(double ir, int count);
    
    void setInterestRate(double IR) override;
    void setCommission(double comm) override;
    void addIRDay() override;
    void addIRMonth() override;

    void takeMoney(long money) override;
    void putMoney(long money) override;
    void transferMoney(Account* ac, long money) override;
};

class Deposit : public Account {
protected:
    Date time_;
    double pocket;
public:
    Deposit(double ir, long money, int count, Date date);
    
    void setInterestRate(double IR) override;
    void setCommission(double comm) override;
    void addIRDay() override;
    void addIRMonth() override;
    
    void takeMoney(long money) override;
    void putMoney(long money) override;
    void transferMoney(Account* ac, long money) override;
};

class Credit : public Account {
protected:
    long creditLimit;
public:
    Credit(double comm, int count, long limit);
    
    void setInterestRate(double IR) override;
    void setCommission(double comm) override;
    void addIRDay() override;
    void addIRMonth() override;
    
    void takeMoney(long money) override;
    void putMoney(long money) override;
    void transferMoney(Account* ac, long money) override;
    
    bool isCredLim_valid();
};

class Command {
protected:
    int commandID;
public:
    virtual ~Command() = default;
    virtual void run() const = 0;
    virtual void undo() const = 0;
    
    int getCommandID();
};

class Transfer : public Command{
private:
    Account* acc_;
    Account* acc2_;
    long money_;
public:
    Transfer(int id, Account* a, Account* a2, long money);
    void run() const override;
    void undo() const override;
};

class Take : public Command{
private:
    Account* acc_;
    long money_;
public:
    Take(int id, Account* a, long money);
    void run() const override;
    void undo() const override;
};

class Put : public Command{
private:
    Account* acc_;
    long money_;
public:
    Put(int id, Account* a, long money);
    void run() const override;
    void undo() const override;
};

// --- CLIENT ---
class Client{
protected:
    static int clientID;
    int thisClientID;
    std::string nameClient;
    std::string surnameClient;
    std::string addressClient;
    std::string passportClient;
public:
    ~Client() = default;
    Client(const std::string& name, const std::string& surname);
    Client(const Client& a) : thisClientID(a.thisClientID), nameClient(a.nameClient), surnameClient(a.surnameClient), addressClient(a.addressClient), passportClient(a.passportClient) { } // copy ctor
    
    int getIDClient() const;
    std::string getNameClient() const;
    std::string getSurnameClient() const;
    std::string getAddressClient() const;
    std::string getPassportClient() const;
    
    void setAddressClient(const std::string& pass);
    void setPassportClient(const std::string& pass);
};

class Builder{
public:
    virtual ~Builder() = default;
    virtual void setClient(const std::string& name, const std::string& surname){}
    virtual void setPassport(const std::string& pass) {}
    virtual void setAddress(const std::string& add) {}
    virtual Client* getClient() {return nullptr;}
    virtual void reset() {}
};

class ClientBuilder : public Builder {
protected:
    Client* client_ = nullptr;
public:
    virtual ~ClientBuilder();
    void setClient(const std::string& name, const std::string& surname) override;
    void setPassport(const std::string& pass) override;
    void setAddress(const std::string& pass) override;
    Client* getClient() override;
    void reset() override;
};

class Bank{
private:
    static int bankID;
    int thisBankID;
    std::map<int, std::vector<Account*>> accounts; // where map->first are clientIDs
    std::vector<Client*> clients;
    std::map<int,Command*> commands;
    
    double percentage;
    double commission;
    long moneyLimit;
    long suspLimit;
    time_t timeB_;
public:
    Bank(long moneyLimit, long suspLimit, double percentage, double commission);
    
    int getBankID();
    double getPerc();
    double getComm();
    long getMoneyLim();
    std::vector<Client*> getClients();
    std::vector<Account*> getAccounts(int cID);
    
    int setCommandID();
    
    void addClient(Client* client);
    void addAccount(int clientID, Accounts val);
    
    void transferMoney(int cID, int cID2);
    void putMoney(int cID, long money);
    void takeMoney(int cID, long money);
    
    void command(Command* c);
    void cancel(int ID);
    
    void CheckUpdateSusp(int clientID, Account* acc);
    void dailyIR();
    void monthlyIR();
    
    bool isClient(int clientID);
    void printClients();
    void printAccounts();
    void printAll();
};

class SystemUtility{
private:
    std::map<std::string, Bank> banks;
public:
    void addBank(const std::string& name, long moneyLimit, long suspLimit, double percentage, double commission);
    void addClient(const std::string& bank, Client* client);
    void addAccount(const std::string& bank, int clientID, Accounts accountName);
    
    void putMoney(const std::string& bank, int clientID);
    void transferMoney(const std::string& bank, int clientID, int clientID2);
    void takeMoney(const std::string& bank, int clientID);
    
    void cancelOperation(const std::string &bank, int ID);
    
    std::map<std::string, Bank> getBanks();
    Bank& getBank(const std::string& bank);
    void printBank();
    void print();
};



#endif /* Banks_hpp */
