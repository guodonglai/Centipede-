// Generated from /ArcadeGameProject/src/Boomerang.java
#include <Boomerang.hpp>

#include <Collidable.hpp>
#include <Flea.hpp>
#include <LinkedCentipede.hpp>
#include <PlayerCharacter.hpp>
#include <Scorpion.hpp>
#include <Spider.hpp>
#include <java/awt/Color.hpp>
#include <java/awt/Image.hpp>
#include <java/awt/Toolkit.hpp>
#include <java/awt/geom/Rectangle2D_Double.hpp>
#include <java/awt/geom/Rectangle2D.hpp>
#include <java/lang/Math.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

Boomerang::Boomerang(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

Boomerang::Boomerang(PlayerCharacter* player, int32_t x, int32_t y, CentipedeComponent* comp) 
    : Boomerang(*static_cast< ::default_init_tag* >(0))
{
    ctor(player,x,y,comp);
}

void Boomerang::init()
{
    BOOMERANG_COLOR = ::java::awt::Color::YELLOW();
}

constexpr int32_t Boomerang::BOOMERANG_SPEED;

constexpr int32_t Boomerang::BOOMERANG_SIZE;

constexpr int32_t Boomerang::RETURN_TIME;

void Boomerang::ctor(PlayerCharacter* player, int32_t x, int32_t y, CentipedeComponent* comp)
{
    super::ctor(x, y, comp);
    init();
    this->timer = 0;
    this->player = player;
}

void Boomerang::update()
{
    if(this->timer < RETURN_TIME) {
        this->y -= BOOMERANG_SPEED;
        this->timer++;
    } else {
        if(::java::lang::Math::abs(this->x - npc(this->player)->getX()) < BOOMERANG_SPEED) {
            this->x = npc(this->player)->getX();
        } else {
            auto sign = static_cast< int32_t >(::java::lang::Math::signum(static_cast< float >(npc(this->player)->getX() - this->x)));
            this->x += sign * BOOMERANG_SPEED;
        }
        this->y += BOOMERANG_SPEED;
        if(npc(this->sprite)->intersects(static_cast< ::java::awt::geom::Rectangle2D* >(npc(this->player)->getSprite()))) {
            this->die();
        }
    }
    this->sprite = new ::java::awt::geom::Rectangle2D_Double(this->x, this->y, BOOMERANG_SIZE, BOOMERANG_SIZE);
}

java::awt::Color* Boomerang::getColor()
{
    return BOOMERANG_COLOR;
}

void Boomerang::collide(Collidable* collidable)
{
    npc(collidable)->collideWithBoomerang(this);
}

void Boomerang::collideWithCentipede(LinkedCentipede* c)
{
    npc(c)->die();
    this->die();
}

void Boomerang::collideWithSpider(Spider* s)
{
    npc(s)->die();
    this->die();
}

java::awt::Image* Boomerang::getImage()
{
    return npc(::java::awt::Toolkit::getDefaultToolkit())->getImage(u"src/Boomerang.png"_j);
}

void Boomerang::collideWithScorpion(Scorpion* s)
{
    npc(s)->die();
    this->die();
}

void Boomerang::collideWithFlea(Flea* f)
{
    npc(f)->die();
    this->die();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* Boomerang::class_()
{
    static ::java::lang::Class* c = ::class_(u"Boomerang", 9);
    return c;
}

java::lang::Class* Boomerang::getClass0()
{
    return class_();
}

