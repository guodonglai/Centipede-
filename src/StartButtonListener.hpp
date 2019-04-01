// Generated from /ArcadeGameProject/src/StartButtonListener.java

#pragma once

#include <fwd-ArcadeGameProject.hpp>
#include <java/awt/event/fwd-ArcadeGameProject.hpp>
#include <java/lang/Object.hpp>
#include <java/awt/event/ActionListener.hpp>

struct default_init_tag;

class StartButtonListener
    : public virtual ::java::lang::Object
    , public virtual ::java::awt::event::ActionListener
{

public:
    typedef ::java::lang::Object super;
    void actionPerformed(::java::awt::event::ActionEvent* e) override;

    // Generated
    StartButtonListener();
protected:
    StartButtonListener(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
