#include <iostream>
#include <iomanip>
#include <math.h>


int main()
{
    int n;
    double points[100][2];
    float p1, p2;
    double x = 0.0, y = 0.0, t = 0.0, dis = 0.0;
    std::cin >> n;

    for(int i = 0; i < n; i++)
    {
        std::cin >> p1 >> p2;
        points[i][0] = static_cast<double>(p1);
        points[i][1] = static_cast<double>(p2);
    }

    for (int i=0; i< n; i++)
    {
        for (int j=i+1;j < n; j++){
            x = points[i][0] - points[j][0];
            y = points[i][1] - points[j][1];
            t = pow(x, 2) + pow(y, 2);
            if (dis  < t)
            {
                dis = t;
            }

        }
    }
    dis = sqrt(dis);
    std::cout << std::fixed << std::setprecision(4) << dis << std::endl;
}