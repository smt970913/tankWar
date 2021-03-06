/*
 * Example player class
 */

#include "Board.h"
#include "Tank.h"

class player: public Tank {

public:
    player();
    ~player() = default;

    /*
     * this simple player class fires at the enemy every turn (regardless of ammo remaining)
     * and misses every time the other player is moving since it fires at where the enemy is, and
     * not where the enemy will be. Keep in mind that after you fire, the opponent gets a turn
     * (to possibly move out of the way), and then the bullet hits. This class uses the base class
     * fireAtOpp(sensors) method to fire at the current position of the enemy. Please note that
     * this only has the possibility of hitting the enemy if they 'sit' on their subsequent turn.
     */
    action doYourThing(const sensors&) override;
    string taunt(const string&) const override;



    /**Our own stuff **/
    action predictiveFire(const sensors&);
    void analyzeEnemyPosition(const sensors&);
    double enemyDistance(int col, int row, const sensors&);
    action evasion(const sensors&);
    bool inBounds(int x, int y);

private:
    // any data that I want to retain for my tank - probably want to store some tank state information
    map<int, location> positionList;

};
