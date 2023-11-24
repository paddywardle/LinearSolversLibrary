import sys
sys.path.append("python/build")

import LinSol

matA = LinSol.Matrix([
            [10, 1, 0, 0, 0, 0, 0],
            [1, 11, 1, 0, 0, 0, 0],
            [0, 1, 12, 1, 0, 0, 0],
            [0, 0, 1, 13, 1, 0, 0],
            [0, 0, 0, 1, 14, 1, 0],
            [0, 0, 0, 0, 1, 15, 1],
            [0, 0, 0, 0, 0, 1, 16]
])

vecA = LinSol.Vector([1, 2, 3, 4, 5, 6, 7])

print("matA@matA\n\n", LinSol.DMOps.matMul(matA, matA))
print("\n")
print("vecA@vecA\n\n", LinSol.DVOps.dot(vecA, vecA))
print("\n")
print("matA@vecA\n\n", LinSol.DVOps.DVMOps.matVecMul(matA, vecA))
print("\n")
print("vecA@matA\n\n", LinSol.DVOps.DVMOps.vecMatMul(vecA, matA))
