// Generated from /ArcadeGameProject/src/CentipedeComponent.java

#pragma once

#include <fwd-ArcadeGameProject.hpp>
#include <java/awt/fwd-ArcadeGameProject.hpp>
#include <java/awt/geom/fwd-ArcadeGameProject.hpp>
#include <java/util/fwd-ArcadeGameProject.hpp>
#include <javax/swing/JPanel.hpp>
#include <java/lang/Runnable.hpp>

struct default_init_tag;

class CentipedeComponent
    : public ::javax::swing::JPanel
    , public virtual ::java::lang::Runnable
{

public:
    typedef ::javax::swing::JPanel super;

private:
    static constexpr int32_t BLOCK_SIZE { int32_t(25) };
    static constexpr int32_t WINDOW_SIZE { int32_t(900) };
    ::java::awt::Color* NORMAL_MUSHROOM_COLOR {  };
    ::java::awt::Color* POISONED_MUSHROOM_COLOR {  };
    ::java::awt::Color* HERO_COLOR {  };
    ::java::awt::Color* BULLET_COLOR {  };
    static constexpr int32_t PISTOL_NUMBER { int32_t(1) };
    static constexpr int32_t SHOTGUN_NUMBER { int32_t(2) };
    static constexpr int32_t BOOMERANG_NUMBER { int32_t(3) };
    int32_t currentLevel {  };
    ::java::util::ArrayList* instances {  };
    ::java::util::ArrayList* instancestoremove {  };
    ::java::util::ArrayList* instancesToAdd {  };
    PlayerCharacter* hero {  };
    CentipedeListener* gameListener {  };
    int32_t centipedeCount {  };
    int32_t mushroomCount {  };
    int32_t fleaTimer {  };
    int32_t enemySpawnTimer {  };
    BackGroundMusicPlayer* player {  };

public: /* package */
    bool IsPaused {  };

private:
    int32_t weaponTimer {  };
protected:
    void ctor();

public:
    virtual int32_t getLevelNum();
    virtual PlayerCharacter* getCharacter();
    virtual void loadLevel(int32_t levelNum) /* throws(IOException) */;
    virtual void addInstanceToAdd(Instance* instance);
    virtual void addInstance(Instance* instance);

private:
    void addSquare(::java::awt::Graphics2D* g2, ::java::awt::geom::Rectangle2D_Double* sprite, ::java::awt::Color* color);
    void addImage(::java::awt::Graphics* g2, ::java::awt::Image* img, int32_t x, int32_t y);

public: /* package */
    virtual void removeinstance(Instance* in);

public:
    void run() override;
    virtual void updateInstances();

public: /* protected */
    void paintComponent(::java::awt::Graphics* g) override;

public:
    virtual void setIsPaused(bool isPaused);

    // Generated
    CentipedeComponent();
protected:
    CentipedeComponent(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    void init();
    virtual ::java::lang::Class* getClass0();
};
