#ifndef SCREWHOLE_H
#define SCREWHOLE_H

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

class ScrewHole : public AbstractPart
{
public:
    ScrewHole(double drill, double drillDepth, double indentRad, double indentDepth);

    virtual ~ScrewHole();

protected:
    virtual Component build();

private:
    double m_drill;
    double m_drill_depth;
    double m_indent_rad;
    double m_indent_depth;
};

#endif // SCREWHOLE_H
