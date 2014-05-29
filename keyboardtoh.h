#ifndef KEYBOARDTOH_H
#define KEYBOARDTOH_H

//for windows compability?
#ifdef WIN32
#ifdef OOMLParts_EXPORTS
#define OOMLParts_EXP_DEC __declspec(dllexport)
#else
#define OOMLParts_EXP_DEC __declspec(dllimport)
#endif
#else
#define OOMLParts_EXP_DEC
#endif

#include <ooml/core/AbstractPart.h>

class KeyboardTOH : public AbstractPart
{
public:

    KeyboardTOH();

    virtual ~KeyboardTOH();

protected:
    virtual Component build();
};

#endif // KEYBOARDTOH_H
