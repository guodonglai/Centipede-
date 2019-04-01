// Generated from /ArcadeGameProject/src/GunPickup.java
#include <GunPickup.hpp>

#include <Collidable.hpp>
#include <PlayerCharacter.hpp>
#include <java/awt/Color.hpp>
#include <java/awt/Image.hpp>
#include <java/awt/Toolkit.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/util/HashMap.hpp>

template<typename T, typename U>
static T java_cast(U* u)
{
    if(!u) return static_cast<T>(nullptr);
    auto t = dynamic_cast<T>(u);
    if(!t) throw new ::java::lang::ClassCastException();
    return t;
}

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

GunPickup::GunPickup(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

GunPickup::GunPickup(int32_t gunID, int32_t x, int32_t y, CentipedeComponent* comp) 
    : GunPickup(*static_cast< ::default_init_tag* >(0))
{
    ctor(gunID,x,y,comp);
}

constexpr int32_t GunPickup::PISTOL_NUMBER;

constexpr int32_t GunPickup::SHOTGUN_NUMBER;

constexpr int32_t GunPickup::BOOMERANG_NUMBER;

void GunPickup::ctor(int32_t gunID, int32_t x, int32_t y, CentipedeComponent* comp)
{
    super::ctor(x, y, comp);
    this->gunID = gunID;
    this->colorMap = new ::java::util::HashMap();
    npc(java_cast< ::java::util::HashMap* >(this->colorMap))->put(::java::lang::Integer::valueOf(PISTOL_NUMBER), static_cast< ::java::lang::Object* >(::java::awt::Color::BLACK()));
    npc(java_cast< ::java::util::HashMap* >(this->colorMap))->put(::java::lang::Integer::valueOf(SHOTGUN_NUMBER), static_cast< ::java::lang::Object* >(::java::awt::Color::GRAY()));
    npc(java_cast< ::java::util::HashMap* >(this->colorMap))->put(::java::lang::Integer::valueOf(BOOMERANG_NUMBER), static_cast< ::java::lang::Object* >(::java::awt::Color::WHITE()));
}

java::awt::Image* GunPickup::getImage()
{
    if(this->gunID == PISTOL_NUMBER) {
        return npc(::java::awt::Toolkit::getDefaultToolkit())->getImage(u"src/Pistol.png"_j);
    }
    if(this->gunID == SHOTGUN_NUMBER) {
        return npc(::java::awt::Toolkit::getDefaultToolkit())->getImage(u"src/Shotgun.png"_j);
    }
    return npc(::java::awt::Toolkit::getDefaultToolkit())->getImage(u"src/Boomerang.png"_j);
}

java::awt::Color* GunPickup::getColor()
{
    return java_cast< ::java::awt::Color* >(npc(java_cast< ::java::util::HashMap* >(this->colorMap))->get(::java::lang::Integer::valueOf(gunID)));
}

int32_t GunPickup::getGunID()
{
    return this->gunID;
}

void GunPickup::collide(Collidable* collidable)
{
    npc(collidable)->collideWithGunPickup(this);
}

void GunPickup::collideWithCharacter(PlayerCharacter* c)
{
    this->die();
    npc(c)->changeGun(this->gunID);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* GunPickup::class_()
{
    static ::java::lang::Class* c = ::class_(u"GunPickup", 9);
    return c;
}

java::lang::Class* GunPickup::getClass0()
{
    return class_();
}

