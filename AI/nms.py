"""
TODO:使用 Python实现NMS,此处的NMS为单个类别的NMS
"""
import numpy as np
import matplotlib.pyplot as plt

def plot_bbox(dets, c='k'):
    x1 = dets[:,0]
    print("x1", x1)
    y1 = dets[:,1]
    print("y1", y1)
    x2 = dets[:,2]
    print("x2", x2)
    y2 = dets[:,3]
    print("y2", y2)

    plt.plot([x1,x2], [y1,y1], c)#上
    plt.plot([x1,x1], [y1,y2], c)#右
    plt.plot([x1,x2], [y2,y2], c) #下
    plt.plot([x2,x2], [y1,y2], c) #左
    plt.title(" nms")

def test():
    '''
    测试NMS
    :return:
    '''
    bbox=np.array([[100,100,210,210,0.72],
                   [250,250,420,420,0.8],
                   [220,220,320,330,0.92],
                   [100,100,210,210,0.72],
                   [230,240,325,330,0.81],
                   [220,230,315,340,0.9]])

    plt.figure(1)
    ax1 = plt.subplot(1, 2 ,1)
    ax2 = plt.subplot(1, 2, 2)

    plt.sca(ax1)
    plot_bbox(bbox, 'b')

    nms_bbox = nms(bbox, thresh=0.5)
    plt.sca(ax2)
    plot_bbox(bbox[nms_bbox], 'y')
    plt.show()

def nms(bbox, thresh):
    '''
    非极大值抑制有许多算法，这里采用最原生、朴素的方法
    :param bbox:同一个类别下若干个回归框的坐标和得分向量如:
        [[x1, y1, x2, y2, score],...] ...其中(x1, y1), (x2, y2)分别表示回归框的左下坐标和右上坐标
    :param thresh:
        非极大值抑制的阈值
    :return: 被抑制后的检测框
    '''

    x1 = bbox[:, 0]
    y1 = bbox[:, 1]
    x2 = bbox[:, 2]
    y2 = bbox[:, 3]

    areas = (x2 - x1 + 1) * (y2 - y1 + 1)#所有回归框的面积

    score = bbox[:, 4]
    #首先对所有回归框进行升序排序，这里保存升序后的数组索引
    index = score.argsort()[::-1]
    save_bbox = []#保存NMS后的回归框

    while index.size > 0:
        i = index[0]#获取当前socre最大的回归框（的索引）
        save_bbox.append(i)

        #计算当前最大socre的回归框与剩余所有框的iou
        x1_left = np.maximum(x1[i], x1[index[1:]])#同时计算交集框的左横坐标
        x2_right = np.minimum(x2[i], x2[index[1:]])#同时计算交集框的右横坐标
        y1_down = np.maximum(y1[i], y1[index[1:]])#同时计算交集框的左下的纵坐标
        y2_top = np.minimum(y2[i], y2[index[1:]])#同时计算交集框的右上纵坐标

        intersection_widths = np.maximum(0, x2_right - x1_left + 1)
        intersection_heights = np.maximum(0, y2_top - y1_down  + 1)
        intersection_areas = intersection_widths * intersection_heights

        ious = intersection_areas / (areas[i] + areas[index[1:]] - intersection_areas)

        iou_index = np.where(ious <= thresh)[0] #只取出iou中小于等于阈值的iou的索引<=>将值较大的iou抑制掉
        index = index[iou_index + 1] #加1的原因：需要在index数组中去取这一轮非极大值抑制后的iou所在index中索引

    return save_bbox


if __name__ == "__main__" :
    test()