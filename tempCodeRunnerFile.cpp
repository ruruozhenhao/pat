#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;

struct _thing {
    int num;
    int price;
    float per;
} p[10000];

bool cmp(_thing a, _thing b) {
    return a.per >= b.per;
}

int main() {
    int n, m;
    float sum = 0;

    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i].num);
    } 
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i].price);
        p[i].per = 1.0 * p[i].price / p[i].num;
    }
    
    sort(p, p+n, cmp);

    for (int i = 0; i < n; i++) {
        if (m - p[i].num >= 0) {
            m = m - p[i].num;
            //sum += p[i].price;  要是卖不完的话就糟了，自己的思维还是不够严禁。
            sum += m * p[i].per;
        } else {
            sum += m * p[i].per;
            break;
        }
    }

    printf("%.2f\n", sum);

    return 0;
}