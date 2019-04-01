// Generated from /ArcadeGameProject/src/Flea.java

#pragma once

#include <fwd-ArcadeGameProject.hpp>
#include <java/awt/fwd-ArcadeGameProject.hpp>
#include <Instance.hpp>

struct default_init_tag;

class Flea
    : public Instance
{

public:
    typedef Instance super;

private:
    static constexpr int32_t MOVEMENT_SPEED { int32_t(1) };
    ::java::awt::Color* FLEA_COLOR {  };
    int32_t MushroomTimer {  };
    CentipedeComponent* comp {  };
protected:
    void ctor(int32_t x, int32_t y, CentipedeComponent* comp);

public:
    void update() override;
    ::java::awt::Image* getImage() override;
    ::java::awt::Color* getColor() override;
    void collideWithCharacter(PlayerCharacter* c) override;
    void collideWithBullet(Bullet* b) override;
    void collideWithShotgunShell(ShotgunShell* s) override;
    void collideWithBoomerang(Boomerang* b) override;

    // Generated
    Flea(int32_t x, int32_t y, CentipedeComponent* comp);
protected:
    Flea(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
};
