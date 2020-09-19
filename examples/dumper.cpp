#include "gilded-rose/fuzzer/gilded_rose_fuzz.hpp"

int main(int argc, char* argv[])
{
    gilded_rose_fuzz().dump(std::vector<std::string>(argv + 1, argv + argc));
}
