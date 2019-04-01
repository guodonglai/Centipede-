// Generated from /ArcadeGameProject/src/Spider.java

#pragma once

#include <fwd-ArcadeGameProject.hpp>
#include <java/awt/fwd-ArcadeGameProject.hpp>
#include <java/lang/fwd-ArcadeGameProject.hpp>
#include <Instance.hpp>

struct default_init_tag;

class Spider
    : public Instance
{

public:
    typedef Instance super;

private:
    ::java::awt::Color* SPIDER_COLOR {  };
    static constexpr int32_t MOVEMENT_SPEED { int32_t(2) };
    int32_t movingSide {  };
    int32_t movingUp {  };
protected:
    void ctor(int32_t x, int32_t y, CentipedeComponent* comp);

public:
    void update() override;
    ::java::awt::Image* getImage() override;
    ::java::lang::String* toString() override;
    ::java::awt::Color* getColor() override;
    void collide(Collidable* c) override;
    void collideWithBullet(Bullet* b) override;
    void collideWithShotgunShell(ShotgunShell* s) override;
    void collideWithBoomerang(Boomerang* b) override;
    void collideWithCharacter(PlayerCharacter* c) override;

    // Generated
    Spider(int32_t x, int32_t y, CentipedeComponent* comp);
protected:
    Spider(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
};
