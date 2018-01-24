#ifndef BULLET_H
#define BULLET_H

class Bullet
{
public:
    Bullet();
    Bullet(float, float, float);

    void shoot(float);

    void set_tx(float);
    void set_ty(float);
    void set_tz(float);

    float get_tx();
    float get_ty();
    float get_tz();

    void draw();

    void setcolor(float[]);

    void set_hyp(float);
    void set_adj(float);
    void set_opp(float);

    float get_hyp();
    float get_adj();
    float get_opp();

	void set_can_shoot(bool);
	bool get_can_shoot();
private:
    float translatex, translatey, translatez;
    float width, depth, height;
    float adjacent, opposite, hypotenuse;
	bool can_shoot;
    float color[3];
};

#endif
