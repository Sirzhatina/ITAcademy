#pragma once

struct Data {
    char id;
    int value;

    bool operator<(const Data& rhs) const {
        return value < rhs.value;
    }
};