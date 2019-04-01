// Generated from /ArcadeGameProject/src/PlayerCharacter.java
#include <PlayerCharacter.hpp>

#include <CentipedeComponent.hpp>
#include <Collidable.hpp>
#include <java/awt/Color.hpp>
#include <java/awt/Image.hpp>
#include <java/awt/Toolkit.hpp>
#include <java/awt/geom/Rectangle2D_Double.hpp>
#include <java/io/IOException.hpp>
#include <java/io/PrintStream.hpp>
#include <java/lang/Boolean.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/System.hpp>
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

PlayerCharacter::PlayerCharacter(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

PlayerCharacter::PlayerCharacter(CentipedeComponent* comp) 
    : PlayerCharacter(*static_cast< ::default_init_tag* >(0))
{
    ctor(comp);
}

java::awt::Color*& PlayerCharacter::HERO_COLOR()
{
    clinit();
    return HERO_COLOR_;
}
java::awt::Color* PlayerCharacter::HERO_COLOR_;

constexpr int32_t PlayerCharacter::DEFAULT_X;

constexpr int32_t PlayerCharacter::DEFAULT_Y;

constexpr int32_t PlayerCharacter::RELOAD_FRAMES;

constexpr int32_t PlayerCharacter::PISTOL_NUMBER;

constexpr int32_t PlayerCharacter::SHOTGUN_NUMBER;

constexpr int32_t PlayerCharacter::BOOMERANG_NUMBER;

constexpr int32_t PlayerCharacter::ANIMATION_TIME;

void PlayerCharacter::ctor(CentipedeComponent* comp)
{
    super::ctor(DEFAULT_X, DEFAULT_Y, comp);
    this->timer = RELOAD_FRAMES;
    this->gunNumber = PISTOL_NUMBER;
    this->animationTimer = 0;
    this->life = 3;
    this->score = 0;
}

void PlayerCharacter::readMap(::java::util::HashMap* hashMap)
{
    this->prevX = this->x;
    this->prevY = this->y;
    if((npc(java_cast< ::java::lang::Boolean* >(npc(hashMap)->get(::java::lang::Integer::valueOf(int32_t(38))))))->booleanValue() && this->y > 600) {
        super::moveUp();
    }
    if((npc(java_cast< ::java::lang::Boolean* >(npc(hashMap)->get(::java::lang::Integer::valueOf(int32_t(39))))))->booleanValue() && this->x < 880) {
        super::moveRight();
    }
    if((npc(java_cast< ::java::lang::Boolean* >(npc(hashMap)->get(::java::lang::Integer::valueOf(int32_t(40))))))->booleanValue() && this->y < 880) {
        super::moveDown();
    }
    if((npc(java_cast< ::java::lang::Boolean* >(npc(hashMap)->get(::java::lang::Integer::valueOf(int32_t(37))))))->booleanValue() && this->x > 0) {
        super::moveLeft();
    }
    this->isFiring = (npc(java_cast< ::java::lang::Boolean* >(npc(hashMap)->get(::java::lang::Integer::valueOf(int32_t(32))))))->booleanValue();
}

int32_t PlayerCharacter::getLives()
{
    return this->life;
}

void PlayerCharacter::hitByEnemy()
{
    if(this->life > 0) {
        this->life--;
        this->x = DEFAULT_X;
        this->y = DEFAULT_Y;
    } else {
        npc(::java::lang::System::out())->println(u"YOU DIED"_j);
        try {
            npc(this->comp)->loadLevel(npc(this->comp)->getLevelNum());
        } catch (::java::io::IOException* exception) {
            npc(exception)->printStackTrace();
        }
    }
}

int32_t PlayerCharacter::getScore()
{
    return this->score;
}

void PlayerCharacter::addScore(int32_t i)
{
    score += i;
}

java::awt::Color* PlayerCharacter::getColor()
{
    return HERO_COLOR_;
}

int32_t PlayerCharacter::getGunID()
{
    return this->gunNumber;
}

java::awt::Image* PlayerCharacter::getImage()
{
    if(this->animationTimer >= ANIMATION_TIME / int32_t(2)) {
        return npc(::java::awt::Toolkit::getDefaultToolkit())->getImage(u"src/Player1.png"_j);
    }
    return npc(::java::awt::Toolkit::getDefaultToolkit())->getImage(u"src/Player2.png"_j);
}

bool PlayerCharacter::getFiring()
{
    if(this->timer > RELOAD_FRAMES && this->isFiring) {
        this->timer = 0;
        return true;
    }
    return false;
}

void PlayerCharacter::addTimer()
{
    if(this->timer <= RELOAD_FRAMES) {
        this->timer += 1;
    }
}

void PlayerCharacter::update()
{
    this->animationTimer++;
    if(this->animationTimer >= ANIMATION_TIME) {
        this->animationTimer = 0;
    }
    this->sprite = new ::java::awt::geom::Rectangle2D_Double(this->x, this->y, int32_t(20), int32_t(20));
}

void PlayerCharacter::stop()
{
    this->x = prevX;
    this->y = prevY;
}

void PlayerCharacter::collide(Collidable* collidable)
{
    npc(collidable)->collideWithCharacter(this);
}

void PlayerCharacter::collideWithMushroom(Mushroom* m)
{
    npc(::java::lang::System::out())->println(u"BOOP"_j);
}

void PlayerCharacter::collideWithCharacter(PlayerCharacter* c)
{
}

void PlayerCharacter::collideWithBullet(Bullet* b)
{
}

void PlayerCharacter::collideWithCentipede(LinkedCentipede* c)
{
    npc(::java::lang::System::out())->println(u"YOU DIED"_j);
}

int32_t PlayerCharacter::getGunNumber()
{
    return this->gunNumber;
}

void PlayerCharacter::changeGun(int32_t gunNum)
{
    this->gunNumber = gunNum;
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* PlayerCharacter::class_()
{
    static ::java::lang::Class* c = ::class_(u"PlayerCharacter", 15);
    return c;
}

void PlayerCharacter::clinit()
{
    super::clinit();
    static bool in_cl_init = false;
struct clinit_ {
    clinit_() {
        in_cl_init = true;
        HERO_COLOR_ = ::java::awt::Color::BLUE();
    }
};

    if(!in_cl_init) {
        static clinit_ clinit_instance;
    }
}

void PlayerCharacter::collideWithBoomerang(Boomerang* b)
{
    Instance::collideWithBoomerang(b);
}

void PlayerCharacter::collideWithFlea(Flea* f)
{
    Instance::collideWithFlea(f);
}

void PlayerCharacter::collideWithGunPickup(GunPickup* g)
{
    Instance::collideWithGunPickup(g);
}

void PlayerCharacter::collideWithScorpion(Scorpion* s)
{
    Instance::collideWithScorpion(s);
}

void PlayerCharacter::collideWithShotgunShell(ShotgunShell* s)
{
    Instance::collideWithShotgunShell(s);
}

void PlayerCharacter::collideWithSpider(Spider* s)
{
    Instance::collideWithSpider(s);
}

void PlayerCharacter::moveDown()
{
    Instance::moveDown();
}

void PlayerCharacter::moveLeft()
{
    Instance::moveLeft();
}

void PlayerCharacter::moveRight()
{
    Instance::moveRight();
}

void PlayerCharacter::moveUp()
{
    Instance::moveUp();
}

java::lang::Class* PlayerCharacter::getClass0()
{
    return class_();
}

