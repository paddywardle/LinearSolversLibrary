#ifndef OPS_H
#define OPS_H

template<typename LinearObject>
class Ops{

    public:

        virtual LinearObject elemMult(const LinearObject& objA, const LinearObject& objB) const=0;

        virtual LinearObject elemAdd(const LinearObject& objA, const LinearObject& objB) const=0;

        virtual LinearObject elemSub(const LinearObject& objA, const LinearObject& objB) const=0;

        virtual LinearObject elemDiv(const LinearObject& objA, const LinearObject& objB) const=0;

        virtual LinearObject scalarMult(const LinearObject& objA, const double val) const=0;

        Ops() = default;
        ~Ops() = default;

};

#endif