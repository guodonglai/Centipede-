// Generated from /ArcadeGameProject/src/Bullet.java

#pragma once

#include <fwd-ArcadeGameProject.hpp>
#include <java/awt/fwd-ArcadeGameProject.hpp>
#include <Instance.hpp>
#include <Collidable.hpp>

struct default_init_tag;

class Bullet
    : public Instance
    , public virtual Collidable
{

public:
    typedef Instance super;

private:
    static constexpr int32_t BULLET_SPEED { int32_t(10) };
    ::java::awt::Color* BULLET_COLOR {  };
    static constexpr int32_t BULLET_SIZE { int32_t(15) };
protected:
    void ctor(int32_t x, int32_t y, CentipedeComponent* comp);

public:
    void update() override;
    ::java::awt::Color* getColor() override;
    void collide(Collidable* collidable) override;
    void collideWithMushroom(Mushroom* m) override;
    void collideWithCharacter(PlayerCharacter* c) override;
    void collideWithBullet(Bullet* b) override;
    void collideWithSpider(Spider* s) override;
    void collideWithScorpion(Scorpion* s) override;
    void collideWithFlea(Flea* f) override;

    // Generated
    Bullet(int32_t x, int32_t y, CentipedeComponent* comp);
protected:
    Bullet(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();

public:
    virtual void collideWithBoomerang(Boomerang* b);
    virtual void collideWithCentipede(LinkedCentipede* c);
    virtual void collideWithGunPickup(GunPickup* g);
    virtual void collideWithShotgunShell(ShotgunShell* s);

private:
    virtual ::java::lang::Class* getClass0();
};
