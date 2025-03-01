class Solution {
  public int numberOfNodes(int n, int[] queries) {
    // flipped[i] := true if we should flip all values in the subtree of node i.
    boolean[] flipped = new boolean[n + 1];

    for (final int q : queries)
      flipped[q] = flipped[q] ^ true;

    return dfs(1, 0, n, flipped);
  }

  private int dfs(int label, int value, int n, boolean[] flipped) {
    if (label > n)
      return 0;
    value ^= flipped[label] ? 1 : 0;
    return value +                          //
        dfs(label * 2, value, n, flipped) + //
        dfs(label * 2 + 1, value, n, flipped);
  }
}
