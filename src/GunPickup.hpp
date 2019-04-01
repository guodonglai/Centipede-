// Generated from /ArcadeGameProject/src/GunPickup.java

#pragma once

#include <fwd-ArcadeGameProject.hpp>
#include <java/awt/fwd-ArcadeGameProject.hpp>
#include <java/util/fwd-ArcadeGameProject.hpp>
#include <Instance.hpp>

struct default_init_tag;

class GunPickup
    : public Instance
{

public:
    typedef Instance super;

private:
    static constexpr int32_t PISTOL_NUMBER { int32_t(1) };
    static constexpr int32_t SHOTGUN_NUMBER { int32_t(2) };
    static constexpr int32_t BOOMERANG_NUMBER { int32_t(3) };
    ::java::util::HashMap* colorMap {  };
    int32_t gunID {  };
protected:
    void ctor(int32_t gunID, int32_t x, int32_t y, CentipedeComponent* comp);

public:
    ::java::awt::Image* getImage() override;
    ::java::awt::Color* getColor() override;
    virtual int32_t getGunID();
    void collide(Collidable* collidable) override;
    void collideWithCharacter(PlayerCharacter* c) override;

    // Generated
    GunPickup(int32_t gunID, int32_t x, int32_t y, CentipedeComponent* comp);
protected:
    GunPickup(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
