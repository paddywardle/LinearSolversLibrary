#ifndef OPS_H
#define OPS_H

template<typename LinearObject>
class Ops{

    public:

        LinearObject& elemMult(const LinearObject& matA, const LinearObject& matB) const;

        LinearObject& elemAdd(const LinearObject& matA, const LinearObject& matB) const;

        LinearObject& elemSub(const LinearObject& matA, const LinearObject& matB) const;

        LinearObject& elemDiv(const LinearObject& matA, const LinearObject& matB) const;

        LinearObject& scalarMult(const LinearObject& matA, const double val) const;

};

#endif