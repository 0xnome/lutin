#include "Lexeur.h"
#include <iostream>
#include <boost/algorithm/string/regex.hpp>
#include <boost/algorithm/string/trim.hpp>
#include <boost/regex.hpp>
#include <regex>
#include "easyloggingpp.h"

#include "SymbolesTerminaux.h"
#include "FinProgramme.h"
#include "ErreurLexicale.h"

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
static const boost::regex s_po("\\(");
static const boost::regex s_pf("\\)");


Lexeur::Lexeur(std::vector<std::string> lignesDuFichier) {
    std::string chaine;
    // lignesDuProgramme = std::vector<std::vector<std::string>>;

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
    lectureTerminee = false;
}

Symbole *Lexeur::getNext() {
    shift();
    return current;
}

void Lexeur::shift() {
    if(lectureTerminee){
        current =  nullptr;
    }
    boost::match_results<std::string::const_iterator> what;
    if (ligne == lignesDuProgramme.size() - 1 && colone > lignesDuProgramme.at(ligne).size() - 1) {
        lectureTerminee = true;
        LOG(INFO) << "Fin Programme" << endl;
        current = new FinProgramme;
    }
    if (colone > lignesDuProgramme.at(ligne).size() - 1) {
        ligne++;
        colone = 0;
    }
    colone++;

    if (regex_match(lignesDuProgramme.at(ligne).at(colone - 1), s_var)) {
        LOG(INFO) << lignesDuProgramme.at(ligne).at(colone - 1) + " type : s_var" << endl;
        current = new IdTerminal(lignesDuProgramme.at(ligne).at(colone - 1));
        return;
    }

    if (regex_match(lignesDuProgramme.at(ligne).at(colone - 1), s_const)) {
        LOG(INFO) << lignesDuProgramme.at(ligne).at(colone - 1) + " type : s_const" << endl;
        current = new ConstTerminal;
        return;
    }

    if (regex_match(lignesDuProgramme.at(ligne).at(colone - 1), s_lire)) {
        LOG(INFO) << lignesDuProgramme.at(ligne).at(colone - 1) + " type : s_lire" << endl;
        current = new LireTerminal;
        return;
    }

    if (regex_match(lignesDuProgramme.at(ligne).at(colone - 1), s_ecrire)) {
        LOG(INFO) << lignesDuProgramme.at(ligne).at(colone - 1) + " type : s_ecrire" << endl;
        current = new EcrireTerminal;
        return;
    }

    if (regex_match(lignesDuProgramme.at(ligne).at(colone - 1), s_num)) {
        LOG(INFO) << lignesDuProgramme.at(ligne).at(colone - 1) + " type : s_num" << endl;
        current = new NumTerminal(std::stoi(lignesDuProgramme.at(ligne).at(colone - 1)));
        return;
    }

    if (regex_match(lignesDuProgramme.at(ligne).at(colone - 1), s_id)) {
        LOG(INFO) << lignesDuProgramme.at(ligne).at(colone - 1) + " type : s_id" << endl;
        current = new IdTerminal(lignesDuProgramme.at(ligne).at(colone - 1));

    }

    if (regex_match(lignesDuProgramme.at(ligne).at(colone - 1), s_add)) {
        LOG(INFO) << lignesDuProgramme.at(ligne).at(colone - 1) + " type : s_add" << endl;
        current = new PlusTerminal;
    }

    if (regex_match(lignesDuProgramme.at(ligne).at(colone - 1), s_sous)) {
        LOG(INFO) << lignesDuProgramme.at(ligne).at(colone - 1) + " type : s_sous" << endl;
        current = new MoinsTerminal;
    }

    if (regex_match(lignesDuProgramme.at(ligne).at(colone - 1), s_div)) {
        LOG(INFO) << lignesDuProgramme.at(ligne).at(colone - 1) + " type : s_div" << endl;
        current = new DivTerminal;
    }

    if (regex_match(lignesDuProgramme.at(ligne).at(colone - 1), s_mul)) {
        LOG(INFO) << lignesDuProgramme.at(ligne).at(colone - 1) + " type : s_mul" << endl;
        current = new MultTerminal;

    }

    if (regex_match(lignesDuProgramme.at(ligne).at(colone - 1), s_vir)) {
        LOG(INFO) << lignesDuProgramme.at(ligne).at(colone - 1) + " type : s_vir" << endl;
        current = new VirguleTerminal;
    }

    if (regex_match(lignesDuProgramme.at(ligne).at(colone - 1), s_pv)) {
        LOG(INFO) << lignesDuProgramme.at(ligne).at(colone - 1) + " type : s_pv" << endl;
        current = new PointVirguleTerminal;
    }

    if (regex_match(lignesDuProgramme.at(ligne).at(colone - 1), s_eg)) {
        LOG(INFO) << lignesDuProgramme.at(ligne).at(colone - 1) + " type : s_eg" << endl;
        current = new EgalTerminal;
    }

    if (regex_match(lignesDuProgramme.at(ligne).at(colone - 1), s_opaff)) {
        LOG(INFO) << lignesDuProgramme.at(ligne).at(colone - 1) + " type : s_opaff" << endl;
        current = new AffectTerminal;
    }

    if (regex_match(lignesDuProgramme.at(ligne).at(colone - 1), s_po)) {
        LOG(INFO) << lignesDuProgramme.at(ligne).at(colone - 1) + " type : s_po" << endl;
        current = new ParOuvTerminal;
    }

    if (regex_match(lignesDuProgramme.at(ligne).at(colone - 1), s_pf)) {
        LOG(INFO) << lignesDuProgramme.at(ligne).at(colone - 1) + " type : s_pf" << endl;
        current = new ParFerTerminal;
    }

    LOG(INFO) << lignesDuProgramme.at(ligne).at(colone - 1) + " type : erreur lexicale" << endl;
    current = new ErreurLexicale;
}

Symbole* Lexeur::getCurrent() {
    return current;
}