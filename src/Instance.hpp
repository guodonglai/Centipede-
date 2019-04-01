// Generated from /ArcadeGameProject/src/Instance.java

#pragma once

#include <fwd-ArcadeGameProject.hpp>
#include <java/awt/fwd-ArcadeGameProject.hpp>
#include <java/awt/geom/fwd-ArcadeGameProject.hpp>
#include <java/lang/fwd-ArcadeGameProject.hpp>
#include <java/lang/Object.hpp>
#include <Moveable.hpp>
#include <Collidable.hpp>

struct default_init_tag;

class Instance
    : public virtual ::java::lang::Object
    , public virtual Moveable
    , public virtual Collidable
{

public:
    typedef ::java::lang::Object super;

private:
    static constexpr int32_t BLOCK_SIZE { int32_t(20) };
    static constexpr int32_t SPEED { int32_t(2) };
    ::java::awt::Color* DEFAULT_COLOR {  };

public:
    CentipedeComponent* comp {  };
    int32_t x {  };
    int32_t y {  };
    ::java::awt::geom::Rectangle2D_Double* sprite {  };

public: /* protected */
    int32_t BlockSIZE {  };
protected:
    void ctor(int32_t x, int32_t y, CentipedeComponent* comp);

public:
    virtual bool isInPlayerArea();
    virtual int32_t getX();
    virtual int32_t getY();
    virtual ::java::awt::Image* getImage();
    virtual ::java::awt::geom::Rectangle2D_Double* getSprite();
    virtual void update();
    virtual ::java::awt::Color* getColor();
    virtual void die();
    ::java::lang::String* toString() override;
    void moveUp() override;
    void moveRight() override;
    void moveDown() override;
    void moveLeft() override;
    void collide(Collidable* collidable) override;
    void collideWithMushroom(Mushroom* m) override;
    void collideWithCharacter(PlayerCharacter* c) override;
    void collideWithBullet(Bullet* b) override;
    void collideWithCentipede(LinkedCentipede* c) override;
    void collideWithShotgunShell(ShotgunShell* s) override;
    void collideWithBoomerang(Boomerang* b) override;
    void collideWithGunPickup(GunPickup* g) override;
    void collideWithSpider(Spider* s) override;
    void collideWithScorpion(Scorpion* s) override;
    void collideWithFlea(Flea* f) override;

    // Generated
    Instance(int32_t x, int32_t y, CentipedeComponent* comp);
protected:
    Instance(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
};
