#include "tile.h"

namespace td{

    Tile::Tile() {
        type = PLAIN;
    }

    Tile::Tile(int t) {
        switch (t) {
            case(0): type = PLAIN; break;
            case(1): type = WATER; break;
            case(2): type = MOUNTAIN; break;
            default: type = UNKNOWN; break;
        }
    }

    Tile::Tile(TileType tt) {
        type = tt;
    }

    int Tile::get_type() const {
        switch (type) {
            case PLAIN: return 0;
            case WATER: return 1;
            case MOUNTAIN: return 2;
            default: return 3;
        }
    }

    Building *Tile::get_building() const {
        return building;
    }


}
