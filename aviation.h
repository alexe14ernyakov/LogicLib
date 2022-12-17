#ifndef EA_AVIATION_H
#define EA_AVIATION_H
#include "enemy.h"

namespace td {

    class Aviation : public Enemy {
    private:
        int   ammunition;
        float damage;

    public:
        Aviation(float x_pos, float y_pos);
        bool get_is_alive() const override;
        int horizontal_index() const override;
        int vertical_index() const override;
        std::unique_ptr<Enemy> clone() const override;
        void make_move(std::vector<Line> field) override;
    };

}

#endif
