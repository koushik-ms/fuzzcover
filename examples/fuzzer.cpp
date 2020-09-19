#include "spellnumber/spell_number_fuzz.hpp"

extern "C" int
LLVMFuzzerTestOneInput(const std::uint8_t* data, std::size_t size)
{
    roman_fuzz().fuzz(data, size);
    return 0;
}
