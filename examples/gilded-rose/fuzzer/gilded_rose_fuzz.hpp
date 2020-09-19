#pragma once

#include "GildedRose.h"
#include <fuzzcover/fuzzcover.hpp>

std::ostream& operator<<(std::ostream& os, const Item& obj)
{
    return os
           << "name: " << obj.name
           << ", sellIn: " << obj.sellIn
           << ", quality: " << obj.quality;
}

class gilded_rose_fuzz : public fuzzcover::fuzzcover_interface<Item>
{
  public:
    test_input_t value_from_bytes(const std::uint8_t* data, std::size_t size) override
    {
        FuzzedDataProvider data_provider(data, size);
        auto sellIn = data_provider.ConsumeIntegral<int>();
        auto quality = data_provider.ConsumeIntegralInRange<int>(0, 50);
        Item test_item(data_provider.ConsumeRemainingBytesAsString(), sellIn, quality);
        return test_item;
    }

    void test_function(const test_input_t& value) override
    {
        GildedRose({value}).updateQuality();
    }
};
