func canReach(s string, minJump int, maxJump int) bool {
    n := len(s)
    cnt := 0
    var dp []int
    dp = make([]int, n)
    dp[0] = 1
    for i := 1; i < n; i++ {
        if i >= minJump {
            cnt += dp[i - minJump]
        }
        if i > maxJump {
            cnt -= dp[i - maxJump - 1];
        }
        if s[i] == '0' && cnt > 0 {
            dp[i] = 1
        }
    }
    if dp[n - 1] == 1 {
        return true
    } else {
        return false
    }
}