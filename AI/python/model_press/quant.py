'''
模型量化公式：
Q = R / S + Z
S = (Rmax - Rmin)/(Qmax - Qmin)
Z = Qmax - Rmax/S

量化操作的优缺点：
    计算快，效率高，计算时的耗能降低
    内存占用小，方便数据文件的储存和传输
    计算精度会有一定程度的下降
'''

import sys
import numpy as np
import time

#定义浮点数集
R = np.random.randn(10).astype('float32')

#非对称量化范围
Qmin, Qmax = 0, 255

#缩放因子S
S = (R.max() - R.min()) / (Qmax - Qmin)

#零点Z
Z = Qmax - R.max() / S

#将浮点数集float32转化为定点数UInt8集
Q = np.round(R / S + Z).astype('uint8')

#将定点UInt8数据反量化为浮点数据Float32
R_ = ((Q - Z) * S).astype('float32')

# 使用均方误差计算差异
mse = ((R - R_)**2).mean()
print("原始数据：", R)
print("反量化后数据：", R_)
print("量化后数据：", Q)
print("原始数据和反量化后数据的均方误差：", mse)

#############################内存对比###############################
# 空数组的内存占用
empty_size = sys.getsizeof(np.array([]))

# 计算实际数据的内存占用
float32_size = (sys.getsizeof(R) - empty_size)
uint8_size = (sys.getsizeof(Q) - empty_size)

print("原始数据内存占用：%d Bytes" % float32_size)
print("量化后数据内存占用：%d Bytes" % uint8_size)
print("量化后数据与原始数据内存占用之比：", uint8_size / float32_size)

#############################速度对比###############################
# 预热次数
warmup = 100

# 重复次数
repeat = 10000

# 预热
sum = R
for i in range(warmup):
    sum += R

sum = Q
for i in range(warmup):
    sum += Q

# 速度测试
start = time.time()
sum = R
for i in range(repeat):
    sum += R
float32_time = time.time() - start

start = time.time()
sum = Q
for i in range(repeat):
    sum += Q
uint8_time = time.time() - start

print("原始数据求和 %d 次耗时 ：%f s" % (repeat, float32_time))
print("量化后数据求和 %d 次耗时：%f s" % (repeat, uint8_time))
print("量化后数据与原始数据计算耗时之比：", uint8_time / float32_time)