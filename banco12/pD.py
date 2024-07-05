import math


def rotate(px, py, cx, cy, angle_degrees):
    angle_radians = math.radians(-angle_degrees)
    cos_theta = math.cos(angle_radians)
    sin_theta = math.sin(angle_radians)
    x_new = cx + (px - cx) * cos_theta - (py - cy) * sin_theta
    y_new = cy + (px - cx) * sin_theta + (py - cy) * cos_theta
    return x_new, y_new


def calculate_vertices(x, y, w, h, v):
    hw = w / 2
    hh = h / 2
    corners = [
        (x + hw, y + hh),
        (x - hw, y + hh),
        (x - hw, y - hh),
        (x + hw, y - hh),
    ]

    # Rotate each corner around the center (x, y)
    rotated_corners = [rotate(px, py, x, y, v) for px, py in corners]

    return rotated_corners


def convex_hull(points):
    points = sorted(points)

    if len(points) <= 1:
        return points

    def cross(o, a, b):
        return (a[0] - o[0]) * (b[1] - o[1]) - (a[1] - o[1]) * (b[0] - o[0])

    lower = []
    for p in points:
        while len(lower) >= 2 and cross(lower[-2], lower[-1], p) <= 0:
            lower.pop()
        lower.append(p)

    upper = []
    for p in reversed(points):
        while len(upper) >= 2 and cross(upper[-2], upper[-1], p) <= 0:
            upper.pop()
        upper.append(p)

    return lower[:-1] + upper[:-1]


def calculate_centroid(vertices):
    x_coords = [v[0] for v in vertices]
    y_coords = [v[1] for v in vertices]
    centroid_x = sum(x_coords) / len(vertices)
    centroid_y = sum(y_coords) / len(vertices)
    return (centroid_x, centroid_y)


def calculate_angle(vertex, centroid):
    return math.atan2(vertex[1] - centroid[1], vertex[0] - centroid[0])


def sort_vertices_clockwise(vertices):
    centroid = calculate_centroid(vertices)
    vertices_with_angles = [(v, calculate_angle(v, centroid)) for v in vertices]
    sorted_vertices_with_angles = sorted(
        vertices_with_angles, key=lambda x: x[1], reverse=True
    )
    sorted_vertices = [v[0] for v in sorted_vertices_with_angles]
    return sorted_vertices


def polygon_area(vertices):
    n = len(vertices)
    area = 0.0
    for i in range(n):
        x1, y1 = vertices[i]
        x2, y2 = vertices[(i + 1) % n]
        area += x1 * y2
        area -= y1 * x2
    area = abs(area) / 2.0
    return area


n = int(input())
while n:
    m = int(input())
    variables = []
    areas = []
    all_vertices = []
    for i in range(m):
        variables.append(tuple(map(float, input().split())))
        vertices = calculate_vertices(*variables[-1])
        all_vertices.append(vertices)
        area = variables[-1][2] * variables[-1][3]
        areas.append(area)
    convex_hull_vertices = convex_hull(
        [item for sublist in all_vertices for item in sublist]
    )
    convex_hull_vertices = sort_vertices_clockwise(convex_hull_vertices)
    area_hull = polygon_area(convex_hull_vertices)
    tot_area = sum(areas)
    print(round(tot_area / area_hull * 100, 1), "%")
    n -= 1
