//
// Created by med on 07/03/16.
//
#include <iostream>

#include "Lexeur.h"
#include <boost/regex.hpp>
#include <regex>
#include <boost/algorithm/string/regex.hpp>
#include <boost/algorithm/string/trim.hpp>

using namespace boost;
using namespace std;

static const boost::regex s_id("[a-zA-Z][a-zA-Z0-9]*");
static const boost::regex s_num("[0-9]+");
static const boost::regex s_var("var");
static const boost::regex s_const("const");
static const boost::regex s_lire("lire");
static const boost::regex s_ecrire("ecrire");
static const boost::regex s_add("\\+");
static const boost::regex s_sous("-");
static const boost::regex s_mul("\\*");
static const boost::regex s_div("/");
static const boost::regex s_vir(",");
static const boost::regex s_pv(";");
static const boost::regex s_eg("=");
static const boost::regex s_opaff(":=");
static const boost::regex s_pf("\\(");
static const boost::regex s_po("\\)");


Lexeur::Lexeur(std::vector<std::string> lignesDuFichier) {
    std::string chaine;
    lignesDuProgramme = std::vector<std::vector<std::string>>();

    for (string ligne : lignesDuFichier) {
        std::vector<std::string> vecteurLigne;
        chaine = boost::regex_replace(ligne, boost::regex(","), boost::regex(" , "));
        chaine = boost::regex_replace(chaine, boost::regex(";"), boost::regex(" ; "));
        chaine = boost::regex_replace(chaine, boost::regex("[^:]="), boost::regex(" = "));
        chaine = boost::regex_replace(chaine, boost::regex(":="), boost::regex(" := "));
        chaine = boost::regex_replace(chaine, boost::regex("\\+"), boost::regex(" \\+ "));
        chaine = boost::regex_replace(chaine, boost::regex("-"), boost::regex(" - "));
        chaine = boost::regex_replace(chaine, boost::regex("\\*"), boost::regex(" \\* "));
        chaine = boost::regex_replace(chaine, boost::regex("/"), boost::regex(" / "));
        chaine = boost::regex_replace(chaine, boost::regex("\\("), boost::regex(" \\( "));
        chaine = boost::regex_replace(chaine, boost::regex("\\)"), boost::regex(" \\) "));

        chaine = boost::regex_replace(chaine, boost::regex("\\s{2,}"), boost::regex(" "));
        trim(chaine);
        boost::algorithm::split_regex(vecteurLigne, chaine, boost::regex(" "));
        lignesDuProgramme.push_back(vecteurLigne);
    };
    ligne = 0;
    colone = 0;
}

std::string Lexeur::getNext() {
    boost::match_results<std::string::const_iterator> what;
    if (ligne == (int)lignesDuProgramme.size()-1 && colone > (int)lignesDuProgramme.at(ligne).size()-1) {
        return "fin";
    }
    if (colone > (int)lignesDuProgramme.at(ligne).size()-1) {
        ligne++;
        colone = 0;
    }
    colone++;


    if(regex_match(lignesDuProgramme.at(ligne).at(colone-1),s_var)) {
        return lignesDuProgramme.at(ligne).at(colone-1) + " type : s_var";
    }

    if(regex_match(lignesDuProgramme.at(ligne).at(colone-1),s_const)) {
        return lignesDuProgramme.at(ligne).at(colone-1) + " type : s_const";
    }

    if(regex_match(lignesDuProgramme.at(ligne).at(colone-1),s_lire)) {
        return lignesDuProgramme.at(ligne).at(colone-1) + " type : s_lire";
    }

    if(regex_match(lignesDuProgramme.at(ligne).at(colone-1),s_ecrire)) {
        return lignesDuProgramme.at(ligne).at(colone-1) + " type : s_ecrire";
    }

    if(regex_match(lignesDuProgramme.at(ligne).at(colone-1),s_num)) {
        return lignesDuProgramme.at(ligne).at(colone-1) + " type : s_num";
    }

    if(regex_match(lignesDuProgramme.at(ligne).at(colone-1),s_id)) {
        return lignesDuProgramme.at(ligne).at(colone-1) + " type : s_id";
    }

    if(regex_match(lignesDuProgramme.at(ligne).at(colone-1),s_add)) {
        return lignesDuProgramme.at(ligne).at(colone-1) + " type : s_add";
    }

    if(regex_match(lignesDuProgramme.at(ligne).at(colone-1),s_sous)) {
        return lignesDuProgramme.at(ligne).at(colone-1) + " type : s_sous";
    }

    if(regex_match(lignesDuProgramme.at(ligne).at(colone-1),s_div)) {
        return lignesDuProgramme.at(ligne).at(colone-1) + " type : s_div";
    }

    if(regex_match(lignesDuProgramme.at(ligne).at(colone-1),s_mul)) {
        return lignesDuProgramme.at(ligne).at(colone-1) + " type : s_mul";
    }

    if(regex_match(lignesDuProgramme.at(ligne).at(colone-1),s_vir)) {
        return lignesDuProgramme.at(ligne).at(colone-1) + " type : s_vir";
    }

    if(regex_match(lignesDuProgramme.at(ligne).at(colone-1),s_pv)) {
        return lignesDuProgramme.at(ligne).at(colone-1) + " type : s_pv";
    }

    if(regex_match(lignesDuProgramme.at(ligne).at(colone-1),s_eg)) {
        return lignesDuProgramme.at(ligne).at(colone-1) + " type : s_eg";
    }

    if(regex_match(lignesDuProgramme.at(ligne).at(colone-1),s_opaff)) {
        return lignesDuProgramme.at(ligne).at(colone-1) + " type : s_opaff";
    }

    if(regex_match(lignesDuProgramme.at(ligne).at(colone-1),s_po)) {
        return lignesDuProgramme.at(ligne).at(colone-1) + " type : s_po";
    }

    if(regex_match(lignesDuProgramme.at(ligne).at(colone-1),s_pf)) {
        return lignesDuProgramme.at(ligne).at(colone-1) + " type : s_pf";
    }

    return lignesDuProgramme.at(ligne).at(colone-1) + " type : erreur lexicale";


}