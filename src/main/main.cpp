#include <iostream>
#include <string>
#include <unordered_map>
#include <functional>

#include "../include/chdir.h"
#include "../include/lstat.h"

constexpr auto CLI_VERSION = "0.0.3";


void
fetch_command()
{
    init_st();
    directory_traversal();
    print_lines_per_language();
}


void
print_help() {
    std::cout <<
        "LangStat CLI\n"
        "Commands:\n"
        "  --fetch,  -f     Fetch statistics\n"
        "  --version,-v     Show version\n"
        "  --help,   -h     Show this help\n";
}


int
main(const int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "Expected exactly one argument\n";
        return 1;
    }

    const std::string command = argv[1];

    const std::unordered_map<std::string, std::function<void()>> commands =
    {
        {"--fetch", fetch_command},
        {"--f", fetch_command},
        {"--version", [] { std::cout << "LangStat Version: " << CLI_VERSION << '\n'; }},
        {"-v",        [] { std::cout << "LangStat Version: " << CLI_VERSION << '\n'; }},
        {"--help",    print_help},
        {"-h",        print_help},
    };

    if (const auto it = commands.find(command); it != commands.end())
    {
        it->second();
        return 0;
    }

    std::cerr << "Command not found. User --help\n";
    return 1;
}