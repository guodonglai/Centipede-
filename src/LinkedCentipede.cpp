// Generated from /ArcadeGameProject/src/LinkedCentipede.java
#include <LinkedCentipede.hpp>

#include <Boomerang.hpp>
#include <Bullet.hpp>
#include <CentipedeComponent.hpp>
#include <Mushroom.hpp>
#include <PlayerCharacter.hpp>
#include <ShotgunShell.hpp>
#include <java/awt/Color.hpp>
#include <java/awt/Image.hpp>
#include <java/awt/Toolkit.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/util/Random.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

LinkedCentipede::LinkedCentipede(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

LinkedCentipede::LinkedCentipede(int32_t x, int32_t y, int32_t nSegments, CentipedeComponent* comp) 
    : LinkedCentipede(*static_cast< ::default_init_tag* >(0))
{
    ctor(x,y,nSegments,comp);
}

LinkedCentipede::LinkedCentipede(int32_t nSegments, CentipedeComponent* component) 
    : LinkedCentipede(*static_cast< ::default_init_tag* >(0))
{
    ctor(nSegments,component);
}

constexpr int32_t LinkedCentipede::SPEED;

java::awt::Color*& LinkedCentipede::CENTIPEDE_COLOR()
{
    clinit();
    return CENTIPEDE_COLOR_;
}
java::awt::Color* LinkedCentipede::CENTIPEDE_COLOR_;

java::awt::Color*& LinkedCentipede::HEAD_COLOR()
{
    clinit();
    return HEAD_COLOR_;
}
java::awt::Color* LinkedCentipede::HEAD_COLOR_;

constexpr int32_t LinkedCentipede::HEAD_SIZE;

constexpr int32_t LinkedCentipede::DEFAULT_X;

constexpr int32_t LinkedCentipede::DEFAULT_Y;

constexpr int32_t LinkedCentipede::MOVEMENT_SPEED;

constexpr int32_t LinkedCentipede::BORDER;

constexpr int32_t LinkedCentipede::SCREEN_SIZE;

void LinkedCentipede::ctor(int32_t x, int32_t y, int32_t nSegments, CentipedeComponent* comp)
{
    super::ctor(x, y, comp);
    this->timer = 0;
    this->prevX = x;
    this->prevY = y;
    this->movingDown = 1;
    this->movingSide = 1;
    this->sick = false;
    this->dead = false;
    this->spawnTimer = 0;
    if(nSegments > 1) {
        this->nextSegment = new LinkedCentipede(x + int32_t(20), y, nSegments - int32_t(1), comp);
        npc(this->comp)->addInstance(this->nextSegment);
    } else {
        this->nextSegment = nullptr;
    }
}

java::awt::Image* LinkedCentipede::getImage()
{
    if(this->nextSegment == nullptr) {
        return npc(::java::awt::Toolkit::getDefaultToolkit())->getImage(u"src/CentipedeHead.png"_j);
    }
    return npc(::java::awt::Toolkit::getDefaultToolkit())->getImage(u"src/CentipedeBody.png"_j);
}

void LinkedCentipede::ctor(int32_t nSegments, CentipedeComponent* component)
{
    ctor(DEFAULT_X, DEFAULT_Y, nSegments, component);
}

int32_t LinkedCentipede::getPrevX()
{
    return this->prevX;
}

int32_t LinkedCentipede::getPrevY()
{
    return this->prevY;
}

int32_t LinkedCentipede::getMovingSide()
{
    return this->movingSide;
}

void LinkedCentipede::dropAndTurn()
{
    this->prevX = this->x;
    this->prevY = this->y;
    this->movingSide *= -int32_t(1);
    this->y += int32_t(20) * this->movingDown;
}

void LinkedCentipede::move()
{
    this->prevY = this->y;
    this->prevX = this->x;
    if(this->x <= BORDER || this->x >= SCREEN_SIZE - BORDER) {
        dropAndTurn();
    }
    if(this->y <= 0 || this->y >= (SCREEN_SIZE - int32_t(2) * BORDER)) {
        this->movingDown *= 0;
    }
    this->x += this->movingSide * MOVEMENT_SPEED;
}

void LinkedCentipede::changeNextSegment(LinkedCentipede* c)
{
    this->nextSegment = c;
}

bool LinkedCentipede::isDead()
{
    return this->dead;
}

void LinkedCentipede::update()
{
    this->timer++;
    if(this->movingDown == 0) {
        this->spawnTimer++;
        if(this->spawnTimer >= 180) {
            this->spawnTimer = 0;
            auto rand = new ::java::util::Random();
            auto newY = int32_t(900) - int32_t(20) * npc(rand)->nextInt(4);
            auto newX = int32_t(40) + int32_t(20) * npc(rand)->nextInt(40);
            npc(this->comp)->addInstanceToAdd(new LinkedCentipede(newX, newY, int32_t(1), this->comp));
        }
    }
    if(this->nextSegment != nullptr && npc(this->nextSegment)->isDead() == true) {
        this->nextSegment = nullptr;
    }
    if(this->timer > 20) {
        if(this->nextSegment == nullptr) {
            if(!this->sick) {
                this->move();
            }
            if(this->sick) {
                this->prevY = this->y;
                this->prevX = this->x;
                this->y += MOVEMENT_SPEED;
            }
        }
        if(this->nextSegment != nullptr) {
            this->prevX = this->x;
            this->prevY = this->y;
            this->x = npc(this->nextSegment)->getPrevX();
            this->y = npc(this->nextSegment)->getPrevY();
        }
        if(this->y >= SCREEN_SIZE - int32_t(2) * BORDER) {
            this->sick = false;
        }
        this->timer = 0;
        if(this->x == this->prevX && this->y == this->prevY) {
            this->die();
        }
    }
    super::update();
}

java::awt::Color* LinkedCentipede::getColor()
{
    if(this->nextSegment == nullptr) {
        return HEAD_COLOR_;
    }
    return CENTIPEDE_COLOR_;
}

java::lang::String* LinkedCentipede::toString()
{
    return u"Centipede"_j;
}

void LinkedCentipede::collideWithMushroom(Mushroom* m)
{
    if(!this->sick) {
        if(npc(m)->getPoisonedStatus()) {
            this->sick = true;
            this->y += 20;
        } else {
            dropAndTurn();
        }
    } else {
        npc(m)->die();
    }
}

void LinkedCentipede::breakSegment()
{
    npc(npc(this->comp)->getCharacter())->addScore(15);
    npc(comp)->addInstanceToAdd(new Mushroom(this->prevX, this->prevY, comp));
    this->dead = true;
    if(this->nextSegment == nullptr) {
        this->die();
    }
    if(this->y < 60) {
        this->y += 20;
    } else {
        this->y -= 20;
    }
    this->movingSide *= -int32_t(1);
    this->nextSegment = nullptr;
}

void LinkedCentipede::collideWithBullet(Bullet* b)
{
    npc(b)->die();
    breakSegment();
}

void LinkedCentipede::collideWithBoomerang(Boomerang* b)
{
    npc(b)->die();
    breakSegment();
}

void LinkedCentipede::collideWithShotgunShell(ShotgunShell* s)
{
    npc(s)->die();
    breakSegment();
}

void LinkedCentipede::collideWithCharacter(PlayerCharacter* c)
{
    npc(c)->hitByEnemy();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* LinkedCentipede::class_()
{
    static ::java::lang::Class* c = ::class_(u"LinkedCentipede", 15);
    return c;
}

void LinkedCentipede::clinit()
{
    super::clinit();
    static bool in_cl_init = false;
struct clinit_ {
    clinit_() {
        in_cl_init = true;
        CENTIPEDE_COLOR_ = ::java::awt::Color::DARK_GRAY();
        HEAD_COLOR_ = ::java::awt::Color::ORANGE();
    }
};

    if(!in_cl_init) {
        static clinit_ clinit_instance;
    }
}

java::lang::Class* LinkedCentipede::getClass0()
{
    return class_();
}

