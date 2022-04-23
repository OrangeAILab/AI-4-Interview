//C++实现NMS
// Created by heyue on 2022/4/23.
//
#include <vector>
#include <algorithm>

using  namespace  std;

struct Bbox{
    double  x;
    double  y;
    double  w;
    double  h;

    double score;
};

double iou(Bbox& box1, Bbox& box2){
    double x1 = std::max(box1.x, box2.x);//inter_area left x
    double x2 = std::min(box1.x + box1.w, box2.x + box2.w);
    double y1 = std::max(box1.y, box2.y);
    double y2 = std::min(box1.y + box1.h, box2.y + box2.w);

    double inter_area = (x2 - x1) * (y2 - y1);
    double iou = inter_area / (box1.w * box1.h + box2.w * box2.h - inter_area);

    return iou;
}

bool sort_score(Bbox& bbox1, Bbox& bbox2){
    return (bbox1.score > bbox2.score);
}

vector<Bbox> nms(vector<Bbox>& bbox, double thresh){
    vector<Bbox> result;

    while (bbox.size() > 0){

        std::sort(bbox.begin(), bbox.end(), sort_score);

        result.push_back(bbox[0]);

        for(int i = 0; i < bbox.size() - 1; ++i){
            double iou_score = iou(bbox[0], bbox[i + 1]);
            if (iou_score > thresh){
                bbox.erase(bbox[i + 1]);
            }
        }
        bbox.erase(bbox[0]);
    }

    return bbox;
}









