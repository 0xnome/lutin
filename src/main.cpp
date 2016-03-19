#include <iostream>
#include "Automate.h"
#include <boost/program_options.hpp>
#include "easyloggingpp.h"

INITIALIZE_EASYLOGGINGPP

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
    /**
     * variables pour la récupération des options
     */
    std::string fichier;
    bool execute = false;
    bool optimize = false;
    bool analyse = false;
    bool program = false;


    try
    {
        po::options_description desc("Options");

        desc.add_options()
                ("help,h", "Affiche ce message d'aide")
                ("program,p", "Affiche sur la sortie standard la représentation en mémoire du programme")
                ("execute,e", "Exécution interactive du programme")
                ("analyse,a", "Analyse statique du programme")
                ("optimize,o", "Transforme le programme et le simplifie")
                ("verbose,v", "Affiche le debug")
                ("input,i", po::value<std::string>()->required(), "programme lutin, argument par défaut");

        po::positional_options_description p;
        p.add("input", -1);
        po::variables_map vm;
        po::notify(vm);

        el::Configurations c;
        c.setToDefault();
        c.parseFromText("*GLOBAL:\n ENABLED = FALSE");
        c.parseFromText("*GLOBAL:\n FORMAT = --- %level --- %msg");

        el::Loggers::reconfigureLogger("default", c);
        try
        {
            po::store(po::command_line_parser(argc, argv).
                    options(desc).positional(p).run(), vm);


            if (argc == 1)
            {
                std::cerr << "Compilateur Lutin" << std::endl;
                std::cerr << "Utilisation: lut [options] fichier" << std::endl;
                std::cerr << desc << std::endl;
                return ERROR_IN_COMMAND_LINE;
            }

            if (vm.count("help"))
            {
                std::cout << "Compilateur Lutin" << std::endl;
                std::cout << "Utilisation: lut [options] fichier" << std::endl;
                std::cout << desc << std::endl;
                return SUCCESS;
            }

            if (vm.count("verbose"))
            {
                c.parseFromText("*GLOBAL:\n ENABLED = TRUE");
                el::Loggers::reconfigureLogger("default", c);
            }

            if (vm.count("execute")) execute = true;
            if (vm.count("analyse")) analyse = true;
            if (vm.count("optimize")) optimize = true;
            if (vm.count("program")) program = true;
            if (vm.count("input")) fichier = vm["input"].as<std::string>();

            po::notify(vm);
        }

        catch (po::error &e)
        {
            std::cerr << "ERROR: " << e.what() << std::endl << std::endl;
            std::cerr << desc << std::endl;
            return ERROR_IN_COMMAND_LINE;
        }

        Automate automate(fichier);

        if (automate.programmeEstCharge())
        {
            if (analyse)
                automate.analyserProgramme();

            if (optimize)
                automate.optimiserProgramme();

            if (program)
                automate.afficherProgramme();

            if (execute)
                automate.executerProgramme();

        } else{
            std::cerr << "Le programme n'est pas correcte." << std::endl;
        }

    }

    catch (std::exception &e)
    {
        std::cerr << "Un erreur non traitée est remontée jusqu'au main : "
        << e.what() << std::endl << "L'application va se stopper" << std::endl;
        return ERROR_UNHANDLED_EXCEPTION;
    }

    return SUCCESS;
}