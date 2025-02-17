#pragma once
#include <stdint.h>
#include "../../lib/uint24.h"

struct EventPack {
    uint24_t cordAddress;
    uint24_t textAddress;
};

struct EventCords {
    uint8_t x, y, spriteIndex;
};

class Event {
  public:
    EventCords cords;
    uint24_t textAddress;

    void loadEvent(uint8_t index, uint8_t subIndex, uint8_t eventIndex);
    void draw(int16_t mapx, int16_t mapy);
};
