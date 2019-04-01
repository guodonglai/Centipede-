// Generated from /ArcadeGameProject/src/Boomerang.java

#pragma once

#include <fwd-ArcadeGameProject.hpp>
#include <java/awt/fwd-ArcadeGameProject.hpp>
#include <Instance.hpp>

struct default_init_tag;

class Boomerang
    : public Instance
{

public:
    typedef Instance super;

private:
    static constexpr int32_t BOOMERANG_SPEED { int32_t(5) };
    ::java::awt::Color* BOOMERANG_COLOR {  };
    static constexpr int32_t BOOMERANG_SIZE { int32_t(15) };
    static constexpr int32_t RETURN_TIME { int32_t(100) };
    int32_t timer {  };
    PlayerCharacter* player {  };
protected:
    void ctor(PlayerCharacter* player, int32_t x, int32_t y, CentipedeComponent* comp);

public:
    void update() override;
    ::java::awt::Color* getColor() override;
    void collide(Collidable* collidable) override;
    void collideWithCentipede(LinkedCentipede* c) override;
    void collideWithSpider(Spider* s) override;
    ::java::awt::Image* getImage() override;
    void collideWithScorpion(Scorpion* s) override;
    void collideWithFlea(Flea* f) override;

    // Generated
    Boomerang(PlayerCharacter* player, int32_t x, int32_t y, CentipedeComponent* comp);
protected:
    Boomerang(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
};
