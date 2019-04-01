// Generated from /ArcadeGameProject/src/ShotgunShell.java

#pragma once

#include <fwd-ArcadeGameProject.hpp>
#include <java/awt/fwd-ArcadeGameProject.hpp>
#include <Instance.hpp>

struct default_init_tag;

class ShotgunShell
    : public Instance
{

public:
    typedef Instance super;

private:
    static constexpr int32_t BULLET_SPEED { int32_t(10) };
    ::java::awt::Color* BULLET_COLOR {  };
    static constexpr int32_t BULLET_SIZE { int32_t(15) };
    static constexpr int32_t NUMBER_OF_BULLETS { int32_t(5) };
    static constexpr int32_t BULLET_TIME { int32_t(25) };
    int32_t angle {  };
    int32_t timer {  };
protected:
    void ctor(int32_t bulletNum, int32_t x, int32_t y, CentipedeComponent* comp);

public:
    void update() override;
    ::java::awt::Color* getColor() override;
    void collide(Collidable* collidable) override;
    void collideWithSpider(Spider* s) override;
    void collideWithScorpion(Scorpion* s) override;
    void collideWithFlea(Flea* f) override;

    // Generated
    ShotgunShell(int32_t bulletNum, int32_t x, int32_t y, CentipedeComponent* comp);
protected:
    ShotgunShell(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
};
