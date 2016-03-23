#include "Lexeur.h"
#include <boost/algorithm/string/regex.hpp>
#include <boost/algorithm/string/trim.hpp>
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
    this->lignesDuFichier = lignesDuFichier;

    for (string ligne : lignesDuFichier) {
        std::vector<std::string> vecteurLigne;
        chaine = boost::regex_replace(ligne, boost::regex(","), boost::regex(" , "));
        chaine = boost::regex_replace(chaine, boost::regex(";"), boost::regex(" ; "));
        chaine = boost::regex_replace(chaine, boost::regex("(:=|=)"), boost::regex(" $1 "));
        chaine = boost::regex_replace(chaine, boost::regex("\\+"), boost::regex(" \\+ "));
        chaine = boost::regex_replace(chaine, boost::regex("-"), boost::regex(" - "));
        chaine = boost::regex_replace(chaine, boost::regex("\\*"), boost::regex(" \\* "));
        chaine = boost::regex_replace(chaine, boost::regex("/"), boost::regex(" / "));
        chaine = boost::regex_replace(chaine, boost::regex("\\("), boost::regex(" \\( "));
        chaine = boost::regex_replace(chaine, boost::regex("\\)"), boost::regex(" \\) "));
        chaine = boost::regex_replace(chaine, boost::regex("\\s{2,}"), boost::regex(" "));
        chaine = boost::regex_replace(chaine, boost::regex("#(.)*"), boost::regex(""));
        trim(chaine);
        boost::algorithm::split_regex(vecteurLigne, chaine, boost::regex(" "));
        if (vecteurLigne.size() == 1 && vecteurLigne.at(0) == "") {
            index.push_back(0);
        }
        else { index.push_back(vecteurLigne.size()); }
        lignesDuProgramme.push_back(vecteurLigne);
    };
    ligne = 0;
    colonne = 0;
    lectureTerminee = false;
    current = nullptr;
    pos = 0;
    shift();
}

Symbole* Lexeur::getNext() {
    shift();
    return current;
}

void Lexeur::shift() {
    if (lectureTerminee) {
        current = nullptr;
        return;
    }

    if (ligne == lignesDuProgramme.size() - 1 && colonne > lignesDuProgramme.at(ligne).size() - 1) {
        lectureTerminee = true;
        LOG(TRACE) << "Fin Programme" << endl;
        current = new FinProgramme;
        return;
    }
    if (colonne > lignesDuProgramme.at(ligne).size() - 1) {
        ligne++;
        colonne = 0;
        pos = 0;
    }

    while (index.at(ligne) == 0) {
        ligne++;
        colonne = 0;
        pos = 0;
        if (ligne == lignesDuProgramme.size()) {
            lectureTerminee = true;
            LOG(TRACE) << "Fin Programme" << endl;
            current = new FinProgramme;
            return;
        }
    }

    colonne++;

    unsigned long colonne_o = lignesDuFichier.at(ligne).find(lignesDuProgramme.at(ligne).at(colonne - 1), pos) + 1;

    pos = colonne_o + lignesDuProgramme.at(ligne).at(colonne - 1).size() - 1;

    if (regex_match(lignesDuProgramme.at(ligne).at(colonne - 1), s_var)) {
        LOG(TRACE) << lignesDuProgramme.at(ligne).at(colonne - 1) + " type : s_var";
        current = new VarTerminal(ligne + 1, colonne_o);
        return;
    }

    if (regex_match(lignesDuProgramme.at(ligne).at(colonne - 1), s_const)) {
        LOG(TRACE) << lignesDuProgramme.at(ligne).at(colonne - 1) + " type : s_const";
        current = new ConstTerminal(ligne + 1, colonne_o);
        return;
    }

    if (regex_match(lignesDuProgramme.at(ligne).at(colonne - 1), s_lire)) {
        LOG(TRACE) << lignesDuProgramme.at(ligne).at(colonne - 1) + " type : s_lire";
        current = new LireTerminal(ligne + 1, colonne_o);
        return;
    }

    if (regex_match(lignesDuProgramme.at(ligne).at(colonne - 1), s_ecrire)) {
        LOG(TRACE) << lignesDuProgramme.at(ligne).at(colonne - 1) + " type : s_ecrire";
        current = new EcrireTerminal(ligne + 1, colonne_o);
        return;
    }

    if (regex_match(lignesDuProgramme.at(ligne).at(colonne - 1), s_num)) {
        LOG(TRACE) << lignesDuProgramme.at(ligne).at(colonne - 1) + " type : s_num";
        current = new NumTerminal(std::stoi(lignesDuProgramme.at(ligne).at(colonne - 1)), ligne + 1, colonne_o);
        return;
    }

    if (regex_match(lignesDuProgramme.at(ligne).at(colonne - 1), s_id)) {
        LOG(TRACE) << lignesDuProgramme.at(ligne).at(colonne - 1) + " type : s_id";
        current = new IdTerminal(lignesDuProgramme.at(ligne).at(colonne - 1), ligne + 1, colonne_o);
        return;
    }

    if (regex_match(lignesDuProgramme.at(ligne).at(colonne - 1), s_add)) {
        LOG(TRACE) << lignesDuProgramme.at(ligne).at(colonne - 1) + " type : s_add";
        current = new PlusTerminal(ligne + 1, colonne_o);
        return;
    }

    if (regex_match(lignesDuProgramme.at(ligne).at(colonne - 1), s_sous)) {
        LOG(TRACE) << lignesDuProgramme.at(ligne).at(colonne - 1) + " type : s_sous";
        current = new MoinsTerminal(ligne + 1, colonne_o);
        return;
    }

    if (regex_match(lignesDuProgramme.at(ligne).at(colonne - 1), s_div)) {
        LOG(TRACE) << lignesDuProgramme.at(ligne).at(colonne - 1) + " type : s_div";
        current = new DivTerminal(ligne + 1, colonne_o);
        return;
    }

    if (regex_match(lignesDuProgramme.at(ligne).at(colonne - 1), s_mul)) {
        LOG(TRACE) << lignesDuProgramme.at(ligne).at(colonne - 1) + " type : s_mul";
        current = new MultTerminal(ligne + 1, colonne_o);
        return;

    }

    if (regex_match(lignesDuProgramme.at(ligne).at(colonne - 1), s_vir)) {
        LOG(TRACE) << lignesDuProgramme.at(ligne).at(colonne - 1) + " type : s_vir";
        current = new VirguleTerminal(ligne + 1, colonne_o);
        return;
    }

    if (regex_match(lignesDuProgramme.at(ligne).at(colonne - 1), s_pv)) {
        LOG(TRACE) << lignesDuProgramme.at(ligne).at(colonne - 1) + " type : s_pv";
        current = new PointVirguleTerminal(ligne + 1, colonne_o);
        return;
    }

    if (regex_match(lignesDuProgramme.at(ligne).at(colonne - 1), s_eg)) {
        LOG(TRACE) << lignesDuProgramme.at(ligne).at(colonne - 1) + " type : s_eg";
        current = new EgalTerminal(ligne + 1, colonne_o);
        return;
    }

    if (regex_match(lignesDuProgramme.at(ligne).at(colonne - 1), s_opaff)) {
        LOG(TRACE) << lignesDuProgramme.at(ligne).at(colonne - 1) + " type : s_opaff";
        current = new AffectTerminal(ligne + 1, colonne_o);
        return;
    }

    if (regex_match(lignesDuProgramme.at(ligne).at(colonne - 1), s_po)) {
        LOG(TRACE) << lignesDuProgramme.at(ligne).at(colonne - 1) + " type : s_po";
        current = new ParOuvTerminal(ligne + 1, colonne_o);
        return;
    }

    if (regex_match(lignesDuProgramme.at(ligne).at(colonne - 1), s_pf)) {
        LOG(TRACE) << lignesDuProgramme.at(ligne).at(colonne - 1) + " type : s_pf";
        current = new ParFerTerminal(ligne + 1, colonne_o);
        return;
    }


    LOG(TRACE) << lignesDuProgramme.at(ligne).at(colonne - 1) + " type : erreur lexicale";

    current = new ErreurLexicale("Erreur lexicale (" + std::to_string(ligne + 1) + ":" + std::to_string(
            colonne_o) + ") caractere " +
                                 lignesDuProgramme.at(ligne).at(colonne - 1));
    std::cerr << *((ErreurLexicale *) current)->getMessage() << std::endl;
}

Symbole *Lexeur::getCurrent() {
    return current;
}