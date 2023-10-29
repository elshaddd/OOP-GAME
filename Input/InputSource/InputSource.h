#ifndef INPUT_SOURCE_H
#define INPUT_SOURCE_H

class InputSource
{
public:
    virtual ~InputSource() = default;

    virtual char getInput() = 0;
};

#endif