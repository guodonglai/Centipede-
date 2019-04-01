// Generated from /ArcadeGameProject/src/Spider.java
#include <Spider.hpp>

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

Spider::Spider(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

Spider::Spider(int32_t x, int32_t y, CentipedeComponent* comp) 
    : Spider(*static_cast< ::default_init_tag* >(0))
{
    ctor(x,y,comp);
}

void Spider::init()
{
    SPIDER_COLOR = ::java::awt::Color::PINK();
}

constexpr int32_t Spider::MOVEMENT_SPEED;

void Spider::ctor(int32_t x, int32_t y, CentipedeComponent* comp)
{
    super::ctor(x, y, comp);
    init();
    this->movingSide = 1;
    this->movingUp = -int32_t(1);
}

void Spider::update()
{
    this->x += MOVEMENT_SPEED * this->movingSide;
    this->y += MOVEMENT_SPEED * this->movingUp;
    this->sprite = new ::java::awt::geom::Rectangle2D_Double(this->x, this->y, int32_t(20), int32_t(20));
    if(this->x >= 880 || this->x <= 20) {
        this->movingSide *= -int32_t(1);
    }
    if(this->y >= 880 || this->y <= 600) {
        this->movingUp *= -int32_t(1);
    }
}

java::awt::Image* Spider::getImage()
{
    return npc(::java::awt::Toolkit::getDefaultToolkit())->getImage(u"src/Spider.png"_j);
}

java::lang::String* Spider::toString()
{
    return u"SPIDER"_j;
}

java::awt::Color* Spider::getColor()
{
    return SPIDER_COLOR;
}

void Spider::collide(Collidable* c)
{
    npc(c)->collideWithSpider(this);
}

void Spider::collideWithBullet(Bullet* b)
{
    npc(npc(this->comp)->getCharacter())->addScore(5);
    npc(b)->die();
    this->die();
}

void Spider::collideWithShotgunShell(ShotgunShell* s)
{
    npc(npc(this->comp)->getCharacter())->addScore(5);
    npc(s)->die();
    this->die();
}

void Spider::collideWithBoomerang(Boomerang* b)
{
    npc(npc(this->comp)->getCharacter())->addScore(5);
    npc(b)->die();
    this->die();
}

void Spider::collideWithCharacter(PlayerCharacter* c)
{
    npc(c)->hitByEnemy();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* Spider::class_()
{
    static ::java::lang::Class* c = ::class_(u"Spider", 6);
    return c;
}

java::lang::Class* Spider::getClass0()
{
    return class_();
}

