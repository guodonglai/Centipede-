// Generated from /ArcadeGameProject/src/ShotgunShell.java
#include <ShotgunShell.hpp>

#include <Collidable.hpp>
#include <Flea.hpp>
#include <Scorpion.hpp>
#include <Spider.hpp>
#include <java/awt/Color.hpp>
#include <java/awt/geom/Rectangle2D_Double.hpp>
#include <java/lang/Math.hpp>
#include <java/lang/NullPointerException.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

ShotgunShell::ShotgunShell(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

ShotgunShell::ShotgunShell(int32_t bulletNum, int32_t x, int32_t y, CentipedeComponent* comp) 
    : ShotgunShell(*static_cast< ::default_init_tag* >(0))
{
    ctor(bulletNum,x,y,comp);
}

void ShotgunShell::init()
{
    BULLET_COLOR = ::java::awt::Color::GRAY();
}

constexpr int32_t ShotgunShell::BULLET_SPEED;

constexpr int32_t ShotgunShell::BULLET_SIZE;

constexpr int32_t ShotgunShell::NUMBER_OF_BULLETS;

constexpr int32_t ShotgunShell::BULLET_TIME;

void ShotgunShell::ctor(int32_t bulletNum, int32_t x, int32_t y, CentipedeComponent* comp)
{
    super::ctor(x, y, comp);
    init();
    this->angle = int32_t(60) + bulletNum * (int32_t(60) / NUMBER_OF_BULLETS);
    this->timer = 0;
}

void ShotgunShell::update()
{
    if(this->timer == BULLET_TIME) {
        this->die();
    }
    this->timer++;
    this->x += BULLET_SPEED * ::java::lang::Math::cos(::java::lang::Math::toRadians(this->angle));
    this->y -= BULLET_SPEED * ::java::lang::Math::sin(::java::lang::Math::toRadians(this->angle));
    this->sprite = new ::java::awt::geom::Rectangle2D_Double(this->x, this->y, BULLET_SIZE, BULLET_SIZE);
}

java::awt::Color* ShotgunShell::getColor()
{
    return BULLET_COLOR;
}

void ShotgunShell::collide(Collidable* collidable)
{
    npc(collidable)->collideWithShotgunShell(this);
}

void ShotgunShell::collideWithSpider(Spider* s)
{
    npc(s)->die();
    this->die();
}

void ShotgunShell::collideWithScorpion(Scorpion* s)
{
    npc(s)->die();
    this->die();
}

void ShotgunShell::collideWithFlea(Flea* f)
{
    npc(f)->die();
    this->die();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* ShotgunShell::class_()
{
    static ::java::lang::Class* c = ::class_(u"ShotgunShell", 12);
    return c;
}

java::lang::Class* ShotgunShell::getClass0()
{
    return class_();
}

