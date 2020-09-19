#include "gilded-rose/fuzzer/gilded_rose_fuzz.hpp"

extern "C" int LLVMFuzzerTestOneInput(const std::uint8_t* data, std::size_t size)
{
    gilded_rose_fuzz().fuzz(data, size);
    return 0;
}
