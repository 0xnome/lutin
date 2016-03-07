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
                ("help", "Print help messages")
                ("programme", "Display the program as it should looks like in memory")
                ("execute", "interactive execution")
                ("analyse", "static program analysis")
                ("optimize", "optimize the program");

        po::variables_map vm;
        try {
            po::store(po::parse_command_line(argc, argv, desc),
                      vm); // can throw

            /** --help option
             */
            if (vm.count("help")) {
                std::cout << "Lutin Compiler" << std::endl
                << desc << std::endl;
                return SUCCESS;
            }

            po::notify(vm);
            // throws on error, so do after help in case
            // there are any problems
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