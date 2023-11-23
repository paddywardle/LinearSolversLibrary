import sys
sys.path.append("python/build")

import LinSol

A = LinSol.DenseMatrix([
            [10, 1, 0, 0, 0, 0, 0],
            [1, 11, 1, 0, 0, 0, 0],
            [0, 1, 12, 1, 0, 0, 0],
            [0, 0, 1, 13, 1, 0, 0],
            [0, 0, 0, 1, 14, 1, 0],
            [0, 0, 0, 0, 1, 15, 1],
            [0, 0, 0, 0, 0, 1, 16]
])

b = LinSol.DenseVector([1,2,3,4,5,6,7])

print("Gauss Seidel")
x = LinSol.Solvers.GSDense.getInstance()
# .solver(A, b)
# print(x)

# print("Jacobi")
# x = LinSol.Solvers.Jac.solver(A, b)
# print(x)

# print("Steepest Descent")
# x = LinSol.Solvers.SD.solver(A, b)
# print(x)

# print("Conjugate Gradient")
# x = LinSol.Solvers.CG.solver(A, b)
# print(x)

# print("Gaussian Elimination")
# x = LinSol.Solvers.GE.solver(A, b)
# print(x)