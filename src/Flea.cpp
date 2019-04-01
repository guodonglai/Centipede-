// Generated from /ArcadeGameProject/src/Flea.java
#include <Flea.hpp>

#include <Boomerang.hpp>
#include <Bullet.hpp>
#include <CentipedeComponent.hpp>
#include <Mushroom.hpp>
#include <PlayerCharacter.hpp>
#include <ShotgunShell.hpp>
#include <java/awt/Color.hpp>
#include <java/awt/Image.hpp>
#include <java/awt/Toolkit.hpp>
#include <java/awt/geom/Rectangle2D_Double.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/util/Random.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

Flea::Flea(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

Flea::Flea(int32_t x, int32_t y, CentipedeComponent* comp) 
    : Flea(*static_cast< ::default_init_tag* >(0))
{
    ctor(x,y,comp);
}

void Flea::init()
{
    FLEA_COLOR = ::java::awt::Color::CYAN();
}

constexpr int32_t Flea::MOVEMENT_SPEED;

void Flea::ctor(int32_t x, int32_t y, CentipedeComponent* comp)
{
    super::ctor(x, y, comp);
    init();
    this->comp = comp;
    auto rand = new ::java::util::Random();
    this->MushroomTimer = npc(rand)->nextInt(80);
}

void Flea::update()
{
    if(this->y < 900) {
        this->y += MOVEMENT_SPEED;
    } else {
        this->die();
    }
    if(this->MushroomTimer >= 90) {
        npc(this->comp)->addInstanceToAdd(new Mushroom(this->x, this->y, this->comp));
        this->MushroomTimer = 0;
    }
    this->MushroomTimer++;
    this->sprite = new ::java::awt::geom::Rectangle2D_Double(this->x, this->y, int32_t(20), int32_t(20));
}

java::awt::Image* Flea::getImage()
{
    return npc(::java::awt::Toolkit::getDefaultToolkit())->getImage(u"src/Flea.png"_j);
}

java::awt::Color* Flea::getColor()
{
    return FLEA_COLOR;
}

void Flea::collideWithCharacter(PlayerCharacter* c)
{
    npc(c)->hitByEnemy();
}

void Flea::collideWithBullet(Bullet* b)
{
    npc(npc(this->comp)->getCharacter())->addScore(10);
    npc(b)->die();
    this->die();
}

void Flea::collideWithShotgunShell(ShotgunShell* s)
{
    npc(npc(this->comp)->getCharacter())->addScore(10);
    npc(s)->die();
    this->die();
}

void Flea::collideWithBoomerang(Boomerang* b)
{
    npc(npc(this->comp)->getCharacter())->addScore(10);
    npc(b)->die();
    this->die();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* Flea::class_()
{
    static ::java::lang::Class* c = ::class_(u"Flea", 4);
    return c;
}

java::lang::Class* Flea::getClass0()
{
    return class_();
}

