# include<bits/stdc++.h>
using namespace std;
void knapsack(int n, float wt[], float p[], float cap) {
        float x[20], tp = 0;
        int i, j, u;
        u = cap;

        for (i = 0; i < n; i++)
                x[i] = 0.0;

        for (i = 0; i < n; i++) {
                if (wt[i] > u)
                        break;
                else {
                        x[i] = 1.0;
                        tp = tp + p[i];
                        u = u - wt[i];
                }
        }

        if (i < n)
                x[i] = u/wt[i];

        tp = tp + (x[i] * p[i]);

        
        cout<<"Maximum profit: "<<tp<<endl;

}

int main() {
        float wt[20], p[20], cap;
        int num, i, j;
        float ratio[20], temp;
        
        cin>>num;

        cout<<"Enter wts and profits of each object "<<endl;
        for (i = 0; i < num; i++) {
                cin>>wt[i]>>p[i];
        }

        cout<<"Capacity  of knapsack? ";
        cin>>cap;

        for (i = 0; i < num; i++) {
                ratio[i] = p[i] / wt[i];
        }

        for (i = 0; i < num; i++) {
                for (j = i + 1; j < num; j++) {
                        if (ratio[i] < ratio[j]) {
                                temp = ratio[j];
                                ratio[j] = ratio[i];
                                ratio[i] = temp;
                                temp = wt[j];
                                wt[j] = wt[i];
                                wt[i] = temp;
                                temp = p[j];
                                p[j] = p[i];
                                p[i] = temp;
                        }
                }
        }

        knapsack(num, wt, p, cap);
        return(0);
}
