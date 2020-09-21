#pragma once

#include "gilded-rose/src/GildedRose.h"
#include <fuzzcover/fuzzcover.hpp>

std::ostream& operator<<(std::ostream& os, const Item& obj)
{
    return os
           << "name: " << obj.name
           << ", sellIn: " << obj.sellIn
           << ", quality: " << obj.quality;
}

void to_json(nlohmann::json &j, const Item &i) {
    j = nlohmann::json({
        {"name", i.name},
        {"sellIn", i.sellIn},
        {"quality", i.quality}
    });
}

void from_json(const nlohmann::json &j, Item& i) {
    j.at("name").get_to(i.name);
    j.at("sellIn").get_to(i.sellIn);
    j.at("quality").get_to(i.quality);
}

class gilded_rose_fuzz : public fuzzcover::fuzzcover_interface<Item>
{
  public:
    test_input_t value_from_bytes(const std::uint8_t* data, std::size_t size) override
    {
        FuzzedDataProvider data_provider(data, size);
        auto sellIn = data_provider.ConsumeIntegralInRange<int>(-1000, 1000);
        auto quality = data_provider.ConsumeIntegralInRange<int>(0, 50);
        auto name = data_provider.PickValueInArray({
            "Aged Brie",
            "Backstage passes to a TAFKAL80ETC concert",
            "Sulfuras, Hand of Ragnaros",
            "+5 Protection"
        });
        Item test_item(name, sellIn, quality);
        return test_item;
    }

    void test_function(const test_input_t& value) override
    {
        std::vector<Item> items{value};
        GildedRose(items).updateQuality();
    }
};
