#ifndef EA_TILE_H
#define EA_TILE_H
#include <vector>
#include "building.h"

namespace td{

    enum TileType{
        PLAIN,
        WATER,
        MOUNTAIN,
        UNKNOWN
    };

    class Tile{
    private:
        TileType  type = PLAIN;
        Building* building = nullptr;

    public:
        Tile();
        Tile(int t);
        Tile(TileType tt);
        int get_type() const;
        Building* get_building() const;
    };

    typedef struct Line{
        std::vector<Tile> line;
    } Line;
}
#endif
