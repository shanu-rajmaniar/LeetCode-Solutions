func canReach(arr []int, start int) bool {
    n := len(arr)
    var vis []int
    vis = make([]int, n)
    ans := false
    var dfs func(int)
    dfs = func(nn int) {
        vis[nn] = 1
        if arr[nn] == 0 { 
            ans = true
        }
        if nn - arr[nn] >= 0 && vis[nn - arr[nn]] == 0 {
            dfs(nn - arr[nn])
        }
        if nn + arr[nn] < n && vis[nn + arr[nn]] == 0 {
            dfs(nn + arr[nn])
        }
    }
    dfs(start)
    return ans
}