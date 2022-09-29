#ifndef MAIN_FUNCTIONS_HPP_INCLUDED
#define MAIN_FUNCTIONS_HPP_INCLUDED
#include "Annuaire.hpp"

void ajouter_contact(Annuaire&);

void retirer_contact(Annuaire&, int);

void affiche_interface(Annuaire&);
void fonction_choix(int choix, Annuaire& annu);
void affichage_contact_via_ville(Annuaire&);
void affichage_contact_via_id(Annuaire&);
void affichage_contact_via_nom(Annuaire&);
void affichage_contact_via_code_postal(Annuaire&, int);

#endif // MAIN_FUNCTIONS_HPP_INCLUDED
