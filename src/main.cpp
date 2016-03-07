#include <iostream>

#include <boost/program_options.hpp>

namespace po = boost::program_options;

using namespace std;

namespace
{
    const size_t ERROR_IN_COMMAND_LINE = 1;
    const size_t SUCCESS = 0;
    const size_t ERROR_UNHANDLED_EXCEPTION = 2;

} // namespace

int main(int argc, char **argv)
{
    try {
        po::options_description desc("Options");

        desc.add_options()
                ("help,h", "Print help messages")
                ("programme,p", "Display the program as it should looks like in memory")
                ("execute,e", "interactive execution")
                ("analyse,a", "static program analysis")
                ("optimize,o", "optimize the program")
                ("input-file,i", po::value<std::string>(), "input file");

        po::positional_options_description p;
        p.add("input-file", -1);
        po::variables_map vm;
        po::notify(vm);

        try {
            po::store(po::command_line_parser(argc, argv).
                    options(desc).positional(p).run(), vm);


            if (vm.count("help") || argc == 1) {
                std::cout << "Lutin Compiler" << std::endl;
                std::cout << "Usage: lutin [options] file" << std::endl;
                std::cout << desc << std::endl;
                return SUCCESS;
            }

            if(vm.count("execute")){
                std::cout << "--execute option specified" << std::endl;
            }

            if(vm.count("analyse")){
                std::cout << "--analyse option specified" << std::endl;
            }

            if(vm.count("optimize")){
                std::cout << "--optimize option specified" << std::endl;
            }

            if(vm.count("programme")){
                std::cout << "--program option specified" << std::endl;
            }

            if (vm.count("input-file")) {
                std::string filename = vm["input-file"].as<std::string>();
                std::cout << "--input-file spécified: " << filename << "\n";
            }


            po::notify(vm);
        }
        catch (po::error &e) {
            std::cerr << "ERROR: " << e.what() << std::endl << std::endl;
            std::cerr << desc << std::endl;
            return ERROR_IN_COMMAND_LINE;
        }


        cout << "More coming soon..." << endl;


    }
    catch (std::exception &e) {
        std::cerr << "Unhandled Exception reached the top of main: "
        << e.what() << ", application will now exit" << std::endl;
        return ERROR_UNHANDLED_EXCEPTION;

    }

    return SUCCESS;
}