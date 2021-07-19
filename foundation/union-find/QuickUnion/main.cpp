#include <iostream>
#define CATCH_CONFIG_MAIN
#include "Catch2/catch.hpp"
#include <vector>

using namespace std;

class QuickUnion {
    vector<int> parents;
    vector<int> weights;
    int componentCount;

public:
    QuickUnion(int N): componentCount(N) {
        parents = vector<int>(N);
        weights = vector<int>(N);

        for(int i = 0; i < N; ++i) {
            parents[i] = i;
            weights[i] = 1;
        }
    }

    void UNION(int p, int q) {
        if(!validate(p)) return;
        if(!validate(q)) return;

        int pRoot = FIND(p);
        int qRoot = FIND(q);

        if(pRoot == qRoot) { return; }

        if (weights[pRoot] < weights[qRoot]) {
            parents[pRoot] = qRoot;
            weights[qRoot] += weights[pRoot];
        } else {
            parents[qRoot] = pRoot;
            weights[pRoot] += weights[qRoot];
        }

        componentCount --;
    }

    int FIND(int p) {
        while( p != parents[p]) {
            p = parents[p];
        }

        return p;
    }

    bool connected(int p, int q) {
        if(!validate(p)) return false;
        if(!validate(q)) return false;

        return FIND(p) == FIND(q);
    }

    int count() {
        return componentCount;
    }

private:
    bool validate(int p) {
        if (p >= parents.size() || p < 0) return false;
        return true;
    }
};


TEST_CASE( "Test Weighted Union Find Algorithms") {
    SECTION("Given 2 points, it should be 1 component") {
        QuickUnion quickUnion(2);
        quickUnion.UNION(0, 1);

        REQUIRE(quickUnion.count() == 1);
        REQUIRE(quickUnion.connected(0, 1) == true);
        REQUIRE(quickUnion.connected(0, 2) == false);
    }

    SECTION("Given 4 points without connection, it should be 2 component") {
        QuickUnion quickUnion(4);
        quickUnion.UNION(0, 1);
        quickUnion.UNION(2, 3);

        REQUIRE(quickUnion.count() == 2);
        REQUIRE(quickUnion.connected(0, 1) == true);
        REQUIRE(quickUnion.connected(0, 3) == false);
    }

    SECTION( "Given 12 pairs (algo4th_tinyUF.txt, it should be 2 component" ) {
        QuickUnion quickUnion(10);
        quickUnion.UNION(4,3);
        quickUnion.UNION(3,8);
        quickUnion.UNION(6,5);
        quickUnion.UNION(9,4);
        quickUnion.UNION(2,1);
        quickUnion.UNION(8,9);
        quickUnion.UNION(5,0);
        quickUnion.UNION(7,2);
        quickUnion.UNION(6,1);
        quickUnion.UNION(6,1);
        quickUnion.UNION(1,0);
        quickUnion.UNION(6,7);

        REQUIRE(quickUnion.count() == 2);
        REQUIRE(quickUnion.connected(4, 8) == true);
        REQUIRE(quickUnion.connected(6, 0) == true);
        REQUIRE(quickUnion.connected(4, 6) == false);
    }
}
