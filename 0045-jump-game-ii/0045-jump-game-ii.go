func jump(nums []int) int {
    n := len(nums)
    last, maxi, ans := nums[0], nums[0], 0
    for i := 1; i < n; {
        j := i
        for j < n && j <= last {
            maxi = int(math.Max(float64(maxi), float64(j + nums[j])))
            j++
        }
        i = j
        ans++
        last = maxi
    }
    return ans
}