#include "Header.h"



int maxSequence(const std::vector<int>& arr) {
    int max_sum = 0;
    int sum = 0;
    int minus = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] >= 0) {
            sum += arr[i];
        }
        else {
            int tmp = max(sum, max_sum);
            max_sum = max(tmp, sum + max_sum + minus);
            sum = 0;
            minus = 0;
            while (arr[i] < 0 && i < arr.size()-1) {
                minus += arr[i];
                i++;
            }
            i--;
            
        }
        cout << "arr["<<i<<"]: " << arr[i] << " minus: " << minus << " max_sum: " << max_sum << " summ: " << sum << endl;
        
    }
    int tmp = max(sum, max_sum);
    max_sum = max(tmp, sum + max_sum + minus);
    return max_sum;
}






int main(void) {
    //cout << endl << maxSequence({ -2, 1, -3, 4, -1, 2, 1, -5, 4 });
    cout << endl << maxSequence({7, 4, 11, - 11, 39, 36, 10, - 6, 37, - 10, - 32, 44, - 26, - 34, 43, 43});
    /*
    Expected: equal to 155
    Actual: 139
    */

}