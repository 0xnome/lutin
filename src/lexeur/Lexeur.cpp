//
// Created by med on 07/03/16.
//
#include <iostream>

#include "Lexeur.h"
#include <boost/regex.hpp>
#include <regex>

using namespace boost;
using namespace std;

static const boost::regex s_id("[a-zA-Z][a-zA-Z0-9]*");
static const boost::regex s_num("[0-9]+");
static const boost::regex s_var("var");
static const boost::regex s_const("const");
static const boost::regex s_lire("const");
//static const boost::regex ex("[Rr]eg...r(.)*");


Lexeur::Lexeur(std::vector<std::string> lignesDuFichier) {
    this->lignesDuFichier = lignesDuFichier;
}

std::string Lexeur::getNext() {
    boost::match_results<std::string::const_iterator> what;

    boost::regex_match(lignesDuFichier.at(0),what, s_num);
    if(what[0].matched) return what[0].str()+" num" ;

    boost::regex_match(lignesDuFichier.at(0),what, s_id);
    if(what[0].matched) return what[0].str()+" id" ;




//    if (boost::regex_match(lignesDuFichier.at(0), id))
//        return
//
//    std::cout << lignesDuFichier.at(0) << std::endl;
//    if (boost::regex_match(lignesDuFichier.at(0), ex)) {
//        return  " matches" ;
//    }
//    else {
//        return  " doesn’t match";
//    }
}