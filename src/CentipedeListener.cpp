// Generated from /ArcadeGameProject/src/CentipedeListener.java
#include <CentipedeListener.hpp>

#include <CentipedeComponent.hpp>
#include <PlayerCharacter.hpp>
#include <com/sun/glass/events/KeyEvent.hpp>
#include <java/awt/event/KeyEvent.hpp>
#include <java/io/IOException.hpp>
#include <java/io/PrintStream.hpp>
#include <java/lang/Boolean.hpp>
#include <java/lang/ClassCastException.hpp>
#include <java/lang/Integer.hpp>
#include <java/lang/NullPointerException.hpp>
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

CentipedeListener::CentipedeListener(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

CentipedeListener::CentipedeListener(CentipedeComponent* component) 
    : CentipedeListener(*static_cast< ::default_init_tag* >(0))
{
    ctor(component);
}

void CentipedeListener::ctor(CentipedeComponent* component)
{
    super::ctor();
    this->component = component;
    this->keyPressedMap = new ::java::util::HashMap();
    npc(java_cast< ::java::util::HashMap* >(this->keyPressedMap))->put(::java::lang::Integer::valueOf(int32_t(37)), ::java::lang::Boolean::valueOf(false));
    npc(java_cast< ::java::util::HashMap* >(this->keyPressedMap))->put(::java::lang::Integer::valueOf(int32_t(38)), ::java::lang::Boolean::valueOf(false));
    npc(java_cast< ::java::util::HashMap* >(this->keyPressedMap))->put(::java::lang::Integer::valueOf(int32_t(39)), ::java::lang::Boolean::valueOf(false));
    npc(java_cast< ::java::util::HashMap* >(this->keyPressedMap))->put(::java::lang::Integer::valueOf(int32_t(40)), ::java::lang::Boolean::valueOf(false));
    npc(java_cast< ::java::util::HashMap* >(this->keyPressedMap))->put(::java::lang::Integer::valueOf(int32_t(85)), ::java::lang::Boolean::valueOf(false));
    npc(java_cast< ::java::util::HashMap* >(this->keyPressedMap))->put(::java::lang::Integer::valueOf(int32_t(68)), ::java::lang::Boolean::valueOf(false));
    npc(java_cast< ::java::util::HashMap* >(this->keyPressedMap))->put(::java::lang::Integer::valueOf(int32_t(32)), ::java::lang::Boolean::valueOf(false));
    npc(java_cast< ::java::util::HashMap* >(this->keyPressedMap))->put(::java::lang::Integer::valueOf(::com::sun::glass::events::KeyEvent::VK_PERIOD), ::java::lang::Boolean::valueOf(false));
    npc(java_cast< ::java::util::HashMap* >(this->keyPressedMap))->put(::java::lang::Integer::valueOf(::com::sun::glass::events::KeyEvent::VK_COMMA), ::java::lang::Boolean::valueOf(false));
}

java::util::HashMap* CentipedeListener::getHashMap()
{
    return java_cast< ::java::util::HashMap* >(this->keyPressedMap);
}

void CentipedeListener::keyTyped(::java::awt::event::KeyEvent* e)
{
}

void CentipedeListener::keyPressed(::java::awt::event::KeyEvent* e)
{
    auto keyCode = npc(e)->getKeyCode();
    npc(java_cast< ::java::util::HashMap* >(this->keyPressedMap))->put(::java::lang::Integer::valueOf(keyCode), ::java::lang::Boolean::valueOf(true));
}

void CentipedeListener::keyReleased(::java::awt::event::KeyEvent* e)
{
    auto keyCode = npc(e)->getKeyCode();
    npc(java_cast< ::java::util::HashMap* >(this->keyPressedMap))->put(::java::lang::Integer::valueOf(keyCode), ::java::lang::Boolean::valueOf(false));
    if(keyCode == ::java::awt::event::KeyEvent::VK_U) {
        auto nextLevel = int32_t(0);
        if(npc(this->component)->getLevelNum() == 2) {
            nextLevel = 0;
        } else {
            nextLevel = npc(this->component)->getLevelNum() + int32_t(1);
        }
        try {
            npc(this->component)->loadLevel(nextLevel);
        } catch (::java::io::IOException* ex) {
            npc(::java::lang::System::out())->println(u"ERROR LOADING LEVEL"_j);
        }
    }
    if(keyCode == ::java::awt::event::KeyEvent::VK_D) {
        auto nextLevel = int32_t(0);
        if(npc(this->component)->getLevelNum() == 0) {
            nextLevel = 2;
        } else {
            nextLevel = npc(this->component)->getLevelNum() - int32_t(1);
        }
        try {
            npc(this->component)->loadLevel(nextLevel);
        } catch (::java::io::IOException* ex) {
            npc(::java::lang::System::out())->println(u"ERROR LOADING LEVEL"_j);
        }
    }
    if(keyCode == ::java::awt::event::KeyEvent::VK_P) {
        npc(this->component)->setIsPaused(!npc(this->component)->IsPaused);
    }
    if(keyCode == ::java::awt::event::KeyEvent::VK_PERIOD) {
        if(npc(npc(this->component)->getCharacter())->getGunID() != 3) {
            npc(npc(this->component)->getCharacter())->changeGun(npc(npc(this->component)->getCharacter())->getGunID() + int32_t(1));
        } else {
            npc(npc(this->component)->getCharacter())->changeGun(1);
        }
    }
    if(keyCode == ::java::awt::event::KeyEvent::VK_COMMA) {
        if(npc(npc(this->component)->getCharacter())->getGunID() != 1) {
            npc(npc(this->component)->getCharacter())->changeGun(npc(npc(this->component)->getCharacter())->getGunID() - int32_t(1));
        } else {
            npc(npc(this->component)->getCharacter())->changeGun(3);
        }
    }
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* CentipedeListener::class_()
{
    static ::java::lang::Class* c = ::class_(u"CentipedeListener", 17);
    return c;
}

java::lang::Class* CentipedeListener::getClass0()
{
    return class_();
}

