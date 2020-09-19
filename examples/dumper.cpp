#include "spellnumber/spell_number_fuzz.hpp"

int main(int argc, char* argv[])
{
    roman_fuzz().dump(std::vector<std::string>(argv + 1, argv + argc));
}
