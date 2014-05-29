#include <ooml/components.h>
#include <ooml/core.h>

#include "screwhole.h"

ScrewHole::ScrewHole(double drill, double drillDepth, double indentRad, double indentDepth) : AbstractPart(),
    m_drill(drill), m_drill_depth(drillDepth), m_indent_rad(indentRad), m_indent_depth(indentDepth)
{
    rebuild();
}

ScrewHole::~ScrewHole()
{

}

Component ScrewHole::build()
{
    Component indent_hole = Cylinder(m_indent_rad, m_indent_depth);

    Component drill_hole = Cylinder(m_drill, m_drill_depth*2);

    return indent_hole.translatedCopy(0,0,m_drill_depth/2+m_indent_depth/2)
            + indent_hole.translatedCopy(0,0, -m_drill_depth/2-m_indent_depth/2)
            + drill_hole;

}
