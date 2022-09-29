#include <iostream>
#include "Contact.hpp"
#include "Adresse.hpp"
#include "ContactPrive.hpp"
#include "ContactPro.hpp"
#include "Annuaire.hpp"
#include "main_functions.hpp"

using namespace std;

int main()
{
//     ContactPrive *eDyn  = new ContactPrive(1,"BETY","Daniel","M", new Adresse (12, "rue des Oliviers","","94000","CRETEIL"),"12/11/1985");
//     eDyn->infos();
//     delete eDyn;
//     cout<<"--------------------------------------"<<endl;
//     ContactPro *Dyn  = new ContactPro(2,"FRAN","Daniel","M","AXA", "SAS", new Adresse (125, "rue LaFayette", "Digicode 1432", "94120", "FONTENAY SOUS BOIS"), "info@axa.fr");
//     Dyn->infos();
//     delete eDyn;

// création annuaire
    Annuaire annu("Annuaire de Contact");

    // fonction principale qui permet l'interface du programme
    affiche_interface(annu);


    return 0;
}
