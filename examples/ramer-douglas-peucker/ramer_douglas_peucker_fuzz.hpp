#pragma once

#define private public

#include <fuzzcover/fuzzcover.hpp>
#include "ramer_douglas_peucker.hpp"

  class ramer_douglas_peucker_fuzz : public fuzzcover::fuzzcover_interface<std::tuple<std::vector<Point>, double>>
{
  public:
    test_input_t value_from_bytes(const std::uint8_t* data, std::size_t size) override
    {
        FuzzedDataProvider data_provider(data, size);
        const auto epsilon = data_provider.ConsumeFloatingPointInRange<double>(0.0, 1.0);

        std::vector<Point> points;
        while (data_provider.remaining_bytes() > 0)
        {
            points.emplace_back(data_provider.ConsumeFloatingPointInRange<double>(-5.0, 5.0),
                data_provider.ConsumeFloatingPointInRange<double>(-5.0, 5.0));
        }

        return {points, epsilon};
    }

    void test_function(const test_input_t& value) override
    {
        std::vector<Point> pointListOut;
        try {
            RamerDouglasPeucker(std::get<0>(value), std::get<1>(value), pointListOut);
        }
        catch (...)
        {}
    }
};
