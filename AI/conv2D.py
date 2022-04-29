'''
todo:
    1.采用累积求和的方法实现2D卷积: conv2D()
    2.采用img2col的方法实现2D卷积: conv2D_img2col()
    3.用例测试
'''
import numpy as np


def conv2D(feature, kernel_size, padding=0, stride=1):
    """
    :param feature:输入特征图
    :param kernel_size: 卷积核大小，默认是int类型
    :param padding:0填充
    :param stride:滑动步长
    :return: 输出特征图
    """
    #先不考虑Batch、通道数
    h_in, w_in = feature.shape

    #init a kernel
    filter = np.ones((kernel_size, kernel_size))

    #根据卷积计算公式计算输出特征图的大小 (H + 2p - k)/s + 1
    h_out = (h_in + 2 * padding - kernel_size ) // stride + 1
    w_out = (w_in + 2 * padding - kernel_size) // stride + 1
    feature_out = np.zeros((h_out, w_out))

    for row in range(0, (h_in + 2 * padding - kernel_size + 1), stride):
        for col in range(0, (w_in + 2 * padding - kernel_size + 1), stride):
            #卷积核滤波/滑窗/提取特征
            patch =  feature[row : row + kernel_size, col : col + kernel_size]
            feature_out[row][col] = np.sum(patch * filter)#与卷积核乘积累加

    return feature_out


def conv2D_img2col(feature, kernel_size, padding=0, stride=1):
    """
    :param feature:
    :param kernel_size:
    :param padding:
    :param stride:
    :return:
    """
    h_in, w_in = feature.shape
    filter = np.ones((kernel_size, kernel_size))

    h_out = h_in + 2 * padding - kernel_size // stride + 1
    w_out = w_in + 2 * padding - kernel_size // stride + 1
    feature_out = np.zeros((h_out, w_out))
    img2col_matrix = np.zeros((kernel_size * kernel_size, h_out * w_out))

    col = 0
    for i in range(0, (h_in + 2 * padding - kernel_size + 1), stride):
        for j in range(0, (w_in + 2 * padding - kernel_size + 1), stride):
            img2col_matrix[:, col] = (feature[i : i + kernel_size, j : j + kernel_size]).reshape(-1)
            ++col

    # Matrix multiply: (1,n) x (n,m) = (1,m)
    feature_out = np.matmul(filter.reshape(1, -1), img2col_matrix).reshape(h_out, w_out)

    return feature_out


def test():
    input = np.random.random((512, 512))
    output = conv2D(
        feature=input,
        kernel_size=3,
        padding=0,
        stride=1
    )
    print("Conv2D输出特征图大小:", output.shape)

    output = conv2D_img2col(
        feature=input,
        kernel_size=3,
        padding=0,
        stride=1
    )
    print("Conv2d_img2col输出特征图大小:", output.shape)


if __name__ == "__main__":
    test()