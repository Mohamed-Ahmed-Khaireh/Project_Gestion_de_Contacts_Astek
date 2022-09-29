#ifndef CONTACT_HPP_INCLUDED
#define CONTACT_HPP_INCLUDED

#include "Adresse.hpp"

class Contact
{
public:
    Contact(int, string, string, string, Adresse*);
    virtual ~Contact();

    int get_id(){return id;}
    string get_nom(){return nom;}
    string get_prenom(){return prenom;}
    string get_sexe(){return sexe;}

    void set_id(int);
    void set_nom(string);
    void set_prenom(string);
    void set_sexe(string);
    void set_adresse(Adresse*);

    virtual void infos();

    Adresse* adresse;

private:
    int id;
    string nom;
    string prenom;
    string sexe;

};



#endif // CONTACT_HPP_INCLUDED
