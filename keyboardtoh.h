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

private:
    double m_lenght;
    double m_width;
    double m_thickness;

    double m_pos_y_edge;
    double m_neg_y_edge;
    double m_pos_x_edge;
    double m_neg_x_edge;

    double m_slot_displacement;
    double m_slot_length;
    double m_slot_width;
    double m_sub_slot_depth;

    double m_slot_pos_y_edge;
    double m_slot_neg_y_edge;
    double m_slot_pos_x_edge;
    double m_slot_neg_x_edge;
};

#endif // KEYBOARDTOH_H
