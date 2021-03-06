#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

string addString(string& nums1, string& nums2){
    int i = nums1.size() - 1;
    int j = nums2.size() - 1;
    int add = 0;
    string ans;

    while(i >= 0 || j >= 0 || add != 0){
        int x = i >= 0 ? nums1[i] - '0' : 0;
        int y = j >= 0 ? nums2[j] - '0' : 0;
        int res = x + y + add;

        ans.push_back(res % 10 + '0');
        add = res / 10;

        i--;
        j--;
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

// string multiply(string& nums1, string& nums2){
//     if(nums1 == "0" || nums2 == "0"){
//         return "0";
//     }

//     string ans = "0";
//     int m = nums1.size();
//     int n = nums2.size();
//     for(int i = n - 1; i >= 0; --i){
//         string tmp;
//         int add = 0;
//         for(int j = n - 1; j > i; --j){
//             tmp.push_back(0 + '0');
//         }

//         int y = nums2[i] - '0';
//         for(int j = m - 1; j >= 0; --j){
//             int x = nums1[j] - '0';
//             int res = x * y + add;
//             tmp.push_back(res % 10 + '0');
//             add = res / 10;
//         }
//         while(add != 0 ){
//             tmp.push_back(add % 10 + '0');
//             add /= 10;
//         }

//         reverse(tmp.begin(), tmp.end()); 
//         ans = addString(ans, tmp);  
//     }
//     return ans;
// }

string multiply(string& nums1, string& nums2){
    if(nums1 == "0" || nums2 == "0"){
        return "0";
    }

    vector<int> ans(nums1.size() + nums2.size(), 0);
    for(int i = nums1.size() - 1; i >= 0; --i){
        int x = nums1[i] - '0';
        for(int j = nums2.size() - 1; j >= 0; --j){
            int y = nums2[j] - '0';
            ans[i + j + 1] += x * y;
            if(ans[i + j + 1] > 9){
                ans[i + j] += ans[i + j + 1] / 10;
                ans[i + j + 1] %= 10;
            }
        }
    }

    string ansStr;
    int index = 0;
    if(ans[0] == 0) index++;
    while(index < ans.size()){
        ansStr += (ans[index] + '0');
        index++;
    }

    return ansStr;
}


int main(void)
{
    string nums1 = "2";
    string nums2 = "3";
    cout << addString(nums1,nums2) << endl;
    cout << multiply(nums1,nums2) << endl;
    return 0;
}