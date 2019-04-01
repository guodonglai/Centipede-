// Generated from /ArcadeGameProject/src/Scorpion.java

#pragma once

#include <fwd-ArcadeGameProject.hpp>
#include <java/awt/fwd-ArcadeGameProject.hpp>
#include <java/lang/fwd-ArcadeGameProject.hpp>
#include <Instance.hpp>

struct default_init_tag;

class Scorpion
    : public Instance
{

public:
    typedef Instance super;

private:
    static constexpr int32_t MOVEMENT_SPEED { int32_t(2) };
    ::java::awt::Color* SCORPION_COLOR {  };
    int32_t direction {  };
protected:
    void ctor(int32_t x, int32_t y, CentipedeComponent* comp);

public:
    void update() override;
    ::java::awt::Image* getImage() override;
    ::java::awt::Color* getColor() override;
    ::java::lang::String* toString() override;
    void collide(Collidable* c) override;
    void collideWithBullet(Bullet* b) override;
    void collideWithShotgunShell(ShotgunShell* s) override;
    void collideWithBoomerang(Boomerang* b) override;
    void collideWithCharacter(PlayerCharacter* c) override;

    // Generated
    Scorpion(int32_t x, int32_t y, CentipedeComponent* comp);
protected:
    Scorpion(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
};
