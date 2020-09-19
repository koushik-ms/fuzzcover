#include "spellnumber/spell_number_fuzz.hpp"

int main(int argc, char* argv[])
{
    roman_fuzz().test(std::vector<std::string>(argv + 1, argv + argc));
}
