// Generated from /ArcadeGameProject/src/LinkedCentipede.java

#pragma once

#include <fwd-ArcadeGameProject.hpp>
#include <java/awt/fwd-ArcadeGameProject.hpp>
#include <java/lang/fwd-ArcadeGameProject.hpp>
#include <Instance.hpp>

struct default_init_tag;

class LinkedCentipede
    : public Instance
{

public:
    typedef Instance super;
    static constexpr int32_t SPEED { int32_t(2) };

private:
    static ::java::awt::Color* CENTIPEDE_COLOR_;
    static ::java::awt::Color* HEAD_COLOR_;

public:
    static constexpr int32_t HEAD_SIZE { int32_t(20) };
    static constexpr int32_t DEFAULT_X { int32_t(440) };
    static constexpr int32_t DEFAULT_Y { int32_t(20) };
    static constexpr int32_t MOVEMENT_SPEED { int32_t(20) };
    static constexpr int32_t BORDER { int32_t(20) };
    static constexpr int32_t SCREEN_SIZE { int32_t(900) };

private:
    int32_t movingDown {  };
    int32_t movingSide {  };
    LinkedCentipede* nextSegment {  };
    int32_t prevX {  };
    int32_t prevY {  };
    int32_t timer {  };
    bool sick {  };
    bool dead {  };
    int32_t spawnTimer {  };
protected:
    void ctor(int32_t x, int32_t y, int32_t nSegments, CentipedeComponent* comp);

public:
    ::java::awt::Image* getImage() override;
protected:
    void ctor(int32_t nSegments, CentipedeComponent* component);

public:
    virtual int32_t getPrevX();
    virtual int32_t getPrevY();
    virtual int32_t getMovingSide();
    virtual void dropAndTurn();
    virtual void move();
    virtual void changeNextSegment(LinkedCentipede* c);
    virtual bool isDead();
    void update() override;
    ::java::awt::Color* getColor() override;
    ::java::lang::String* toString() override;
    void collideWithMushroom(Mushroom* m) override;
    virtual void breakSegment();
    void collideWithBullet(Bullet* b) override;
    void collideWithBoomerang(Boomerang* b) override;
    void collideWithShotgunShell(ShotgunShell* s) override;
    void collideWithCharacter(PlayerCharacter* c) override;

    // Generated
    LinkedCentipede(int32_t x, int32_t y, int32_t nSegments, CentipedeComponent* comp);
    LinkedCentipede(int32_t nSegments, CentipedeComponent* component);
protected:
    LinkedCentipede(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();
    static void clinit();
    static ::java::awt::Color*& CENTIPEDE_COLOR();
    static ::java::awt::Color*& HEAD_COLOR();

private:
    virtual ::java::lang::Class* getClass0();
};
