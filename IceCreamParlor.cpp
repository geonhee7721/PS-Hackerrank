

/* 
 * Hash Tables: Ice Cream Parlor
 * https://www.hackerrank.com/challenges/ctci-ice-cream-parlor/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=search
 */

void whatFlavors(vector<int> cost, int money) {
    multimap<int, int> costMap;
    for (int i = 0; i < cost.size(); ++i) costMap.insert(make_pair(cost[i], i));
    
    for (int i = 0; i < cost.size(); ++i) {
        int another = money - cost[i];
        if (another <= 0) continue;
        
        if ((cost[i] == another && costMap.count(another) > 1) || (cost[i] != another && costMap.count(another) > 0)) {
            for (auto f = costMap.lower_bound(another); f != costMap.upper_bound(another); f++) {
                if (i != f->second) {
                    cout << i + 1 << " " << f->second + 1 << "\n";
                    return;
                }
            }
        }
    }
}
