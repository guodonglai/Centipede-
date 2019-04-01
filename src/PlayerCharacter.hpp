// Generated from /ArcadeGameProject/src/PlayerCharacter.java

#pragma once

#include <fwd-ArcadeGameProject.hpp>
#include <java/awt/fwd-ArcadeGameProject.hpp>
#include <java/util/fwd-ArcadeGameProject.hpp>
#include <Instance.hpp>
#include <Moveable.hpp>
#include <Collidable.hpp>

struct default_init_tag;

class PlayerCharacter
    : public Instance
    , public virtual Moveable
    , public virtual Collidable
{

public:
    typedef Instance super;

private:
    static ::java::awt::Color* HERO_COLOR_;
    static constexpr int32_t DEFAULT_X { int32_t(424) };
    static constexpr int32_t DEFAULT_Y { int32_t(800) };
    static constexpr int32_t RELOAD_FRAMES { int32_t(20) };
    static constexpr int32_t PISTOL_NUMBER { int32_t(1) };
    static constexpr int32_t SHOTGUN_NUMBER { int32_t(2) };
    static constexpr int32_t BOOMERANG_NUMBER { int32_t(3) };
    static constexpr int32_t ANIMATION_TIME { int32_t(30) };
    bool isFiring {  };
    int32_t timer {  };
    int32_t prevX {  };
    int32_t prevY {  };
    int32_t gunNumber {  };
    int32_t animationTimer {  };
    int32_t life {  };
    int32_t score {  };
protected:
    void ctor(CentipedeComponent* comp);

public:
    virtual void readMap(::java::util::HashMap* hashMap);
    virtual int32_t getLives();
    virtual void hitByEnemy();
    virtual int32_t getScore();
    virtual void addScore(int32_t i);
    ::java::awt::Color* getColor() override;
    virtual int32_t getGunID();
    ::java::awt::Image* getImage() override;
    virtual bool getFiring();
    virtual void addTimer();
    void update() override;
    virtual void stop();
    void collide(Collidable* collidable) override;
    void collideWithMushroom(Mushroom* m) override;
    void collideWithCharacter(PlayerCharacter* c) override;
    void collideWithBullet(Bullet* b) override;
    void collideWithCentipede(LinkedCentipede* c) override;
    virtual int32_t getGunNumber();
    virtual void changeGun(int32_t gunNum);

    // Generated
    PlayerCharacter(CentipedeComponent* comp);
protected:
    PlayerCharacter(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();
    virtual void collideWithBoomerang(Boomerang* b);
    virtual void collideWithFlea(Flea* f);
    virtual void collideWithGunPickup(GunPickup* g);
    virtual void collideWithScorpion(Scorpion* s);
    virtual void collideWithShotgunShell(ShotgunShell* s);
    virtual void collideWithSpider(Spider* s);
    virtual void moveDown();
    virtual void moveLeft();
    virtual void moveRight();
    virtual void moveUp();

private:
    static ::java::awt::Color*& HERO_COLOR();
    virtual ::java::lang::Class* getClass0();
};
