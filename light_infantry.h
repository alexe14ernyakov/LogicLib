#ifndef EA_LIGHT_INFANTRY_H
#define EA_LIGHT_INFANTRY_H
#include <memory>
#include <iostream>
#include "enemy.h"

namespace td {

    class Light_Infantry : public Enemy{
    private:
        float dodge_chance;

    public:
        Light_Infantry() = default;
        Light_Infantry(float x_pos, float y_pos);
        Light_Infantry(const Light_Infantry& source) = default;
        bool get_is_alive() const override;
        int horizontal_index() const override;
        int vertical_index() const override;
        std::unique_ptr<Enemy> clone() const override;
        void make_move(std::vector<Line> field) override;
    };

}

#endif
