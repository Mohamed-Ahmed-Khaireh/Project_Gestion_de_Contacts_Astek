#ifndef CONTACTPRIVE_HPP_INCLUDED
#define CONTACTPRIVE_HPP_INCLUDED

#include "Contact.hpp"
#include "Adresse.hpp"

class ContactPrive: public Contact
{
public:
    // ContactPrive(int=0, string="NOM", string="Prenom", string="H", Adresse*=nullptr, string="00/00/0000");
    ContactPrive(int, string, string,string, Adresse*, string);
    ~ContactPrive();

    void set_adresse(Adresse*);
    void set_date_naissance(string);

    string get_date_naissance(){return date_naissance;}

    void infos() override;

private:
    string date_naissance;
};

#endif // CONTACTPRIVE_HPP_INCLUDED
