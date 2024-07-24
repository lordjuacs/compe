white_sheet = tuple(map(float, input().split()))
first_black_sheet = tuple(map(float, input().split()))
second_black_sheet = tuple(map(float, input().split()))

wb1_area = max(
    0,
    min(white_sheet[2], first_black_sheet[2])
    - max(white_sheet[0], first_black_sheet[0]),
) * max(
    0,
    min(white_sheet[3], first_black_sheet[3])
    - max(white_sheet[1], first_black_sheet[1]),
)
wb2_area = max(
    0,
    min(white_sheet[2], second_black_sheet[2])
    - max(white_sheet[0], second_black_sheet[0]),
) * max(
    0,
    min(white_sheet[3], second_black_sheet[3])
    - max(white_sheet[1], second_black_sheet[1]),
)
all_area = max(
    0,
    min(white_sheet[2], first_black_sheet[2], second_black_sheet[2])
    - max(white_sheet[0], first_black_sheet[0], second_black_sheet[0]),
) * max(
    0,
    min(white_sheet[3], first_black_sheet[3], second_black_sheet[3])
    - max(white_sheet[1], first_black_sheet[1], second_black_sheet[1]),
)
white_area = (white_sheet[2] - white_sheet[0]) * (white_sheet[3] - white_sheet[1])
occluded_area = wb1_area + wb2_area - all_area

print("YES" if occluded_area < white_area else "NO")
