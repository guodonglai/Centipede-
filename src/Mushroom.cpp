// Generated from /ArcadeGameProject/src/Mushroom.java
#include <Mushroom.hpp>

#include <Boomerang.hpp>
#include <Bullet.hpp>
#include <CentipedeComponent.hpp>
#include <Collidable.hpp>
#include <LinkedCentipede.hpp>
#include <PlayerCharacter.hpp>
#include <ShotgunShell.hpp>
#include <java/awt/Color.hpp>
#include <java/awt/Image.hpp>
#include <java/awt/Toolkit.hpp>
#include <java/awt/geom/Rectangle2D_Double.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/util/Random.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

Mushroom::Mushroom(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

Mushroom::Mushroom(int32_t x, int32_t y, CentipedeComponent* comp) 
    : Mushroom(*static_cast< ::default_init_tag* >(0))
{
    ctor(x,y,comp);
}

void Mushroom::init()
{
    NORMAL_COLOR = ::java::awt::Color::GREEN();
    POISONED_COLOR = ::java::awt::Color::MAGENTA();
}

void Mushroom::ctor(int32_t x, int32_t y, CentipedeComponent* comp)
{
    super::ctor(x, y, comp);
    init();
    this->isPoisoned = false;
    this->life = 4;
}

bool Mushroom::getPoisonedStatus()
{
    return this->isPoisoned;
}

java::awt::Image* Mushroom::getImage()
{
    if(this->isPoisoned && this->life != 0) {
        auto fileName = ::java::lang::StringBuilder().append(u"src/PoisonedMushroom"_j)->append(this->life)
            ->append(u".png"_j)->toString();
        return npc(::java::awt::Toolkit::getDefaultToolkit())->getImage(fileName);
    }
    if(this->isPoisoned && this->life == 0) {
        return npc(::java::awt::Toolkit::getDefaultToolkit())->getImage(u"src/PoisonedMushroom1.png"_j);
    }
    if(!this->isPoisoned && this->life != 0) {
        auto fileName = ::java::lang::StringBuilder().append(u"src/RegularMushroom"_j)->append(this->life)
            ->append(u".png"_j)->toString();
        return npc(::java::awt::Toolkit::getDefaultToolkit())->getImage(fileName);
    }
    return npc(::java::awt::Toolkit::getDefaultToolkit())->getImage(u"src/RegularMushroom1.png"_j);
}

java::lang::String* Mushroom::toString()
{
    return u"Mushroom"_j;
}

void Mushroom::update()
{
    this->sprite = new ::java::awt::geom::Rectangle2D_Double(x, y, this->BlockSIZE, this->BlockSIZE - (int32_t(4) - this->life) * int32_t(5));
}

java::awt::Color* Mushroom::getColor()
{
    if(!this->isPoisoned) {
        return NORMAL_COLOR;
    }
    return POISONED_COLOR;
}

void Mushroom::collide(Collidable* collidable)
{
    npc(collidable)->collideWithMushroom(this);
}

void Mushroom::collideWithMushroom(Mushroom* m)
{
}

void Mushroom::collideWithCharacter(PlayerCharacter* c)
{
    npc(c)->stop();
}

void Mushroom::collideWithBullet(Bullet* b)
{
    npc(b)->die();
    if(this->life > 0) {
        this->life--;
    }
    if(this->life == 0) {
        this->die();
        npc(npc(this->comp)->getCharacter())->addScore(2);
    }
}

void Mushroom::collideWithBoomerang(Boomerang* b)
{
    npc(b)->die();
    if(this->life > 0) {
        this->life--;
    }
    if(this->life == 0) {
        this->die();
        npc(npc(this->comp)->getCharacter())->addScore(2);
    }
}

void Mushroom::collideWithShotgunShell(ShotgunShell* s)
{
    npc(s)->die();
    if(this->life > 0) {
        this->life--;
    }
    if(this->life == 0) {
        this->die();
        npc(npc(this->comp)->getCharacter())->addScore(2);
    }
}

void Mushroom::collideWithCentipede(LinkedCentipede* c)
{
    npc(c)->dropAndTurn();
}

void Mushroom::collideWithSpider(Spider* s)
{
    auto rand = new ::java::util::Random();
    if(npc(rand)->nextInt(120) == 1) {
        this->die();
    }
}

void Mushroom::collideWithScorpion(Scorpion* s)
{
    this->isPoisoned = true;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* Mushroom::class_()
{
    static ::java::lang::Class* c = ::class_(u"Mushroom", 8);
    return c;
}

void Mushroom::collideWithFlea(Flea* f)
{
    Instance::collideWithFlea(f);
}

void Mushroom::collideWithGunPickup(GunPickup* g)
{
    Instance::collideWithGunPickup(g);
}

java::lang::Class* Mushroom::getClass0()
{
    return class_();
}

