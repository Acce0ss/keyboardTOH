#ifndef KEYBOARDMOUNT_H
#define KEYBOARDMOUNT_H

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

class KeyboardMount : public AbstractPart
{
public:

    KeyboardMount();

    virtual ~KeyboardMount();

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
    double m_slot_depth;
    double m_sub_slot_depth;

    double m_slot_pos_y_edge;
    double m_slot_neg_y_edge;
    double m_slot_pos_x_edge;
    double m_slot_neg_x_edge;

    double m_keys_slot_length;
    double m_keys_slot_width;
    double m_keys_slot_displacement;
};
#endif // KEYBOARDMOUNT_H
