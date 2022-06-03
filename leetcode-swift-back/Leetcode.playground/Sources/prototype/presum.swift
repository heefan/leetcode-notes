import Foundation


func presum(_ nums: [Int]) -> [Int] {
    var presum = [Int](repeating:0, count: nums.count + 1)
    
    nums.enumerated().forEach {
        presum[$0+1] = presum[$0] + $1
    }
    
    presum.removeFirst(1)
    return presum
}

let array = [1,2,3,4]
let result = presum(array)
//assert(result == [1,3,6,10], "the arry should be prsum")


