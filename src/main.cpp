#include <iostream>
#include "Automate.h"
#include <boost/program_options.hpp>

namespace po = boost::program_options;

using namespace std;

namespace
{
    const size_t ERROR_IN_COMMAND_LINE = 1;
    const size_t SUCCESS = 0;
    const size_t ERROR_UNHANDLED_EXCEPTION = 2;
}

int main(int argc, char **argv)
{
    std::string fichier;
    try {
        po::options_description desc("Options");

        desc.add_options()
                ("help,h", "Affiche ce message d'aide")
                ("program,p", "Affiche sur la sortie standard la représentation en mémoire du programme")
                ("execute,e", "Exécution interactive du programme")
                ("analyse,a", "Analyse statique du programme")
                ("optimize,o", "Transforme le programme et le simplifie")
                ("input,i", po::value<std::string>()->required(), "programme lutin, argument par défaut");

        po::positional_options_description p;
        p.add("input", -1);
        po::variables_map vm;
        po::notify(vm);

        try {
            po::store(po::command_line_parser(argc, argv).
                    options(desc).positional(p).run(), vm);


            if (argc == 1) {
                std::cerr << "Compilateur Lutin" << std::endl;
                std::cerr << "Utilisation: lut [options] fichier" << std::endl;
                std::cerr << desc << std::endl;
                return ERROR_IN_COMMAND_LINE;
            }

            if (vm.count("help")) {
                std::cout << "Compilateur Lutin" << std::endl;
                std::cout << "Utilisation: lut [options] fichier" << std::endl;
                std::cout << desc << std::endl;
                return SUCCESS;
            }

            if (vm.count("execute")) {
                std::cout << "--execute option spécifiée" << std::endl;
            }

            if (vm.count("analyse")) {
                std::cout << "--analyse option spécifiée" << std::endl;
            }

            if (vm.count("optimize")) {
                std::cout << "--optimize option spécifiée" << std::endl;
            }

            if (vm.count("program")) {
                std::cout << "--program option spécifiée" << std::endl;
            }

            if (vm.count("input")) {
                fichier = vm["input"].as<std::string>();
            }

            po::notify(vm);
        }
        catch (po::error &e) {
            std::cerr << "ERROR: " << e.what() << std::endl << std::endl;
            std::cerr << desc << std::endl;
            return ERROR_IN_COMMAND_LINE;
        }

        Automate automate(fichier);

    }
    catch (std::exception &e) {
        std::cerr << "Unhandled Exception reached the top of main: "
        << e.what() << ", application will now exit" << std::endl;
        return ERROR_UNHANDLED_EXCEPTION;

    }

    return SUCCESS;
}