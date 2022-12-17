#ifndef EA_ENEMY_H
#define EA_ENEMY_H
#include <vector>
#include <memory>
#include "tile.h"

namespace td{

    class Enemy{
    protected:
        bool  is_alive;
        float x;
        float y;
        float max_health;
        float current_health;
        float regeneration_speed;
        float move_speed;
        float castle_damage;

    public:
        //Enemy() = default;
        virtual bool get_is_alive() const = 0;
        float get_x() const {return x;};
        float get_castle_damage() const {return castle_damage * current_health;};
        void kill() {is_alive = false;};
        virtual int horizontal_index() const = 0;
        virtual int vertical_index() const = 0;
        virtual std::unique_ptr<Enemy> clone() const = 0;
        virtual void make_move(std::vector<Line> field) = 0;
    };

}

#endif
