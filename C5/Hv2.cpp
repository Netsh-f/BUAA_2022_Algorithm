#include <iostream>
#include<bits/stdc++.h>

using namespace std;

#define MAX 1005

struct poi {
    double x;
    double y;
} points[MAX];

int box[MAX];

bool comp_x (poi a, poi b) {
    return a.x < b.x;
}

bool comp_y (int a, int b) {
    return points[a].y < points[b].y;
}

double dis_max(poi a, poi b) {
    return max(fabs(a.x - b.x), fabs(a.y - b.y));
}

int min_dis (int p, int q) {
    if (q - p == 0) {
        return 10000000;
    }
    else if (q - p == 1) {
        return dis_max(points[p], points[q]);
    }
    else {
        double dis_min = 0;
        int m = (p + q) / 2;
        dis_min = min(min_dis(p, m-1), min_dis(m + 1, q));
//        int f_p = m;
        int tmp_p = 0;
        for (int i = p; i <= q; i++) {
            if (points[i].x >= (points[m].x - dis_min) && points[i].x <= (points[m].x + dis_min)) {
                box[tmp_p] = i;
                tmp_p++;
            }
        }
        sort(box , box + tmp_p, comp_y);
        for (int i = 0; i < tmp_p; i++) {
            for (int j = i + 1; j < tmp_p; j++) {
                if (points[box[j]].y - points[box[i]].y >= dis_min) {
                    break;
                }
                dis_min = min(dis_min, dis_max(points[box[i]], points[box[j]]));
            }
        }
        return dis_min;
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> points[i].x;
        cin >> points[i].y;
    }
    sort(points + 1, points + n + 1, comp_x);
    double ans = min_dis(1, n);
    printf("%.4lf\n", ans);
    return 0;
}
