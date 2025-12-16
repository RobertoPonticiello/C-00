void PhoneBook::addContact()
{
    std::string input;

    if (nextIndex > 7)
    {
        nextIndex = 0;
    }
    std::cout << "Inserisci il nome: " << std::endl;
    std::getline(std::cin, input);
    contacts[nextIndex].setFirstName(input);
    std::cout << "Inserisci il cognome: " << std::endl;
    std::getline(std::cin, input);
    contacts[nextIndex].setLastName(input);
    std::cout << "Inserisci il Nickname: " << '\n';
    std::getline(std::cin, input);
    contacts[nextIndex].setNickname(input);
    std::cout << "Inserisci il Numero di telefono: " << '\n';
    std::getline(std::cin, input);
    contacts[nextIndex].setNumber(input);
    std::cout << "Inserisci il Segreto: " << '\n';
    std::getline(std::cin, input);
    contacts[nextIndex].setSecret(input);
}

void PhoneBook::search()
{
    std::string input;

    void printTable() const;
    std::cout << "Inserisci un indice" << '\n';
    std::getline(std::cin, input);
    contacts[nextIndex].setFirstName(input);
    void printTable(input) const;
}

void PhoneBook::printTable()
{
    std::string input;

    std::cout << "Inserisci un indice" << '\n';
    std::getline(std::cin, input);
    void printContact(int index) const;
}

int main(int argc, char **argv)
{
    std::string input;

    std::cout << "IL PROGRAMMA PRENDE SOLO STE 3 COSE, SCE'" << '\n';
    std::cout << "ADD  -  SEARCH  -  EXIT" << '\n';

}