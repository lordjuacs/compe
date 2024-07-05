import math


def point_subtract(p, q):
    return (p[0] - q[0], p[1] - q[1])


def point_dot(p, q):
    return p[0] * q[0] + p[1] * q[1]


def point_cross(p, q):
    return p[0] * q[1] - p[1] * q[0]


def point_length(p):
    return math.sqrt(p[0] * p[0] + p[1] * p[1])


def distance(p, q1, q2):
    if point_dot(point_subtract(p, q1), point_subtract(q2, q1)) < 0:
        d = point_length(point_subtract(p, q1))
    elif point_dot(point_subtract(p, q2), point_subtract(q1, q2)) < 0:
        d = point_length(point_subtract(p, q2))
    else:
        d = abs(
            point_cross(point_subtract(p, q1), point_subtract(q2, q1))
        ) / point_length(point_subtract(q2, q1))
    return d / 2


def find_maximum_radius(inner, outer):
    max_radius = float("inf")
    for i in range(len(inner)):
        for j in range(len(outer)):
            max_radius = min(
                max_radius, distance(inner[i], outer[j], outer[(j + 1) % len(outer)])
            )
            max_radius = min(
                max_radius, distance(outer[j], inner[i], inner[(i + 1) % len(inner)])
            )
    return max_radius


t = int(input())
for i in range(t):
    n_inner = int(input())
    inner = []
    for i in range(n_inner):
        inner.append(tuple(map(float, input().split())))

    n_outer = int(input().strip())
    outer = []
    for i in range(n_outer):
        outer.append(tuple(map(float, input().split())))

    max_radius = find_maximum_radius(inner, outer)
    print(f"{max_radius:.10f}")
