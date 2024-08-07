
#include <algorithm>
#include <iostream>
#include <vector>


class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        int n = nums.size(), i = 0, j = 1, k = 2, t1 = 1, t2 = 1, t3 = 1, ti = 0, tj = 0, tk = 0,val=0;
        bool fi = false, fj = false, fk = false;
        std::vector<int> sol;
        std::vector<std::vector<int>> res;

        std::sort(nums.begin(),nums.end());
        ti = nums[0];
        tj = nums[1];
        tk = nums[2];
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] == ti && fi)
                continue;
            fi = false;

            val = -nums[i];
            j = i + 1;
            k = nums.size() - 1;
            while (j < k) {
                if (nums[j] + nums[k] > val) {
                    k--;
                    fj = false;
                    continue;
                }
                if (nums[j] + nums[k] < val) {
                    j++;
                    fj = false;
                    continue;
                }

                if (tj == nums[j]&&nums[k]==tk && fj) {
                    j++;
                    k--;
                    continue;
                }



                if (nums[j] + nums[k] == val) {
                    res.push_back({ nums[i],nums[j],nums[k] });

                    ti = nums[i];
                    tj = nums[j];
                    tk = nums[k];

                    fi = fj = fk = true;

                    k--;
                    j++;
                    continue;
                }

            }

        }



        return res;
    }
};


int main(void) {

    std::vector<int> a = { -2, 0, 1, 1, 2
    };
    Solution sol;
    sol.threeSum(a);
    return 0;
}