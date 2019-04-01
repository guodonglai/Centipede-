// Generated from /ArcadeGameProject/src/CentipedeComponent.java
#include <CentipedeComponent.hpp>

#include <BackGroundMusicPlayer.hpp>
#include <Boomerang.hpp>
#include <Bullet.hpp>
#include <CentipedeListener.hpp>
#include <Collidable.hpp>
#include <Flea.hpp>
#include <GunPickup.hpp>
#include <Instance.hpp>
#include <LinkedCentipede.hpp>
#include <Mushroom.hpp>
#include <PlayerCharacter.hpp>
#include <Scorpion.hpp>
#include <ShotgunShell.hpp>
#include <Spider.hpp>
#include <java/awt/Color.hpp>
#include <java/awt/Dimension.hpp>
#include <java/awt/Font.hpp>
#include <java/awt/Graphics2D.hpp>
#include <java/awt/Graphics.hpp>
#include <java/awt/Image.hpp>
#include <java/awt/geom/Rectangle2D_Double.hpp>
#include <java/awt/geom/Rectangle2D.hpp>
#include <java/io/BufferedReader.hpp>
#include <java/io/FileNotFoundException.hpp>
#include <java/io/FileReader.hpp>
#include <java/io/IOException.hpp>
#include <java/io/PrintStream.hpp>
#include <java/io/Serializable.hpp>
#include <java/lang/ArrayStoreException.hpp>
#include <java/lang/CharSequence.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Comparable.hpp>
#include <java/lang/InterruptedException.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/String.hpp>
#include <java/lang/StringBuilder.hpp>
#include <java/lang/System.hpp>
#include <java/lang/Thread.hpp>
#include <java/util/ArrayList.hpp>
#include <java/util/Iterator.hpp>
#include <java/util/Random.hpp>
#include <javax/swing/JOptionPane.hpp>
#include <SubArray.hpp>
#include <ObjectArray.hpp>

template<typename ComponentType, typename... Bases> struct SubArray;
namespace java
{
    namespace io
    {
typedef ::SubArray< ::java::io::Serializable, ::java::lang::ObjectArray > SerializableArray;
    } // io

    namespace lang
    {
typedef ::SubArray< ::java::lang::CharSequence, ObjectArray > CharSequenceArray;
typedef ::SubArray< ::java::lang::Comparable, ObjectArray > ComparableArray;
typedef ::SubArray< ::java::lang::String, ObjectArray, ::java::io::SerializableArray, ComparableArray, CharSequenceArray > StringArray;
    } // lang
} // java

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

namespace
{
    template<typename F>
    struct finally_
    {
        finally_(F f) : f(f), moved(false) { }
        finally_(finally_ &&x) : f(x.f), moved(false) { x.moved = true; }
        ~finally_() { if(!moved) f(); }
    private:
        finally_(const finally_&); finally_& operator=(const finally_&);
        F f;
        bool moved;
    };

    template<typename F> finally_<F> finally(F f) { return finally_<F>(f); }
}
CentipedeComponent::CentipedeComponent(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

CentipedeComponent::CentipedeComponent() 
    : CentipedeComponent(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void CentipedeComponent::init()
{
    NORMAL_MUSHROOM_COLOR = ::java::awt::Color::GREEN();
    POISONED_MUSHROOM_COLOR = ::java::awt::Color::MAGENTA();
    HERO_COLOR = ::java::awt::Color::BLUE();
    BULLET_COLOR = ::java::awt::Color::GRAY();
}

constexpr int32_t CentipedeComponent::BLOCK_SIZE;

constexpr int32_t CentipedeComponent::WINDOW_SIZE;

constexpr int32_t CentipedeComponent::PISTOL_NUMBER;

constexpr int32_t CentipedeComponent::SHOTGUN_NUMBER;

constexpr int32_t CentipedeComponent::BOOMERANG_NUMBER;

void CentipedeComponent::ctor()
{
    super::ctor();
    init();
    setBackground(::java::awt::Color::WHITE());
    this->centipedeCount = 1;
    this->mushroomCount = 1;
    this->weaponTimer = 0;
    this->player = new BackGroundMusicPlayer();
    this->setPreferredSize(new ::java::awt::Dimension(this->WINDOW_SIZE, this->WINDOW_SIZE));
    auto option = ::javax::swing::JOptionPane::showOptionDialog(this, u"Welcome to Centipede!"_j, u"Centipede"_j, ::javax::swing::JOptionPane::YES_NO_OPTION, ::javax::swing::JOptionPane::PLAIN_MESSAGE, nullptr, new ::java::lang::StringArray({
        u"Start"_j
        , u"Exit"_j
    }), u"a"_j);
    if(option == 1) {
        ::java::lang::System::exit(0);
    }
    this->instances = new ::java::util::ArrayList();
    this->currentLevel = 0;
    try {
        loadLevel(this->currentLevel);
    } catch (::java::io::IOException* ex) {
    }
    this->gameListener = new CentipedeListener(this);
    this->addKeyListener(this->gameListener);
}

int32_t CentipedeComponent::getLevelNum()
{
    return this->currentLevel;
}

PlayerCharacter* CentipedeComponent::getCharacter()
{
    return this->hero;
}

void CentipedeComponent::loadLevel(int32_t levelNum) /* throws(IOException) */
{
    this->currentLevel = levelNum;
    this->centipedeCount = 1;
    this->mushroomCount = 1;
    this->instances = new ::java::util::ArrayList();
    npc(java_cast< ::java::util::ArrayList* >(this->instances))->add(static_cast< ::java::lang::Object* >(new LinkedCentipede(int32_t(15), this)));
    this->instancestoremove = new ::java::util::ArrayList();
    this->instancesToAdd = new ::java::util::ArrayList();
    this->hero = new PlayerCharacter(this);
    npc(java_cast< ::java::util::ArrayList* >(this->instances))->add(static_cast< ::java::lang::Object* >(this->hero));
    this->fleaTimer = 0;
    this->enemySpawnTimer = 0;
    ::java::io::BufferedReader* br = nullptr;
    try {
        br = new ::java::io::BufferedReader(new ::java::io::FileReader(::java::lang::StringBuilder().append(u"src/level"_j)->append(levelNum)
            ->append(u".txt"_j)->toString()));
    } catch (::java::io::FileNotFoundException* exception) {
    }
    {
        auto finally0 = finally([&] {
            npc(br)->close();
        });
        {
            auto sb = new ::java::lang::StringBuilder();
            auto line = npc(br)->readLine();
            auto yGrid = int32_t(0);
            while (line != nullptr) {
                yGrid++;
                npc(sb)->append(line);
                npc(sb)->append(::java::lang::System::lineSeparator());
                line = npc(br)->readLine();
            }
            auto everything = npc(sb)->toString();
            auto lines = npc(everything)->split(::java::lang::System::getProperty(u"line.separator"_j));
            auto scanX = int32_t(0);
            auto scanY = int32_t(0);
            for(auto currentLine : *npc(lines)) {
                scanY += 20;
                scanX = 0;
                for (auto i = int32_t(0); i < npc(currentLine)->length(); i++) {
                    scanX += 20;
                    if(npc(currentLine)->charAt(i) == u'M') {
                        npc(java_cast< ::java::util::ArrayList* >(this->instances))->add(static_cast< ::java::lang::Object* >(new Mushroom(scanX, scanY, this)));
                    }
                    if(npc(currentLine)->charAt(i) == u'S') {
                        npc(java_cast< ::java::util::ArrayList* >(this->instances))->add(static_cast< ::java::lang::Object* >(new GunPickup(this->SHOTGUN_NUMBER, scanX, scanY, this)));
                    }
                    if(npc(currentLine)->charAt(i) == u'P') {
                        npc(java_cast< ::java::util::ArrayList* >(this->instances))->add(static_cast< ::java::lang::Object* >(new GunPickup(this->PISTOL_NUMBER, scanX, scanY, this)));
                    }
                    if(npc(currentLine)->charAt(i) == u'B') {
                        npc(java_cast< ::java::util::ArrayList* >(this->instances))->add(static_cast< ::java::lang::Object* >(new GunPickup(this->BOOMERANG_NUMBER, scanX, scanY, this)));
                    }
                }
            }
        }
    }

}

void CentipedeComponent::addInstanceToAdd(Instance* instance)
{
    npc(java_cast< ::java::util::ArrayList* >(this->instancesToAdd))->add(static_cast< ::java::lang::Object* >(instance));
}

void CentipedeComponent::addInstance(Instance* instance)
{
    npc(java_cast< ::java::util::ArrayList* >(this->instances))->add(static_cast< ::java::lang::Object* >(instance));
}

void CentipedeComponent::addSquare(::java::awt::Graphics2D* g2, ::java::awt::geom::Rectangle2D_Double* sprite, ::java::awt::Color* color)
{
    npc(g2)->setColor(color);
    npc(g2)->fill(sprite);
}

void CentipedeComponent::addImage(::java::awt::Graphics* g2, ::java::awt::Image* img, int32_t x, int32_t y)
{
    npc(g2)->drawImage(img, x, y, this);
}

void CentipedeComponent::removeinstance(Instance* in)
{
    npc(java_cast< ::java::util::ArrayList* >(this->instancestoremove))->add(static_cast< ::java::lang::Object* >(in));
}

void CentipedeComponent::run()
{
    try {
        while (true) {
            if(!this->IsPaused) {
                this->updateInstances();
            }
            this->repaint();
            ::java::lang::Thread::sleep(static_cast< int64_t >(16.666667));
        }
    } catch (::java::lang::InterruptedException* ex) {
    }
}

void CentipedeComponent::updateInstances()
{
    for (auto _i = npc(java_cast< ::java::util::ArrayList* >(this->instancestoremove))->iterator(); _i->hasNext(); ) {
        Instance* y = java_cast< Instance* >(_i->next());
        {
            npc(java_cast< ::java::util::ArrayList* >(this->instances))->remove(static_cast< ::java::lang::Object* >(y));
        }
    }
    for (auto _i = npc(java_cast< ::java::util::ArrayList* >(this->instancesToAdd))->iterator(); _i->hasNext(); ) {
        Instance* toAdd = java_cast< Instance* >(_i->next());
        {
            npc(java_cast< ::java::util::ArrayList* >(this->instances))->add(static_cast< ::java::lang::Object* >(toAdd));
        }
    }
    this->instancesToAdd = new ::java::util::ArrayList();
    this->instancestoremove = new ::java::util::ArrayList();
    npc(this->hero)->readMap(npc(this->gameListener)->getHashMap());
    npc(this->hero)->addTimer();
    if(npc(this->hero)->getFiring()) {
        if(npc(this->hero)->getGunNumber() == this->PISTOL_NUMBER) {
            npc(java_cast< ::java::util::ArrayList* >(this->instances))->add(static_cast< ::java::lang::Object* >(new Bullet(npc(this->hero)->getX() + int32_t(5), npc(this->hero)->getY(), this)));
        }
        if(npc(this->hero)->getGunNumber() == this->SHOTGUN_NUMBER) {
            for (auto i = int32_t(0); i < 6; i++) {
                npc(java_cast< ::java::util::ArrayList* >(this->instances))->add(static_cast< ::java::lang::Object* >(new ShotgunShell(i, npc(this->hero)->getX() + int32_t(5), npc(this->hero)->getY(), this)));
            }
        }
        if(npc(this->hero)->getGunNumber() == this->BOOMERANG_NUMBER) {
            npc(java_cast< ::java::util::ArrayList* >(this->instances))->add(static_cast< ::java::lang::Object* >(new Boomerang(this->hero, npc(this->hero)->getX() + int32_t(5), npc(this->hero)->getY() - int32_t(1), this)));
        }
    }
    npc(this->hero)->update();
    this->centipedeCount = 0;
    this->mushroomCount = 0;
    for (auto _i = npc(java_cast< ::java::util::ArrayList* >(this->instances))->iterator(); _i->hasNext(); ) {
        Instance* instance = java_cast< Instance* >(_i->next());
        {
            npc(instance)->update();
            if(npc(npc(this->hero)->getSprite())->intersects(static_cast< ::java::awt::geom::Rectangle2D* >(npc(instance)->getSprite()))) {
                npc(this->hero)->collide(static_cast< Collidable* >(instance));
            }
            if(npc(npc(instance)->toString())->equals(static_cast< ::java::lang::Object* >(u"Centipede"_j))) {
                this->centipedeCount++;
            }
            if(npc(npc(instance)->toString())->equals(static_cast< ::java::lang::Object* >(u"Mushroom"_j)) && npc(instance)->isInPlayerArea()) {
                this->mushroomCount++;
            }
            for (auto _i = npc(java_cast< ::java::util::ArrayList* >(this->instances))->iterator(); _i->hasNext(); ) {
                Instance* some = java_cast< Instance* >(_i->next());
                {
                    if(npc(npc(instance)->getSprite())->intersects(static_cast< ::java::awt::geom::Rectangle2D* >(npc(some)->getSprite()))) {
                        npc(instance)->collide(static_cast< Collidable* >(some));
                    }
                }
            }
        }
    }
    if(this->centipedeCount == 0) {
        npc(::java::lang::System::out())->println(u"YOU WON!"_j);
        npc(this->hero)->addScore(100);
        auto nextLevel = int32_t(0);
        if(this->currentLevel == 2) {
            nextLevel = 0;
        } else {
            nextLevel = this->currentLevel + int32_t(1);
        }
        try {
            loadLevel(nextLevel);
        } catch (::java::io::IOException* exception) {
            npc(exception)->printStackTrace();
        }
    }
    this->enemySpawnTimer++;
    if(this->enemySpawnTimer >= 300) {
        this->enemySpawnTimer = 0;
        auto rand = new ::java::util::Random();
        auto newX = int32_t(40) + int32_t(20) * npc(rand)->nextInt(40);
        auto newY = int32_t(40) + int32_t(20) * npc(rand)->nextInt(30);
        if(npc(rand)->nextBoolean()) {
            newY = int32_t(600) + int32_t(20) * npc(rand)->nextInt(14);
            npc(java_cast< ::java::util::ArrayList* >(this->instancesToAdd))->add(static_cast< ::java::lang::Object* >(new Spider(newX, newY, this)));
        } else {
            npc(java_cast< ::java::util::ArrayList* >(this->instancesToAdd))->add(static_cast< ::java::lang::Object* >(new Scorpion(newX, newY, this)));
        }
        auto weaponX = int32_t(40) + int32_t(20) * npc(rand)->nextInt(40);
        auto weaponY = int32_t(600) + int32_t(20) * npc(rand)->nextInt(14);
        npc(java_cast< ::java::util::ArrayList* >(this->instancesToAdd))->add(static_cast< ::java::lang::Object* >(new GunPickup(npc(rand)->nextInt(2) + int32_t(1), weaponX, weaponY, this)));
    }
    if(this->mushroomCount <= 5) {
        if(this->fleaTimer < 180) {
            this->fleaTimer++;
        }
        if(this->fleaTimer >= 180) {
            auto rand = new ::java::util::Random();
            auto dist = npc(rand)->nextInt(40);
            npc(java_cast< ::java::util::ArrayList* >(this->instancesToAdd))->add(static_cast< ::java::lang::Object* >(new Flea(int32_t(40) + int32_t(20) * dist, int32_t(40), this)));
            this->fleaTimer = 0;
        }
    }
}

void CentipedeComponent::paintComponent(::java::awt::Graphics* g)
{
    super::paintComponent(g);
    auto g2 = java_cast< ::java::awt::Graphics2D* >(g);
    addSquare(g2, npc(this->hero)->getSprite(), npc(this->hero)->getColor());
    for (auto _i = npc(java_cast< ::java::util::ArrayList* >(this->instances))->iterator(); _i->hasNext(); ) {
        Instance* instance = java_cast< Instance* >(_i->next());
        {
            addSquare(g2, npc(instance)->getSprite(), npc(instance)->getColor());
            if(npc(instance)->getImage() != nullptr) {
                addImage(g2, npc(instance)->getImage(), npc(instance)->getX(), npc(instance)->getY());
            }
        }
    }
    npc(g2)->setColor(::java::awt::Color::RED());
    npc(g2)->setFont(new ::java::awt::Font(u"Ariel"_j, ::java::awt::Font::PLAIN, int32_t(30)));
    npc(g2)->drawString(::java::lang::StringBuilder().append(u"Lives: "_j)->append(npc(this->hero)->getLives())
        ->append(u"      Score: "_j)
        ->append(npc(this->hero)->getScore())->toString(), int32_t(20), int32_t(880));
    if(this->IsPaused) {
        auto ground = new ::java::awt::geom::Rectangle2D_Double(int32_t(900) / int32_t(2), int32_t(900) / int32_t(2), int32_t(135), int32_t(40));
        npc(g2)->setColor(::java::awt::Color::BLACK());
        npc(g2)->fill(ground);
        npc(g2)->setColor(::java::awt::Color::white());
        npc(g2)->draw(ground);
        auto paused = u"Paused"_j;
        npc(g2)->setFont(new ::java::awt::Font(u"Consolas"_j, ::java::awt::Font::ITALIC, int32_t(40)));
        npc(g2)->drawString(paused, int32_t(900) / int32_t(2) + int32_t(2), int32_t(900) / int32_t(2) + int32_t(30));
    }
}

void CentipedeComponent::setIsPaused(bool isPaused)
{
    this->IsPaused = isPaused;
    npc(this->player)->pause(this->IsPaused);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* CentipedeComponent::class_()
{
    static ::java::lang::Class* c = ::class_(u"CentipedeComponent", 18);
    return c;
}

java::lang::Class* CentipedeComponent::getClass0()
{
    return class_();
}

