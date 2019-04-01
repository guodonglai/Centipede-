// Generated from /ArcadeGameProject/src/Collidable.java

#pragma once

#include <fwd-ArcadeGameProject.hpp>
#include <java/lang/Object.hpp>

struct Collidable
    : public virtual ::java::lang::Object
{
    virtual void collide(Collidable* collidable) = 0;
    virtual void collideWithMushroom(Mushroom* m) = 0;
    virtual void collideWithCharacter(PlayerCharacter* c) = 0;
    virtual void collideWithBullet(Bullet* b) = 0;
    virtual void collideWithCentipede(LinkedCentipede* c) = 0;
    virtual void collideWithShotgunShell(ShotgunShell* s) = 0;
    virtual void collideWithBoomerang(Boomerang* b) = 0;
    virtual void collideWithGunPickup(GunPickup* g) = 0;
    virtual void collideWithSpider(Spider* s) = 0;
    virtual void collideWithScorpion(Scorpion* s) = 0;
    virtual void collideWithFlea(Flea* f) = 0;

    // Generated
    static ::java::lang::Class *class_();
};
