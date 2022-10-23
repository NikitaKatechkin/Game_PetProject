#ifndef HANDLINGOBJECT_H
#define HANDLINGOBJECT_H

#include "../DataTypes.h"

class HandlingObject
{
public:
    HandlingObject() = default;
    virtual ~HandlingObject() = default;

public:
    virtual void handleEvents(EventQueue queue) = 0;
};

#endif