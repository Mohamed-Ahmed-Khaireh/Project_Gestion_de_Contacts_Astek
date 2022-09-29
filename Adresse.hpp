#ifndef ADRESSE_HPP_INCLUDED
#define ADRESSE_HPP_INCLUDED

#include <iostream>
using namespace std;

class Adresse
{
public:
    Adresse(int=0, string="rue", string="complement", int=00000, string="ville");
    Adresse(int=0, string="rue", string="complement", string="00000", string="ville");
    ~Adresse();


    void set_numero(int);
    void set_rue(string);
    void set_complement(string);
    void set_code_postal(string);
    void set_ville(string);

    int get_numero(){return this->numero;}
    string get_rue(){return this->rue;}
    string get_complement(){return this->complement;}
    string get_code_postal(){return this->code_postal;}
    string get_ville(){return this->ville;}

    void infos();

private:
    int numero;
    string rue;
    string complement;
    string code_postal;
    string ville;

};


#endif // ADRESSE_HPP_INCLUDED
