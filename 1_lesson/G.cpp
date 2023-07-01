#include <iostream>
#include <algorithm>

int main() {
    int x1, y1, x2, y2, x3, y3, x4, y4;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    int left = std::max(x1, x3);
    int right = std::min(x2, x4);
    int bottom = std::max(y1, y3);
    int top = std::min(y2, y4);

    int intersection_area = 0;
    if (left < right && bottom < top) {
        intersection_area = (right - left) * (top - bottom);
    }

    int area1 = (x2 - x1) * (y2 - y1);
    int area2 = (x4 - x3) * (y4 - y3);
    int total_area = area1 + area2;

    if (intersection_area > 0) {
        total_area -= intersection_area;
    }

    std::cout << total_area << std::endl;

    return 0;
}
