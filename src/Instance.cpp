// Generated from /ArcadeGameProject/src/Instance.java
#include <Instance.hpp>

#include <CentipedeComponent.hpp>
#include <java/awt/Color.hpp>
#include <java/awt/geom/Rectangle2D_Double.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

Instance::Instance(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

Instance::Instance(int32_t x, int32_t y, CentipedeComponent* comp) 
    : Instance(*static_cast< ::default_init_tag* >(0))
{
    ctor(x,y,comp);
}

void Instance::init()
{
    DEFAULT_COLOR = ::java::awt::Color::RED();
    BlockSIZE = int32_t(20);
}

constexpr int32_t Instance::BLOCK_SIZE;

constexpr int32_t Instance::SPEED;

void Instance::ctor(int32_t x, int32_t y, CentipedeComponent* comp)
{
    super::ctor();
    init();
    this->comp = comp;
    this->x = x;
    this->y = y;
    this->sprite = new ::java::awt::geom::Rectangle2D_Double(x, y, BLOCK_SIZE, BLOCK_SIZE);
}

bool Instance::isInPlayerArea()
{
    if(this->y > 600 && this->y < 900) {
        if(this->x > 0 && this->x < 900) {
            return true;
        }
    }
    return false;
}

int32_t Instance::getX()
{
    return this->x;
}

int32_t Instance::getY()
{
    return this->y;
}

java::awt::Image* Instance::getImage()
{
    return nullptr;
}

java::awt::geom::Rectangle2D_Double* Instance::getSprite()
{
    return this->sprite;
}

void Instance::update()
{
    this->sprite = new ::java::awt::geom::Rectangle2D_Double(this->x, this->y, BLOCK_SIZE, BLOCK_SIZE);
}

java::awt::Color* Instance::getColor()
{
    return DEFAULT_COLOR;
}

void Instance::die()
{
    npc(this->comp)->removeinstance(this);
}

java::lang::String* Instance::toString()
{
    return u"NOT A CENTIPEDE"_j;
}

void Instance::moveUp()
{
    this->y -= SPEED;
}

void Instance::moveRight()
{
    this->x += SPEED;
}

void Instance::moveDown()
{
    this->y += SPEED;
}

void Instance::moveLeft()
{
    this->x -= SPEED;
}

void Instance::collide(Collidable* collidable)
{
}

void Instance::collideWithMushroom(Mushroom* m)
{
}

void Instance::collideWithCharacter(PlayerCharacter* c)
{
}

void Instance::collideWithBullet(Bullet* b)
{
}

void Instance::collideWithCentipede(LinkedCentipede* c)
{
}

void Instance::collideWithShotgunShell(ShotgunShell* s)
{
}

void Instance::collideWithBoomerang(Boomerang* b)
{
}

void Instance::collideWithGunPickup(GunPickup* g)
{
}

void Instance::collideWithSpider(Spider* s)
{
}

void Instance::collideWithScorpion(Scorpion* s)
{
}

void Instance::collideWithFlea(Flea* f)
{
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* Instance::class_()
{
    static ::java::lang::Class* c = ::class_(u"Instance", 8);
    return c;
}

java::lang::Class* Instance::getClass0()
{
    return class_();
}

