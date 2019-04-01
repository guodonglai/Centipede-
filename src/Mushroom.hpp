// Generated from /ArcadeGameProject/src/Mushroom.java

#pragma once

#include <fwd-ArcadeGameProject.hpp>
#include <java/awt/fwd-ArcadeGameProject.hpp>
#include <java/lang/fwd-ArcadeGameProject.hpp>
#include <Instance.hpp>
#include <Collidable.hpp>

struct default_init_tag;

class Mushroom
    : public Instance
    , public virtual Collidable
{

public:
    typedef Instance super;

private:
    ::java::awt::Color* NORMAL_COLOR {  };
    ::java::awt::Color* POISONED_COLOR {  };
    int32_t life {  };
    bool isPoisoned {  };
protected:
    void ctor(int32_t x, int32_t y, CentipedeComponent* comp);

public:
    virtual bool getPoisonedStatus();
    ::java::awt::Image* getImage() override;
    ::java::lang::String* toString() override;
    void update() override;
    ::java::awt::Color* getColor() override;
    void collide(Collidable* collidable) override;
    void collideWithMushroom(Mushroom* m) override;
    void collideWithCharacter(PlayerCharacter* c) override;
    void collideWithBullet(Bullet* b) override;
    void collideWithBoomerang(Boomerang* b) override;
    void collideWithShotgunShell(ShotgunShell* s) override;
    void collideWithCentipede(LinkedCentipede* c) override;
    void collideWithSpider(Spider* s) override;
    void collideWithScorpion(Scorpion* s) override;

    // Generated
    Mushroom(int32_t x, int32_t y, CentipedeComponent* comp);
protected:
    Mushroom(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();

public:
    virtual void collideWithFlea(Flea* f);
    virtual void collideWithGunPickup(GunPickup* g);

private:
    virtual ::java::lang::Class* getClass0();
};
