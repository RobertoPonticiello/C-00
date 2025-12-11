#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>

class PhoneBook {
private:
    Contact contacts[8];
    int     nextIndex;

public:
    PhoneBook();

    void addContact();
    void search() const;

private:
    void printTable() const;
    void printContact(int index) const;
};


class Contact {
private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string number;
    std::string darkest_secret;

public:
    Contact();    // costruttore

    void setFirstName(std::string first_name);
    void setLastName(std::string last_name);
    void setNickname(std::string nickname);
    void setNumber(std::string number);
    void setSecret(std::string darkest_secret);

    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    std::string getNumber() const;
    std::string getSecret() const;
};


#endif
