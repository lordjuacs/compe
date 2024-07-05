def is_point_in_triangle(A, B, C, P):
    def vector_dot(v1, v2):
        return v1[0] * v2[0] + v1[1] * v2[1]

    v0 = (C[0] - A[0], C[1] - A[1])
    v1 = (B[0] - A[0], B[1] - A[1])
    v2 = (P[0] - A[0], P[1] - A[1])

    dot00 = vector_dot(v0, v0)
    dot01 = vector_dot(v0, v1)
    dot02 = vector_dot(v0, v2)
    dot11 = vector_dot(v1, v1)
    dot12 = vector_dot(v1, v2)

    invDenom = 1 / (dot00 * dot11 - dot01 * dot01)
    u = (dot11 * dot02 - dot01 * dot12) * invDenom
    v = (dot00 * dot12 - dot01 * dot02) * invDenom

    return u >= 0 and v >= 0 and (u + v) <= 1


def area(A, B, C):
    return abs((A[0] * (B[1] - C[1]) + B[0] * (C[1] - A[1]) + C[0] * (A[1] - B[1])) / 2)


# Example usage:
A = tuple(map(float, input().split()))
B = tuple(map(float, input().split()))
C = tuple(map(float, input().split()))
n = int(input())
count = 0
for i in range(n):
    P = tuple(map(float, input().split()))
    count += is_point_in_triangle(A, B, C, P)
print(round(area(A, B, C), 1))
print(count)
