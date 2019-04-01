// Generated from /ArcadeGameProject/src/StartButtonListener.java
#include <StartButtonListener.hpp>

StartButtonListener::StartButtonListener(const ::default_init_tag&)
    : super(*static_cast< ::default_init_tag* >(0))
{
    clinit();
}

StartButtonListener::StartButtonListener()
    : StartButtonListener(*static_cast< ::default_init_tag* >(0))
{
    ctor();
}

void StartButtonListener::actionPerformed(::java::awt::event::ActionEvent* e)
{
}

extern java::lang::Class *class_(const char16_t *c, int n);

java::lang::Class* StartButtonListener::class_()
{
    static ::java::lang::Class* c = ::class_(u"StartButtonListener", 19);
    return c;
}

java::lang::Class* StartButtonListener::getClass0()
{
    return class_();
}

