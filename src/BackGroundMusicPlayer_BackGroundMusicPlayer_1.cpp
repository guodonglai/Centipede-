// Generated from /ArcadeGameProject/src/BackGroundMusicPlayer.java
#include <BackGroundMusicPlayer_BackGroundMusicPlayer_1.hpp>

#include <BackGroundMusicPlayer.hpp>
#include <java/lang/Exception.hpp>

BackGroundMusicPlayer_BackGroundMusicPlayer_1::BackGroundMusicPlayer_BackGroundMusicPlayer_1(BackGroundMusicPlayer *BackGroundMusicPlayer_this)
    : super(*static_cast< ::default_init_tag* >(0))
    , BackGroundMusicPlayer_this(BackGroundMusicPlayer_this)
{
    clinit();
    ctor();
}

void BackGroundMusicPlayer_BackGroundMusicPlayer_1::run()
{
    try {
        while (true) {
            BackGroundMusicPlayer::play();
        }
    } catch (::java::lang::Exception* exception) {
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* BackGroundMusicPlayer_BackGroundMusicPlayer_1::class_()
{
    static ::java::lang::Class* c = ::class_(u"", 0);
    return c;
}

java::lang::Class* BackGroundMusicPlayer_BackGroundMusicPlayer_1::getClass0()
{
    return class_();
}

