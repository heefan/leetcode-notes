//
// Created by LI Tian on 25/2/22.
//

// quick sort
// 思想：partition 和 sort
//   *. partition: 其实是双指针 i, j
//        *. 选中pivot(一般是第一个或者最后一个，就按照最后一个算好了）。
//        *. ---i: 用于存放数值比arr[pivot]小的数
//        *.   i---j 存放数值比arr[pivot]大的数
//        *.       j---- 用于遍历。
//      遍历完后，得出新的pivot的位置， -----(i,j)-----(Pivot)，这样pivot与j交换，就是新的pivot的值。
//   *  sort: 递归方法
// 要素：
// https://www.youtube.com/watch?v=duln2xAZhBA
//
// 个人体会：我之前把quick sort和merge sort混了。

#include "catch2/catch.hpp"
#include <vector>
#include "vector_helper.h"

using namespace std;

// 2,1,3
// 如果pivot选择为3，那么这就是一个合法的partition，所以partition算法并不会改变这个vector，最终返回的新的pivot也是index=2.
// 下一次检查的是partition [2,1] 和 3.. （越界，不用查）
//
// 2，3，1, 设pivot为1
// 2,3都比pivot大，说明分区不合法，要更新分区。
// 合法的分区是，i的左边都比1小，i到j 都应该比pivot大，但是没有这个数，所以i还是初始值0
// 开始更新分区，这时候将左边界i与pivot交换，左边界i作为新的pivot返回。
// 即， 2,3,1 ->  1,3,2 (返回i=0)

// 算法的关键
// 判断条件： 吃进去新元素的右指针j < pivot值，说明该新元素应该放在左边界处。
// 2,5,3,4 (p=4)`
// 第0轮：进来2，满足条件，但是i,j都是0，所以交换等于没交换,  i=>1, j=>>1
// 第1轮：进来5，不满足条件，i==1, j=>>2
// 第2轮：进来3，满足条件，这时i指向5，j指向3，做交换， => 2,3,5,4 => i=>2, j=>3 (i总是指向可以交换的位置）
// 第3轮，循环结束, 排序结果为, 2,3,5,4  (i=2, j=3, p=3) 也就是说，i现在指向的位置，就应该是pivot应该在的位置。
// 将pivot放在i的位置 =》  2,3,4，5， 下一次的pivot就是i(i==2)

// 快速记忆：
// 分区+递归
// 分区：1. 双指针控制遍历，i,j,pivot,
//      2. 交换条件： 右指针值（新元素） 小于 pivot值，则将左指针值 与 右指针交换 达到 左指针总是指向小于pivot的分区。
// 循环完毕，将pivot放回原数组中，通过交换 左指针值。 这样 做指针就是新的分区值。

int partition(vector<int> &arr, int start, int end) {
    int pivot = end; //pivot 是比较的标准。 最终将pivot放在应该放得位置，然后作为下一个pivot的值。
    int i = start;  // i控制左边界, j控制右边界
    for(int j=start; j<end; ++j) {
        if(arr[j] < arr[pivot]) {
            swap(arr[i], arr[j]);  // 新元素的位置，应该在左边界i处，所以做交换
            ++i;
        }
    }
    swap(arr[i], arr[pivot]);
    return i;
}

void quickSort(vector<int> &arr, int start, int end) {
    if(start > end) return ;
    int p = partition(arr, start, end);
    quickSort(arr, start, p-1);
    quickSort(arr, p+1, end);
}

TEST_CASE("foundation: quick sort") {
    SECTION("sort vector with quick sort") {
        vector<int> arr = {2,5,3,4};

        quickSort(arr, 0, arr.size()-1);
        vector<int> expect = {2,3,4,5};

        REQUIRE(isVectorSame(arr, expect) == true);
    }
}
