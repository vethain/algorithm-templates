double my_sqrt(double a)
{
    // 处理负数情况，返回 NaN
    if (a < 0)
    {
        return std::numeric_limits<double>::quiet_NaN();
    }

    // 特殊情况：0 和 1 的平方根是自身
    if (a == 0 || a == 1)
    {
        return a;
    }

    // 牛顿迭代法计算平方根近似值
    double x0 = a / 2;             // 初始猜测值
    double x1 = (x0 + a / x0) / 2; // 第一次迭代

    // 迭代直到精度满足要求（相邻两次迭代差值小于 1e-15）
    while (std::abs(x1 - x0) > 1e-15)
    {
        x0 = x1;
        x1 = (x0 + a / x0) / 2; // 牛顿迭代公式
    }

    // 检查结果是否接近某个整数（完全平方数情况）
    double candidate = std::round(x1); // 四舍五入得到候选整数
    if (std::abs(candidate * candidate - a) < 1e-10)
    {
        return candidate; // 如果是完全平方数，返回精确整数
    }

    return x1; // 否则返回迭代得到的近似值
}