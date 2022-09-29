#include <iostream>
#include <string>
#include "main_functions.hpp"
#include "ContactPrive.hpp"
#include "ContactPro.hpp"


using namespace std;

// ajouter un contact
void ajouter_contact(Annuaire& annu){
    string propri, nom, prenom, sexe, rue, complement, code_postal, ville, nom_entreprise, statut_juridique, mail, date_naissance;
    int id, numero_rue;
    cout << "Contact Prive ou Pro? (pro/prive) ";
    cin >> propri;

    // Si c'est un conctact pro
    if(propri == "pro"){
        cout << endl << "Id: "; cin >> id;
        cout << endl << "NOM: "; getline(cin >> ws, nom);
        cout << endl << "Prenom: "; getline(cin, prenom);
        cout << endl << "Sexe (M/F): "; getline(cin, sexe);
        cout << endl << "Entreprise: "; getline(cin, nom_entreprise);
        cout << endl << "Statut Juridique: "; getline(cin, statut_juridique);
        cout << endl << "Numero adresse entreprise: "; cin >> numero_rue;
        cout << endl << "Rue entreprise: "; getline(cin >> ws, rue);
        cout << endl << "Complement adresse: "; getline(cin, complement);
        cout << endl << "Code postal: "; getline(cin, code_postal);
        cout << endl << "Ville: "; getline(cin, ville);
        cout << endl << "Mail: "; getline(cin, mail);

ContactPro *cont = new ContactPro(id, nom, prenom, sexe, nom_entreprise, statut_juridique, new Adresse(numero_rue, rue, complement, code_postal, ville),mail);
        annu.ajouter(cont);
    }
    // Si c'est un contact privé
    else if(propri == "prive"){
        cout << endl << "Id: "; cin >> id;
        cout << endl << "NOM: "; getline(cin >> ws, nom);
        cout << endl << "Prenom: "; getline(cin, prenom);
        cout << endl << "Sexe (M/F): "; getline(cin, sexe);
        cout << endl << "Numero adresse: "; cin >> numero_rue;
        cout << endl << "Rue: "; getline(cin >> ws, rue);
        cout << endl << "Complement adresse: "; getline(cin, complement);
        cout << endl << "Code postal: "; getline(cin, code_postal);
        cout << endl << "Ville: "; getline(cin, ville);
        cout << endl << "Date de naissance (jj/mm/aaaa): "; getline(cin, date_naissance);
 ContactPrive* cont = new ContactPrive(id, nom, prenom, sexe,
            new Adresse(numero_rue, rue, complement, code_postal, ville),
            date_naissance);
        annu.ajouter(cont);
        //insert(cont);

    }
    // Autre: mauvais choix
    else
        cout << "Mauvais choix" << endl;


}

// retirer un contact selon l'id
void retirer_contact(Annuaire& annu){
    int id;
    cout << "Donner id du contact a retirer: "; cin >> id;
    annu.retirer(id);
}

// afficher les contacts vivant dans une ville indiquée
void affichage_contact_via_ville(Annuaire& annu){
    string ville;
    cout << "Quelle est le nom de la ville: ";
    getline(cin >> ws, ville);
    annu.afficher_par_ville(ville);
}
// afficher les contacts via id indiquée
void affichage_contact_via_id(Annuaire& annu){
    int id;
   cout << "Donner id du contact a recherche: "; cin >> id;
    annu.afficher_par_id(id);
}
// affihcer les contacts ayant le nom indiqué
void affichage_contact_via_nom(Annuaire& annu){
    string nom;
    cout << "Quel est le nom du contact: ";
    getline(cin >> ws, nom);
    annu.afficher_par_nom(nom);
}

 //affihcer les contacts ayant le code postale
void affichage_contact_via_code_postal(Annuaire& annu){
    string code_postal;
    cout << "Quel est le code postal du contact: ";
    getline(cin >> ws, code_postal);
    annu.afficher_par_code_postal(code_postal);
}

// affiche l'interface principale du programme
void affiche_interface(Annuaire& annu){
    string choix;


    // interface
    while(1){
        cout << "\n\n===== GESTIONNAIRE DE CONTACTS =====" << endl;
        cout << "Faire un choix:" << endl;
        cout << "\t1- Afficher les contacts" << endl;
        cout << "\t2- Ajouter un contact" << endl;
        cout << "\t3- Rechercher un contact via l'id" << endl;
        cout << "\t4- Rechercher un contact via sa ville" << endl;
        cout << "\t5- Rechercher un contact via son nom" << endl;
        cout << "\t6- Rechercher un contact via son code postale" << endl;
        cout << "\t7- Supprimer un contact via l'id" << endl;
        cout << "\t8- Exportation des contacts Prives vers un fichier \"privates.dat\" "<< endl;
        cout << "\t9- Exportation des contacts Pros vers un fichier \"pros.dat\" "<< endl;
        cout << "\n\t0- Quitter l'application" << endl;
        cout << "===== CHOIX: ";
        cin >> choix;

        // quitter
        if (choix == "0"){
            cout << "Au revoir" << endl;
            break;
        }

        fonction_choix(stoi(choix), annu);
    }
}

// choisit l'action selon le choix
void fonction_choix(int choix, Annuaire& annu){
    switch(choix){
        case 1: annu.afficher(); break;
        case 2: ajouter_contact(annu); break;
        case 3: affichage_contact_via_id(annu); break;
        case 4: affichage_contact_via_ville(annu); break;
        case 5: affichage_contact_via_nom(annu); break;
        case 6: affichage_contact_via_code_postal(annu); break;
        case 7: retirer_contact(annu); break;
        case 8: annu.enregistre_fichier_prive(); break;
        case 9: annu.enregistre_fichier_pro(); break;
        default: cout << "Mauvais choix" << endl; break;
    }
}
