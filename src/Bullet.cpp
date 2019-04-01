// Generated from /ArcadeGameProject/src/Bullet.java
#include <Bullet.hpp>

#include <Collidable.hpp>
#include <Flea.hpp>
#include <Scorpion.hpp>
#include <Spider.hpp>
#include <java/awt/Color.hpp>
#include <java/awt/geom/Rectangle2D_Double.hpp>
#include <java/lang/NullPointerException.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

Bullet::Bullet(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

Bullet::Bullet(int32_t x, int32_t y, CentipedeComponent* comp) 
    : Bullet(*static_cast< ::default_init_tag* >(0))
{
    ctor(x,y,comp);
}

void Bullet::init()
{
    BULLET_COLOR = ::java::awt::Color::GRAY();
}

constexpr int32_t Bullet::BULLET_SPEED;

constexpr int32_t Bullet::BULLET_SIZE;

void Bullet::ctor(int32_t x, int32_t y, CentipedeComponent* comp)
{
    super::ctor(x, y, comp);
    init();
}

void Bullet::update()
{
    this->y -= BULLET_SPEED;
    this->sprite = new ::java::awt::geom::Rectangle2D_Double(this->x, this->y, BULLET_SIZE, BULLET_SIZE);
}

java::awt::Color* Bullet::getColor()
{
    return this->BULLET_COLOR;
}

void Bullet::collide(Collidable* collidable)
{
    npc(collidable)->collideWithBullet(this);
}

void Bullet::collideWithMushroom(Mushroom* m)
{
}

void Bullet::collideWithCharacter(PlayerCharacter* c)
{
}

void Bullet::collideWithBullet(Bullet* b)
{
}

void Bullet::collideWithSpider(Spider* s)
{
    npc(s)->die();
    this->die();
}

void Bullet::collideWithScorpion(Scorpion* s)
{
    npc(s)->die();
    this->die();
}

void Bullet::collideWithFlea(Flea* f)
{
    npc(f)->die();
    this->die();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* Bullet::class_()
{
    static ::java::lang::Class* c = ::class_(u"Bullet", 6);
    return c;
}

void Bullet::collideWithBoomerang(Boomerang* b)
{
    Instance::collideWithBoomerang(b);
}

void Bullet::collideWithCentipede(LinkedCentipede* c)
{
    Instance::collideWithCentipede(c);
}

void Bullet::collideWithGunPickup(GunPickup* g)
{
    Instance::collideWithGunPickup(g);
}

void Bullet::collideWithShotgunShell(ShotgunShell* s)
{
    Instance::collideWithShotgunShell(s);
}

java::lang::Class* Bullet::getClass0()
{
    return class_();
}

