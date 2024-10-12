from PIL import Image

x_start = 12  # 起始点坐标
y_start = 138
fill_width = 36  # 信息点宽度
fill_height = 13  # 信息点高度
space_width = 23  # 间隔宽度
space_height = 27  # 间隔高度
num_length = 9  # 准考证号长度


def bw_judge(R, G, B):  # bw_ judge用于判断一 个像素的填涂情况
    Gray_scale = 0.299 * R + 0.587 * G + 0.114 * B
    return Gray_scale < 132


def fill_judge(x, y):  # fill_ judge用于判断信息点的填涂情况
    count = 0
    for i in range(x, x + fill_width+1):
        for j in range(y, y + fill_height+1):
            R, G, B = pixels[i, j]
            if bw_judge(R, G, B):
                count = count + 1
    if count >= fill_width * fill_height * 0.64:
        return True


total_width = fill_width + space_width
total_height = fill_height + space_height
img = Image.open("fill.bmp")
pixels = img.load()

number = ""
for col in range(num_length):  # x从左至右，y从上至下对填涂区进行检测
    for row in range(10):
        x = x_start + total_width * col
        y = y_start + total_height * row
        if fill_judge(x, y) == True:
            number += str(row)
            break
    else:  # 10个信息点检测完毕后未发现有填涂
        number = number + "#"
print(number)
