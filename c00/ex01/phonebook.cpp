#include "phonebook.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>

/* ================= CONSTRUCTOR ================= */

PhoneBook::PhoneBook() : nextIndex(0), count(0) {}

/* ================= UTILITY ================= */

static std::string getNonEmptyInput(const std::string& prompt)
{
    std::string input;

    while (true)
    {
        std::cout << prompt;
        std::getline(std::cin, input);

        if (!input.empty())
            return input;

        std::cout << "Input non valido. Il campo non può essere vuoto.\n";
    }
}

/* ================= ADD CONTACT ================= */

void PhoneBook::addContact()
{
    Contact c;

    c.setFirstName(getNonEmptyInput("First name: "));
    c.setLastName(getNonEmptyInput("Last name: "));
    c.setNickname(getNonEmptyInput("Nickname: "));
    c.setNumber(getNonEmptyInput("Phone number: "));
    c.setSecret(getNonEmptyInput("Darkest secret: "));

    contacts[nextIndex] = c;

    nextIndex = (nextIndex + 1) % 8;
    if (count < 8)
        count++;
}

/* ================= SEARCH ================= */

void PhoneBook::search() const
{
    std::string input;
    int         index;

    if (count == 0)
    {
        std::cout << "PhoneBook is empty.\n";
        return;
    }

    printTable();

    while (true)
    {
        std::cout << "Index: ";
        std::getline(std::cin, input);

        if (input.empty())
        {
            std::cout << "Indice non valido.\n";
            continue;
        }

        index = std::atoi(input.c_str());

        if (index < 0 || index >= count)
        {
            std::cout << "Indice fuori range.\n";
            continue;
        }

        break;
    }

    printContact(index);
}

/* ================= PRINT TABLE ================= */

static std::string formatField(const std::string &str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void PhoneBook::printTable() const
{
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First" << "|"
              << std::setw(10) << "Last" << "|"
              << std::setw(10) << "Nick" << "\n";

    for (int i = 0; i < count; i++)
    {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << formatField(contacts[i].getFirstName()) << "|"
                  << std::setw(10) << formatField(contacts[i].getLastName()) << "|"
                  << std::setw(10) << formatField(contacts[i].getNickname()) << "\n";
    }
}

/* ================= PRINT CONTACT ================= */

void PhoneBook::printContact(int index) const
{
    std::cout << "First name: " << contacts[index].getFirstName() << "\n";
    std::cout << "Last name: " << contacts[index].getLastName() << "\n";
    std::cout << "Nickname: " << contacts[index].getNickname() << "\n";
    std::cout << "Phone: " << contacts[index].getNumber() << "\n";
    std::cout << "Secret: " << contacts[index].getSecret() << "\n";
}

/* ================= MAIN ================= */

int main()
{
    PhoneBook   pb;
    std::string cmd;

    while (true)
    {
        std::cout << "ADD | SEARCH | EXIT\n> ";
        std::getline(std::cin, cmd);

        if (cmd == "ADD")
            pb.addContact();
        else if (cmd == "SEARCH")
            pb.search();
        else if (cmd == "EXIT")
            break;
        else
            std::cout << "Comando non valido.\n";
    }

    return 0;
}
