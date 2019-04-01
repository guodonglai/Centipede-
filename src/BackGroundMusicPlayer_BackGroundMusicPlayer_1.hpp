// Generated from /ArcadeGameProject/src/BackGroundMusicPlayer.java

#pragma once

#include <fwd-ArcadeGameProject.hpp>
#include <java/lang/Object.hpp>
#include <java/lang/Runnable.hpp>

struct default_init_tag;

class BackGroundMusicPlayer_BackGroundMusicPlayer_1
    : public virtual ::java::lang::Object
    , public virtual ::java::lang::Runnable
{

public:
    typedef ::java::lang::Object super;
    void run() override;

    // Generated
    BackGroundMusicPlayer_BackGroundMusicPlayer_1(BackGroundMusicPlayer *BackGroundMusicPlayer_this);
    static ::java::lang::Class *class_();
    BackGroundMusicPlayer *BackGroundMusicPlayer_this;

private:
    virtual ::java::lang::Class* getClass0();
    friend class BackGroundMusicPlayer;
};
