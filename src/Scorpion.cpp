// Generated from /ArcadeGameProject/src/Scorpion.java
#include <Scorpion.hpp>

#include <Boomerang.hpp>
#include <Bullet.hpp>
#include <CentipedeComponent.hpp>
#include <Collidable.hpp>
#include <PlayerCharacter.hpp>
#include <ShotgunShell.hpp>
#include <java/awt/Color.hpp>
#include <java/awt/Image.hpp>
#include <java/awt/Toolkit.hpp>
#include <java/awt/geom/Rectangle2D_Double.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

Scorpion::Scorpion(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

Scorpion::Scorpion(int32_t x, int32_t y, CentipedeComponent* comp) 
    : Scorpion(*static_cast< ::default_init_tag* >(0))
{
    ctor(x,y,comp);
}

void Scorpion::init()
{
    SCORPION_COLOR = ::java::awt::Color::RED();
}

constexpr int32_t Scorpion::MOVEMENT_SPEED;

void Scorpion::ctor(int32_t x, int32_t y, CentipedeComponent* comp)
{
    super::ctor(x, y, comp);
    init();
    this->direction = -int32_t(1);
}

void Scorpion::update()
{
    if(this->x <= 0 || this->x >= 900) {
        this->direction *= -int32_t(1);
    }
    this->x += MOVEMENT_SPEED * this->direction;
    this->sprite = new ::java::awt::geom::Rectangle2D_Double(this->x, this->y, int32_t(20), int32_t(20));
}

java::awt::Image* Scorpion::getImage()
{
    return npc(::java::awt::Toolkit::getDefaultToolkit())->getImage(u"src/Scorpion.png"_j);
}

java::awt::Color* Scorpion::getColor()
{
    return SCORPION_COLOR;
}

java::lang::String* Scorpion::toString()
{
    return u"Scorpion"_j;
}

void Scorpion::collide(Collidable* c)
{
    npc(c)->collideWithScorpion(this);
}

void Scorpion::collideWithBullet(Bullet* b)
{
    npc(npc(this->comp)->getCharacter())->addScore(5);
    npc(b)->die();
    this->die();
}

void Scorpion::collideWithShotgunShell(ShotgunShell* s)
{
    npc(npc(this->comp)->getCharacter())->addScore(5);
    npc(s)->die();
    this->die();
}

void Scorpion::collideWithBoomerang(Boomerang* b)
{
    npc(npc(this->comp)->getCharacter())->addScore(5);
    npc(b)->die();
    this->die();
}

void Scorpion::collideWithCharacter(PlayerCharacter* c)
{
    npc(c)->hitByEnemy();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* Scorpion::class_()
{
    static ::java::lang::Class* c = ::class_(u"Scorpion", 8);
    return c;
}

java::lang::Class* Scorpion::getClass0()
{
    return class_();
}

