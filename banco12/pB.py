import math

n = int(input())
while n:
    m = int(input())
    curr_pos = [0, 0]
    curr_angle = 0
    for i in range(m):
        diff_angle, diff_dist = map(float, input().split())
        curr_angle += diff_angle
        curr_angle %= 360
        if curr_angle == 0:
            curr_pos[1] += diff_dist
        elif curr_angle == 90:
            curr_pos[0] -= diff_dist
        elif curr_angle == 180:
            curr_pos[1] -= diff_dist
        elif curr_angle == 270:
            curr_pos[0] += diff_dist
        if curr_angle > 0 and curr_angle < 90:
            curr_pos[0] -= diff_dist * math.fabs(math.sin(curr_angle * math.pi / 180))
            curr_pos[1] += diff_dist * math.fabs(math.cos(curr_angle * math.pi / 180))
        elif curr_angle > 90 and curr_angle < 180:
            curr_pos[0] -= diff_dist * math.fabs(math.sin(curr_angle * math.pi / 180))
            curr_pos[1] -= diff_dist * math.fabs(math.cos(curr_angle * math.pi / 180))
        elif curr_angle > 180 and curr_angle < 270:
            curr_pos[0] += diff_dist * math.fabs(math.sin(curr_angle * math.pi / 180))
            curr_pos[1] -= diff_dist * math.fabs(math.cos(curr_angle * math.pi / 180))
        elif curr_angle > 270 and curr_angle < 360:
            curr_pos[0] += diff_dist * math.fabs(math.sin(curr_angle * math.pi / 180))
            curr_pos[1] += diff_dist * math.fabs(math.cos(curr_angle * math.pi / 180))

    print(curr_pos[0], curr_pos[1])
    n -= 1
