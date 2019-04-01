// Generated from /ArcadeGameProject/src/Main.java
#include <Main.hpp>

#include <CentipedeComponent.hpp>
#include <java/awt/Component.hpp>
#include <java/io/PrintStream.hpp>
#include <java/lang/NullPointerException.hpp>
#include <java/lang/Runnable.hpp>
#include <java/lang/String.hpp>
#include <java/lang/System.hpp>
#include <java/lang/Thread.hpp>
#include <javax/swing/JFrame.hpp>

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

template<typename T>
static T* npc(T* t)
{
    if(!t) throw new ::java::lang::NullPointerException();
    return t;
}

Main::Main(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

Main::Main()
    : Main(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void Main::main(::java::lang::StringArray* args)
{
    clinit();
    npc(::java::lang::System::out())->println(u"Write your cool arcade game here!"_j);
    auto frame = new ::javax::swing::JFrame(u"Centipede"_j);
    auto game = new CentipedeComponent();
    npc(game)->setFocusable(true);
    npc(game)->requestFocusInWindow();
    npc(frame)->add(static_cast< ::java::awt::Component* >(game));
    auto thread = new ::java::lang::Thread(static_cast< ::java::lang::Runnable* >(game));
    npc(thread)->start();
    npc(frame)->setDefaultCloseOperation(::javax::swing::JFrame::EXIT_ON_CLOSE);
    npc(frame)->pack();
    npc(frame)->setVisible(true);
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* Main::class_()
{
    static ::java::lang::Class* c = ::class_(u"Main", 4);
    return c;
}

java::lang::Class* Main::getClass0()
{
    return class_();
}

