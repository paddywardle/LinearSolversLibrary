import numpy as np

A = np.loadtxt('files/Ax.txt', delimiter=',')
print(A.shape)
b = np.loadtxt('files/bx.txt', delimiter=',')

print(np.linalg.solve(A, b))