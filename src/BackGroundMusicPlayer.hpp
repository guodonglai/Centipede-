// Generated from /ArcadeGameProject/src/BackGroundMusicPlayer.java

#pragma once

#include <fwd-ArcadeGameProject.hpp>
#include <javax/sound/sampled/fwd-ArcadeGameProject.hpp>
#include <java/lang/Object.hpp>

struct default_init_tag;

class BackGroundMusicPlayer
    : public virtual ::java::lang::Object
{

public:
    typedef ::java::lang::Object super;

private:
    static ::javax::sound::sampled::Clip* clip_;

public: /* protected */
    bool clipIsPaused {  };
protected:
    void ctor();

public: /* package */
    static void play();

public:
    virtual void pause(bool shouldBePaused);

    // Generated
    BackGroundMusicPlayer();
protected:
    BackGroundMusicPlayer(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

public: /* protected */
    static ::javax::sound::sampled::Clip*& clip();

private:
    virtual ::java::lang::Class* getClass0();
    friend class BackGroundMusicPlayer_BackGroundMusicPlayer_1;
};
