// Generated from /ArcadeGameProject/src/CentipedeListener.java

#pragma once

#include <fwd-ArcadeGameProject.hpp>
#include <java/awt/event/fwd-ArcadeGameProject.hpp>
#include <java/util/fwd-ArcadeGameProject.hpp>
#include <java/lang/Object.hpp>
#include <java/awt/event/KeyListener.hpp>

struct default_init_tag;

class CentipedeListener
    : public virtual ::java::lang::Object
    , public virtual ::java::awt::event::KeyListener
{

public:
    typedef ::java::lang::Object super;
    ::java::util::HashMap* keyPressedMap {  };
    CentipedeComponent* component {  };
protected:
    void ctor(CentipedeComponent* component);

public:
    virtual ::java::util::HashMap* getHashMap();
    void keyTyped(::java::awt::event::KeyEvent* e) override;
    void keyPressed(::java::awt::event::KeyEvent* e) override;
    void keyReleased(::java::awt::event::KeyEvent* e) override;

    // Generated
    CentipedeListener(CentipedeComponent* component);
protected:
    CentipedeListener(const ::default_init_tag&);


public:
    static ::java::lang::Class *class_();

private:
    virtual ::java::lang::Class* getClass0();
};
