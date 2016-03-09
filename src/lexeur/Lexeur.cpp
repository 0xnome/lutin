//
// Created by med on 07/03/16.
//
#include <iostream>

#include "Lexeur.h"
#include <boost/regex.hpp>
#include <regex>
#include <boost/algorithm/string/regex.hpp>
#include <boost/algorithm/string/trim.hpp>
#include <IdTerminal.h>
#include <ConstTerminal.h>
#include <InstructionLecture.h>
#include <InstructionEcriture.h>
#include <NumTerminal.h>
#include <VirguleTerminal.h>
#include <PointVirguleTerminal.h>
#include <FinProgramme.h>
#include <ErreurLexicale.h>
#include <EgalTerminal.h>

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

Symbole *Lexeur::getNext() {
    boost::match_results<std::string::const_iterator> what;
    if (ligne == (int) lignesDuProgramme.size() - 1 && colone > (int) lignesDuProgramme.at(ligne).size() - 1) {
        return new FinProgramme();
    }
    if (colone > (int) lignesDuProgramme.at(ligne).size() - 1) {
        ligne++;
        colone = 0;
    }
    colone++;

    if (regex_match(lignesDuProgramme.at(ligne).at(colone - 1), s_var)) {
        cout << lignesDuProgramme.at(ligne).at(colone - 1) + " type : s_var" << endl;
        return new IdTerminal(lignesDuProgramme.at(ligne).at(colone - 1));
    }

    if (regex_match(lignesDuProgramme.at(ligne).at(colone - 1), s_const)) {
        cout << lignesDuProgramme.at(ligne).at(colone - 1) + " type : s_const" << endl;
        return new ConstTerminal();
    }

    if (regex_match(lignesDuProgramme.at(ligne).at(colone - 1), s_lire)) {
        cout << lignesDuProgramme.at(ligne).at(colone - 1) + " type : s_lire" << endl;
        return new InstructionLecture();
    }

    if (regex_match(lignesDuProgramme.at(ligne).at(colone - 1), s_ecrire)) {
        cout << lignesDuProgramme.at(ligne).at(colone - 1) + " type : s_ecrire" << endl;
        return new InstructionEcriture();
    }

    if (regex_match(lignesDuProgramme.at(ligne).at(colone - 1), s_num)) {
        cout << lignesDuProgramme.at(ligne).at(colone - 1) + " type : s_num" << endl;
        return new NumTerminal(std::stoi(lignesDuProgramme.at(ligne).at(colone - 1)));
    }

    if (regex_match(lignesDuProgramme.at(ligne).at(colone - 1), s_id)) {
        cout << lignesDuProgramme.at(ligne).at(colone - 1) + " type : s_id" << endl;
        return new IdTerminal(lignesDuProgramme.at(ligne).at(colone - 1));
    }

    if (regex_match(lignesDuProgramme.at(ligne).at(colone - 1), s_add)) {
        return lignesDuProgramme.at(ligne).at(colone - 1) + " type : s_add";
    }

    if (regex_match(lignesDuProgramme.at(ligne).at(colone - 1), s_sous)) {
        return lignesDuProgramme.at(ligne).at(colone - 1) + " type : s_sous";
    }

    if (regex_match(lignesDuProgramme.at(ligne).at(colone - 1), s_div)) {
        return lignesDuProgramme.at(ligne).at(colone - 1) + " type : s_div";
    }

    if (regex_match(lignesDuProgramme.at(ligne).at(colone - 1), s_mul)) {
        cout << lignesDuProgramme.at(ligne).at(colone - 1) + " type : s_mul" << endl;
        return new VirguleTerminal();

    }

    if (regex_match(lignesDuProgramme.at(ligne).at(colone - 1), s_vir)) {
        return lignesDuProgramme.at(ligne).at(colone - 1) + " type : s_vir";
    }

    if (regex_match(lignesDuProgramme.at(ligne).at(colone - 1), s_pv)) {
        cout << lignesDuProgramme.at(ligne).at(colone - 1) + " type : s_pv" << endl;
        return new PointVirguleTerminal();
    }

    if (regex_match(lignesDuProgramme.at(ligne).at(colone - 1), s_eg)) {
        cout << lignesDuProgramme.at(ligne).at(colone - 1) + " type : s_eg" << endl;
        return new EgalTerminal();
    }

    if (regex_match(lignesDuProgramme.at(ligne).at(colone - 1), s_opaff)) {
        return lignesDuProgramme.at(ligne).at(colone - 1) + " type : s_opaff";
    }

    if (regex_match(lignesDuProgramme.at(ligne).at(colone - 1), s_po)) {
        return lignesDuProgramme.at(ligne).at(colone - 1) + " type : s_po";
    }

    if (regex_match(lignesDuProgramme.at(ligne).at(colone - 1), s_pf)) {
        return lignesDuProgramme.at(ligne).at(colone - 1) + " type : s_pf";
    }

    cout << lignesDuProgramme.at(ligne).at(colone - 1) + " type : erreur lexicale" << endl;
    return new ErreurLexicale();
}