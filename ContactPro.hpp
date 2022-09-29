#ifndef CONTACTPRO_HPP_INCLUDED
#define CONTACTPRO_HPP_INCLUDED

#include "Contact.hpp"
#include "Adresse.hpp"


class ContactPro: public Contact
{
public:
    ContactPro(int, string, string, string, string, string, Adresse*, string);
    ~ContactPro();

    void set_nom_entreprise(string);
    void set_statut_juridique(string);
    void set_mail(string);


    string get_nom_entreprise(){return nom_entreprise;}
    string get_statut_juridique(){return statut_juridique;}
    string get_mail(){return mail;}

    void infos() override;

private:
    string nom_entreprise;
    string statut_juridique;
    string mail;
};


#endif // CONTACTPRO_HPP_INCLUDED
