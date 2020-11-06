#include "accountCtrl.hpp"
#include <climits> // for max size of types

Account::Account()
    :num(0)
     ,balance(0)
     ,firstName("unknown")
     ,lastName("unknown")
{
}

Account::Account(const unsigned& num, const std::string& firstName
        , const std::string& lastName, const ULLong& balance)
    :num(num)
     ,firstName(firstName)
     ,lastName(lastName)
     ,balance(balance)
{
}

/*this function will be used for Account's istream operator */
std::pair<std::string, bool> getName(std::string str) {
    std::pair<std::string, bool> res("unknown", true);
    if(str.size() == 0) {
        std::cout << "ther's no name\nTry again";
        res.second = false;
        return res;
    }
    if(str[0] < 'A' || str[0] > 'Z') {
        std::cout << "Wrong input!\n"
            << "The name must start with a capital letter and contain "
            << "only the characters \"a - z\"\n Please try again";
        res.second = false;
        return res;
    }
    res.first.erase(1, -1);
    res.first[0] = str[0];
    for(size_t i = 1; i < str.size(); ++i) {
        if(str[i] < 'a' || str[i] > 'z') {
            if(str[i] != ' ') {
                std::cout << "Wrong input!\n"
                    << "The name must start with a capital letter and contain "
                    << "only the characters \"a - z\"\n Please try again";
                res.second = false;
                return res;
            }
            /*after the space, characters will be ignored */
            std::cout << "after the space symbols are ignored\n"
                << "so your name is written as \""
                << res.first << "\"\n";
            return res;
        }
        res.first += str[i];
    }
    return res;
}
        


std::istream& operator >> (std::istream& in, Account& a) {
    std::string inputStr;
    /*
     * input number for Account Id as string and test it before initialization
     * the testor will send messages about test proces
     */
    while(true) {
        std::cout << "Enter Account Number: ";
        in >> inputStr;
        std::pair<unsigned, bool> result = getNumber< unsigned >(inputStr, UINT_MAX);
            if(result.second) {
            a.num = result.first;
            break;
        }
    }
    /*
     * input firstName for account and test it before initialization
     * the testor will send messages about test proces
     */
    while(true) {
        std::cout << "Enter First Name: ";
        in >> inputStr;
        std::pair<std::string, bool> result = getName(inputStr);
        if(result.second) {
            a.firstName = result.first;
            break;
        }
    }
    /*
     * input last name for account and test it brfore init
     * the testor will send messages about test procces
     */
    while(true) {
        std::cout << "Enter Last Name: ";
        in >> inputStr;
        std::pair<std::string, bool> result = getName(inputStr);
        if(result.second) {
            if(result.first != a.firstName) {
                a.lastName = result.first;
                break;
            }
            std::cout << "first and last names are the same "
                << "Please try another last name\n";
        }
    }
    /*
     * input balance count and test before init
     * the testor will send messages about proces
     */
    while(true) {
        std::cout << "Enter Balance: ";
        in >> inputStr;
        std::pair<ULLong, bool> result = getNumber< ULLong >(inputStr, ULLONG_MAX);
        if(result.second) {
            a.balance = result.first;
            break;
        }
    }
    return in;
}

std::ostream& operator << (std::ostream& out, const Account& a) {
    out << "Record " << a.num << " has following data:\n"
        << "\nAccount Number (ID): " << a.num
        << "\nFirst Name: " << a.firstName
        << "\nLast Name: " << a.lastName
        << "\nCurrent Balance: " << a.balance << '\n';
    return out;
}
