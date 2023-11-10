/*
☞ Better.Call.Vee ☜
created: 11th November, 2023 04:09:20 GMT+6
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

double eps = 1e-6, n, height, total_area, each;

double cut_height(double need) {
    double low = 0, high = height, cut, base_of_cut, area_of_cut;
    while(high - low > eps) {
        cut = low + (high - low) / 2.0;
        base_of_cut = (height - cut) / height;
        area_of_cut = 0.5 * (base_of_cut + 1.0) * cut;

        if(area_of_cut < need)
            low = cut;
        else if(area_of_cut > need)
            high = cut;
        else
            break;
    }
    return height - cut;
}

/*
একটা ত্রিভূজ কাটলে শুধুমাত্র সবার উপরের ভাগ বাদে বাকি সব ট্রাপিজিয়াম হিসেবে
ভাগ হয়। 
    /----------\ উপরের বেজ
   /____________\ নীচের বেজ
ট্রাপিজিয়ামের ক্ষেত্রফল হলো ০.৫ গুণ উপরের বেজ + নিচের বেজ গুণ উচ্চতা 

আমরা প্রত্যেকবার binary search করে একেকটা উচ্চতা নিচ্ছি। এরপর ট্রাপিজিয়ামের
উপরের বেজ বের করে ক্ষেত্রফল বের করে চেক করতেসি যে আমাদের যতোটুক দরকার 
ততোটুক এর সাথে মিলতেসে কিনা।
ট্রাপিজিয়াম এর উপরের বেজ কিভাবে বের করতেসি??
=> নিচের বেজ সবসময় ১(দেওয়া আছে)। আমাদের গাজর হলো একটা সমদ্বিবাহু ত্রিভুজ। 
আমরা বাইনারি সার্চ করে যেই হাইট না নিচ্ছি(cut), ধরি সেইটা দিয়ে আমরা একটা ছোট 
ত্রিভুজ বানাবো। এই ছোট ত্রিভুজের ভূমিই হলো আমাদের এই ভাগ প্রত্যেক ভাগের 
ট্রাপিজিয়ামের উপরের বেজ।
 *         /\
 *        /  \ এই চিত্র দেখলেই বুঝা যায়।
 *       /  x \
 *      /------\ ধরি, আমরা এই বরাবর কাট করেছি। তাহলে, এর উপরের অংশে কিন্তু একটা ছোট ত্রিভুজ সৃষ্টি হয়েছে।
 *     /        \ 
 *    /----------\
 *   /____________\ 
এবার এই ছোট x ত্রিভুজ এর ভূমিই কিন্তু আমাদের সেই ট্রাপিজিয়াম এর আপার বেজ।
তাহলে একটা অনুপাত করা যাক।
ছোট ত্রিভুজের ভূমি    ছোট ত্রিভুজের উচ্চতা(cut)
---------------- = -------------------
বড় ত্রিভুজের ভূমি     বড় ত্রিভুজের উচ্চতা(height)

হিসাব নিকাশ শেষে সেই ট্রাপিজিয়ামের আপার বেজ দাড়ায় = height - cut / height
বড় ত্রিভুজের ভুমি কিন্তু ১(প্রশ্নেই দেওয়া আছে)।
*/

int main() {
    cin >> n >> height;
    total_area = 0.5 * height;
    each = total_area / n; //প্রত্যেক ভাগে যতো করে এরিয়া পড়বে।

    for(double i = n - 1.0; i >= 1.0; i -= 1.0) { //n - 1 থেকে লুপ কারণ নিচে থেকে হিসাব করতেসি।
        double area_from_root = i * each; //গুণ কারন এরিয়ার হিসাব ভূমি থেকে করা হচ্ছে, চিত্র দেখলেই বুঝা যায়
        cout << fixed << setprecision(13) << cut_height(area_from_root) << " ";
    }

    return 0;
}

/**
 * PROBLEM SUMMARY: Equal Area Triangle Sections
 *
 * Igor has adopted n little bunnies and has an isosceles triangle-shaped carrot
 * with a base length of 1 unit and height h units. He wants to cut the carrot
 * into n pieces of equal area for the bunnies by making n - 1 cuts parallel
 * to the base. The challenge is to determine the positions of the cuts to
 * ensure equal areas.
 *
 * The area of the isosceles triangle (carrot) is calculated as (base * height)
 * / 2. Each piece must have an area of (total area / n).
 *
 * The goal is to find the distances from the apex (top) of the triangle to each
 * cut, ensuring that the area below each cut (and above the previous cut, if
 * any) is equal.
 *
 * Triangle Visualization (not to scale):
 *
 *         /\
 *        /  \
 *       /    \ <-- Cut 1 (distance x1 from apex)
 *      /------\
 *     /        \ <-- Cut 2 (distance x2 from apex)
 *    /----------\
 *   /____________\ <-- Base
 *
 * INPUT:
 * The input contains two space-separated integers, n and h (2 <= n <= 1000, 1
 * <= h <= 10^5).
 *
 * OUTPUT:
 * The output should contain n - 1 real numbers x1, x2, ..., xn-1, representing
 * the distances from the apex to each cut. The output is considered correct if
 * the absolute or relative error of each number doesn't exceed 10^-6.
 *
 * Example:
 * Input: 3 2
 * Output: 1.154700538379 1.632993161855
 *
 * The cuts at distances x1 and x2 from the apex divide the triangle into three
 * sections of equal area.
 *
 * APPROACH:
 * A binary search algorithm is used to determine the height at which each cut
 * should be made to achieve the equal areas. This involves iteratively
 * adjusting the cut position and calculating the area of the trapezoid formed
 * until the desired precision is reached.
 */
