// Generated from /ArcadeGameProject/src/BackGroundMusicPlayer.java
#include <BackGroundMusicPlayer.hpp>

#include <BackGroundMusicPlayer_BackGroundMusicPlayer_1.hpp>
#include <java/io/File.hpp>
#include <java/io/PrintStream.hpp>
#include <java/lang/Exception.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/String.hpp>
#include <java/lang/System.hpp>
#include <java/lang/Thread.hpp>
#include <javax/sound/sampled/AudioSystem.hpp>
#include <javax/sound/sampled/Clip.hpp>

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

BackGroundMusicPlayer::BackGroundMusicPlayer(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

BackGroundMusicPlayer::BackGroundMusicPlayer() 
    : BackGroundMusicPlayer(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

javax::sound::sampled::Clip*& BackGroundMusicPlayer::clip()
{
    clinit();
    return clip_;
}
javax::sound::sampled::Clip* BackGroundMusicPlayer::clip_;

void BackGroundMusicPlayer::ctor()
{
    super::ctor();
    ::java::lang::Runnable* player = new BackGroundMusicPlayer_BackGroundMusicPlayer_1(this);
    (new ::java::lang::Thread(player))->start();
}

void BackGroundMusicPlayer::play()
{
    clinit();
    auto song = new ::java::io::File(u"src/Youtube-Arcade Classics 2_ Millipede_Centipede Music - Game Select Screen.wav"_j);
    try {
        clip_ = ::javax::sound::sampled::AudioSystem::getClip();
        npc(clip_)->open(::javax::sound::sampled::AudioSystem::getAudioInputStream(song));
        npc(clip_)->start();
        ::java::lang::Thread::sleep(npc(clip_)->getMicrosecondLength() / int32_t(1000));
    } catch (::java::lang::Exception* e) {
        npc(::java::lang::System::out())->println(u"Not Found"_j);
    }
}

void BackGroundMusicPlayer::pause(bool shouldBePaused)
{
    if(shouldBePaused) {
        npc(clip_)->stop();
        return;
    }
    npc(clip_)->start();
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* BackGroundMusicPlayer::class_()
{
    static ::java::lang::Class* c = ::class_(u"BackGroundMusicPlayer", 21);
    return c;
}

java::lang::Class* BackGroundMusicPlayer::getClass0()
{
    return class_();
}

