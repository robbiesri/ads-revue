// Copyright (c) 2025 Robert Srinivasiah

#include <algorithm>
#include <cstdint>
#include <vector>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

TEST_CASE("Simple transforms")
{
    std::vector<uint32_t> input(100, static_cast<uint32_t>(5));

    std::ranges::transform(input, input.begin(), [](const uint32_t i) {
        return i * 5;
    });

    CHECK(input.front() == 5 * 5);
    CHECK(input.back() == 5 * 5);
}
