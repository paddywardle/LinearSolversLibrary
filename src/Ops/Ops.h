#ifndef OPS_H
#define OPS_H

template<typename LinearObject>
class Ops{

    public:

        virtual LinearObject& elemMult(const LinearObject& matA, const LinearObject& matB) const=0;

        virtual LinearObject& elemAdd(const LinearObject& matA, const LinearObject& matB) const=0;

        virtual LinearObject& elemSub(const LinearObject& matA, const LinearObject& matB) const=0;

        virtual LinearObject& elemDiv(const LinearObject& matA, const LinearObject& matB) const=0;

        virtual LinearObject& scalarMult(const LinearObject& matA, const double val) const=0;

};

#endif