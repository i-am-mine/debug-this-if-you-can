#include "../header/solution_interface.h"
using namespace std;

int countTrapezoids(vector<vector<int>>& points) {
    int n = points.size();
    if (n < 4) return 0;

    // Map: Slope -> (Intercept -> Count of Pairs)
    // Slope is {dy, dx} reduced. Intercept is dx*y - dy*x.
    map<pair<int, int>, map<long long, int>> lines;

    // Map: Midpoint -> (Slope -> Count of Segments)
    // Midpoint represented by {sum_x, sum_y}.
    // We group by slope to distinguish between valid parallelograms and collinear degenerate ones.
    map<pair<int, int>, map<pair<int, int>, int>> midpoints;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int x1 = points[i][0], y1 = points[i][1];
            int x2 = points[j][0], y2 = points[j][1];

            // --- 1. Slope Calculation ---
            int dy = y2 - y1;
            int dx = x2 - x1;

            int g = std::gcd(abs(dy), abs(dx));
            dy /= g;
            dx /= g;

            // Canonicalize slope: ensure dx > 0, or if dx==0 then dy > 0
            if (dx < 0 || (dx == 0 && dy < 0)) {
                dx = -dx;
                dy = -dy;
            }
            pair<int, int> slope = {dy, dx};

            // --- 2. Line Grouping (for Trapezoid Candidates) ---
            long long intercept = (long long)dx * y1 - (long long)dy * x1;
            lines[slope][intercept]++;

            // --- 3. Midpoint Grouping (for Parallelogram Subtraction) ---
            // We store the slope alongside the midpoint count
            midpoints[{x1 + x2, y1 + y2}][slope]++;
        }
    }

    long long totalCandidates = 0;

    // Calculate potential trapezoids based on parallel lines
    // Sum of products of counts on distinct parallel lines
    for (auto const& [slope, interceptMap] : lines) {
        long long sumCounts = 0;
        long long sumSqCounts = 0;

        for (auto const& [intercept, count] : interceptMap) {
            sumCounts += count;
            sumSqCounts += (long long)count * count;
        }

        // Formula for sum(a_i * a_j) where i < j: ((Sum)^2 - Sum(Sq)) / 2
        totalCandidates += (sumCounts * sumCounts - sumSqCounts) / 2;
    }

    long long validParallelograms = 0;

    // Calculate valid parallelograms to subtract
    // A valid parallelogram is formed by two segments sharing a midpoint BUT having different slopes.
    // If they have the same slope, they are collinear and didn't contribute to totalCandidates.
    for (auto const& [mid, slopeMap] : midpoints) {
        long long totalSegmentsAtMid = 0;
        long long degeneratePairs = 0;

        for (auto const& [slope, count] : slopeMap) {
            totalSegmentsAtMid += count;
            // Pairs of segments with the SAME slope are collinear (degenerate)
            degeneratePairs += (long long)count * (count - 1) / 2;
        }

        long long totalPairs = totalSegmentsAtMid * (totalSegmentsAtMid - 1) / 2;

        // Valid parallelograms = Total pairs sharing midpoint - Degenerate (collinear) pairs
        validParallelograms += (totalPairs - degeneratePairs);
    }

    return (int)(totalCandidates - validParallelograms);
}
