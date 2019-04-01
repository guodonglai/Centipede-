// Generated from /ArcadeGameProject/src/Moveable.java

#pragma once

#include <fwd-ArcadeGameProject.hpp>
#include <java/lang/Object.hpp>

struct Moveable
    : public virtual ::java::lang::Object
{
    virtual void moveUp() = 0;
    virtual void moveRight() = 0;
    virtual void moveDown() = 0;
    virtual void moveLeft() = 0;

    // Generated
    static ::java::lang::Class *class_();
};
